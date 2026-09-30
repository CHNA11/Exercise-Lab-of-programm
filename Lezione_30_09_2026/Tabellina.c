# include <stdio.h>
int main(){
    int intero; // dichiara variabile da inserire
    int i=0; // dichiara indice di iterazione
    printf("dammi un numero intero positivo : ");
    scanf("%d",&intero); //inserire numero dato da utente
    printf("\n");
    while (i<10){
        printf("%-2d x %-2d = %-2d\n",intero,i,intero*i); // stampa tabellina
        i++; //incrementa indice di iterazione
    }
}