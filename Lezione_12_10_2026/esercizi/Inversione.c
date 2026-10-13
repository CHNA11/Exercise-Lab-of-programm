# include <stdio.h>
# include <stdlib.h>
int main(){
    int n=5; //inizializzare una variabile per numero di elementi
    int *array=(int*) malloc(n*sizeof(int)); //allocare memoria neccessaria
    if(array==NULL){ //controllo
        printf("allocazione insuccesso\n");
        return 1;
    }
    int *p=array; //inizializzare variabile di supporto
    for (int i=0; i<n; i++){
        printf("inserisci valore nella posizione %d : ",i+1); //chiedere in input
        scanf("%d",p);
        p++;
    };
    int *yarra=(int*)malloc(n*sizeof(int)); //allocare nuovo array a ordine inverso
    if (yarra==NULL){
        printf("allocazione insuccesso");
        return 1;
    };
    int *q=yarra; //inizializzare nuovo puntatore per questo array inverso
    for (int j=0; j<n; j++){
        p--; //tornare indietro poiché nel scorso ciclo ha incrementato di 1
        *q=*p; //mettere nella matrice
        q++; //andare al prossimo di seconda
    };
    for (int k=0; k<n; k++){
        printf("nella posizione %d il primo array ha : %4d il secondo array ha : %4d\n",k+1,array[k],yarra[k]);
    };
    free(array);
    free(yarra);
    return 0;
}