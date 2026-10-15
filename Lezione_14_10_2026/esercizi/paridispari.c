# include <stdio.h>
# include <stdlib.h>

//dichiarazione prototipo delle funzioni
int inserimentodimensione();
void inserimentoarray(int n, int *array);
int pari(int * array, int n);
int dispari(int *array, int n);

int main(){
    int n; //dichiarazione dimensione
    //chiede dimensione di array
    do {
        n=inserimentodimensione();
    } while(n<1); //controlla che sia legale
    //allocazione dinamico
    int *array=(int *) malloc(n*sizeof(int));
    //controllo
    if(array==NULL){
        printf("allocazione insuccesso");
        return 1;
    }
    //richiama funzione per inserire
    inserimentoarray(n, array);
    // stampa risultati
    printf("nei numeri inseriti ci sono %d pari e %d dispari\n",pari(array,n),dispari(array,n));
    printf("ci sono %.1f %% di numeri pari e %.1f %% di numeri dispari\n", (float)pari(array,n)*100/n, (float)dispari(array,n)*100/n);
    //liberazione memoria
    free(array);
}

int inserimentodimensione(){
    int n; //dichiarazione variabile
    printf("inserisci quantità di numeri da inserire : ");
    scanf("%d",&n); //lettura da tastiera
    return n;
}

void inserimentoarray(int n,int* array){
    for (int i=0; i<n; i++){ //inserire elementi con ciclo
        printf("inserisci numero nella posizione %d : ", i+1);
        scanf("%d",&array[i]); //array è un puntatore ma array[i] è un valore
    }
}

int pari(int* array, int n){
    int cont=0; //dichiarazione contatore pari
    for (int i=0; i<n; i++){
        if (array[i] %2 == 0){ //mod 2 =0 allora è pari
            cont++; //incremento
        };
    };
    return cont;
}
//si può evitare, basta fare numero totale n - numero di pari
int dispari(int* array, int n){ //ricopio da funzione pari
    int cont=0;
    for (int i=0; i<n; i++){
        if (array[i] %2 == 1){ //unica differenza mod2=1
            cont++; 
        };
    };
    return cont;
}
