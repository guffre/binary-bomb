#ifdef _WIN32
    HANDLE thread;
#else
    pthread_t thread;
#endif


char* get_user_input(void){
    char *user_input = calloc(128,1);
    while (1) {
        printf("> ");
        fgets(user_input, 127, stdin);
        user_input[strcspn(user_input, "\n")] = 0;
        if (strlen(user_input) > 0) {
            break;
        }
    }
    return user_input;
}

int failure(int stage) {
    printf("\nWhoops! Try again...\n");
    exit(stage);
}

static inline void banner_stage_one(void) {
    printf("\n\t*** Stage One***\n");
    printf("  _               _                        ___  _  _   _  _  ____ ___  __ \n");
    printf(" | |             | |                      |__ \\| || | | || ||___ \\__ \\/_ |\n");
    printf(" | |__   __ _ ___| |__    ___  _ __ __ _     ) | || |_| || |_ __) | ) || |\n");
    printf(" | '_ \\ / _` / __| '_ \\  / _ \\| '__/ _` |   / /|__   _|__   _|__ < / / | |\n");
    printf(" | |_) | (_| \\__ \\ | | || (_) | | | (_| |  / /_   | |    | | ___) / /_ | |\n");
    printf(" |_.__/ \\__,_|___/_| |_(_)___/|_|  \\__, | |____|  |_|    |_||____/____||_|\n");
    printf("                                    __/ |                                 \n");
    printf("                                   |___/\n");
}

static inline void banner_stage_two(void) {
    printf("\n\t*** Stage Two***\n");
    printf("__________________          _-_\n");
    printf("\\________________|)____.---'---`---.___\n");
    printf("\t  ||      \\----._________.----/\n");
    printf("\t  ||     / ,'   `---'\n");
    printf("       ___||_,--'  -._ \n");
    printf("      /___          ||(-\n");
    printf("          `---._____-'\n");
}

static inline void banner_stage_three(void) {
    printf("\n\t*** Stage Three***\n");
    printf(" ,adPPYba, ,adPPYYba,  ,adPPYba, ,adPPYba, ,adPPYYba, 8b,dPPYba,  \n");
    printf("a8\"     \"\" \"\"     `Y8 a8P_____88 I8[    \"\" \"\"     `Y8 88P'   \"Y8  \n");
    printf("8b         ,adPPPPP88 8PP\"\"\"\"\"\"\"  `\"Y8ba,  ,adPPPPP88 88          \n");
    printf("\"8a,   ,aa 88,    ,88 \"8b,   ,aa aa    ]8I 88,    ,88 88          \n");
    printf(" `\"Ybbd8\"' `\"8bbdP\"Y8  `\"Ybbd8\"' `\"YbbdP\"' `\"8bbdP\"Y8 88\n");
}

static inline void banner_stage_four(void) {
    printf("\n\t*** Stage Four***\n");
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
}

static inline void banner_stage_five(void) {
    printf("\n\t*** Stage Five***\n");
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
}

