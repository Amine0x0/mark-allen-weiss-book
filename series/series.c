#include <math.h>
#include <stdio.h>

int prove(double resA, double resB){
    printf("- %f\n- %f\n", resA, resB);
    return fabs(resA - resB) < 1e-9;
}

void sep(){
    printf("----------------\n");
}

// sigma i = 0, stops at n , body: 2i == 2 ^ (n + 1) - 1
void theorem1(double i, double n, double A){
    int body = 0.0; 
    for (i; i <= n; i++){
        body += pow(A, i);
    }
    
    double equivalent = (pow(A, (n + 1)) - 1) / (A - 1);

    if (prove(equivalent, body))
        printf("theorem1\n");
    else{
        printf("not equivalent\n");
    }
    return ;
}

//proof
// lets prove that S = 1 + A + A ^ 2 + A ^ 3 + A ^ 4 .... == 2 ^ (n + 1) - 1
// if we multiply both sides with A, we have AS = A + A ^ 2 + A ^ 3 ....
// which means that AS = A + A ^ 2 ... A ^ (n + 1)
// which means that S - AS = 1 - A ^ (n + 1)
// S (1 - A) = A - A ^ (n + 1)
// S = A ^ n + 1 - 1 / A - 1


int main(){
    theorem1(0, 7, 2);
    sep();
}