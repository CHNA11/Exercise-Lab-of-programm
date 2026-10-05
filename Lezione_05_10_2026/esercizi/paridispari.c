# include <stdio.h>
int main(){
    int dimensione; //dichiarare una variabile per dimensione dell'array
    do{
    printf("dammi il dimensione dell'array che vuoi inserire : "); //chiedere dimensione
    scanf("%d",&dimensione);
    printf("\n");
    } while(dimensione<=0);
    int numeri[dimensione]; // dichiarare variabile con lunghezza data
    int contpari=0; //inizializzare variabile per contare pari
    int contdisp=0; //inizializzare variabile per contare dispari
    for(int i=0; i<dimensione; i++){
        printf("dammi il numero nella posizione %d : ", i);
        scanf("%d", &numeri[i]);
        printf("\n");
        if (numeri[i]%2==0){ //controllare se è pari o dispari
            contpari++;
        }
        else{
            contdisp++;
        }
    }
    float parperc = (float)contpari*100/dimensione; //considerare percentuale dei pari
    float dispperc = (float)contdisp*100/dimensione; //considerare perccentuale dei dispari
    printf("Nei numeri inseriti contiene %.2f %% di numeri pari e %.2f %% di numeri dispari\n", parperc,dispperc);
    return 0;
}