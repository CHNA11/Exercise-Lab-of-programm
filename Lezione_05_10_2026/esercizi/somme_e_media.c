# include <stdio.h>
int main() {
    int numeri[5]; // dichiarare un variabile di array da inserire
    int somma = 0; // inizializzare variabile per somma
    float media; //dichairare variabile per media che può non essere intera
    printf("Si chiede di inserire 5 numeri interi e non oltre\n");
    for(int i=0; i<5; i++)
    {
        printf("Inserisci un numero intero: ");
        scanf("%d", &numeri[i]);
        printf("\n");
        somma=somma+numeri[i]; // ogni volta aggiungo quello inserito
    }
    media = somma/5.0; // calcolo media
    printf("La somma dei numeri inseriti è: %d\n", somma); // stampa risultato
    printf("La media dei numeri inseriti è: %.2f\n", media);
    return 0;
}