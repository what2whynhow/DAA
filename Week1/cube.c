#include<stdio.h>
int main(){
printf("CH.SC.U4CSE24150\n");
int n;
int sum=0;
printf("Enter value of n:");
scanf("%d",&n);
for(int i=1;i<n+1;i++){
sum+=i*i*i;
}
printf("The sum of cubes of first %d natural numbers is %d\n",n,sum);
}