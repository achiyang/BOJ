#include <stdio.h>

long long factorial(int n){
    if (n < 2){
        return 1;
    }
    
    return n * factorial(n - 1);
}

int main() {
    int N;
    
    scanf("%d", &N);
    
    printf("%lld\n", factorial(N));
    
    return 0;
}