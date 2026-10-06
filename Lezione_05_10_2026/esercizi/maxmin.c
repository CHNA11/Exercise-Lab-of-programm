# include <stdio.h>
int main(){
    int N; //dichiara una variabile per dimensione dell'array
    do{
        printf("dammi la dimensione dell'array che vuoi inserire, compreso tra 1 e 100 : ");
        scanf("%d", &N);
        printf("\n");
        if(N>100){ //controllare se ha inserito un numero superiore
            printf("si prega di inserire un numero intero non superiore a 100");
        }
        else if(N<1){ //oppure un numero negativo
            printf("si prega di inserire un numero intero positivo");
        }
    } while(N>100 || N<1);
    int interi[N]; //dichiarare variabile per inserire numeri
    int indmin=0; //inizializzare variabile per indice di min
    int indmax=0; //inizializzare variabile per indice di max
    for (int i=0; i<N; i++){
        printf("dammi il numero intero nella posizione %d : ", i); //si chiede di inserire numeri nell'array
        scanf("%d", &interi[i]);
        printf("\n");
        if (interi[i]>interi[indmax]){ //si assume che al posizione 0 abbia massimo
            indmax=i; //se non è massimo allora prende quello più grande
        }
        if (interi[i]<interi[indmin]){ //analogamente per minimo
            indmin=i; //cambio di indice per valore minimo
        }
    }
    printf("il valore massimo che hai inserito nell'array è %d e si trova nella posizione %d\n",interi[indmax],indmax); //stampa risultati
    printf("il valore minimo che hai inserito nell'array è %d e si trova nella posizione %d\n",interi[indmin],indmin);
    return 0;
}