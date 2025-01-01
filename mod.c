#include <stdio.h>
long long modExponentiation(long long base, long long power, long long modulus) {
    long long result = 1; 
    base = base % modulus;  
    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        power = power / 2;  
    }
    return result;
}

int main() {
    long long base, power, modulus;
    
    printf("Enter three numbers base, power, and modulus: ");
    scanf("%lld %lld %lld", &base, &power, &modulus);
    if(modulus<0 || power<=1)
    {
        printf("modulus should be >1 and power should be >=0");
        return 0;
    }
    long long result = modExponentiation(base, power, modulus);
    printf("Result of %lld^%lld %% %lld = %lld\n", base, power, modulus, result);
    
    return 0;
}
