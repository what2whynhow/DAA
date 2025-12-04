#include<stdio.h>
int main(){
int n;
int sum=0;
printf("CH.SC.U4CSE24150\n");
printf("Enter value of n:");
scanf("%d",&n);
for(int i=1;i<n+1;i++){
sum+=i*i;
}
printf("The sum of squares of first %d natural numbers is %d\n",n,sum);
}