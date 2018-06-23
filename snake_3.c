#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define HEIGHT 28
#define WIDTH 60
int box[HEIGHT][WIDTH] = {0};
int lenth = 4;
int grade = 0;


void gotoxy(int, int);
void start();
void show();
int with(char);
void lose();
int eat(int, int);
int alive(int, int);
void introduce();
void food();


int main() {
    char move;
    char try;
    int a = 1;
    introduce();
    move = 'a';
    scanf("%c",&try);
    getchar();
    start();
    while (a != 9) {
        show();
        if (kbhit()) {
            move = (char)getch();
            a = with(move);
        }
        else
          a = with(move);
       food();
       Sleep(200);
      // system("cls");
        // move = (char)getch();
        // a = with(move);

    }
    lose();
    return 0;
}


//³õÊ¼ÓÎÏ·
void start() {
    int i;
    //³õÊ¼»¯ÓÎÏ·
    for (i = 0; i < HEIGHT; i++) {
        box[i][0] = 7134;
        box[i][WIDTH-1] = 7134;
    }
    //ÊúÊÇ1£¬ºáÊÇ9
    for (i = 0; i < WIDTH; i++) {
        box[0][i] = 9928;
        box[HEIGHT-1][i] = 9928;
    }
    //³õÊ¼»¯Éß
    box[20][20] = 4;
    box[20][21] = 3;
    box[20][22] = 2;
    box[20][23] = 1;
    //9928_
    //7134|
    //如果有机会可以尝试循环几次换一个框，类似升级加强难度那种
    //7ÊÇÍ·£¬2ÊÇÉí£¬4ÊÇÎ²
    //555ÊÇÊ³Îï

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
            if(box[i][j] == 7134){
                printf("|");
                printf("hhhhhhhhhhhhh");//for test
            }
            if (box[i][j] == 9928){
                printf("_");
            }
            if(box[i][j] == lenth){
             //   printf("¡ñ");
                printf("●");
            }
            if(box[i][j] < lenth && box[i][j] > 0){
             //   printf("¡ö");
                printf("■");
            }
            if(box[i][j] == -1){
                //用-1表示食物吧
//                printf("");  // Õâ¸ö×Ö·û²»ÄÜÓÃ
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
    //Ä£Äâgotoxyº¯Êý

}

int with(char move) {
    int i = 0, j = 0;//d
    int head_x = 0, head_y = 0;
    for (i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++){
         //   printf("%c",move);

            if ('w' == move) {
                if (lenth == box[j][i]) {
                    head_x = i;
                    head_y = j - 1;
                }
            }
            if ('a' == move) {
                if (lenth == box[j][i]) {
                    // printf("find it\n");
                    head_x = i - 1;
                    head_y = j;
                }
            }
            if ('s' == move) {
                if (lenth == box[j][i]) {
                    head_x = i;
                    head_y = j + 1;
                }
            }
            if ('d' == move) {
                if (lenth == box[j][i]) {
                    head_x = i + 1;
                    head_y = j;
                }
            }
            // printf("%d,%d\n",head_y,head_x);
            // printf("%d      \n",box[head_y][head_x]);
            //for test
            
            // if(eat(head_x, head_y)) {
            //     lenth += 1;
            //     box[head_y][head_x] = lenth;
            // }
            // else {
            //     if (box[j][i] > 1) {
            //         box[head_y][head_x] = lenth;
            //         box[j][i] -= 1;
            //     }

            // }
        }
    }
   if (!alive(head_x, head_y)) { 
            // printf("gggggggggggggggfuck");  
                  return 9;
            }
   for (i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++){
            if(eat(head_x, head_y)) {
                // printf("eat");
                lenth += 1;
                box[head_y][head_x] = lenth;
            }
            else {
                if (box[j][i] > 0) {
                    // printf("no eat");
                    box[head_y][head_x] = lenth;
                    box[j][i] -= 1;
                }

            }
        } 
    }
return 1;     

}
//Èç¹ûËÀÁËreturn 9£»


int eat(int head_x, int head_y) {
    if (box[head_y][head_x] < 0) {
        return 1;
    }
    else {
        return 0;
    }

}

int alive(int head_x, int head_y) {
    if (!eat(head_x, head_y)) {
        if (box[head_y][head_x]) {
           return 0;
        }
    return 1;
    }
    return 1;
    
}

void lose() {
    int i;
    //char try = (char)getch();
    gotoxy(0, 0);
    for(i = 0; i < 13; i++)
        printf("\n");
    for(i = 0; i < 25; i++)
        printf(" ");
    printf("Good Game!");

}


void introduce() {
    int i;
    //char try = (char)getch();
    gotoxy(0, 0);
    for(i = 0; i < 13; i++)
        printf("\n");
    for(i = 0; i < 10; i++)
        printf(" ");
    printf("press whatever you like to get start!");

}

void food() {
    int heigh, width;
    grade += 1;
    if(0 == grade % 17) {
        srand((unsigned)time(NULL));
        heigh = rand() % 28 + 1;
        width = rand() % 60 + 1;
        while(0 != box[heigh][width]){
            heigh = rand() % 28 + 1;
            width = rand() % 60 + 1;
        }
        box[heigh][width] = -1;
    }
}
