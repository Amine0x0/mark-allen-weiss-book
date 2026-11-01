#include <stdio.h>
#include <math.h>

int prove(int resA, int resB){
    printf("%d\n%d\n", resA, resB);
    return resA == resB;
}
void sep(){
    printf("----------------\n");
}
// x^a * x^b == x^(a+b)
void theorem1(int x, int a, int b){
    printf("// x^a * x^b == x^(a+b)\n");
    if (prove((int)(round(pow(x, a) * pow(x, b))), (int)(round(pow(x, a + b)))))
        printf("theorem1\n");
    else
        printf("not equal.\n");
}
// x^a / x^b == x^(a-b)
void theorem2(int x, int a, int b){
    printf("// x^a / x^b == x^(a-b)\n");
    int formula1 = pow(x,a) / pow(x,b);
    int formula2 = pow(x, (a - b));

    if (prove(formula1, formula2))
        printf("theorem2\n");
    else
        printf("not equal\n");
}
// x^a * x^b = x ^ (a * b)
void theorem3(int x, int a, int b){
    printf("// x^a * x^b = x ^ (a * b)\n");
    int formula1 = pow((pow(x, a)), b);
    int formula2 = pow(x, (a * b));

    if (prove(formula1, formula2))
        printf("theorem3\n");
    else
        printf("not equal\n");
}
// x^n + x^n = 2(x ^ n) != x ^ 2n
void theorem4(int x, int n){
    printf("// x^n + x^n = 2(x ^ n) != x ^ 2n\n");
    int formula1 = pow(x,n) + pow(x, n);
    int formula2 = 2 * (pow(x,n));

    if (prove(formula1, formula2))
        printf("theorem4\n");
    else
        printf("not equal\n");
}

// 2 ^ n + 2 ^ n = 2 ^ (n + 1)
void theorem5(int n){
    printf("// 2 ^ n + 2 ^ n = 2 ^ (n + 1)\n");
    int formula1 = pow(2, n) + pow(2, n);
    int formula2 = pow(2, (n + 1));

    if (prove(formula1, formula2))
        printf("theorem5\n");
    else
        printf("not equal\n");
}

int main(){
    theorem1(4, 5, 6);
    sep();
    theorem2(4, 5, 6);
    sep();
    theorem3(2, 2, 2);
    sep();
    theorem4(4,5);
    sep();
    theorem5(9);
    return (0);
}