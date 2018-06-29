#include "Snake/snake.h"

int main() {
    char move = 'a';
    char try = 0;
    int a = 1;

    introduce();
    wait();
    system("cls");
//    scanf("%c", &try);
//    getchar();
    start();
    while (a != 9) {
        show();
        gra();
        if (kbhit()) {
            try = (char)getch();
            if(try == 'w' || try == 'a' || try == 's' || try == 'd') {
                if (!(try == 'w' && move == 's') && !(try == 'a' && move == 'd') && !(try == 's' && move == 'w') && !(try == 'd' && move == 'a'))
                    move = try;
            }
        }
        a = with(move);
        food();
        if(level.time == 5) {
            Sleep((DWORD) (rand() % 100));
        }
        else
            Sleep((DWORD) level.time);
        //
        // move = (char)getch();
        // a = with(move);
        grade += 1;
    }
    while ((try = (char)getchar()) != EOF && try != '\n');
    system("cls");
    gotoxy(16,20);
    printf("请输入您的名字\n");
    gets(user_name);
    lose();
    return 0;
}
