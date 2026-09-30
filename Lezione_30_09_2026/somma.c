#include <stdio.h>
int main(){
    int somma=0; //dichiarare una variabile per somma
    int intero; //dichiarare variabile da inserire
    printf("se inserisci 0 si termina calcolo della somma \n");
    do {
        printf("dammi un numero intero : ");
        scanf("%d",&intero); //inserire numero dato da utente
        printf("\n");
        somma=somma+intero; //incrementa variabile per somma
    } while (intero!=0); // finché non inserisce 0
    printf("la somma dei numeri inseriti è : %d\n",somma); //stampa somma
}