# include <stdio.h>
# include <stdlib.h>
int main(){
    int n; //dichiarazione numero di interi
    printf("quanti numeri intendi inserire : ");
    scanf("%d",&n);
    int *array= (int *) malloc(n*sizeof(int)); //allocazione dinamico
    if(array==NULL){ //controllo
        printf("allocazione insuccesso");
        return 1;
    };
    for(int i=0; i<n; i++){ //chiedere numeri all'utente
        printf("inserisci numero nella posizione %d : ",i+1);
        scanf("%d",&array[i]); //array[i]sono interi e non puntatori
    };
    for(int i=0; i<n-1; i++){
        int *p=array; //puntatore per primo elemento
        int *q=array+1; //puntatore per secondo elemento
        for(int j=0; j<n-1-i; j++){
            if(*p>*q){ //scambio bubble sort
                int temp=*p;
                *p=*q;
                *q=temp;
            };
            p++; //incremento dentro ciclo
            q++;
        };
    }; 
    //stampa risultato
    printf("dopo ordinamento i numeri sono : ");
    for(int i=0; i<n; i++){
        printf("%3d ",array[i]);
    };
    free(array); //liberazione memoria dinamico
    return 0;
}