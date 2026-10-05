# include <stdio.h>
int main() {
    // invece di memorizzare 10 valori in variabili differenti, array è una struttura dati che contiene un numero fisso di elementi
    // con tutti i dati del stesso tipo.
    // per ogni casella ha un indice che parte da 0, quello di indice 6 è la settima casella.
    // accesso casuale, ovvero dato un indice, le altre vengono saltate
    // dichiarazione
    int numeri[10]; // un variabile di array con 10 casselle
    // iterazione (generalmente for)
    // bisogna prendere attenzione al range della memoria, se si supera, si accede a memoria qualsiasi elemento possibile,
    // perché memorizza in modo random, e crashia il programma.
    printf("Inserisci 10 numeri\n");
    for (int i = 0; i<10; i++){
        printf("Inserisci un numero: ");
        scanf("%d", &numeri[i]);
    }
    // esiste ricerca lineare, e ricerca binaria, ma funziona solo vettore ordinato
    // per incremento di un array, unico modo è creare una nuova array e immergere dentro quello vecchio
    // per multiarray abbiamo matrice.
    // stringhe sono array di caratteri, in c è più particolari, è vettore di itpo char che termina con '\0'
    // come vantaggio, ha librerie ad hoc per manipolare stringhe.
    // string.h con delle codice tipo strlen ecc.
    
}