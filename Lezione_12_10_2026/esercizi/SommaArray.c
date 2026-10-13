# include <stdio.h>
int main(){
    int numero;//dichiarare quantità di numeri
    do{ //chiedere all'utente
        printf("dimmi quanti numeri vuoi inserire, deve essere compreso tra 1 e 100 :");
        scanf("%d",&numero);
    } while(numero<1 || numero>100); //controllare il numero sia in range
    int array[numero]; //dichairare array del numero
    for(int i=0; i<numero; i++){
        printf("il valore del numero nella posizione %d è : ",i+1); //chiedere all'utente numero di ogni posizione
        scanf("%d",&array[i]);
    }
    int *p=array; //inzializzare un puntatore per array che punta per primo
    int somma=0; //inizializzare una variabile per la somma
    for(int j=0; j<numero; j++){
        somma=somma+*p; //sommare con puntatore
        *p++; //passare al posizione di prossimo elemento nell'array
    };
    printf("la somma è : %d\n",somma);
    return 0;
}