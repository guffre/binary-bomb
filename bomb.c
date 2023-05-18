#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <pthread.h>
    #include <linux/input.h>
#endif
#include "support.h"

void startup() __attribute__((constructor));
int stage_one();
int stage_two();
int stage_three();
int stage_four();
int stage_five();
int secret_stage();
void teardown() __attribute__((destructor));

int lock = 0;
int keys[] = {0x34, 0x35, 0x36};

void startup() {
    #ifdef _WIN32
    thread = (HANDLE)CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)secret_stage, NULL, 0, NULL);
    #else
    pthread_create(&thread, NULL, secret_stage, NULL);
    #endif
}

void teardown() {
    int wait_length = 10000;
    if (lock < 5) {
        wait_length = 1;
    }
    #ifdef _WIN32
    WaitForSingleObject(thread, wait_length);
    #else
    #endif
}

int main(int argc, char **argv) {
    printf("[+] Welcome to the \"RE-ALL-THE-THINGS\" binary bomb!\n");
    printf("[+] Really Excellent - Assembly Language Learner - \nTo Help Everyone - That Has Interest, Now Get Solving!\n\n");
    printf("[+] Good luck!\n");
    lock = stage_one();
    lock = stage_two();
    lock = stage_three();
    lock = stage_four();
    lock = stage_five();
    printf("You've completed RE-ALL-THE-THINGS!\n");
    return 0;
}

int stage_one() {
    banner_stage_one();
    char *user_input = get_user_input();
    char *password = "hunter2";

    if (strcmp(user_input, password)){
        failure(1);
    }

    printf("Stage one complete!\n");
    free(user_input);
    return 1;
}

int stage_two() {
    banner_stage_two();
    char *user_input = get_user_input();
    char password[] = "Captain Picard";
    int length = strlen(user_input);
    
    for (int count = 0; count < length; count++){
        if (password[count] != user_input[count]) {
            failure(2);
        }
    }

    printf("Stage two complete!\n");
    free(user_input);
    return 2;
}

int stage_three() {
    banner_stage_three();
    char *user_input = get_user_input();
    char *password = "piqt(kim{iz)";
    int length = strlen(password);

    for (int count = 0; count < length; count++){
        if (password[count]+8 != user_input[count]) {
            failure(3);
        }
    }

    printf("Stage three complete!\n");
    free(user_input);
    return 3;
}

int stage_four() {
    banner_stage_four();
    char *user_input = get_user_input();
    unsigned char sbox[] = {20, 195, 96, 227, 71, 99, 214, 105, 102, 153, 43, 124, 83, 137, 54, 242, 238, 96, 73, 138, 124, 92, 23, 108, 248, 10, 152, 136, 60, 192, 55, 234, 203, 130, 13, 48, 102, 33, 199, 130, 215, 235, 177, 138, 167, 146, 132, 139, 131, 8, 173, 132, 147, 89, 174, 155, 103, 45, 10, 20, 164, 51, 212, 246, 236, 131, 173, 177, 22, 223, 41, 179, 102, 144, 236, 198, 199, 191, 59, 242, 124, 34, 133, 115, 148, 188, 249, 147, 68, 124, 94, 168, 123, 141, 181, 127, 248, 37, 54, 69, 149, 94, 173, 244, 75, 100, 67, 123, 160, 121, 129, 207, 34, 117, 33, 117, 195, 213, 104, 238, 87, 171, 32, 106, 144, 59, 119, 34, 234, 52, 12, 209, 93, 57, 157, 162, 94, 225, 129, 48, 192, 197, 141, 212, 186, 57, 20, 236, 17, 75, 98, 214, 99, 202, 5, 16, 219, 163, 112, 245, 61, 43, 23, 137, 78, 189, 89, 60, 13, 139, 184, 97, 103, 131, 28, 60, 110, 157, 98, 111, 6, 109, 197, 151, 106, 234, 156, 161, 6, 231, 6, 217, 22, 210, 109, 26, 135, 24, 241, 240, 149, 53, 61, 166, 242, 51, 115, 167, 233, 27, 13, 191, 150, 105, 118, 208, 16, 32, 140, 117, 11, 128, 193, 40, 63, 76, 21, 5, 183, 170, 51, 127, 118, 76, 230, 230, 239, 213, 157, 131, 162, 180, 83, 23, 95, 243, 59, 61, 172, 181, 69, 146, 254, 217, 93, 141};
    unsigned char password[] = {0x78,0xac,0xc,0x84,0x20,0x14,0xa6}; 

    for (int count = 0; count <= 6; count++){
        if (((unsigned char)(user_input[count])^sbox[count]) != password[count]) {
            failure(4);
        }
    }

    printf("Stage four complete!\n");
    free(user_input);
    return 4;
}

int stage_five() {
    banner_stage_five();
    char *user_input = get_user_input();
    int total = 0;
    int adder = 0;

    for (int count = 0; count < 5; count++) {
        int current = user_input[count] - 48;
        switch (count) {
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
        failure(5);
    }
    printf("Stage five complete!\n");
    free(user_input);
    return 5;
}

int secret_stage() {
    //Note: Some keyboards do not support 3-key rollover. If this is the case
    //simply change "keystate >= 0" to "keystate != 0". This allows the stage
    //to be passed by pushing the keys in order, rather then all at once.
    #ifdef _WIN32
    int counter = 3;
    int keystate;
    while (counter) {
        counter--;
        keystate = GetAsyncKeyState(keys[counter]);
        if ((lock < 5) || (keystate >= 0)){
            counter = 3;
        }
        if (lock >= 5) {
            printf(".");
        }
        Sleep(100);
    }
    #else
    FILE *kbd = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");

    char key_map[KEY_MAX/8 + 1];    //  Create a byte array the size of the number of keys

    memset(key_map, 0, sizeof(key_map));    //  Initate the array to zero's
    ioctl(fileno(kbd), EVIOCGKEY(sizeof(key_map)), key_map);    //  Fill the keymap with the current keyboard state

    int keyb = key_map[key/8];  //  The key we want (and the seven others arround it)
    int mask = 1 << (key % 8);  //  Put a one in the same column as out key state will be in;

    return !(keyb & mask);  //  Returns true if pressed otherwise false
    #endif
    printf("\nCongratulations on beating the secret stage!\n");
    return 1;
}