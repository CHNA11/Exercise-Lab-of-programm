# include <stdio.h>
int main(){
    int pos=0; //dichiare una variabile per numeri positivi prima di cicli
    int neg=0; //dichiare una variabile per numeri negativi prima di cicli
    int nullo=0; //dichiare una variabile per numeri nulli prima di cicli
    int intero; //dichiare variabile da inserire
    for (int i=0; i<10; i++) {
        printf("dammi un numero intero :");
        scanf("%d",&intero); //inserire numero dato da utente
        printf("\n");
        if (intero>0) 
        {
            pos++; //incrementa variabile per numeri positivi
        }
        else if (intero<0) 
        {
            neg++; //incrementa variabile per numeri negativi
        }
        else   //un intero non maggiore o minore di 0 è per forza 0
        {
            nullo++; //incrementa variabile per numeri nulli
        }
    }
    printf("In tutto hai inserito %d numeri positivi, %d numeri negativi e %d numeri nulli\n",pos,neg,nullo);
}