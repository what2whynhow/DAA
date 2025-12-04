#include<stdio.h>
int sum(int n){
int sum=0;
for(int i=1;i<n+1;i++){
sum+=i;
}
return sum;
}
int main(){
printf("CH.SC.U4CSE24150\n");
int n;
printf("Enter value of n:");
scanf("%d",&n);
printf("The sum of first %d natural numbers is %d\n",n,sum(n));
}
