# include <stdio.h>
# include <stdlib.h> // libreria per malloc
int main(){
    int n; // dichiarare variabile per dimensione dell'array
    printf("dimmi quanti numeri intendi inserire : ");
    scanf("%d",&n);
    
    //allocare dinamicamente un array
    int *arr_1 = (int*) malloc(n * sizeof(int));
    //allocare il secondo da precedere copia
    int *arr_2 = (int*) malloc(n*sizeof(int));
    //controllare allocazione
    if(arr_1==NULL || arr_2==NULL ){
        printf("allocazione dinamica insuccesso\n");
        return 1;
    }
    //inizializzare dei puntatori
    int *p=arr_1; //ricordare che arr_1 è già un puntatore
    int *q=arr_2;
    //chiedere in input numeri nel primo array
    for(int i=0; i<n; i++){
        printf("inserisci il numero nello posizione %d : ", i+1);
        scanf("%d",p);
        *q=*p;
        *p++;
        *q++;
    }
    for(int j=0; j<n; j++){
        printf("l'elemento nella posizione %d del arr_1 è: %3d  del arr_2 è : %3d\n",j+1,arr_1[j],arr_2[j]);
    }
    //liberare la memoria
    free(arr_1);
    free(arr_2);
    return 0;
}