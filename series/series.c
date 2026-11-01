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


int main(){
    theorem1(0, 7, 2);
    sep();
}