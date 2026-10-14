# include <stdio.h>
# include <stdlib.h>
int somma(int numeri[],int n);
int richiesta(int numeri[],int n);
float media(int somma, int n);
int main(){
    //dichiarare lunghezza del vettore
    int n=5;
    // allocazione dinamico vettore
    int *vett= (int *) malloc (n*sizeof(int));
    //controllo
    if (vett==NULL){
        printf("allocazione insuccesso");
        return 1;
    };
    richiesta(vett,n);
    int som=somma(vett,n);
    printf("somma dei numeri inseriti è : %d",som);
    printf("media dei numeri inseriti è : %.2f",media(som,n));
}

int richiesta(int numeri[], int n){
    for(int i=0; i<n; i++){
        printf("inserisci numero nella posizione %d : ",i);
        scanf("%d",numeri[i]);
    };
};

int somma(int numeri[],int n){
    int somma=0;
    for (int i=0; i<n; i++){
        somma=somma+numeri[i];
    };
    return somma;
};

float media(int somma, int n){
    return (float) somma/n;
};