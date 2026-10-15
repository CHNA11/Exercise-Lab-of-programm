# include <stdio.h>
# include <stdlib.h>
// dichiarazione prototipo delle funzione
int somma(int numeri[],int n); 
int richiesta(int numeri[],int n);
float media(int somma, int n);
//passare a main
int main(){
    //inizializzare lunghezza del vettore, per modificare lunghezza basta cambiare questo valore
    int n=5;
    // allocazione dinamico vettore
    int *vett= (int *) malloc (n*sizeof(int));
    //controllo
    if (vett==NULL){
        printf("allocazione insuccesso");
        return 1;
    };
    //richiama funzione di chiedere a utente per inserire numeri
    richiesta(vett,n);
    //stampare risultato della somma con funzione somma
    printf("somma dei numeri inseriti è : %d\n",somma(vett,n));
    //stampare risultato della media usando parametro anche risultato della funzione somma
    printf("media dei numeri inseriti è : %.2f\n",media(somma(vett,n),n));
    //liberazione
    free(vett);
}

int richiesta(int numeri[], int n){
    //richiesta di valori
    for(int i=0; i<n; i++){
        printf("inserisci numero nella posizione %d : ",i+1);
        scanf("%d",&numeri[i]); //numeri[i] non sono puntatori
    };
};

int somma(int numeri[],int n){
    int somma=0; //inizializzare valore per somma
    for (int i=0; i<n; i++){
        somma=somma+numeri[i]; //aggiungere ad ogni iterazione
    };
    return somma; //ridare come risultato la somma
};

float media(int somma, int n){ //tipo float perché è possibile dare risultato con le virgole
    return (float) somma/n; //passare a tipo float
};