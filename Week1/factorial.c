#include<stdio.h>
int factorial(int n){
if(n==1){
return 1;
}
else{
return n*factorial(n-1);
}
}
int main(){
int n;
printf("CH.SC.U4CSE24150\n");
printf("Enter value of n:");
scanf("%d",&n);
printf("The factorial of %d is %d\n",n,factorial(n));
}
