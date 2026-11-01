#include <math.h>
#include <stdio.h>

void syracuse(int number) {
    if (number == 1) {
        printf("%d\n", number);
        return;
    }

    printf("%d -> ", number);

    if (number % 2 == 0) {
        syracuse(number / 2);
    } else {
        syracuse((3 * number) + 1);
    }
}

int main(){
    syracuse(5556);
}