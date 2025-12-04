#include <stdio.h>

int main() {
    int n;
    printf("CH.SC.U4CSE24150\n");
    printf("Enter the number of Fibonacci terms to generate: ");
    
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 0;
    }

    int t1 = 0;
    int t2 = 1; 

    int nextTerm;

    printf("Fibonacci Series (first %d terms):\n", n);

    if (n >= 1) {
        printf("%d", t1);
    }
    if (n >= 2) {
        printf(", %d", t2);
    }

    for (int i = 3; i <= n; ++i) {
        nextTerm = t1 + t2;
        
        if (nextTerm < t2) { 
            printf("\n\n(Note: Integer overflow occurred at term %d. Output may be inaccurate from this point.)\n", i);
            break; 
        }

        printf(", %d", nextTerm);
        
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");

    return 0;
}