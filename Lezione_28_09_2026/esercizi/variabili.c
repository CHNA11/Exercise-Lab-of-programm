# include <stdio.h>
# include <windows.h> //per riconoscere è

int main(){
    SetConsoleOutputCP(65001); // trasformare forma in UTF-8
    int intero;  // dichiarazione di variabili
    float floating;
    char carattere;
    double doppia;
    _Bool un_bool;
    intero = 5;  // assegnazione di variabili
    floating = 1.2f;
    carattere = 'c';
    doppia = 16.0;
    un_bool = 1;
    printf("variabile di tipo int è %d\n", intero); //stampare valori assegnati
    printf("variabile di tipo float è %f\n", floating);
    printf("variabile di tipo char è %c\n", carattere);
    printf("variabile di tipo double è %lf\n", doppia);
    printf("variabile di tipo bool è %d\n", un_bool); // si esce con 1, perché?
return 0;
}