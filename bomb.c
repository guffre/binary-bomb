#include <Windows.h>
#include <stdio.h>
#include <math.h>

#define INPUT_FAILURE 10

int stage_zero();
int stage_one();
int stage_two();
int stage_three();
int stage_four();
int secret_stage(int *key_length);

int lock = 0; //Not thread-safe, but I don't want to confuse newcomers with critical sections
int keys[] = {0x34, 0x35, 0x36};
int calloc_size = 64;

int failure(int stage) {
    printf("\nWhoops! Try again...\n");
    exit(stage);
}
int user_input(char *p, int len){
    printf("> ");
    fgets(p, len, stdin);
    int i;
    for (i = 0; i < len; i++) {
        if (p[i] == '\n') {
            p[i] = '\x0';
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    int magic = 3;
    HANDLE mnum = (HANDLE)CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)secret_stage, &magic, 0, NULL);
    printf("[+] Welcome to the \"RE-ALL-THE-THINGS\" binary bomb!\n");
    printf("[+] Really Excellent - Assembly Language Learner - \nTo Help Everyone - That Has Interest, Now Get Solving!\n\n");
    printf("[+] Good luck!\n");
    lock = stage_zero();
    lock = stage_one();
    lock = stage_two();
    lock = stage_three();
    lock = stage_four();
    WaitForSingleObject(mnum, 10000);
    printf("\You've completed RE-ALL-THE-THINGS!\n");
    return 0;
}

int stage_zero() {
    char p[16] = {0};
    printf("\n\t*** Stage Zero***\n");
printf("  _               _                        ___  _  _   _  _  ____ ___  __ \n");
printf(" | |             | |                      |__ \\| || | | || ||___ \\__ \\/_ |\n");
printf(" | |__   __ _ ___| |__    ___  _ __ __ _     ) | || |_| || |_ __) | ) || |\n");
printf(" | '_ \\ / _` / __| '_ \\  / _ \\| '__/ _` |   / /|__   _|__   _|__ < / / | |\n");
printf(" | |_) | (_| \\__ \\ | | || (_) | | | (_| |  / /_   | |    | | ___) / /_ | |\n");
printf(" |_.__/ \\__,_|___/_| |_(_)___/|_|  \\__, | |____|  |_|    |_||____/____||_|\n");
printf("                                    __/ |                                 \n");
printf("                                   |___/\n");

    char *password = "hunter2";
    if (user_input(p, 16) == 0) {
        failure(INPUT_FAILURE);
    }
    if (strcmp(p,password)){
        failure(0);
    }
    printf("Stage zero complete!\n");
    return 0;
}

int stage_one(){
    char *p = calloc(64,1);
    int count = 0;
    char pw[] = "Captain Jean Luc Picard, of the USS Enterprise";
    printf("\n\t*** Stage One***\n");
printf("__________________          _-_\n");
printf("\\________________|)____.---'---`---.___\n");
printf("\t  ||      \\----._________.----/\n");
printf("\t  ||     / ,'   `---'\n");
printf("       ___||_,--'  -._ \n");
printf("      /___          ||(-\n");
printf("          `---._____-'\n");

    if (user_input(p, 64) == 0) {
        failure(INPUT_FAILURE);
    }
    for (count; count < 46; count++){
        if (pw[count] != p[count] || p[count] == 0x0) {
            failure(1);
        }
    }
    free(p);
    printf("Stage one complete!\n");
    return 1;
}

int stage_two(){
    int buf_len = 64;
    char *p = calloc(buf_len,1);
    char *password = "piqt(kim{iz)";
    int count = strlen(password)-1;
    printf("\n\t*** Stage Two***\n");
printf(" ,adPPYba, ,adPPYYba,  ,adPPYba, ,adPPYba, ,adPPYYba, 8b,dPPYba,  \n");
printf("a8\"     \"\" \"\"     `Y8 a8P_____88 I8[    \"\" \"\"     `Y8 88P'   \"Y8  \n");
printf("8b         ,adPPPPP88 8PP\"\"\"\"\"\"\"  `\"Y8ba,  ,adPPPPP88 88          \n");
printf("\"8a,   ,aa 88,    ,88 \"8b,   ,aa aa    ]8I 88,    ,88 88          \n");
printf(" `\"Ybbd8\"' `\"8bbdP\"Y8  `\"Ybbd8\"' `\"YbbdP\"' `\"8bbdP\"Y8 88\n");
    if (user_input(p, buf_len) == 0) {
        failure(INPUT_FAILURE);
    }
    while (count >= 0) {
        if (p[count]+8 != password[count]) {
            failure(2);
        }
        count--;
    }
    free(p);
    printf("Stage two complete!\n");
    return 2;
}

int stage_three(){
    int sbox[] = {20, 195, 96, 227, 71, 99, 214, 105, 102, 153, 43, 124, 83, 137, 54, 242, 238, 96, 73, 138, 124, 92, 23, 108, 248, 10, 152, 136, 60, 192, 55, 234, 203, 130, 13, 48, 102, 33, 199, 130, 215, 235, 177, 138, 167, 146, 132, 139, 131, 8, 173, 132, 147, 89, 174, 155, 103, 45, 10, 20, 164, 51, 212, 246, 236, 131, 173, 177, 22, 223, 41, 179, 102, 144, 236, 198, 199, 191, 59, 242, 124, 34, 133, 115, 148, 188, 249, 147, 68, 124, 94, 168, 123, 141, 181, 127, 248, 37, 54, 69, 149, 94, 173, 244, 75, 100, 67, 123, 160, 121, 129, 207, 34, 117, 33, 117, 195, 213, 104, 238, 87, 171, 32, 106, 144, 59, 119, 34, 234, 52, 12, 209, 93, 57, 157, 162, 94, 225, 129, 48, 192, 197, 141, 212, 186, 57, 20, 236, 17, 75, 98, 214, 99, 202, 5, 16, 219, 163, 112, 245, 61, 43, 23, 137, 78, 189, 89, 60, 13, 139, 184, 97, 103, 131, 28, 60, 110, 157, 98, 111, 6, 109, 197, 151, 106, 234, 156, 161, 6, 231, 6, 217, 22, 210, 109, 26, 135, 24, 241, 240, 149, 53, 61, 166, 242, 51, 115, 167, 233, 27, 13, 191, 150, 105, 118, 208, 16, 32, 140, 117, 11, 128, 193, 40, 63, 76, 21, 5, 183, 170, 51, 127, 118, 76, 230, 230, 239, 213, 157, 131, 162, 180, 83, 23, 95, 243, 59, 61, 172, 181, 69, 146, 254, 217, 93, 141};
    int password[] = {0x78,0xac,0xc,0x84,0x20,0x14,0xa6}; 
    char *p = calloc(calloc_size,1);
    int count = 0;

    printf("\n\t*** Stage Three***\n");
printf("                                       \\  __\n");
printf("                                        \\/  \\\n");
printf("                                        /\\__/\n");
printf("                                       |  \n");
printf("                              _________|__________\n");
printf("                        _,.-'`                    `'-.,_\n");
printf("                    _,-'                                `-._\n");
printf("                 ,-'                _______       ,......   `-.\n");
printf("               ,'    _.---._     __/S E G A\\__   ( START )     `.\n");
printf("              /    ,'  .-.  `.  |G E N E S I S|   `''''''  .-.   \\\n");
printf("             /    /  __|_|__  \\ ``````````````        .-. ( C )   \\\n");
printf("            |     | |__(_)__| |                  .-. ( B ) `-'     |\n");
printf("            |     \\    | |    /                 ( A ) `-'          |\n");
printf("            |      `._ '-' _,'                   `-'               |\n");
printf("             \\        `---'      _______________                   /\n");
printf("              \\              _,-'               `-._              /\n");
printf("               \\           ,'                       `.           /\n");
printf("                `.        /                           \\        ,'\n");
printf("                  `.____,'                             `.____,'\n");

    if (user_input(p, calloc_size) == 0) {
        failure(INPUT_FAILURE);
    }
    for (count; count < 6; count++){
        if ((p[count]^sbox[count]) != password[count]) {
            failure(2);
        }
    }
    printf("%d\n",count);
    if ((p[6]^sbox[6]) != password[6]) { 
        failure(3);
    }
    free(p);
    printf("Stage three complete!\n");
    return 3;
}

int stage_four() {
        char *p = calloc(calloc_size,1);
        int total = 0;
        int adder = 0;
        int x = 0;

        printf("\n\t*** Stage Four***\n");
printf("           __________  \n");
printf("         .'----------`.                              \n");
printf("         | .--------. |                             \n");
printf("         | |########| |       __________              \n");
printf("         | |########| |      /__________\\             \n");
printf(".--------| `--------' |------|    --=-- |-------------.\n");
printf("|        `----,-.-----'      |o ======  |             | \n");
printf("|       ______|_|_______     |__________|             | \n");
printf("|      /  %%%%%%%%%%%%%%%%%%%%%%%%  \\                             | \n");
printf("|     /  %%%%%%%%%%%%%%%%%%%%%%%%%%%%  \\                            | \n");
printf("|     ^^^^^^^^^^^^^^^^^^^^                            | \n");
printf("+-----------------------------------------------------+\n");
printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n");

    if (user_input(p, calloc_size) != 1) {
        failure(INPUT_FAILURE);
    }
    for (x = 0; x < 5; x++){
        int current = p[x]-48;
        switch (x) {
            case 0:
                adder = pow(current,1);
                break;
            case 1:
                adder = pow(current,2);
                break;
            case 2:
                adder = pow(current,3);
                break;
            case 3:
                adder = pow(current,4);
                break;
            case 4:
                adder = pow(current,5);
                break;
        }
        total += adder;
    }
    if (total != 9001) {
        failure(4);
    }
    free(p);
    printf("Stage four complete!\n");
    return 4;
}

int secret_stage(int *x) {
    //Note: Some keyboards do not support 3-key rollover. If this is the case
    //simply change "keystate >= 0" to "keystate != 0". This allows the stage
    //to be passed by pushing the keys in order, rather then all at once.
    int counter = *x;
    int keystate;
    while (counter){
        counter--;
        keystate = GetAsyncKeyState(keys[counter]);
        if ((lock != 4) ||  (keystate >= 0)){
            counter = *x;
        }
        if (lock == 4) {
            printf(".");
        }
        Sleep(100);
    }
    printf("\nCongratulations on beating the secret stage!\n");
    return 1;
}
