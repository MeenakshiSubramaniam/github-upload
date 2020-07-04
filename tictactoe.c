#include<stdio.h>
#include<string.h>
#include<stdlib.h>
  char a[3][3];int i,j,t=0;
      char ch;
  int checkDiagonal(char a[3][3])
  {
        if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&(a[0][0]=='X'||a[0][0]=='O'))
        {
          if(a[0][0]=='X')
           ch='X';
          else
           ch='O';
           return 1;
        }
        if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&(a[0][2]=='X'||a[0][2]=='O'))
        {
          if(a[0][2]=='X')
           ch='X';
          else
            ch='O';
          return 1;
        }
        else
        return -1;
  }

  int checkStraight(char a[3][3])
  {
      for(i=0;i<3;i++)
      {
                 if(a[i][0]==a[i][1]&&a[i][1]==a[i][2]&&(a[i][0]=='X'||a[i][0]=='O'))
                {
                 if(a[i][0]=='X')
                   ch='X';
                  else
                   ch='O';
                 return 1;
                }
        }
      return -1;
  }

  int checkDown(char a[3][3])
  {
      for(i=0;i<3;i++)
      {
            if(a[0][i]==a[1][i]&&a[1][i]==a[2][i]&&(a[0][i]=='X'||a[0][i]=='O'))
                {
                    if(a[0][i]=='X') ch='X';
                    else                  ch='O';
                  return 1;
                }
      }
      return -1;
  }
  void showBoard(char a[3][3])
{
    printf("\n\n");
   printf("\t\t\t  %c | %c  | %c  \n", a[0][0],   a[0][1], a[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", a[1][0],
                             a[1][1], a[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", a[2][0],
                            a[2][1], a[2][2]);
 return;
}
   int main()
   {
          showBoard(a);
     int d=0,full=0,count=9;
          for(i=0;i<3;i++)
            {
               for(j=0;j<3;j++)
               {
                  a[i][j]=32;//printf("%c",game[i][j]);
               }
          }
        for(i=0;i<count;i++)
        {
         printf("Enter Player index x,y and value\n");
        scanf("%d %d %c",&i,&j,&ch);
        if((ch!='X'&&ch!='O')||(i>3||i<1)||(j>3||j<1)||a[i-1][j-1]=='X'||a[i-1][j-1]=='O')
        {printf("Invalid Input Try Again\n");++count;continue;}
         a[i-1][j-1]=ch;++full;
         showBoard(a);
          d=checkDiagonal(a);
         if(d==1){   printf("%c wins\n",ch);break;}
         d=checkStraight(a);
         if(d==1){printf("%c wins\n",ch);break;}
         d=checkDown(a);
         if(d==1){printf("%c wins\n",ch);break;}
         if(full==9){
        printf("Draw");break;}
        }
  return 0;
  }
