#include <stdio.h>

int main() {
    int A, B;
    
    scanf("%d %d", &A, &B);
    
    printf("%.10lf", A / (double)B);
    
    return 0;
}