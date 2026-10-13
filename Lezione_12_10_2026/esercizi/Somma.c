# include <stdio.h>
int main(){
    int x;
    int y; // dichiarazione di variabili da sommare
    int *p=&x; //inizializzare puntatori a int
    int *q=&y; //analogamente per y
    printf("inserire valore della variabile x : "); //chiedere i valori di x e y 
    scanf("%d",p); //usare puntatore per esercizio
    printf("inserire valore della variabile y : ");
    scanf("%d",q);
    int somma=*p+*q; //inizializzare una variabile con calcolo della somma usando puntatori
    int *s=&somma; //inizializzare una variabile anche per la somma
    printf("la somma calcolata con i puntatori è : %d\n",*s); //prova a stampare risultato con il puntatore
    return 0;
}