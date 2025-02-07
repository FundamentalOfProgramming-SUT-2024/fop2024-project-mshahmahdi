#include<stdio.h>
#include<ncursesw/ncurses.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>
#include<time.h>

#define WIDTH 200
#define HEIGHT 50

int *values_ptr = NULL;

typedef struct{
    char name[50];
    char password[50];
    char email[60];
    int score ;int gold;
    int count_game; 
    int time_game;
    int color; int game_level;
    int health; int amount_health; int weapon;
    int Excellentـfood ; int Regular_food; int health_Potion; int amount_food;
    int count_step;
    int x; int y;

} hinfo;

typedef struct{
    int x;
    int y;
} cor;

void print_margin();
void inter_menu(int * s_i_m, int * s_m, hinfo * hero, FILE * names, FILE * passwords, FILE * emails);
void print_option(int num_op, char * choices[]);
int sim_name(FILE * names, char name[]);
int is_valid_email(char email[]);
int is_valid_password(const char *str);
void creat_new_account(hinfo * hero, FILE * names, FILE * passwords, FILE * emails);
int find_name_in_file(FILE * file, char name[]);
int check_name_in_line(FILE * file, int n, char password[]);
void log_in(hinfo * hero, FILE * names, FILE * passwords);
void print_margin_score();
void print_option_menu(int num_op, char * choices[]);
char* get_nth_line(char * file_name, int n);
int compare(const void *a, const void *b);
void find_top_10_lines(char filename[], int topLines[200]);
void score_menu(hinfo * hero,FILE * names, FILE * scores, FILE * golds, FILE * count_games,FILE * time_games);
void print_option_setting2(int num_op2, char * choices2[]);
void print_option_setting1(int num_op1, char * choices[]);
void setting_menu(hinfo * hero);
void menu(int * s_m, int * s_p_g, hinfo * hero, FILE * names, FILE * emails, FILE * scores, FILE * golds, FILE * count_games,FILE * time_games);
void rand_num(int min_x, int max_x, int min_y, int max_y, int *x, int *y);
void rand_int(int min, int max, int *x);
void margin_map_8(char map[10][20], int pos_door);
void first_amount_8(char map[10][20]);
void margin_map_7(char map[10][20], int pos_door);
void first_amount_7(char map[10][20]);
void margin_map_6(char map[10][20], int pos_door);
void first_amount_6(char map[10][20]);
void draw_map_6_1(char map[10][20]);
void draw_map_7_1(char map[10][20]);
void draw_map_7_2(char map[10][20]);
void draw_map_8_1(char map[10][20]);
void draw_map_8_2(char map[10][20]);
void print_map_room(char map[10][20],int x, int y);
void print_map_page(char map[40][150],int x, int y, int color);
void shuffleArray(int arr[], int size);
void first_amount0(char map[10][20]);
void first_amount0c(char map[40][150]);
void first_amountr(int x, int y, char map[x][y]);
void put_map(char map_col[40][150], char map[10][20], int x, int y);
void put_rahro(char map_col[40][150], int tool, int arz, char ** rahro, int x, int y);
char **allocateGrid(int rows, int cols);
char **drawRandomPath(int x1, int y1, int x2, int y2, int *outRows, int *outCols);
void foun_door1(char map[10][20], cor * door);
void foun_door2(char map[10][20], cor * door, cor * door2);
void Preparing_map(int * s_p_m, int * s_p_g, char map_page[3][40][150]);
void print_endgame(int * s_m, int * s_p_g);
void damage(hinfo * hero, char map_page[40][150], char hayola);
void move_jolo(hinfo * hero, char map_page[40][150], int * s_i_m, int * s_p_g);
void move_aghab(hinfo * hero, char map_page[40][150], int * s_m, int * s_p_g );
void move_bala(hinfo * hero, char map_page[40][150] ,int * s_m, int * s_p_g);
void move_paeen(hinfo * hero, char map_page[40][150], int * s_m, int * s_p_g);
void attack_zaif(hinfo * hero, char map_page[40][150]);
void attack_ghavi(hinfo * hero, char map_page[40][150]);
void handel_game(char map_page[40][150], hinfo * hero, int time_start, int time_end, int *s_m, int *s_i_m, int * s_p_g, char key);







int main(){

    setlocale(LC_ALL, ""); initscr(); start_color(); keypad(stdscr, TRUE); srand(time(NULL));

    init_color(50, 803, 803, 803);// نقره ای 
    init_color(51, 804, 498, 196); // برنزی
    init_color(52, 1000, 843, 0); // طلایی
    init_color(53, 662, 662, 662); // خاکستری
    init_color(54, 1000, 647, 0); // نارنجی
    init_color(55, 500, 0, 500); // بنفش
    init_color(56, 250, 880, 815); // فیروزه ای
    init_color(57, 0, 1000, 500); // زمردی
    init_color(58, 500, 1000, 500); // سبز روشن
    init_color(59, 165, 412, 882); // آبی سلطتنی
    init_color(60, 600, 300, 600); // بنفش کمرنگ
    init_color(61, 0, 800, 0);  // سبز پررنگ 
    init_color(62, 900, 800, 300);  // رنگ موزی

    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(8, 50, COLOR_BLACK);
    init_pair(9, 51, COLOR_BLACK);
    init_pair(10, 52, COLOR_BLACK);
    init_pair(11, 53, COLOR_BLACK);
    init_pair(12, 54, COLOR_BLACK);
    init_pair(13, 55, COLOR_BLACK);
    init_pair(14, 56, COLOR_BLACK);
    init_pair(15, 57, COLOR_BLACK);
    init_pair(16, 58, COLOR_BLACK);
    init_pair(17, 59, COLOR_BLACK);
    init_pair(18, 60, COLOR_BLACK);
    init_pair(19, 61, COLOR_BLACK);
    init_pair(20, 62, COLOR_BLACK);

    FILE * names; FILE * passwords;FILE * emails; FILE * scores; FILE * golds; FILE * count_games; FILE * time_games;
    hinfo * hero = (hinfo *) malloc (sizeof(hinfo)); char map_page[3][40][150];
    hero->amount_health = 1000000, hero->health = hero->amount_health,hero->health_Potion = 0; hero->weapon = 0; hero->game_level = 1; hero->Regular_food = 0; hero->Excellentـfood = 0;  hero->score = 0; hero->gold = 0; hero->amount_food = 10;
    hero->x = 1, hero->y=1; hero->color = 0; 
    int s_i_m = 1; int s_m = 0; int s_p_g = 0; int s_p_m = 0; int time_start; int time_end; char key;
    //print_margin();
    getch();
    while(1){
        if(s_i_m == 1){
            attron(A_BOLD);
            inter_menu(&s_i_m, &s_m, hero, names, passwords, emails);
            attroff(A_BOLD);
        }
        else if(s_m == 1){
            menu(&s_m, &s_p_m, hero, names, emails, scores, golds, count_games, time_games);
        }
        else if(s_p_m == 1){
            Preparing_map(&s_p_m, &s_p_g, map_page);
        }
        
        else if(s_p_g == 1){

            if(hero->game_level == 1){
                key = getch();
                handel_game(map_page[0], hero, time_start, time_end, &s_m, &s_i_m, &s_p_g, key);
            }
            else if(hero->game_level == 2){
                key = getch();
                handel_game(map_page[1], hero, time_start, time_end, &s_m, &s_i_m, &s_p_g, key);
            }
            else if(hero->game_level == 3){
                key = getch();
                handel_game(map_page[2], hero, time_start, time_end, &s_m, &s_i_m, &s_p_g, key);
            }
        }



    }

    //inter_menu();
    refresh();
    getch();
    getch();
    getch();
    endwin();


    return 0;
}



void print_margin(){
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    attron(COLOR_PAIR(1));

    for (int i = 0; i < 200; i++) {
        mvprintw(0, i, "#");           
        mvprintw(50 - 1, i, "#");   
    }
    for (int i = 0; i < 50; i++) {
        mvprintw(i, 0, "#");            
        mvprintw(i, 200 - 1, "#");    
    }
    refresh();
    attroff(COLOR_PAIR(1));
}
void print_option(int num_op, char * choices[]){

    if(num_op%3 == 0){
        attron(A_REVERSE);
        mvprintw(10, 90, "%s", choices[0]);
        attroff(A_REVERSE);
        mvprintw(12, 95, "%s", choices[1]);
        mvprintw(14, 93, "%s", choices[2]);
        attron(COLOR_PAIR(3)); mvprintw(17, 75, "%s", choices[3]); attroff(COLOR_PAIR(3)); refresh();
    }
    else if(num_op%3 == 1){
        mvprintw(10, 90, "%s", choices[0]);
        attron(A_REVERSE);
        mvprintw(12, 95, "%s", choices[1]);
        attroff(A_REVERSE);
        mvprintw(14, 93, "%s", choices[2]);
        attron(COLOR_PAIR(3)); mvprintw(17, 75, "%s", choices[3]); attroff(COLOR_PAIR(3)); refresh();
    }
    else if(num_op%3 == 2){
        mvprintw(10, 90, "%s", choices[0]);
        mvprintw(12, 95, "%s", choices[1]);
        attron(A_REVERSE);
        mvprintw(14, 93, "%s", choices[2]);
        attroff(A_REVERSE);
        attron(COLOR_PAIR(3)); mvprintw(17, 75, "%s", choices[3]); attroff(COLOR_PAIR(3)); refresh();

    }
}
void inter_menu(int * s_i_m, int * s_m, hinfo * hero, FILE * names, FILE * passwords, FILE * emails){


    curs_set(FALSE);
    noecho();
    int num_op = 0;
    int key;
    char * choices[] = {"<< Creat new account >>", "<< Log in >>", "<< guest login >>", "Note: If you log in as a guest, your score will not be recorded."};

    while(1){

        clear();
        print_margin();
        attron(COLOR_PAIR(2));
        mvprintw(3, 98 , "ROGUE");
        print_option(num_op, choices);
        refresh();


        key = getch();
        
        if(key == KEY_UP){
            num_op -= 1;
            if(num_op < 0){
                num_op = 2;
            }
        }
        else if(key == KEY_DOWN){
            num_op += 1;
            if(num_op > 2){
                num_op = 0;
            }
        }
        else if(key == 10){
            break;
        }

    }

    attroff(COLOR_PAIR(2));

    if(num_op == 0){
        creat_new_account(hero, names, passwords, emails);
        *s_i_m = 0; *s_m = 1;
    }
    else if(num_op == 1){
        log_in(hero, names, passwords);
        *s_i_m = 0; *s_m = 1;
    }
    else if(num_op == 2){
        strcpy(hero->name, "guest");
        *s_i_m = 0; *s_m = 1;

    }

    
    noecho();
    
}
int sim_name(FILE * names, char name[]){
    names = fopen("names.txt", "a+");
    char line [100];
    while (fgets(line, sizeof(line), names)) {
        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, name) == 0) {
            return 1;
        }
    }
    return 0;
}
int is_valid_email(char email[]) {

    char *at = strchr(email, '@'); 
    char *dot = strrchr(email, '.');

    if (!at || !dot) return 0; 
    if (at == email || dot == email) return 0; 
    if (at > dot) return 0; 
    if (*(at + 1) == '.' || *(dot + 1) == '\0') return 0; 

    if (strchr(at + 1, '@')) return 0; 

    return 1; 
}
int is_valid_password(const char *str) {
    int has_upper = 0, has_lower = 0, has_digit = 0;

    while (*str) { 
        if (isupper(*str)) has_upper = 1;  
        if (islower(*str)) has_lower = 1;  
        if (isdigit(*str)) has_digit = 1;  
        str++; 

        if (has_upper && has_lower && has_digit)
            return 1;
    }
    return 0; 
}
void creat_new_account(hinfo * hero, FILE * names, FILE * passwords, FILE * emails){

    clear();
    start_color();
    curs_set(FALSE); noecho();
    char * name = (char *) malloc (50 * sizeof(char)) ; char  * password = (char *) malloc (50 * sizeof(char)); char  * email = (char *) malloc (60 * sizeof(char)); int score = 0;
    int sn = 0; int sp = 0; int se = 0;

    print_margin();
    attron(COLOR_PAIR(4));
    mvprintw(15, 60, "Enter your name :");
    mvprintw(19, 60, "Enter your password :");
    mvprintw(23, 60, "Enter your email :");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(3));
    mvprintw(17, 60, "(The name should not contain spaces or enter characters !)");
    mvprintw(21, 60, "(The password must be at least 7 characters long and include uppercase and lowercase English letters and numbers !)");
    mvprintw(25, 60, "(The email must be in the format ""xxx@y.zzz"" !)");
    attroff(COLOR_PAIR(3));
    refresh();
    
    curs_set(TRUE); echo();
    mvscanw(15, 90, "%s", name);
    if(strcmp(name, "") != 0){ sn = 1; } if(sim_name(names, name) == 0){ sn += 2; }
    curs_set(FALSE);

    
    while(1){
        
        if(sn == 1){
            sn = 0;
            clear();
            print_margin();
            attron(COLOR_PAIR(4));
            mvprintw(15, 60, "Enter your name :");
            mvprintw(19, 60, "Enter your password :");
            mvprintw(23, 60, "Enter your email :");
            attroff(COLOR_PAIR(4));
            attron(COLOR_PAIR(3));
            mvprintw(17, 60, "(This name exists !)");
            mvprintw(21, 60, "(The password must be at least 7 characters long and include uppercase and lowercase English letters and numbers !)");
            mvprintw(25, 60, "(The email must be in the format ""xxx@y.zzz"" !)");
            attroff(COLOR_PAIR(3));
            refresh();

            curs_set(TRUE); echo();
            strcpy(name, ""); mvscanw(15, 90, "%s", name);
            if(strcmp(name, "") != 0){ sn = 1; } if(sim_name(names, name) == 0){ sn += 2; }
            curs_set(FALSE);  

        }

        else if(sn == 2){
            sn = 0;
            clear();
            print_margin();
            attron(COLOR_PAIR(4));
            mvprintw(15, 60, "Enter your name :");
            mvprintw(19, 60, "Enter your password :");
            mvprintw(23, 60, "Enter your email :");
            attroff(COLOR_PAIR(4));
            attron(COLOR_PAIR(3));
            mvprintw(17, 60, "(The name should not contain spaces or enter characters !)");
            mvprintw(21, 60, "(The password must be at least 7 characters long and include uppercase and lowercase English letters and numbers !)");
            mvprintw(25, 60, "(The email must be in the format ""xxx@y.zzz"" !)");
            attroff(COLOR_PAIR(3));
            refresh();    

            curs_set(TRUE); echo();
            strcpy(name, ""); mvscanw(15, 90, "%s", name);
            if(strcmp(name, "") != 0){ sn = 1; } if(sim_name(names, name) == 0){ sn += 2; }
            curs_set(FALSE);   
        }

        else if(sn == 3){
            strcpy(hero->name, name);
            names = fopen("names.txt", "a+");
            fprintf(names, "\n%s", name);
            fclose(names);
            break;
        }

    }

    
    clear();
    print_margin();
    attron(COLOR_PAIR(4));
    mvprintw(15, 60, "Enter your name :"); mvprintw(15, 90, "%s", hero->name);
    mvprintw(19, 60, "Enter your password :");
    mvprintw(23, 60, "Enter your email :");
    mvprintw(17, 60, "(Correct name)");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(3));
    mvprintw(21, 60, "(The password must be at least 7 characters long and include uppercase and lowercase English letters and numbers !)");
    mvprintw(25, 60, "(The email must be in the format ""xxx@y.zzz"" !)");
    attroff(COLOR_PAIR(3));
    refresh();

    curs_set(TRUE); echo();
    mvscanw(19, 90, "%s", password);
    if((is_valid_password(password) == 1) && (strlen(password ) >= 7)){ sp = 1; }
    curs_set(FALSE); 
    
    while(1){

        if(sp == 0){

            clear();
            print_margin();
            attron(COLOR_PAIR(4));
            mvprintw(15, 60, "Enter your name :"); mvprintw(15, 90, "%s", hero->name);
            mvprintw(19, 60, "Enter your password :");
            mvprintw(23, 60, "Enter your email :");
            mvprintw(17, 60, "(Correct name)");
            attroff(COLOR_PAIR(4));
            attron(COLOR_PAIR(3));
            mvprintw(21, 60, "(The password is invalid !)");
            mvprintw(25, 60, "(The email must be in the format ""xxx@y.zzz"" !)");
            attroff(COLOR_PAIR(3));
            refresh();

            curs_set(TRUE); echo();
            strcpy(password, ""); mvscanw(19, 90, "%s", password);
            if((is_valid_password(password) == 1) && (strlen(password ) >= 7)){ sp = 1; }
            curs_set(FALSE); 
        }

        else if(sp == 1){
            strcpy(hero->password, password);
            passwords = fopen("passwords.txt", "a+");
            fprintf(passwords, "\n%s", password);
            break;
        }

    }

    clear();
    print_margin();
    attron(COLOR_PAIR(4));
    mvprintw(15, 60, "Enter your name :"); mvprintw(15, 90, "%s", hero->name);
    mvprintw(19, 60, "Enter your password :"); mvprintw(19, 90, "%s", hero->password);
    mvprintw(23, 60, "Enter your email :");
    mvprintw(17, 60, "(Correct name)");
    mvprintw(21, 60, "(Correct password)");
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(3));
    mvprintw(25, 60, "(The email must be in the format ""xxx@y.zzz"" !)");
    attroff(COLOR_PAIR(3));
    refresh();

    curs_set(TRUE); echo();
    mvscanw(23, 90, "%s", email);
    if(is_valid_email(email) == 1){ se = 1; }
    curs_set(FALSE); 

    while(1){
        if(se == 0){
        clear();
            print_margin();
            attron(COLOR_PAIR(4));
            mvprintw(15, 60, "Enter your name :"); mvprintw(15, 90, "%s", hero->name);
            mvprintw(19, 60, "Enter your password :"); mvprintw(19, 90, "%s", hero->password);
            mvprintw(23, 60, "Enter your email :");
            mvprintw(17, 60, "(Correct name)");
            mvprintw(21, 60, "(Correct password)");
            attroff(COLOR_PAIR(4));
            attron(COLOR_PAIR(3));
            mvprintw(25, 60, "(The email is not formatted correctly !)");
            attroff(COLOR_PAIR(3));
            refresh();

            curs_set(TRUE); echo();
            mvscanw(23, 90, "%s", email);
            if(is_valid_email(email) == 1){ se = 1; }
            curs_set(FALSE); 
        }
        else if(se == 1){
            strcpy(hero->email, email);
            emails = fopen("emails.txt", "a+");
            fprintf(emails, "\n%s", email);

            clear();
            print_margin();
            attron(COLOR_PAIR(4));
            mvprintw(15, 60, "Enter your name :"); mvprintw(15, 90, "%s", hero->name);
            mvprintw(19, 60, "Enter your password :"); mvprintw(19, 90, "%s", hero->password);
            mvprintw(23, 60, "Enter your email :"); mvprintw(23, 90, "%s", hero->email);
            mvprintw(17, 60, "(Correct name)");
            mvprintw(21, 60, "(Correct password)");
            mvprintw(25, 60, "(Correct email)");
            getch();
            attroff(COLOR_PAIR(4));
            refresh();

            break;
        }

    }
}
int find_name_in_file(FILE * file, char name[]) {
    file = fopen("names.txt", "r");

    char line[256]; 
    int line_number = 0; 

    while (fgets(line, sizeof(line), file)) {
        line_number++; 

        line[strcspn(line, "\n")] = '\0';
        
        if (strcmp(line, name) == 0) {
            fclose(file); 
            return line_number; 
        }
    }

    fclose(file); 
    return -1; 
}
int check_name_in_line(FILE * file, int n, char password[]) {
    file = fopen("passwords.txt", "r");

    char line[256]; 
    int current_line = 1; 

    while (fgets(line, sizeof(line), file)) {
        
        if (current_line == n) {
            line[strcspn(line, "\n")] = '\0'; 
            if (strcmp(line, password) == 0) {
                fclose(file);
                return 1; 
            } else {
                fclose(file);
                return 0; 
            }
        }
        current_line++; 
    }

    fclose(file); 
    return 0; 
}
void log_in(hinfo * hero, FILE * names, FILE * passwords){

    char name[50]; char password[50];
    int sn = 0; int sp = 0;

    clear();
    print_margin();
    attron(COLOR_PAIR(2));
    mvprintw(20, 70, "Enter your name : ");
    mvprintw(24, 70, "Enter your password :");
    attroff(COLOR_PAIR(2));
    refresh();
    
    
    curs_set(TRUE); echo();
    mvscanw(20, 100, "%s", name); int line = find_name_in_file(names, name);
    if(line != -1){ sn = 1; }
    curs_set(FALSE); 

    while(1){
        if(sn == 0){

            clear();
            print_margin();
            attron(COLOR_PAIR(2));
            mvprintw(20, 70, "Enter your name : ");
            mvprintw(24, 70, "Enter your password :");
            attroff(COLOR_PAIR(2));
            attron(COLOR_PAIR(3));
            mvprintw(22, 70, "(The name entered does not exist !)");
            attroff(COLOR_PAIR(3));
            refresh();
            
            
            curs_set(TRUE); echo();
            mvscanw(20, 100, "%s", name); line = find_name_in_file(names, name);
            if(line != -1){ sn = 1; }
            curs_set(FALSE);  
        }

        else if(sn == 1){
            break;

        }
    }

    clear();
    print_margin();
    attron(COLOR_PAIR(2));
    mvprintw(20, 70, "Enter your name : "); mvprintw(20, 90, "%s", name);
    mvprintw(24, 70, "Enter your password :");
    attroff(COLOR_PAIR(2));
    refresh();
    
    curs_set(TRUE); echo();
    mvscanw(24, 100, "%s", password); sp = check_name_in_line(passwords, line, password);
    curs_set(FALSE); 

    while(1){
        if(sp == 0){
            
            clear();
            print_margin();
            attron(COLOR_PAIR(2));
            mvprintw(20, 70, "Enter your name : "); mvprintw(20, 90, "%s", name);
            mvprintw(24, 70, "Enter your password :");
            attroff(COLOR_PAIR(2));
            attron(COLOR_PAIR(3));
            mvprintw(26, 70, "The password entered is incorrect !");
            attroff(COLOR_PAIR(3));
            refresh();
            
            curs_set(TRUE); echo();
            mvscanw(24, 100, "%s", password); sp = check_name_in_line(passwords, line, password);
            curs_set(FALSE); 
        }

        else if(sp == 1){
            clear();
            print_margin();
            attron(COLOR_PAIR(2));
            strcpy(hero->name, name);
            mvprintw(20, 70, "Enter your name : "); mvprintw(20, 90, "%s", name);
            mvprintw(24, 70, "Enter your password :"); mvprintw(24, 90, "%s", password);
            attroff(COLOR_PAIR(2));
            attron(COLOR_PAIR(4));
            mvprintw(26, 70, "You have successfully logged in !");
            attroff(COLOR_PAIR(4));
            refresh();
        
            break;
        }
    }
    
}
void print_margin_score(){

    attron(COLOR_PAIR(6));

    for (int i = 20; i < 180; i++) {
        mvprintw(5, i, "-");           
        mvprintw(45 - 1, i, "-");   
    }
    for (int i = 5; i < 45; i++) {
        mvprintw(i, 20, "|");            
        mvprintw(i, 180 - 1, "|");    
    }
    refresh();
    attroff(COLOR_PAIR(6));
}
void print_option_menu(int num_op, char * choices[]){

    if(num_op%4 == 0){
        attron(A_REVERSE);
        mvprintw(15, 94, "%s", choices[0]);
        attroff(A_REVERSE);
        mvprintw(17, 94, "%s", choices[1]);
        mvprintw(19, 94, "%s", choices[2]);
        mvprintw(21, 94, "%s", choices[3]);
        attron(COLOR_PAIR(3)); attroff(COLOR_PAIR(3)); refresh();
    }
    else if(num_op%4 == 1){
        mvprintw(15, 94, "%s", choices[0]);
        attron(A_REVERSE);
        mvprintw(17, 94, "%s", choices[1]);
        attroff(A_REVERSE);
        mvprintw(19, 94, "%s", choices[2]);
        mvprintw(21, 94, "%s", choices[3]);
        attron(COLOR_PAIR(3)); attroff(COLOR_PAIR(3)); refresh();
    }
    else if(num_op%4 == 2){
        mvprintw(15, 94, "%s", choices[0]);
        mvprintw(17, 94, "%s", choices[1]);
        attron(A_REVERSE);
        mvprintw(19, 94, "%s", choices[2]);
        attroff(A_REVERSE);
        mvprintw(21, 94, "%s", choices[3]);
        attron(COLOR_PAIR(3)); attroff(COLOR_PAIR(3)); refresh();

    }
    else if(num_op%4 == 3){
        mvprintw(15, 94, "%s", choices[0]);
        mvprintw(17, 94, "%s", choices[1]);
        mvprintw(19, 94, "%s", choices[2]);
        attron(A_REVERSE);
        mvprintw(21, 94, "%s", choices[3]);
        attroff(A_REVERSE);
        attron(COLOR_PAIR(3)); attroff(COLOR_PAIR(3)); refresh();
    }
}
char* get_nth_line(char * file_name, int n) {
    FILE * file  = fopen(file_name, "r");

    char buffer[1024];  
    int current_line = 0;
    char *result = NULL;

    while (fgets(buffer, sizeof(buffer), file)) {
        current_line++;
        if (current_line == n) {
            result = malloc(strlen(buffer) + 1); 
            if (result) {
                strcpy(result, buffer);  
            }
            break;
        }
    }

    fclose(file);
    return result;  
}
int compare(const void *a, const void *b) {
    int idx1 = *(int*)a;
    int idx2 = *(int*)b;
    return values_ptr[idx2] - values_ptr[idx1];  
}
void find_top_10_lines(char filename[], int topLines[200]) {
    int values[200];
    int lineNumbers[200];  
    int index[200];  
    int count = 0;

    FILE *file = fopen(filename, "r");
    if (!file) {
        return;
    }

    while (count < 200 && fscanf(file, "%d", &values[count]) == 1) {
        lineNumbers[count] = count + 1;  
        index[count] = count;  
        count++;
    }

    fclose(file);
    values_ptr = values;
    qsort(index, count, sizeof(int), compare);

    for (int i = 0; i < 200 && i < count; i++) {
        topLines[i] = lineNumbers[index[i]];
    }

    values_ptr = NULL;
}
void score_menu(hinfo * hero,FILE * names, FILE * scores, FILE * golds, FILE * count_games,FILE * time_games){

    clear(); curs_set(FALSE);
    print_margin_score();
    attron(COLOR_PAIR(2)); mvprintw(8, 94, "<< Scoreboard >>"); attroff(COLOR_PAIR(2));
    char file_score[] = "scores.txt" ;int index[200]; find_top_10_lines(file_score, index);

    for(int i = 0; i < 10; i++){
        if(i == 0){
            attron(COLOR_PAIR(10)); attron(A_BOLD);
            mvprintw(12, 25, "%d)", i+1);
            char * fnames = "names.txt"; char * name = get_nth_line(fnames, index[i]); name[strlen(name)-1] = '\0'; mvprintw(12, 30, "&&& Legend &&&     %s   🥇", name);
            char * fscores = "scores.txt"; char * score = get_nth_line(fscores, index[i]); mvprintw(12, 80, "%s", score);
            char * fgolds = "golds.txt"; char * gold = get_nth_line(fgolds, index[i]); mvprintw(12, 100, "%s",gold);attroff(COLOR_PAIR(10));
            attron(COLOR_PAIR(3));
            char * fcount_games = "count_games.txt"; char * count_game = get_nth_line(fcount_games, index[i]); mvprintw(12, 120, "%s", count_game); attroff(COLOR_PAIR(3));
            attron(COLOR_PAIR(4));
            char * ftime_games = "time_games.txt"; char * time_game = get_nth_line(ftime_games , index[i]); mvprintw(12, 140, "%s", time_game); attroff(COLOR_PAIR(4));attroff(A_BOLD);
            if(strcmp(name, hero->name) == 0){
                attron(COLOR_PAIR(7));
                mvprintw(12, 160, "%s", "You");
                attroff(COLOR_PAIR(7));
            }
        }
        else if(i == 1){
            attron(COLOR_PAIR(8)); attron(A_BOLD);
            mvprintw(15, 25, "%d)", i+1);
            char * fnames = "names.txt"; char * name = get_nth_line(fnames, index[i]); name[strlen(name)-1] = '\0'; mvprintw(15, 30, "&& Legend &&     %s   🥈", name);
            char * fscores = "scores.txt"; char * score = get_nth_line(fscores, index[i]); mvprintw(15, 80, "%s", score);
            char * fgolds = "golds.txt"; char * gold = get_nth_line(fgolds, index[i]); mvprintw(15, 100, "%s",gold);attroff(COLOR_PAIR(8));
            attron(COLOR_PAIR(3));
            char * fcount_games = "count_games.txt"; char * count_game = get_nth_line(fcount_games, index[i]); mvprintw(15, 120, "%s", count_game); attroff(COLOR_PAIR(3));
            attron(COLOR_PAIR(4));
            char * ftime_games = "time_games.txt"; char * time_game = get_nth_line(ftime_games , index[i]); mvprintw(15, 140, "%s", time_game); attroff(COLOR_PAIR(4));attroff(A_BOLD);
            if(strcmp(name, hero->name) == 0){
                attron(COLOR_PAIR(7));
                mvprintw(15, 160, "%s", "You");
                attroff(COLOR_PAIR(7));
            }
        }
        else if(i == 2){
            attron(COLOR_PAIR(9)); attron(A_BOLD);
            mvprintw(18, 25, "%d)", i+1);
            char * fnames = "names.txt"; char * name = get_nth_line(fnames, index[i]); name[strlen(name)-1] = '\0'; mvprintw(18, 30, "& legend &     %s   🥉", name);
            char * fscores = "scores.txt"; char * score = get_nth_line(fscores, index[i]); mvprintw(18, 80, "%s", score);
            char * fgolds = "golds.txt"; char * gold = get_nth_line(fgolds, index[i]); mvprintw(18, 100, "%s",gold);attroff(COLOR_PAIR(9));
            attron(COLOR_PAIR(3));
            char * fcount_games = "count_games.txt"; char * count_game = get_nth_line(fcount_games, index[i]); mvprintw(18, 120, "%s", count_game); attroff(COLOR_PAIR(3));
            attron(COLOR_PAIR(4));
            char * ftime_games = "time_games.txt"; char * time_game = get_nth_line(ftime_games , index[i]); mvprintw(18, 140, "%s", time_game); attroff(COLOR_PAIR(4));attroff(A_BOLD);
            if(strcmp(name, hero->name) == 0){
                attron(COLOR_PAIR(7));
                mvprintw(18, 160, "%s", "You");
                attroff(COLOR_PAIR(7));
            }
        }
        else{
            mvprintw((i+4)*3, 25, "%d)", i+1);
            char * fnames = "names.txt"; char * name = get_nth_line(fnames, index[i]); name[strlen(name)-1] = '\0'; mvprintw((i+4)*3, 30, "%s", name);
            char * fscores = "scores.txt"; char * score = get_nth_line(fscores, index[i]); mvprintw((i+4)*3, 80, "%s", score);
            char * fgolds = "golds.txt"; char * gold = get_nth_line(fgolds, index[i]); mvprintw((i+4)*3, 100, "%s",gold);attroff(COLOR_PAIR(8));
            attron(COLOR_PAIR(3));
            char * fcount_games = "count_games.txt"; char * count_game = get_nth_line(fcount_games, index[i]); mvprintw((i+4)*3, 120, "%s", count_game); attroff(COLOR_PAIR(3));
            attron(COLOR_PAIR(4));
            char * ftime_games = "time_games.txt"; char * time_game = get_nth_line(ftime_games , index[i]); mvprintw((i+4)*3, 140, "%s", time_game); attroff(COLOR_PAIR(4));attroff(A_BOLD);
            if(strcmp(name, hero->name) == 0){
                attron(COLOR_PAIR(7));
                mvprintw((i+4)*3, 160, "You");
                attroff(COLOR_PAIR(7));
            }
        }
    }
    print_margin(); print_margin_score();
    refresh();
}
void print_option_setting2(int num_op2, char * choices2[]){

    if(num_op2%3 == 0){
        attron(COLOR_PAIR(2));attron(A_REVERSE);
        mvprintw(23, 88, "%s", choices2[0]);
        attroff(A_REVERSE);
        mvprintw(23, 99, "%s", choices2[1]);
        mvprintw(23, 112, "%s", choices2[2]);
        attroff(COLOR_PAIR(2));
        attron(COLOR_PAIR(3)); attroff(COLOR_PAIR(3)); refresh();
    }
    else if(num_op2%3 == 1){
        attron(COLOR_PAIR(2));
        mvprintw(23, 88, "%s", choices2[0]);
        attron(A_REVERSE);
        mvprintw(23, 99, "%s", choices2[1]);
        attroff(A_REVERSE);
        mvprintw(23, 112, "%s", choices2[2]);attroff(COLOR_PAIR(2));
        attron(COLOR_PAIR(3)); attroff(COLOR_PAIR(3)); refresh();
    }
    else if(num_op2%3 == 2){
        attron(COLOR_PAIR(2));
        mvprintw(23, 88, "%s", choices2[0]);
        mvprintw(23, 99, "%s", choices2[1]);
        attron(A_REVERSE);
        mvprintw(23, 112, "%s", choices2[2]);
        attroff(COLOR_PAIR(2));attroff(A_REVERSE);
        attron(COLOR_PAIR(3)); attroff(COLOR_PAIR(3)); refresh();

    }
}
void print_option_setting1(int num_op1, char * choices[]){

    if(num_op1%4 == 0){
        attron(COLOR_PAIR(3));attron(A_REVERSE);
        mvprintw(17, 85, "%s", choices[0]); attroff(COLOR_PAIR(3));attroff(A_REVERSE);
        attron(COLOR_PAIR(4));
        mvprintw(17, 93, "%s", choices[1]); attroff(COLOR_PAIR(4));attron(COLOR_PAIR(1)); 
        mvprintw(17, 103, "%s", choices[2]); attroff(COLOR_PAIR(1));
        mvprintw(17, 112, "%s", choices[3]); 
        attron(COLOR_PAIR(3)); attroff(COLOR_PAIR(3)); refresh();
    }
    else if(num_op1%4 == 1){
        attron(COLOR_PAIR(3));
        mvprintw(17, 85, "%s", choices[0]);attroff(COLOR_PAIR(3));attron(COLOR_PAIR(4));
        attron(A_REVERSE);
        mvprintw(17, 93, "%s", choices[1]);attroff(COLOR_PAIR(4));
        attroff(A_REVERSE);
        attron(COLOR_PAIR(1)); 
        mvprintw(17, 103, "%s", choices[2]);attroff(COLOR_PAIR(1));
        mvprintw(17, 112, "%s", choices[3]);
        attron(COLOR_PAIR(3)); attroff(COLOR_PAIR(3)); refresh();
    }
    else if(num_op1%4 == 2){
        attron(COLOR_PAIR(3));
        mvprintw(17, 85, "%s", choices[0]);attroff(COLOR_PAIR(3));attron(COLOR_PAIR(4)); 
        mvprintw(17, 93, "%s", choices[1]);attroff(COLOR_PAIR(4));attron(COLOR_PAIR(1)); 
        attron(A_REVERSE);
        mvprintw(17, 103, "%s", choices[2]);attroff(COLOR_PAIR(1));
        attroff(A_REVERSE);
        mvprintw(17, 112, "%s", choices[3]);
        attron(COLOR_PAIR(3)); attroff(COLOR_PAIR(3)); refresh();

    }
    else if(num_op1%4 == 3){
        attron(COLOR_PAIR(3));
        mvprintw(17, 85, "%s", choices[0]);attroff(COLOR_PAIR(3));attron(COLOR_PAIR(4)); 
        mvprintw(17, 93, "%s", choices[1]);attroff(COLOR_PAIR(4));attron(COLOR_PAIR(1));
        mvprintw(17, 103, "%s", choices[2]);attroff(COLOR_PAIR(1));
        attron(A_REVERSE);
        mvprintw(17, 112, "%s", choices[3]);
        attroff(A_REVERSE);
        attron(COLOR_PAIR(3)); attroff(COLOR_PAIR(3)); refresh();
    }
}
void setting_menu(hinfo * hero){


    char *choices1[] = {"Red", "Green", "Blue", "White"}; int num_op1 = 0; int key1;
    char *choices2[] = {"Easy",  "Medium", "Hard"}; int num_op2 = 0; int key2;

    while(1){

        
        clear();
        attron(A_BOLD); curs_set(false);
        print_margin();
        attron(COLOR_PAIR(2));
        mvprintw(3, 95 , "<< setting >>"); mvprintw(15, 87, "Choose your character color :");
        mvprintw(21, 90, "Game difficulty level :"); mvprintw(23, 88, "%s", choices2[0]); mvprintw(23, 99, "%s", choices2[1]); mvprintw(23, 112, "%s", choices2[2]);
        attroff(COLOR_PAIR(2));
        print_option_setting1(num_op1, choices1);
        print_margin();
        refresh();

        key1 = getch();
        
        if(key1 == KEY_LEFT){
            num_op1 -= 1;
            if(num_op1 < 0){
                num_op1 = 3;
            }
        }
        else if(key1 == KEY_RIGHT){
            num_op1 += 1;
            if(num_op1 > 3){
                num_op1 = 0;
            }
        }
        else if(key1 == 10){
            hero->color = num_op1;
            break;
        }
    }

    while(1){

        
        clear();
        attron(A_BOLD); curs_set(false);
        print_margin();

        attron(COLOR_PAIR(2));
        mvprintw(3, 95 , "<< setting >>"); mvprintw(15, 87, "Choose your character color :");
        mvprintw(17, 97, "# %s #", choices1[num_op1]); mvprintw(21, 90, "Game difficulty level :");
        attroff(COLOR_PAIR(2));
        print_option_setting2(num_op2, choices2);
        refresh();

        key2 = getch();
        
        if(key2 == KEY_LEFT){
            num_op2 -= 1;
            if(num_op2 < 0){
                num_op2 = 2;
            }
        }
        else if(key2 == KEY_RIGHT){
            num_op2 += 1;
            if(num_op2 > 2){
                num_op2 = 0;
            }
        }
        else if(key2 == 10){
            hero->amount_health = (num_op2+1) *10;
            hero->amount_health = hero->amount_health;
            break;
        }
    }

    clear();
    print_margin();
    attron(COLOR_PAIR(2));
    mvprintw(3, 95 , "<< setting >>"); mvprintw(15, 87, "Choose your character color :");
    mvprintw(17, 97, "# %s #", choices1[num_op1]); mvprintw(21, 90, "Game difficulty level :"); mvprintw(23, 97, "# %s #", choices2[num_op2]);
    refresh();
    attroff(COLOR_PAIR(2));
    attroff(A_BOLD);
}
void menu(int * s_m, int * s_p_g, hinfo * hero, FILE * names, FILE * emails, FILE * scores, FILE * golds, FILE * count_games,FILE * time_games){

    curs_set(FALSE);
    noecho();
    int num_op = 0;
    int key;
    char * choices[] = {"<< New game >>", "<< Load game >>", "<< High Scores >>", "<< Settings >>"};

    while(1){

        clear();
        print_margin();
        attron(COLOR_PAIR(2)); attron(A_BOLD);
        mvprintw(3, 98 , "ROGUE");
        print_option_menu(num_op, choices);
        attroff(A_BOLD);
        refresh();

        key = getch();
        
        if(key == KEY_UP){
            num_op -= 1;
            if(num_op < 0){
                num_op = 3;
            }
        }
        else if(key == KEY_DOWN){
            num_op += 1;
            if(num_op > 3){
                num_op = 0;
            }
        }
        else if(key == 10){
            break;
        }
    }
    attroff(COLOR_PAIR(2));

    if(num_op == 0){
        *s_m = 0; *s_p_g = 1;
    }
    else if(num_op == 1){
        if(strcmp(hero->name, "guest") == 0){

            clear();
            print_margin();attron(A_BOLD);
            attron(COLOR_PAIR(3)); mvprintw(18, 70, "You are logged in as a guest and cannot continue your previous game"); attroff(COLOR_PAIR(3));
            attroff(A_BOLD);getch(); menu(s_m, s_p_g, hero, names, emails, scores, golds, count_games, time_games);
        }
        else{
            *s_m = 0; *s_p_g = 2; 
        }
    }
    else if(num_op == 2){
            score_menu(hero, names, scores, golds, count_games, time_games);
            key = getch();
            while(key != 10){
                key = getch();
            }
            menu(s_m, s_p_g, hero, names, emails, scores, golds, count_games, time_games);
    }
    else if(num_op == 3){
            setting_menu(hero);
            key = getch();
            while(key != 10){
                key = getch();
            }
            menu(s_m, s_p_g, hero, names, emails, scores, golds, count_games, time_games);        
    }

}
void rand_num(int min_x, int max_x, int min_y, int max_y, int *x, int *y) {
    *x = (rand() % (max_x - min_x + 1)) + min_x; 
    *y = (rand() % (max_y - min_y + 1)) + min_y;
}
void rand_int(int min, int max, int *x){
    *x = (rand() % (max - min + 1)) + min;
}
void margin_map_8(char map[10][20], int pos_door) {
    for (int i = 0; i < 20; i++) {
        map[0][i] = '-';
        map[9][i] = '-';
    }
    for (int i = 1; i < 9; i++) {
        map[i][0] = '|';
        map[i][19] = '|'; 
    }
    if(pos_door == 1){
        int x; rand_int(3,16, &x);
        map[9][x] = '+';
        int y;rand_int(2, 8, &y); map[y][0] = '<';
        
    }
    else if(pos_door == 2){
        int y; rand_int(2,7, &y);
        map[y][19] = '+';
        int x; rand_int(3,16, &x);
        map[0][x] = '+';
    }
    else if(pos_door == 3){
        int y; rand_int(2,7, &y);
        map[y][0] = '+';
        int x; rand_int(3,16, &x);
        map[0][x] = '+';
    }
    else if(pos_door == 4){
        int y; rand_int(2,7, &y);
        map[y][19] = '+';
        int x; rand_int(3,16, &x);
        map[9][x] = '+';
    }
    else if(pos_door == 5){
        int y; rand_int(2,7, &y);
        map[y][0] = '+';
        int x; rand_int(3,16, &x);
        map[9][x] = '+';
    }
    else if(pos_door == 6){
        int x; rand_int(3,16, &x);
        map[0][x] = '+';
        int y;rand_int(1, 8, &y); map[y][19] = '>';
    }
}
void first_amount_8(char map[10][20]) {
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 19; j++) {
            map[i][j] = '.'; 
        }
    }
}
void margin_map_7(char map[10][20], int pos_door) {
    for (int i = 0; i < 19; i++) {
        map[0][i] = '-';
        map[8][i] = '-';
    }
    for (int i = 1; i < 8; i++) {
        map[i][0] = '|';
        map[i][18] = '|'; 
    }
    if(pos_door == 1){
        int x; rand_int(3,15, &x);
        map[8][x] = '+';
        int y;rand_int(1, 7, &y); map[y][0] = '<';
    }
    else if(pos_door == 2){
        int y; rand_int(2,6, &y);
        map[y][18] = '+';
        int x; rand_int(3,15, &x);
        map[0][x] = '+';
    }
    else if(pos_door == 3){
        int y; rand_int(2,6, &y);
        map[y][0] = '+';
        int x; rand_int(3,15, &x);
        map[0][x] = '+';
    }
    else if(pos_door == 4){
        int y; rand_int(2,6, &y);
        map[y][18] = '+';
        int x; rand_int(3,15, &x);
        map[8][x] = '+';
    }
    else if(pos_door == 5){
        int y; rand_int(2,6, &y);
        map[y][0] = '+';
        int x; rand_int(3,15, &x);
        map[8][x] = '+';
    }
    else if(pos_door == 6){
        int x; rand_int(3,15, &x);
        map[0][x] = '+';
        int y;rand_int(1, 7, &y); map[y][18] = '>';
    }
}
void first_amount_7(char map[10][20]) {
    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < 18; j++) {
            map[i][j] = '.'; 
        }
    }
}
void margin_map_6(char map[10][20], int pos_door) {
    for (int i = 0; i < 18; i++) {
        map[0][i] = '-';
        map[7][i] = '-';
    }
    for (int i = 1; i < 7; i++) {
        map[i][0] = '|';
        map[i][17] = '|'; 
    }
    if(pos_door == 1){
        int x; rand_int(3,14, &x);
        map[7][x] = '+';
        int y;rand_int(2, 6, &y); map[y][0] = '<';
    }
    else if(pos_door == 2){
        int y; rand_int(2,5, &y);
        map[y][17] = '+';
        int x; rand_int(3,14, &x);
        map[0][x] = '+';
    }
    else if(pos_door == 3){
        int y; rand_int(2,5, &y);
        map[y][0] = '+';
        int x; rand_int(3,14, &x);
        map[0][x] = '+';
    }
    else if(pos_door == 4){
        int y; rand_int(2,5, &y);
        map[y][17] = '+';
        int x; rand_int(3,14, &x);
        map[7][x] = '+';
    }
    else if(pos_door == 5){
        int y; rand_int(2,5, &y);
        map[y][0] = '+';
        int x; rand_int(3,14, &x);
        map[7][x] = '+';
    }
    else if(pos_door == 6){
        int x; rand_int(3,14, &x);
        map[0][x] = '+';
        int y;rand_int(1, 6, &y); map[y][17] = '>';
    }
}
void first_amount_6(char map[10][20]) {
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 17; j++) {
            map[i][j] = '.'; 
        }
    }
}
void draw_map_6_1(char map[10][20]){

    int c_p = 0; int c_S = 0; int c_t = 0; int c_A = 0; int c_a = 0; int c_o = 0; int c_D = 0; int c_F = 0;
    int x; int y;
    while(c_p != 3){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'p';
            c_p += 1;
        }
    }
    while(c_S != 1){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'S';
            c_S += 1;
        }
    }
    while(c_t != 2){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 't';
            c_t += 1;
        }
    }
    while(c_a != 2){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'a';
            c_a += 1;
        }
    }
    while(c_A != 1){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'A';
            c_A += 1;
        }
    }
    while(c_o != 3){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.' && map[x][y-1] != '+' && map[x][y+1] != '+' && map[x-1][y] != '+' && map[x+1][y] != '+' && map[x][y-1] != '<' && map[x][y-1] != '>'  ){
            map[x][y] = 'o';
            c_o += 1;
        }
    }
    while(c_D != 2){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'D';
            c_D += 1;
        }
    }
    while(c_F != 2){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'F';
            c_F += 1;
        }
    }
} 
void draw_map_6_2(char map[10][20]){

    int c_p = 0; int c_S = 0; int c_t = 0; int c_A = 0; int c_a = 0; int c_o = 0; int c_D = 0; int c_F = 0;
    int x; int y;
    while(c_p != 4){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'p';
            c_p += 1;
        }
    }
    while(c_S != 2){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'S';
            c_S += 1;
        }
    }
    while(c_t != 2){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 't';
            c_t += 1;
        }
    }
    while(c_a != 3){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'a';
            c_a += 1;
        }
    }
    while(c_A != 1){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'A';
            c_A += 1;
        }
    }
    while(c_o != 3){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.' && map[x][y-1] != '+' && map[x][y+1] != '+' && map[x-1][y] != '+' && map[x+1][y] != '+' && map[x][y-1] != '<' && map[x][y-1] != '>'  ){
            map[x][y] = 'o';
            c_o += 1;
        }
    }
    while(c_D != 3){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'D';
            c_D += 1;
        }
    }
    while(c_F != 1){
        rand_num(1, 6, 1, 16, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'F';
            c_F += 1;
        }
    }
}
void draw_map_7_1(char map[10][20]){

    int c_p = 0; int c_S = 0; int c_t = 0; int c_A = 0; int c_a = 0; int c_o = 0; int c_D = 0; int c_F = 0; int c_m = 0; int c_P = 0;
    int x; int y;
    while(c_P != 1){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'P';
            c_P += 1;
        }    
    }
    while(c_p != 4){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'p';
            c_p += 1;
        }
    }
    while(c_S != 3){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'S';
            c_S += 1;
        }
    }
    while(c_t != 3){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 't';
            c_t += 1;
        }
    }
    while(c_a != 3){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'a';
            c_a += 1;
        }
    }
    while(c_A != 2){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'A';
            c_A += 1;
        }
    }
    while(c_o != 4){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.' && map[x][y-1] != '+' && map[x][y+1] != '+' && map[x-1][y] != '+' && map[x+1][y] != '+' && map[x][y-1] != '<' && map[x][y-1] != '>'  ){
            map[x][y] = 'o';
            c_o += 1;
        }
    }
    while(c_D != 4){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'D';
            c_D += 1;
        }
    }
    while(c_F != 2){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'F';
            c_F += 1;
        }
    }
    while(c_m != 1){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'm';
            c_m += 1;
        }
    }
} 
void draw_map_7_2(char map[10][20]){

    int c_p = 0; int c_S = 0; int c_t = 0; int c_A = 0; int c_a = 0; int c_o = 0; int c_D = 0; int c_F = 0; int c_m = 0; int c_P = 0;
    int x; int y;
    while(c_P != 2){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'P';
            c_P += 1;
        }    
    }
    while(c_p != 4){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'p';
            c_p += 1;
        }
    }
    while(c_S != 3){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'S';
            c_S += 1;
        }
    }
    while(c_t != 3){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 't';
            c_t += 1;
        }
    }
    while(c_a != 3){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'a';
            c_a += 1;
        }
    }
    while(c_A != 3){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'A';
            c_A += 1;
        }
    }
    while(c_o != 3){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.' && map[x][y-1] != '+' && map[x][y+1] != '+' && map[x-1][y] != '+' && map[x+1][y] != '+' && map[x][y-1] != '<' && map[x][y-1] != '>'  ){
            map[x][y] = 'o';
            c_o += 1;
        }
    }
    while(c_D != 3){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'D';
            c_D += 1;
        }
    }
    while(c_F != 2){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'F';
            c_F += 1;
        }
    }
    while(c_m != 1){
        rand_num(1, 7, 1, 17, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'm';
            c_m += 1;
        }
    }
}
void draw_map_8_1(char map[10][20]){

    int c_p = 0; int c_S = 0; int c_t = 0; int c_A = 0; int c_a = 0; int c_o = 0; int c_D = 0; int c_F = 0; int c_m = 0; int c_P = 0;
    int x; int y;
    while(c_P != 1){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'P';
            c_P += 1;
        }    
    }
    while(c_p != 6){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'p';
            c_p += 1;
        }
    }
    while(c_S != 4){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'S';
            c_S += 1;
        }
    }
    while(c_t != 3){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 't';
            c_t += 1;
        }
    }
    while(c_a != 4){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'a';
            c_a += 1;
        }
    }
    while(c_A != 2){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'A';
            c_A += 1;
        }
    }
    while(c_o != 5){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.' && map[x][y-1] != '+' && map[x][y+1] != '+' && map[x-1][y] != '+' && map[x+1][y] != '+' && map[x][y-1] != '<' && map[x][y-1] != '>'  ){
            map[x][y] = 'o';
            c_o += 1;
        }
    }
    while(c_D != 5){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'D';
            c_D += 1;
        }
    }
    while(c_F != 3){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'F';
            c_F += 1;
        }
    }
    while(c_m != 1){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'm';
            c_m += 1;
        }
    }
}
void draw_map_8_2(char map[10][20]){

    int c_p = 0; int c_S = 0; int c_t = 0; int c_A = 0; int c_a = 0; int c_o = 0; int c_D = 0; int c_F = 0; int c_m = 0; int c_P = 0;
    int x; int y;
    while(c_P != 2){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'P';
            c_P += 1;
        }    
    }
    while(c_p != 6){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'p';
            c_p += 1;
        }
    }
    while(c_S != 4){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'S';
            c_S += 1;
        }
    }
    while(c_t != 2){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 't';
            c_t += 1;
        }
    }
    while(c_a != 3){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'a';
            c_a += 1;
        }
    }
    while(c_A != 3){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'A';
            c_A += 1;
        }
    }
    while(c_o != 4){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.' && map[x][y-1] != '+' && map[x][y+1] != '+' && map[x-1][y] != '+' && map[x+1][y] != '+' && map[x][y-1] != '<' && map[x][y-1] != '>'  ){
            map[x][y] = 'o';
            c_o += 1;
        }
    }
    while(c_D != 4){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'D';
            c_D += 1;
        }
    }
    while(c_F != 3){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'F';
            c_F += 1;
        }
    }
    while(c_m != 2){
        rand_num(1, 8, 1, 18, &x, &y);
        if(map[x][y] == '.' && map[x][y+1] == '.' && map[x][y-1] == '.'){
            map[x][y] = 'm';
            c_m += 1;
        }
    }
}
void print_map_room(char map[10][20],int x, int y){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){

            if(map[i][j] == '.'){
                attron(COLOR_PAIR(4));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(4));
            }
            else if(map[i][j] == '-'){
                attron(COLOR_PAIR(12));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(12));                
            }
            else if(map[i][j] == '|'){
                attron(COLOR_PAIR(12));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(12));                
            }
            else if(map[i][j] == '+'){
                attron(COLOR_PAIR(2));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(2));                
            }
            else if(map[i][j] == '-'){
                attron(COLOR_PAIR(12));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(12)); 
            }               
            else if(map[i][j] == '>'){
                attron(COLOR_PAIR(2));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(2));                
            }
            else if(map[i][j] == '<'){
                attron(COLOR_PAIR(2));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(2));                
            }
            else if(map[i][j] == 'o'){
                attron(COLOR_PAIR(8));
                mvprintw(x+i, y+j, "O");
                attroff(COLOR_PAIR(8));                
            }
            else if(map[i][j] == '^'){
                attron(COLOR_PAIR(2));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(2));                
            }
            else if(map[i][j] == 'D'){
                attron(COLOR_PAIR(13));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(2));                
            }
            else if(map[i][j] == 'F'){
                attron(COLOR_PAIR(13));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(2));                
            }
            else if(map[i][j] == 'g'){
                mvprintw(x+i, y+j, "💎");
            }
            else if(map[i][j] == 'P'){
                attron(COLOR_PAIR(14));
                mvprintw(x+i, y+j, "•");
                attroff(COLOR_PAIR(14));
            }
            else if(map[i][j] == 'p'){
                attron(A_BOLD) ;attron(COLOR_PAIR(10));
                mvprintw(x+i, y+j, "•");
                attroff(A_BOLD) ;attroff(COLOR_PAIR(10));
            }
            else if(map[i][j] == 'a'){
                attron(COLOR_PAIR(19));
                mvprintw(x+i, y+j, "∗");
                attroff(COLOR_PAIR(19));
            }
            else if(map[i][j] == 'A'){
                attron(A_BOLD); attron(COLOR_PAIR(15));
                mvprintw(x+i, y+j, "∗");
                attroff(A_BOLD); attroff(COLOR_PAIR(15));
            }
            else if(map[i][j] == 'm'){
                attron(COLOR_PAIR(17));
                mvprintw(x+i, y+j, "⚗");
                attroff(COLOR_PAIR(17));
            }
            else if(map[i][j] == 'S'){
                mvprintw(x+i, y+j, "🗡️");
            }
            else if(map[i][j] == 't'){
                attron(COLOR_PAIR(4));
                mvprintw(x+i, y+j, ".");
                attroff(COLOR_PAIR(4));
            }
            else if(map[i][j] == 'f'){
                attron(COLOR_PAIR(18));
                mvprintw(x+i, y+j, "F");
                attroff(COLOR_PAIR(18));
            }
        }
    }
}
void print_map_page(char map[40][150],int x, int y, int color){
    clear();
    print_margin();
    for(int i = 0; i < 40; i++){
        for(int j = 0; j < 150; j++){
            if(map[i][j] == '@'){
                if(color == 0){
                    attron(COLOR_PAIR(3));
                    mvprintw(x+i, y+j, "%c", map[i][j]);
                    attroff(COLOR_PAIR(3));
                }
                else if(color == 1){
                    attron(COLOR_PAIR(16));
                    mvprintw(x+i, y+j, "%c", map[i][j]);
                    attroff(COLOR_PAIR(16));
                }
                else if(color == 2){
                    attron(COLOR_PAIR(1));
                    mvprintw(x+i, y+j, "%c", map[i][j]);
                    attroff(COLOR_PAIR(1));
                }
                else if(color == 3){
                    attron(COLOR_PAIR(5));
                    mvprintw(x+i, y+j, "%c", map[i][j]);
                    attroff(COLOR_PAIR(5));
                }
            }
            if(map[i][j] == '.'){
                attron(COLOR_PAIR(4));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(4));
            }
            else if(map[i][j] == '-'){
                attron(COLOR_PAIR(12));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(12));                
            }
            else if(map[i][j] == '|'){
                attron(COLOR_PAIR(12));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(12));                
            }
            else if(map[i][j] == '+'){
                attron(COLOR_PAIR(2));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(2));                
            }
            else if(map[i][j] == '-'){
                attron(COLOR_PAIR(12));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(12)); 
            }               
            else if(map[i][j] == '>'){
                attron(COLOR_PAIR(2));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(2));                
            }
            else if(map[i][j] == '<'){
                attron(COLOR_PAIR(2));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(2));                
            }
            else if(map[i][j] == '#'){
                mvprintw(x+i, y+j, "%c", map[i][j]);               
            }
            else if(map[i][j] == 'o'){
                attron(COLOR_PAIR(8));
                mvprintw(x+i, y+j, "O");
                attroff(COLOR_PAIR(8));                
            }
            else if(map[i][j] == '^'){
                attron(COLOR_PAIR(2));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(2));                
            }
            else if(map[i][j] == 'D'){
                attron(COLOR_PAIR(13));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(2));                
            }
            else if(map[i][j] == 'F'){
                attron(COLOR_PAIR(13));
                mvprintw(x+i, y+j, "%c", map[i][j]);
                attroff(COLOR_PAIR(2));                
            }
            else if(map[i][j] == 'g'){
                mvprintw(x+i, y+j, "💎");
            }
            else if(map[i][j] == 'P'){
                attron(COLOR_PAIR(14));
                mvprintw(x+i, y+j, "•");
                attroff(COLOR_PAIR(14));
            }
            else if(map[i][j] == 'p'){
                attron(A_BOLD) ;attron(COLOR_PAIR(10));
                mvprintw(x+i, y+j, "•");
                attroff(A_BOLD) ;attroff(COLOR_PAIR(10));
            }
            else if(map[i][j] == 'a'){
                attron(COLOR_PAIR(19));
                mvprintw(x+i, y+j, "∗");
                attroff(COLOR_PAIR(19));
            }
            else if(map[i][j] == 'A'){
                attron(A_BOLD); attron(COLOR_PAIR(15));
                mvprintw(x+i, y+j, "∗");
                attroff(A_BOLD); attroff(COLOR_PAIR(15));
            }
            else if(map[i][j] == 'm'){
                attron(COLOR_PAIR(17));
                mvprintw(x+i, y+j, "⚗");
                attroff(COLOR_PAIR(17));
            }
            else if(map[i][j] == 'S'){
                mvprintw(x+i, y+j, "🗡️");
            }
            else if(map[i][j] == 't'){
                attron(COLOR_PAIR(4));
                mvprintw(x+i, y+j, ".");
                attroff(COLOR_PAIR(4));
            }
            else if(map[i][j] == 'f'){
                attron(COLOR_PAIR(18));
                mvprintw(x+i, y+j, "F");
                attroff(COLOR_PAIR(18));
            }
        }
    }
}
void shuffleArray(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
void first_amount0(char map[10][20]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            map[i][j] = 0;
        }
    }
}
void first_amount0c(char map[40][150]){
    for(int i = 0; i < 40; i++){
        for(int j = 0; j < 150; j++){
            map[i][j] = 0;
        }
    }
}
void first_amountr(int x, int y, char map[x][y]){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            map[i][j] = 0;
        }
    }

}
void put_map(char map_col[40][150], char map[10][20], int x, int y){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            if(map[i][j] != 0){
                map_col[x+i][y+j] = map[i][j];
            }
        }
    }
}
void put_rahro(char map_col[40][150], int tool, int arz, char ** rahro, int x, int y){
    for(int i = 0; i < tool; i++){
        for(int j = 0; j <arz; j++){
            if(rahro[i][j] != 0){
                map_col[x+i][y+j] = rahro[i][j];
            }
        }
    }
}
char **allocateGrid(int rows, int cols) {
    char **grid = malloc(rows * sizeof(char *));
    if (!grid) {
        perror("Allocation error");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc((cols + 1) * sizeof(char)); // +1 برای '\0'
        if (!grid[i]) {
            perror("Allocation error");
            exit(EXIT_FAILURE);
        }
    }
    return grid;
}
char **drawRandomPath(int x1, int y1, int x2, int y2, int *outRows, int *outCols) {
    int minX = (x1 < x2) ? x1 : x2;
    int maxX = (x1 > x2) ? x1 : x2;
    int minY = (y1 < y2) ? y1 : y2;
    int maxY = (y1 > y2) ? y1 : y2;
    int cols = maxX - minX + 1;
    int rows = maxY - minY + 1;
    *outRows = rows;
    *outCols = cols;

    char **grid = allocateGrid(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = ' ';
        }
        grid[i][cols] = '\0'; // پایان رشته
    }

    #define SET_POINT(x, y, ch) do { \
        int col = (x) - minX;       \
        int row = (y) - minY;       \
        grid[row][col] = (ch);      \
    } while(0)

    int currX = x1, currY = y1;
    SET_POINT(currX, currY, '+');

    while (currX != x2 || currY != y2) {

        int moves[2][2];
        int count = 0;

        if (currX < x2) {
            moves[count][0] = currX + 1;
            moves[count][1] = currY;
            count++;
        } else if (currX > x2) {
            moves[count][0] = currX - 1;
            moves[count][1] = currY;
            count++;
        }

        if (currY < y2) {
            moves[count][0] = currX;
            moves[count][1] = currY + 1;
            count++;
        } else if (currY > y2) {
            moves[count][0] = currX;
            moves[count][1] = currY - 1;
            count++;
        }

        int choice = 0;
        if (count > 1) {
            choice = rand() % count;
        }
        currX = moves[choice][0];
        currY = moves[choice][1];

        if (!(currX == x2 && currY == y2)) {
            SET_POINT(currX, currY, '#');
        }
    }

    SET_POINT(x2, y2, '+');

    #undef SET_POINT
    return grid;
}
void foun_door1(char map[10][20], cor * door){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            if(map[i][j] == '+'){
                door->x = i;
                door->y = j;
                return;
            }
        }
    }
}
void foun_door2(char map[10][20], cor * door, cor * door2){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            if(map[i][j] == '+'){
                door2->x = i;
                door2->y = j;
            }
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            if(map[i][j] == '+'){
                door->x = i;
                door->y = j;
                return;
            }
        }
    }
}
void Preparing_map(int * s_p_m, int * s_p_g, char map_page[3][40][150]){
    
    for(int i = 0; i < 3; i++){
        if(*s_p_m == 1){
            int row; int cool; int row2; int cool2; int row3; int cool3; int row4; int cool4; int row5; int cool5; int row6; int cool6; 
            int nn = 0; int numbers[6] = {1, 2, 3, 4, 5, 6};
            cor * door1 = (cor *)malloc(sizeof(cor)); cor * door2 = (cor *)malloc(sizeof(cor)); cor * door3 = (cor *)malloc(sizeof(cor)); cor * door4 = (cor *)malloc(sizeof(cor)); cor * door5 = (cor *)malloc(sizeof(cor));; cor * door6 = (cor *)malloc(sizeof(cor));
            cor * door1_2 = (cor *)malloc(sizeof(cor)); cor * door2_2  = (cor *)malloc(sizeof(cor));cor * door3_2  = (cor *)malloc(sizeof(cor)); cor * door4_2  = (cor *)malloc(sizeof(cor)); cor * door5_2  = (cor *)malloc(sizeof(cor)); cor * door6_2  = (cor *)malloc(sizeof(cor));
            char map1[10][20]; char map2[10][20]; 
            char map3[10][20]; char map4[10][20]; 
            char map5[10][20]; char map6[10][20]; char map_col[6][10][20];
            shuffleArray(numbers, 6);
            for(int i = 0; i < 6; i++){
                if(numbers[i] == 1){
                    first_amount0(map1);margin_map_6(map1, i+1); first_amount_6(map1); draw_map_6_1(map1);
                    memcpy(map_col[i], map1, sizeof(map1));
                }
                else if(numbers[i] == 2){
                    first_amount0(map2);margin_map_6(map2, i+1); first_amount_6(map2); draw_map_6_2(map2);
                    memcpy(map_col[i], map2, sizeof(map2));
                }
                else if(numbers[i] == 3){
                    first_amount0(map3);margin_map_7(map3, i+1); first_amount_7(map3); draw_map_7_1(map3);
                    memcpy(map_col[i], map3, sizeof(map3));
                }
                else if(numbers[i] == 4){
                    first_amount0(map4);margin_map_7(map4, i+1); first_amount_7(map4); draw_map_7_2(map4);
                    memcpy(map_col[i], map4, sizeof(map4));
                }
                else if(numbers[i] == 5){
                    first_amount0(map5);margin_map_8(map5, i+1); first_amount_8(map5); draw_map_8_1(map5);
                    memcpy(map_col[i], map5, sizeof(map5));
                }
                else if(numbers[i] == 6){
                    first_amount0(map6);margin_map_8(map6, i+1); first_amount_8(map6); draw_map_8_2(map6);
                    memcpy(map_col[i], map6, sizeof(map6));
                }
            }
            map_col[0][1][1] = '@';
            first_amount0c(map_page[i]); 

            foun_door1(map_col[0], door1); foun_door2(map_col[1], door2, door2_2);
            char  ** rahro1 = drawRandomPath(door1->y, door1->x+1, door2->y, door2->x+19, &row, &cool);

            if(door1->y < door2->y){
                rahro1[0][0] = '#'; rahro1[row-1][cool-1] = '#';
                put_rahro(map_page[i], row, cool, rahro1, door1->x+1, door1->y); 
            }
            else{
                rahro1[row-1][0] = '#'; rahro1[0][cool-1] = '#';
                put_rahro(map_page[i], row, cool, rahro1, door1->x+1, door2->y);
            }
            
            foun_door2(map_col[2], door3, door3_2);
            char ** rahro2 = drawRandomPath(door2_2->y+1, door2_2->x+20, door3_2->y+59, door3_2->x+20, &row2, &cool2);

            if(door2_2->x < door3_2->x){
                rahro2[0][0] = '#'; rahro2[row2-1][cool2-1] = '#';
                put_rahro(map_page[i], row2, cool2, rahro2, door2_2->x+20, door2_2->y+1); 
            }
            else{
                rahro2[row2-1][0] = '#'; rahro2[0][cool2-1] = '#';
                put_rahro(map_page[i], row2, cool2, rahro2, door3_2->x+20, door2_2->y+1);
            }
            
            foun_door2(map_col[3], door4, door4_2);
            char ** rahro3 = drawRandomPath(door3->y+60, door3->x+19, door4_2->y+60, door4_2->x+1, &row3, &cool3);
            
            if(door3->y+60 < door4_2->y+60){
                rahro3[row3-1][0] = '#'; rahro3[0][cool3-1] = '#';
                put_rahro(map_page[i], row3, cool3, rahro3, door4_2->x+1, door3->y+60);
            }
            else{
                rahro3[0][0] = '#'; rahro3[row3-1][cool3-1] = '#';
                put_rahro(map_page[i], row3, cool3, rahro3, door4_2->x+1, door4_2->y+60);
            }

            foun_door2(map_col[4], door5, door5_2);
            char ** rahro4 = drawRandomPath(door4->y+61, door4->x, door5->y+119, door5->x, &row4, &cool4);

            if(door4->x < door5->x){
                rahro4[0][0] = '#'; rahro4[row4-1][cool4-1] = '#';
                put_rahro(map_page[i], row4, cool4, rahro4, door4->x, door4->y+61);
            }
            else{
                rahro4[row4-1][0] = '#'; rahro4[0][cool4-1] = '#';
                put_rahro(map_page[i], row4, cool4, rahro4, door5->x, door4->y+61);
            }

            foun_door1(map_col[5], door6);
            char ** rahro5 = drawRandomPath(door5_2->y+120, door5_2->x+1, door6->y+120, door6->x+19, &row5, &cool5);
            if(door5_2->y < door6->y){
                rahro5[0][0] = '#'; rahro5[row5-1][cool5-1] = '#';
                put_rahro(map_page[i], row5, cool5, rahro5, door5_2->x+1, door5_2->y+120);
            }
            else{
                rahro5[row5-1][0] = '#'; rahro5[0][cool5-1] = '#';
                put_rahro(map_page[i], row5, cool5, rahro5, door5_2->x+1, door6->y+120);
            }

            put_map(map_page[i], map_col[0],0, 0); put_map(map_page[i], map_col[1], 20, 0); put_map(map_page[i], map_col[2], 20, 60); 
            put_map(map_page[i], map_col[3], 0, 60); put_map(map_page[i], map_col[4], 0, 120); put_map(map_page[i], map_col[5], 20, 120);
        }  
    }

    *s_p_m = 0; *s_p_g = 1; 
}
void print_endgame(int * s_m, int * s_p_g){

    int key; int numop = 0;
    while(1){
        clear();
        print_margin();
        attron(A_BOLD); attron(COLOR_PAIR(2)); 
        mvprintw(20, 89, "YOU LOSE");
        
        if(numop == 0){
            attron(A_REVERSE);
            mvprintw(23, 91, "Exit");
            attroff(A_REVERSE);
            mvprintw(24, 91, "Home");
        }

        else if(numop == 1){
            mvprintw(23, 91, "Exit");
            attron(A_REVERSE);
            mvprintw(24, 91, "Home");
            attroff(A_REVERSE);
        }

        key = getch();

        if(key == KEY_UP){
            numop -= 1;
            if(numop < 0){
                numop = 1;
            }
        }
        else if(key == KEY_DOWN){
            numop += 1;
            if(numop > 1){
                numop = 0;
            }
        }
        else if(key == 10){
            break;
        }
    }

    if(numop == 0){
        exit(1);
    }

    else{
        *s_m = 1;
        *s_p_g = 0;
    }

}
void print_win(){
    clear();attron(A_BOLD); attron(COLOR_PAIR(2));
    mvprintw(20, 50, "You win !");
    attroff(A_BOLD); attroff(COLOR_PAIR(2));
    getch();

}
void damage(hinfo * hero, char map_page[40][150], char hayola){
    if(map_page[hero->x][hero->y+1] == hayola){
        hero->health -=2;
    }
    if(map_page[hero->x][hero->y-1] == hayola){
        hero->health -=2;
    }
    if(map_page[hero->x+1][hero->y] == hayola){
        hero->health -=2;
    }
    if(map_page[hero->x-1][hero->y] == hayola){
        hero->health -=2;
    }
    if(map_page[hero->x+1][hero->y+1] == hayola){
        hero->health -=2;
    }
    if(map_page[hero->x+1][hero->y-1] == hayola){
        hero->health -=2;
    }
    if(map_page[hero->x-1][hero->y+1] == hayola){
        hero->health -=2;
    }
    if(map_page[hero->x-1][hero->y-1] == hayola){
        hero->health -=2;
    }
}
void move_jolo(hinfo * hero, char map_page[40][150], int * s_m, int * s_p_g){
    if(map_page[hero->x][hero->y+1] == '.'){
        map_page[hero->x][hero->y+1] = '@'; map_page[hero->x][hero->y] = '.';
        hero->y+=1;
    } 
    else if(map_page[hero->x][hero->y+1] == '+'){
        if(map_page[hero->x][hero->y+2] == '#'){
            map_page[hero->x][hero->y+2] = '@'; map_page[hero->x][hero->y] = '.';
        }
        else{
            map_page[hero->x][hero->y+2] = '@'; map_page[hero->x][hero->y] = '#';
        }
        hero->y+=2;
    }
    else if(map_page[hero->x][hero->y+1] == '#'){
        map_page[hero->x][hero->y+1] = '@'; map_page[hero->x][hero->y] = '#';
        hero->y+=1;
    }
    else if(map_page[hero->x][hero->y+1] == 'a'){
        if((hero->Regular_food + hero->Excellentـfood) < 5){
            hero->Regular_food +=1;map_page[hero->x][hero->y+1] = '@'; map_page[hero->x][hero->y] = '.';
            hero->y+=1;
        }
    } 
    else if(map_page[hero->x][hero->y+1] == 'A'){
        if((hero->Regular_food + hero->Excellentـfood) < 5){
            hero->Excellentـfood+=1; map_page[hero->x][hero->y+1] = '@'; map_page[hero->x][hero->y] = '.';
            hero->y+=1;
        }
    }
    else if(map_page[hero->x][hero->y+1] == 'm'){
        if(hero->health_Potion < 3){
            hero->health_Potion+=1; map_page[hero->x][hero->y+1] = '@'; map_page[hero->x][hero->y] = '.';
            hero->y+=1;
        }
    }
    else if(map_page[hero->x][hero->y+1] == 't'){
        hero->health-=1; map_page[hero->x][hero->y+1] = '@'; map_page[hero->x][hero->y] = '.';
        hero->y+=1;
    }
    else if(map_page[hero->x][hero->y+1] == 'S'){
        hero->weapon+=3; map_page[hero->x][hero->y+1] = '@'; map_page[hero->x][hero->y] = '.';
        hero->y+=1;
    }
    else if(map_page[hero->x][hero->y+1] == 'p'){
        hero->score += 100; map_page[hero->x][hero->y+1] = '@'; map_page[hero->x][hero->y] = '.';
        hero->y+=1;
    }
    else if(map_page[hero->x][hero->y+1] == 'P'){
        hero->score += 500; map_page[hero->x][hero->y+1] = '@'; map_page[hero->x][hero->y] = '.';
        hero->y+=1;
    }
    else if(map_page[hero->x][hero->y+1] == '>'){
        if(hero->game_level <= 3){
            hero->game_level +=1;
            hero->x = 1; hero->y = 1;
        }
        if(hero->game_level == 4){
            *s_p_g  = 0;
            *s_m = 1;
            hero->amount_health = 20;hero->health = hero->amount_health; hero->health_Potion = 0; hero->weapon = 0; hero->game_level = 1; hero->Regular_food = 0; hero->Excellentـfood = 0;  hero->score = 0; hero->gold = 0; hero->amount_food = 10;
            hero->color = 2; hero->x = 1, hero->y=1;
            print_win();


        }
    }
    else if(map_page[hero->x][hero->y+1] == '<'){
        if(hero->game_level > 1){
            hero->game_level -=1;
        }
    }
}
void move_aghab(hinfo * hero, char map_page[40][150], int * s_m, int * s_p_g ){
    if(map_page[hero->x][hero->y-1] == '.'){
        map_page[hero->x][hero->y-1] = '@'; map_page[hero->x][hero->y] = '.';
        hero->y-=1;
    } 
    else if(map_page[hero->x][hero->y-1] == '+'){
        if(map_page[hero->x][hero->y-2] == '#'){
        map_page[hero->x][hero->y-2] = '@'; map_page[hero->x][hero->y] = '.';
        }
        else{
            map_page[hero->x][hero->y-2] = '@'; map_page[hero->x][hero->y] = '#';
        }
        hero->y-=2;
    }
    else if(map_page[hero->x][hero->y-1] == '#'){
        map_page[hero->x][hero->y-1] = '@'; map_page[hero->x][hero->y] = '#';
        hero->y-=1;
    }
    else if(map_page[hero->x][hero->y-1] == 'a'){
        if((hero->Regular_food + hero->Excellentـfood) < 5){
            hero->Regular_food +=1;map_page[hero->x][hero->y-1] = '@'; map_page[hero->x][hero->y] = '.';
            hero->y-=1;
        }
    } 
    else if(map_page[hero->x][hero->y-1] == 'A'){
        if((hero->Regular_food + hero->Excellentـfood) < 5){
            hero->Excellentـfood+=1; map_page[hero->x][hero->y-1] = '@'; map_page[hero->x][hero->y] = '.';
            hero->y-=1;
        }
    }
    else if(map_page[hero->x][hero->y-1] == 'm'){
        if(hero->health_Potion < 3){
            hero->health_Potion+=1; map_page[hero->x][hero->y-1] = '@'; map_page[hero->x][hero->y] = '.';
            hero->y-=1;
        }
    }
    else if(map_page[hero->x][hero->y-1] == 't'){
        hero->health-=1; map_page[hero->x][hero->y-1] = '@'; map_page[hero->x][hero->y] = '.';
        hero->y-=1;
    }
    else if(map_page[hero->x][hero->y-1] == 'S'){
        hero->weapon+=3; map_page[hero->x][hero->y-1] = '@'; map_page[hero->x][hero->y] = '.';
        hero->y-=1;
    }
    else if(map_page[hero->x][hero->y-1] == 'p'){
        hero->score += 100; map_page[hero->x][hero->y-1] = '@'; map_page[hero->x][hero->y] = '.';
        hero->y-=1;
    }
    else if(map_page[hero->x][hero->y-1] == 'P'){
        hero->score += 500; map_page[hero->x][hero->y-1] = '@'; map_page[hero->x][hero->y] = '.';
        hero->y-=1;
    }
    else if(map_page[hero->x][hero->y-1] == '>'){
    //     //if(hero->game_level < 3){
    //         hero->game_level +=1;
    //     }
    //     if(hero->game_level == 3){
    //         print_win();
    //         *s_p_g  = 0;
    //         *s_m = 1;

    //     }
    }
    else if(map_page[hero->x][hero->y-1] == '<'){
        if(hero->game_level > 1){
            hero->game_level -=1; hero->x = 1; hero->y = 1 ; map_page[1][1] = '@';
        }
    }
}
void move_bala(hinfo * hero, char map_page[40][150] ,int * s_m, int * s_p_g){
    if(map_page[hero->x-1][hero->y] == '.'){
        map_page[hero->x-1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
        hero->x-=1;
    } 
    else if(map_page[hero->x-1][hero->y] == '+'){
        if(map_page[hero->x-2][hero->y] == '#'){
            map_page[hero->x-2][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
        }  
        else{
           map_page[hero->x-2][hero->y] = '@'; map_page[hero->x][hero->y] = '#'; 
        }  
        hero->x-=2;
    }
    else if(map_page[hero->x-1][hero->y] == '#'){
        map_page[hero->x-1][hero->y] = '@'; map_page[hero->x][hero->y] = '#';
        hero->x-=1;
    }
    else if(map_page[hero->x-1][hero->y] == 'a'){
        if((hero->Regular_food + hero->Excellentـfood) < 5){
            hero->Regular_food +=1;map_page[hero->x-1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
            hero->x-=1;
        }
    } 
    else if(map_page[hero->x-1][hero->y] == 'A'){
        if((hero->Regular_food + hero->Excellentـfood) < 5){
            hero->Excellentـfood+=1; map_page[hero->x-1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
            hero->x-=1;
        }
    }
    else if(map_page[hero->x-1][hero->y] == 'm'){
        if(hero->health_Potion < 3){
            hero->health_Potion+=1; map_page[hero->x-1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
            hero->x-=1;
        }
    }
    else if(map_page[hero->x-1][hero->y] == 't'){
        hero->health-=1; map_page[hero->x-1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
        hero->x-=1;
    }
    else if(map_page[hero->x-1][hero->y] == 'S'){
        hero->weapon+=3; map_page[hero->x-1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
        hero->x-=1;
    }
    else if(map_page[hero->x-1][hero->y] == 'p'){
        hero->score += 100; map_page[hero->x-1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
        hero->x-=1;
    }
    else if(map_page[hero->x-1][hero->y] == 'P'){
        hero->score += 500; map_page[hero->x-1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
        hero->x-=1;
    }
    else if(map_page[hero->x-1][hero->y] == '<'){
        if(hero->game_level > 1){
            hero->game_level -=1;
        }
    }
    else if(map_page[hero->x-1][hero->y] == '<'){
        if(hero->game_level > 1){
            hero->game_level -=1;
        }
    }
}
void move_paeen(hinfo * hero, char map_page[40][150], int * s_m, int * s_p_g){
    if(map_page[hero->x+1][hero->y] == '.'){
        map_page[hero->x+1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
        hero->x+=1;
    } 
    else if(map_page[hero->x+1][hero->y] == '+'){
        if(map_page[hero->x+2][hero->y] == '#'){
            map_page[hero->x+2][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
        }
        else{
            map_page[hero->x+2][hero->y] = '@'; map_page[hero->x][hero->y] = '#';
        }
        hero->x+=2;
    }
    else if(map_page[hero->x+1][hero->y] == '#'){
        if(map_page[hero->x][hero->y+1] == '-'){
             map_page[hero->x+1][hero->y] = '@'; map_page[hero->x][hero->y] = '+';
        }
        else{
            map_page[hero->x+1][hero->y] = '@'; map_page[hero->x][hero->y] = '#';
        }
        hero->x+=1;
    }
    else if(map_page[hero->x+1][hero->y] == 'a'){
        if((hero->Regular_food + hero->Excellentـfood) < 5){
            hero->Regular_food +=1;map_page[hero->x+1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
            hero->x+=1;
        }
    } 
    else if(map_page[hero->x+1][hero->y] == 'A'){
        if((hero->Regular_food + hero->Excellentـfood) < 5){
            hero->Excellentـfood+=1; map_page[hero->x+1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
            hero->x+=1;
        }
    }
    else if(map_page[hero->x+1][hero->y] == 'm'){
        if(hero->health_Potion < 3){
            hero->health_Potion+=1; map_page[hero->x+1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
            hero->x+=1;
        }
    }
    else if(map_page[hero->x+1][hero->y] == 't'){
        hero->health-=1; map_page[hero->x+1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
        hero->x+=1;
    }
    else if(map_page[hero->x+1][hero->y] == 'S'){
        hero->weapon+=3; map_page[hero->x+1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
        hero->x+=1;
    }
    else if(map_page[hero->x+1][hero->y] == 'p'){
        hero->score += 100; map_page[hero->x+1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
        hero->x+=1;
    }
    else if(map_page[hero->x+1][hero->y] == 'P'){
        hero->score += 500; map_page[hero->x+1][hero->y] = '@'; map_page[hero->x][hero->y] = '.';
        hero->x+=1;
    }
    else if(map_page[hero->x+1][hero->y] == '>'){
        if(hero->game_level < 3){
            hero->game_level +=1;
        }
        if(hero->game_level == 3){
            print_win();
            *s_p_g  = 0;
            *s_m = 1;

        }
    }
    else if(map_page[hero->x+1][hero->y] == '<'){
        if(hero->game_level > 1){
            hero->game_level -=1;
        }
    }
}
void attack_zaif(hinfo * hero, char map_page[40][150]){
    if(map_page[hero->x+1][hero->y] == 'D' || map_page[hero->x+1][hero->y] == 'f'){
        map_page[hero->x+1][hero->y] = '.';
    }
    if(map_page[hero->x+2][hero->y] == 'D' || map_page[hero->x+2][hero->y] == 'f'){
        map_page[hero->x+2][hero->y] = '.';
    }
    if(map_page[hero->x-1][hero->y] == 'D' || map_page[hero->x-1][hero->y] == 'f'){
        map_page[hero->x-1][hero->y] = '.';
    }
    if(map_page[hero->x-2][hero->y] == 'D' || map_page[hero->x-2][hero->y] == 'f'){
        map_page[hero->x-2][hero->y] = '.';
    }
    if(map_page[hero->x][hero->y+1] == 'D' || map_page[hero->x][hero->y+1] == 'f'){
        map_page[hero->x][hero->y+1] = '.';
    }
    if(map_page[hero->x][hero->y+2] == 'D' || map_page[hero->x][hero->y+2] == 'f'){
        map_page[hero->x][hero->y+2] = '.';
    }
    if(map_page[hero->x][hero->y-1] == 'D' || map_page[hero->x][hero->y-1] == 'f'){
        map_page[hero->x][hero->y-1] = '.';
    }
    if(map_page[hero->x][hero->y-2] == 'D' || map_page[hero->x][hero->y-2] == 'f'){
        map_page[hero->x][hero->y-2] = '.';
    }
    if(map_page[hero->x+1][hero->y+1] == 'D' || map_page[hero->x+1][hero->y+1] == 'f'){
        map_page[hero->x+1][hero->y+1] = '.';
    }
    if(map_page[hero->x+1][hero->y-1] == 'D' || map_page[hero->x+1][hero->y-1] == 'f'){
        map_page[hero->x+1][hero->y-1] = '.';
    }
    if(map_page[hero->x-1][hero->y-1] == 'D' || map_page[hero->x-1][hero->y-1] == 'f'){
        map_page[hero->x-1][hero->y-1] = '.';
    }
    if(map_page[hero->x-1][hero->y+1] == 'D' || map_page[hero->x-1][hero->y+1] == 'f'){
        map_page[hero->x-1][hero->y+1] = '.';
    }
    if(map_page[hero->x+1][hero->y] == 'F'){
        map_page[hero->x+1][hero->y] = 'f';
    }
    if(map_page[hero->x+2][hero->y] == 'F'){
        map_page[hero->x+2][hero->y] = 'f';
    }
    if(map_page[hero->x-1][hero->y] == 'F'){
        map_page[hero->x-1][hero->y] = 'f';
    }
    if(map_page[hero->x-2][hero->y] == 'F'){
        map_page[hero->x-2][hero->y] = 'f';
    }
    if(map_page[hero->x][hero->y+1] == 'F'){
        map_page[hero->x][hero->y+1] = 'f';
    }
    if(map_page[hero->x][hero->y+2] == 'F'){
        map_page[hero->x][hero->y+2] = 'f';
    }
    if(map_page[hero->x][hero->y-1] == 'F'){
        map_page[hero->x][hero->y-1] = 'f';
    }
    if(map_page[hero->x][hero->y-2] == 'F'){
        map_page[hero->x][hero->y-2] = 'f';
    }
    if(map_page[hero->x+1][hero->y+1] == 'F'){
        map_page[hero->x+1][hero->y+1] = 'f';
    }
    if(map_page[hero->x+1][hero->y-1] == 'F'){
        map_page[hero->x+1][hero->y-1] = 'f';
    }
    if(map_page[hero->x-1][hero->y-1] == 'F'){
        map_page[hero->x-1][hero->y-1] = 'f';
    }
    if(map_page[hero->x-1][hero->y+1] == 'F'){
        map_page[hero->x-1][hero->y+1] = 'f';
    }
}
void attack_ghavi(hinfo * hero, char map_page[40][150]){
    if(map_page[hero->x+1][hero->y] == 'D' || map_page[hero->x+1][hero->y] == 'f' || map_page[hero->x+1][hero->y] == 'F'){
        map_page[hero->x+1][hero->y] = '.';
    }
    if(map_page[hero->x+2][hero->y] == 'D'|| map_page[hero->x+2][hero->y] == 'f' || map_page[hero->x+2][hero->y] == 'F'){
        map_page[hero->x+2][hero->y] = '.';
    }
    if(map_page[hero->x-1][hero->y] == 'D' || map_page[hero->x-1][hero->y] == 'f' || map_page[hero->x-1][hero->y] == 'F'){
        map_page[hero->x-1][hero->y] = '.';
    }
    if(map_page[hero->x-2][hero->y] == 'D' || map_page[hero->x-2][hero->y] == 'f' || map_page[hero->x-2][hero->y] == 'F'){
        map_page[hero->x-2][hero->y] = '.';
    }
    if(map_page[hero->x][hero->y+1] == 'D' || map_page[hero->x][hero->y+1] == 'f' || map_page[hero->x][hero->y+1] == 'F'){
        map_page[hero->x][hero->y+1] = '.';
    }
    if(map_page[hero->x][hero->y+2] == 'D' || map_page[hero->x][hero->y+2] == 'f' || map_page[hero->x][hero->y+2] == 'F'){
        map_page[hero->x][hero->y+2] = '.';
    }
    if(map_page[hero->x][hero->y-1] == 'D' || map_page[hero->x][hero->y-1] == 'f' || map_page[hero->x][hero->y-1] == 'F'){
        map_page[hero->x][hero->y-1] = '.';
    }
    if(map_page[hero->x][hero->y-2] == 'D' || map_page[hero->x][hero->y-2] == 'f' || map_page[hero->x][hero->y-2] == 'F'){
        map_page[hero->x][hero->y-2] = '.';
    }
    if(map_page[hero->x+1][hero->y+1] == 'D' || map_page[hero->x+1][hero->y+1] == 'f' || map_page[hero->x+1][hero->y+1] == 'F'){
        map_page[hero->x+1][hero->y+1] = '.';
    }
    if(map_page[hero->x+1][hero->y-1] == 'D' || map_page[hero->x+1][hero->y-1] == 'f' || map_page[hero->x+1][hero->y-1] == 'F'){
        map_page[hero->x+1][hero->y-1] = '.';
    }
    if(map_page[hero->x-1][hero->y-1] == 'D' || map_page[hero->x-1][hero->y-1] == 'f' || map_page[hero->x-1][hero->y-1] == 'F'){
        map_page[hero->x-1][hero->y-1] = '.';
    }
    if(map_page[hero->x-1][hero->y+1] == 'D' || map_page[hero->x-1][hero->y+1] == 'f' || map_page[hero->x-1][hero->y+1] == 'F'){
        map_page[hero->x-1][hero->y+1] = '.';
    }
}
void handel_game(char map_page[40][150], hinfo * hero, int time_start, int time_end, int *s_m, int *s_i_m, int * s_p_g, char key){
     
    if(hero->count_step == 10){
        hero->amount_food -= 1;
        hero->count_step = 0;
    }
    if(hero ->amount_food < 5){
        hero->health -= 1;
        if(hero->amount_food < 0){
            hero->amount_food = 0;
        }
    }
    if(hero->amount_food == 10){
        if(hero->health < hero->amount_health){
        hero->health +=1;
        }
    }
    if(hero->health == 0){
        hero->time_game += ((double)(time_end - time_start)) / CLOCKS_PER_SEC;
        print_endgame(s_m, s_i_m);
    }
    if(hero->health == hero->amount_health){

    }
    
    damage(hero, map_page, 'F');
    damage(hero, map_page, 'f');
    damage(hero, map_page, 'D');

    if(key == '6'){
        move_jolo(hero, map_page, s_m, s_p_g);
    }
    if(key == '4'){
        move_aghab(hero, map_page, s_m, s_p_g);
    }
    if(key == '8'){
        move_bala(hero, map_page, s_m, s_p_g);
    }
    if(key == '2'){
        move_paeen(hero, map_page, s_m, s_p_g);
    }
    if(key == 'i'){
        attack_zaif(hero, map_page);
        hero->gold;
    }
    if(key == 'o'){
        if(hero->weapon > 0){
            attack_ghavi(hero, map_page);
            hero->gold+=1;
            hero->weapon -= 1;
        }
    }
    if(key == 'e'){
        if(hero->Regular_food > 0){
            hero->amount_food += 1;
            if(hero->amount_food > 10){
                hero->amount_food = 10;
            }
            hero->Regular_food -= 1;
        }   
    }
    if(key == 'r'){
        if(hero->Excellentـfood > 0){
            hero->amount_food += 2;
            if(hero->amount_food > 10){
                hero->amount_food = 10;
            }
            hero->Excellentـfood -= 1;
        }   
    }
    if(key == 'p'){
        if(hero->health_Potion > 0){
            hero->health = hero->amount_health;
            hero->health_Potion -= 1;
        }   
    }
    clear();
    print_map_page(map_page, 10, 15, hero->color);
    attron(A_BOLD); attron(COLOR_PAIR(20));
    mvprintw(2, 89, "<< ROGUE >>");
    mvprintw(43, 5, "your name : %s   your level : %d   your health : %d   your score : %d   your gold : %d   your count food : %d   your Amount of food : %d   your potion : %d   your weapon : %d", hero->name, hero->game_level, hero->health,hero->score, hero->gold, (hero->Regular_food+hero->Excellentـfood),hero->amount_food, hero->health_Potion, hero->weapon);
    attroff(A_BOLD); attroff(COLOR_PAIR(20));
    hero->count_step+=1;
}
