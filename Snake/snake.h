#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#define HEIGHT 40
#define WIDTH 60
struct {
    int time;
    int food;
} level;
int grade = 0;
char user_name[64];
int box[HEIGHT][WIDTH] = {{7134, }, };
int lenth = 4;


void gotoxy(short, short);
void start();
void show();
int with(char);
void lose();
int eat(int, int);
int alive(int, int);
void introduce();
void food();
void menu();
void wait();
void gra();
void file();

void start() {
    int i;
    //?????????·
    for (i = 0; i < HEIGHT; i++) {
        box[i][0] = 7134;
        box[i][WIDTH-1] = 7134;
    }
    //?ú??1???á??9
    for (i = 0; i < WIDTH; i++) {
        box[0][i] = 9928;
        box[HEIGHT-1][i] = 9928;
    }
    //????????
    box[20][20] = 4;
    box[20][21] = 3;
    box[20][22] = 2;
    box[20][23] = 1;
    //9928_
    //7134|
    //如果有机会可以尝试循环几次换一个框，类似升级加强难度那种
    //7???·??2???í??4????
    //555??????
    //7134,9928

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
            if(box[i][j] > 5000 && box[i][j] <=7134){
                printf("|");

            }
            if (box[i][j] > 7134){
                printf("_");
            }
            if(box[i][j] == lenth){
                //   printf("??");
                printf("2");
            }
            if(box[i][j] < lenth && box[i][j] > 0){
                //   printf("??");
                printf("3");
            }
            if(box[i][j] == -1){
                //用-1表示食物吧
//                printf("");  // ????×?·???????
                printf("*");
            }
            if(box[i][j] == 0){
                printf(" ");
            }
        }
        printf("\n");
    }
}

void gotoxy(short x, short y) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
    //????gotoxy????

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


int eat(int head_x, int head_y) {
    if (box[head_y][head_x] < 0) {
        grade += 7;
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
    system("cls");
    //char try = (char)getch();
    gotoxy(0, 0);
    for(i = 0; i < 16; i++)
        printf("\n");
    for(i = 0; i < 25; i++)
        printf(" ");
    printf("您已经很优秀了\n");
    file();

}


void introduce() {
    int i;
    char try;
    gotoxy(0, 0);
    for(i = 0; i < 6; i++)
        printf("\n");
    for(i = 0; i < 10; i++)
        printf(" ");
    printf("               THIS IS THE GREAT MAGGOT_3.0\n");
    printf("\n");
    Sleep(1000);
    printf("                    你可以直接按s来开始【如果您熟悉的话】\n");
    Sleep(1000);
    printf("                      或者也可以按m来看一眼游戏规则\n");
    Sleep(1000);
    printf("              不要瞎**按，否则你需要重新开一遍就是这么任性，哼唧\n");
    Sleep(1000);
    printf("      出现了任何问题或者您有什么想法都可以通过mao-zu@outlook.com来告知我\n");
    Sleep(1000);
    printf("                                祝顺好\n");
    Sleep(1000);
    try = (char)getch();
    if(try == 'm')
        menu();
    else if(try == 's') {
        system("cls");
        printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
        printf("                   HAVE FUN");
        Sleep(2000);
    }
    else {
        system("cls");
        printf("怎么就这么不听劝呢");
        while(1) {
            scanf("%d",&i);
        }

    }


}

void food() {
    int heigh, width;
    int food;
    grade += 1;
    food = level.food;
    if(0 == grade % food) {
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


void menu() {
    system("cls");
    printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
    printf("                             理论上他是贪吃蛇\n");
    Sleep(1000);
    printf("                      毕竟规则就很像那个经典的小游戏\n");
    Sleep(1000);
    printf("         我叫他长尾蛆的原因也只是因为在我的1.0,2.0中他真的是扭曲变形如蛆虫\n");
    Sleep(1000);
    printf("                没什么多说的吧，wasd控制，别撞自己，别撞墙\n");
    Sleep(1000);
    printf("                          魔改版运动速度的任意的\n");
    Sleep(1000);
    printf("                         一如既往的按任意键开始\n");
    getch();
}


void wait() {
    int i;
    system("cls");
    printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
    printf("                                  秋豆麻袋\n");
    printf("                            您可以选一下难度系数\n");
    printf("                            初级---------------1\n");
    printf("                            中极---------------2\n");
    printf("                            高级---------------3\n");
    printf("                            魔改---------------4\n");
    scanf("%d",&i);
    if(i == 1) {
        level.time = 100;
        level.food = 13;
    }
    if(i == 2) {
        level.time = 50;
        level.food = 15;
    }
    if(i == 3) {
        level.time = 10;
        level.food = 15;
    }
    if(i == 4) {
        level.time = 5;
        level.food = 17;
    }
}


void gra() {
    gotoxy(70, 10);
    printf("您的得分%d\n",grade);

}

void file() {
    char user_name1[64], user_name2[64], user_name3[64];
    int grade1, grade2, grade3,i;
    printf("\n");
    for(i = 0; i < 25; i++) printf(" ");
    printf("最高记录");
    printf("\n");
    FILE *fp1 = fopen("grade.txt","a+");
    fscanf(fp1, "%s %d", user_name1, &grade1);for(i = 0; i < 25; i++) printf(" ");
    fscanf(fp1, "%s %d", user_name2, &grade2);for(i = 0; i < 25; i++) printf(" ");
    fscanf(fp1, "%s %d", user_name3, &grade3);for(i = 0; i < 25; i++) printf(" ");
    fclose(fp1);
    if (grade > grade1) {
        printf("\n");for(i = 0; i < 25; i++) printf(" ");
        printf("%s %d\n", user_name, grade);for(i = 0; i < 25; i++) printf(" ");
        printf("%s %d\n", user_name1, grade1);for(i = 0; i < 25; i++) printf(" ");
        printf("%s %d\n", user_name2, grade2);for(i = 0; i < 25; i++) printf(" ");
    }
    else if (grade > grade2) {
        printf("\n");for(i = 0; i < 25; i++) printf(" ");
        printf("%s %d\n", user_name1, grade1);for(i = 0; i < 25; i++) printf(" ");
        printf("%s %d\n", user_name, grade);for(i = 0; i < 25; i++) printf(" ");
        printf("%s %d\n", user_name2, grade2);for(i = 0; i < 25; i++) printf(" ");
    }
    else if (grade > grade3) {
        printf("\n");for(i = 0; i < 25; i++) printf(" ");
        printf("%s %d\n", user_name1, grade1);for(i = 0; i < 25; i++) printf(" ");
        printf("%s %d\n", user_name2, grade2);for(i = 0; i < 25; i++) printf(" ");
        printf("%s %d\n", user_name, grade);for(i = 0; i < 25; i++) printf(" ");
    }
    else {
        printf("\n");for(i = 0; i < 25; i++) printf(" ");
        printf("%s %d\n", user_name1, grade1);for(i = 0; i < 25; i++) printf(" ");
        printf("%s %d\n",user_name2, grade2);for(i = 0; i < 25; i++) printf(" ");
        printf("%s %d\n",  user_name3, grade3);for(i = 0; i < 25; i++) printf(" ");
    }
    FILE *fp2 = fopen("grade.txt","w");
    if (grade > grade1) {
        fprintf(fp2,"%s %d\n", user_name, grade);
        fprintf(fp2,"%s %d\n", user_name1, grade1);
        fprintf(fp2,"%s %d\n", user_name2, grade2);
    }
    else if (grade > grade2) {
        fprintf(fp2,"%s %d\n", user_name1, grade1);
        fprintf(fp2,"%s %d\n", user_name, grade);
        fprintf(fp2,"%s %d\n", user_name2, grade2);
    }
    else if (grade > grade3) {
        fprintf(fp2,"%s %d\n", user_name1, grade1);
        fprintf(fp2,"%s %d\n", user_name2, grade2);
        fprintf(fp2,"%s %d\n", user_name, grade);
    }
    else {
        fprintf(fp2,"%s %d\n", user_name1, grade1);
        fprintf(fp2,"%s %d\n",user_name2, grade2);
        fprintf(fp2,"%s %d\n",  user_name3, grade3);
    }
    fclose(fp2);
}

#endif //SNAKE_SNAKE_H
