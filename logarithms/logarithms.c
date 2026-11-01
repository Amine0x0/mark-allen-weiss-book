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
    printf("- %f\n- %f\n", resA, resB);
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
    printf("// x ^ a = b if log.x B = a\n");
    double a = baseLog(x, b);
    double formula1 = pow(x, a);
    double formula2 = b;

    if (prove(formula1, formula2))
        printf("theorem1\n");
    else
        printf("not equal\n");
}

// log.a B = log.c B / log.c A
// ln(1) = 0 
void theorem2(int a, int b, int c){
    printf("log.a B = log.c B / log.c A\n");
    if (a > 0 && b > 0 && c > 0 && a != 1){
        double formula1 = baseLog(a, b);
        double formula2 = baseLog(c, b) / baseLog(c, a);
        if (prove(formula1, formula2))
            printf("theorem2\n");
        else
            printf("not equal\n");
    }
}

// we try to prove log.a B = log.c B / log.c A
    // lets suppose that

    // x = log.c B
    // y = log.c A
    // z = log.a B

    //by the definition of logarithms
    // [x ^ a = b if log.x B = A]
    // 
    // log.c B = x
    // so C ^ x = B
    // and C ^ y = A
    // and A ^ z = B

    // so B = C ^ x = A ^ z
    // since  A = c ^ y
    // (C ^ y) ^ z = B
    // C ^ (y * z) = B
    // and since C ^ x = B
    // C ^ x = C ^ (y * z)
    // x = (y * z)
    // z = x / y
    // so we proved log.a B = log.c B / log.c A 


// logAB = log A + log B
void theorem3(int a, int b){
    printf("// logAB = log A + log B\n");
    if (a > 0 && b > 0 && a != 1){
        double formula1 = log(a * b);
        double formula2 = log(a) + log(b);
        if (prove(formula1, formula2))
            printf("theorem3\n");
        else
            printf("not equal\n");
    }
}

// we try to prove logAB = logA + logB
// let log A = x
// let log B = y
// and logAB = z
// assuming were gonna use base 2
// since we know that log.x A = B then x ^ b = A
// since log.2 A = x
// then 2 ^ x = A
// and 2 ^ y = B
// so log( (2 ^ x) * (2 ^ y) = z)
// log.2 (2 ^ (x + y)) = z
// 2 ^ z = 2 ^ (x + y)
// z = x + y
// meaning logAB = log A + logB


//log A/B = log A − log B
void theorem4(double a ,double b){
    printf("log A/B = log A − log B\n");
    double formula1 = log(a / b);
    double formula2 = log(a) - log(b);

    if (prove(formula1, formula2))
        printf("theorem4\n");
    else
            printf("not equal\n");
    return ;
}

int main(){
    theorem1(2, 3);
    sep();
    theorem2(4, 5, 6);
    sep();
    theorem3(5,6);
    sep();
    theorem4(4,5);
    sep();
    return (0);
}