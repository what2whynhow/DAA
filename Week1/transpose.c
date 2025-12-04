#include<stdio.h>
int main(){
printf("CH.SC.U4CSE24150\n");
int mat[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int trans[3][3]={{0,0,0},{0,0,0},{0,0,0}};
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
printf("Enter value of [%d][%d]:",i+1,j+1);
scanf("%d",&mat[i][j]);
}
}
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
trans[j][i]=mat[i][j];
}
}
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
printf("%d",trans[i][j]);
}
printf("\n");
}
}