#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    int segreto = rand() % 100 + 1; // genera un numero casuale tra 1 e 100
    int tentativo = 0; // inizializza il tentativo dell'utente
    int risposta; // inizializza la risposta dell'utente
    printf("Indovina il numero segreto tra 1 e 100!\n");
    do {
        printf("Inserisci il tuo numero tentativo: ");
        scanf("%d", &risposta); // legge il tentativo dell'utente
        if (risposta < segreto) {
            printf("il numero giusto è maggiore di quello che hai inserito\n");
            }
        else if ( risposta > segreto){
            printf("il numero giusto è minore di quello che hai inserito\n");
        }
        tentativo++;
    } while (risposta != segreto); //continua finché non indovina)
    printf("il numero segreto è %d, e hai usato %d tentativi per indovinare\n", segreto, tentativo);
}