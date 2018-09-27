#include <stdio.h>

double seno(double angle) {
    double value = angle, term = angle;
    int signal = -1, i = 0;

    for (i = 3; i < 30; i += 2) {
        term = term/((i - 1)*i);
        term *= angle*angle;
        value += signal*term;
        signal *= -1;
    }

    return value;
}

int main() {
    printf("O seno de 1.75 é igual a %.15f\n", seno(1.75));

    return 0;
}
