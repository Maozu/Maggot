#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define HEIGHT 28
#define WIDTH 60
int box[HEIGHT][WIDTH] = {0};


void gotoxy(int, int);
void start();
void show();
int with(char);
void lose();
int eat(int, int);
int alive(int, int);


int main() {
    char move;
    char try;
    int a = 1;
    move = 'a';
    scanf("%c",&try);
    printf("hhhhhhhhhhhhhhhhhhhh");
    printf("fghfghfghf");
    getchar();
    start();
    while (a != 9) {
        show();
      //   if (kbhit()) {
      //       move = (char)getch();
      //       a = with(move);
      //   }
      //   a = with(move);
      //  Sleep(2000);
      // // system("cls");
        move = (char)getch();
        a = with(move);

    }
    lose();
    return 0;
}


//初始游戏
void start() {
    int i;
    //初始化游戏
    for (i = 0; i < HEIGHT; i++) {
        box[i][0] = 1;
        box[i][WIDTH-1] = 1;
    }
    //竖是1，横是9
    for (i = 0; i < WIDTH; i++) {
        box[0][i] = 9;
        box[HEIGHT-1][i] = 9;
    }
    //初始化蛇
    box[20][20] = 7;
    box[20][21] = 2;
    box[20][22] = 2;
    box[20][23] = 4;
    //7是头，2是身，4是尾
    //555是食物

//    // For Test
//    for (i = 0; i < HEIGHT; i++) {
//        for (int j = 0; j < WIDTH; j++)
//            printf("%d", box[i][j]);
//        printf("\n");
//    }


}

void show() {
    gotoxy(0, 0);
    // system("cls");
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for(j = 0;j < WIDTH; j++) {
            if(box[i][j] == 1){
                printf("|");
            }
            if (box[i][j] == 9){
                printf("_");
            }
            if(box[i][j] == 7 ){
             //   printf("●");
                printf("o");
            }
            if((box[i][j] == 2) || (box[i][j] ==4)){
             //   printf("■");
                printf("d");
            }
            if(box[i][j] == 555){
//                printf("");  // 这个字符不能用
                printf("*");
            }
            if(box[i][j] == 0){
                printf(" ");
            }
        }
        printf("\n");
    }
}

void gotoxy(int x,int y) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
    //模拟gotoxy函数

}

int with(char move) {
    int i = 0, j = 0;//d
    int head_x = 0, head_y = 0;
    for (i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++){
         //   printf("%c",move);
            if ('w' == move) {
                if (7 == box[j][i]) {
                    box[j][i] = 2;
                    head_x = i;
                    head_y = j - 1;

                }
            }
            if ('a' == move) {
                if (7 == box[j][i]) {
                    box[j][i] = 2;
                    head_x = i - 1;
                    head_y = j;
                }
            }
            if ('s' == move) {
                if (7 == box[j][i]) {
                    box[j][i] = 2;
                    head_x = i;
                    head_y = j + 1;
                }
            }
            if ('d' == move) {
                if (7 == box[j][i]) {
                    box[j][i] = 2;
                    head_x = i + 1;
                    head_y = j;
                }
            }
            if(4 == box[j][i]){
                if(!eat(head_x, head_y)){
                    box[j][i] = 0;
                }
            }
            
        }
    }
    if (!alive(head_x, head_y)) {   
        return 9;
    }
    box[head_y][head_x] = 7;
    return 0;

}
//如果死了return 9；


int eat(int head_x, int head_y) {
    if (box[head_y][head_x] == 555) {
        printf("1");
        return 1;
    }
    else {
        printf("0");
        return 0;
    }

}

int alive(int head_x, int head_y) {
    if (box[head_y][head_x]) {
        return 0;
    }
    return 1;
}

void lose() {
    int i;
    //char try = (char)getch();
    for(i = 0; i < 13; i++)
        printf("\n");
    for(i = 0; i < 25; i++)
        printf(" ");
    printf("Good Game!");

}







































