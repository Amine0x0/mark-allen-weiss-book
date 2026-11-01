//x^A = B if log.x B = A
// log is the inverse of exponents basically
//In computer science, all logarithms are to the base 2 unless specified otherwise.
// log.a B = log.c B / log.c A; for A,B,C > 0 && A != 1
// log() in c in logarithme naturel basically log(e) with e = constante d'euler
// to calculate log.x A you have to do ln(A)/ln(x)

#include <stdio.h>
#include <math.h>

double euler = 2.718281828459045;

int prove(double resA, double resB){
    printf("%f\n%f\n", resA, resB);
    return fabs(resA - resB) < 1e-9;
}

void sep(){
    printf("----------------\n");
}

double baseLog(int base, int value){
    return (log(value) / log(base));    
}

// x ^ a = b if log.x B = a
void theorem1(int x, int b){
    double a = baseLog(x, b);
    double formula1 = pow(x, a);
    double formula2 = b;

    if (prove(formula1, formula2))
        printf("theorem1\n");
    else
        printf("not equal\n");
}

// log.a B = log.c B / log.c A
void theorem2(int a, int b, int c){
    if (a > 0 && b > 0 && c > 0){
        double formula1 = baseLog(a, b);
        double formula2 = baseLog(c, b) / baseLog(c, a);
        if (prove(formula1, formula2))
            printf("theorem2\n");
        else
            printf("not equal\n");
    }
}

int main(){
    theorem1(2, 3);
    sep();
    theorem2(4, 5, 6);
    sep();

    return (0);
}