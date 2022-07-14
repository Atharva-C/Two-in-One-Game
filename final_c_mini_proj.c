#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
int play_tictactoe();
int play_rockpaperscissor();
void draw_board(char grid[3][3]);
int check_win(char grid[3][3]);
int main(){
    int choice;
    char you;
    printf("\n\n\n\n\nHi! What's up friends!\n\nBored with studies??,Take a short break and play these games to refresh your mind!!");
    while(1)
    {
        printf("\n\n\n***MENU***\t\t\n\n");
        printf("\n1.play TIC-TAC-TOE\n");
        printf("\n2.play ROCK-PAPER-SCISSOR\n");
        printf("\n3.EXIT\n");
        printf("\nWhich GAME would you like to PLAY:");
        scanf("%d",&choice);
        switch(choice)
        {
            
            case 1:
            printf("\n\n\t\t\tWELCOME! TO THE GAME\n\n(INSTRUCTION:TWO PLAYES ARE REQUIRED TO PLAY THIS GAME!)\n\n");
            play_tictactoe();
            break;
            
            case 2:
            printf("\n\n\t\t\tWELCOME TO THE GAME\n\n(INSTRUCTION:THIS IS A SINGLE PLAYER GAME PLAYED AGAINST CPU!)\n\n");
            scanf("%c", &you);
            printf("\nROCK!!--PAPER!!--SCISSOR!!\n");
            play_rockpaperscissor();
            break;
            
            case 3:
            printf("Exited!");
            return 0;
            break;
            
            default:
            printf("INVALID INPUT!\nTRY AGAIN");
        }
    }
}
int play_tictactoe()
{
    char grid[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int flag=1,position,outcome,drawGame=0;
    char ch;
    while(1){
        draw_board(grid);
        if(flag==1)
            printf("\nPLAYER 1's TURN: ");
        else
            printf("\nPLAYER 2's TURN: ");
        scanf("%d",&position);
        if(position>=1 && position<=9){ // 1 to 9  // 0/x
            if(flag==1){
                ch='O';
                flag=0;
            }
            else{
                ch='X';
                flag=1;
            }
            if(position>=1 && position<=3){ // 1 to 3
                if(grid[0][position-1]!='O' && grid[0][position-1]!='X'){
                    grid[0][position-1]=ch;
                    drawGame++;
                }
                else{
                    printf("\nYou Can Not play here!\nChoose Other Position:");
                    if(ch=='X'){
                        flag=0;
                    }
                    else{
                        flag=1;
                    }
                    getch();
                }
            }
        else if(position>=4 && position<=6){ // 4 to 6
            if(grid[1][position-4]!='O' && grid[1][position-4]!='X'){
                    grid[1][position-4]=ch;
                    drawGame++;
                }
                else{
                    printf("\nYou Can Not play here!\nChoose Other Position:");
                    if(ch=='X'){
                        flag=0;
                    }
                    else{
                        flag=1;
                    }
                    getch();
                }
            }
            else{  // 7 to 9
                if(grid[2][position-7]!='O' && grid[2][position-7]!='X'){
                    grid[2][position-7]=ch;
                    drawGame++;
                }
                else{
                    printf("\nYou Can Not Place The Char Here. Choose Other Position:");
                    if(ch=='X')
                        flag=0;
                    else
                        flag=1;
                    getch();
                }
            }
            outcome=check_win(grid);
            if(outcome==1){
                draw_board(grid);
                printf("\nPLAYER 1 WON!!");
                getch();
                break;
            }
            if(outcome==2){
                draw_board(grid);
                printf("\nPLAYER 2 WON!!");
                getch();
                break;
            }
            if(drawGame==9 && outcome==0){
                draw_board(grid);
                printf("\nGAME DRAW!!");
                getch();
                break;
            }
        }
        else{
            printf("\nINVALID POSITION!! ENTER A NUMBER FROM 1 TO 9 ONLY\n");
            getch();
        }
        }
    getch();
    return 0;
}
void draw_board(char grid[3][3])
{
    int i,j;
    for(i=0;i<3;i++){
        printf("-------------\n|");
        for(j=0;j<3;j++){
            printf(" %c |",grid[i][j]);
        }
        printf("\n");
    }
    printf("-------------\n");
}
int check_win(char grid[3][3])
{
    int i,a0[8]={0},ax[8]={0};
    for(i=0;i<3;i++){
        if(grid[0][i]=='O'){ a0[0]++; }
        if(grid[1][i]=='O'){ a0[1]++; }
        if(grid[2][i]=='O'){ a0[2]++; }
        if(grid[i][0]=='O'){ a0[3]++; }
        if(grid[i][1]=='O'){ a0[4]++; }
        if(grid[i][2]=='O'){ a0[5]++; }

        if(grid[i][i]=='O'){ a0[6]++; }
        if(grid[i][2-i]=='O'){ a0[7]++; }
    }
    for(i=0;i<3;i++){
        if(grid[0][i]=='X'){ ax[0]++; }
        if(grid[1][i]=='X'){ ax[1]++; }
        if(grid[2][i]=='X'){ ax[2]++; }

        if(grid[i][0]=='X'){ ax[3]++; }
        if(grid[i][1]=='X'){ ax[4]++; }
        if(grid[i][2]=='X'){ ax[5]++; }

        if(grid[i][i]=='X'){ ax[6]++; }
        if(grid[i][2-i]=='X'){ ax[7]++; }
    }
    for(i=0;i<8;i++){
        if(a0[i]==3)
            return 1;
    }
    for(i=0;i<8;i++){
        if(ax[i]==3)
            return 2;
    }
    return 0;
}
int play_rockpaperscissor()
{
    int rockpaperscissor(char a,char b);
    char you,comp;
    srand(time(0));
    int number=rand()%100+1;
    if(number<33)
        comp='R';
    else if(number>=33 && number<=66)
        comp='P';
    else if(number>66)
        comp='S';
    printf("choose:");
    scanf("%c", &you);
    printf("\nYOU CHOSE:%c AND COMPUTER CHOSE:%c\n\n",you,comp);
    int result=rockpaperscissor(you,comp);
    if(result==1)
        printf("YOU WON!!");
    else if(result==-1)
        printf("YOU LOSE!!");
    else
        printf("SO GAME DRAW!!");
        return 0;
}
int rockpaperscissor(char a,char b)
{
     if(a==b)
        return 0;
    if(a=='R' && b=='P')
        return -1;
    else if(a=='P' && b=='R')
        return 1;
    if(a=='R' && b=='S')
        return 1;
    else if(a=='S' && b=='R')
        return -1;
    if(a=='P' && b=='S')
        return 1;
    else if(a=='S' && b=='P')
        return -1;
}



