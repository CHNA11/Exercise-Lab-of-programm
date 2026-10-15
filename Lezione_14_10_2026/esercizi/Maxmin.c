# include <stdio.h>
# include <stdlib.h>

//dichiarazione prototipo delle funzioni
//ricopiati da quello di paridispari
int inserimentodimensione();
void inserimentoarray(int n, int *array);
int cercamax(int n, int* array);
int cercamin(int n, int* array);
int indmax(int n, int* array);
int indmin(int n, int* array);

int main(){
    int n; //dichiarazione variabile per dimensione
    //chie
    do {
        n=inserimentodimensione();
    } while( n<1 || n>100); //richiedere finché sia legale il valore
    //allocazione dinamico
    int *array=(int *) malloc(n*sizeof(int));
    //controllo
    if (array==NULL){
        printf("allocazione insuccesso");
        return 1;
    }
    //richiama funzione per inserire
    inserimentoarray(n,array);
    //stampare risultati
    printf("il valore massimo presenti nell'array è : %d\n",cercamax(n,array));
    printf("il valore minimo presenti nell'array è : %d\n",cercamin(n,array));
    printf("il valore massimo presenti nell'array si trova nella posizione : %d\n",indmax(n,array));
    printf("il valore minimo presenti nell'array si trova nella posizione : %d\n",indmin(n,array));
    //liberazione
    free(array);
}


int inserimentodimensione(){
    int n; //dichiarazione variabile
    printf("inserisci quantità di numeri da inserire con massimo 100 : ");
    scanf("%d",&n); //lettura da tastiera
    return n;
}

void inserimentoarray(int n,int* array){
    for (int i=0; i<n; i++){ //inserire elementi con ciclo
        printf("inserisci numero nella posizione %d : ", i+1);
        scanf("%d",&array[i]); //array è un puntatore ma array[i] è un valore
    }
}

int cercamax(int n, int *array){ 
    //assumere max sia primo
    int max=array[0];
    for(int i=0; i<n; i++){
        if (array[i]>max){
            max=array[i];//altrimenti cambia
        }
    }
    return max;
}

int cercamin(int n, int *array){ //analoga a cercamax
    int min=array[0];
    for(int i=0; i<n; i++){
        if (array[i]<min){
            min=array[i];
        }
    }
    return min;
}

int indmax(int n, int* array){ //analoga a cercamax
    int indmax=0;
    for(int i=0; i<n; i++){
        if(array[indmax]<array[i]){
            indmax=i;
        }
    }
    return indmax+1;
}
int indmin(int n, int* array){ //analoga a cerca max
    int indmin=0;
    for(int i=0; i<n; i++){
        if(array[indmin]>array[i]){
            indmin=i;
        }
    }
    return indmin+1;
}