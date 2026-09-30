# include <stdio.h>
enum ScelteDelloSchermo { //enumerare possibili scelte
    Somma=1,
    Sottrazione,
    Moltiplicazione,
    Divisione,
    Esci
};
int main(){
    int scelta;  //inizializzare una variabile in corrispondenza della scelta
    float x; //inizializzare due variabili per numeri reali da inserire
    float y;
    float risultato; // una variabile per risultato del calcolo
    do {
    printf("1. Somma\n"); //rappresentare il menu
    printf("2. Sottrazione\n");
    printf("3. Moltiplicazione\n");
    printf("4. Divisione\n");
    printf("5. Esci\n");
        printf("scegliere una delle opzione nel menu : "); //chiede di scegliere un opzione
        scanf("%d",&scelta);
        printf("\n");
        if (scelta>=Somma && scelta<=Divisione) { //consideriamo solo casi validi
        printf("dammi due numeri reali: "); //chiedere numeri da operare
        scanf("%f %f",&x,&y);
        printf("\n");
        switch (scelta){ //considerare operazione scelto
            case Somma:
                 risultato=x+y;
                 printf("il risultato dell'operazione è : %.2f\n",risultato);
                 break;
            case Sottrazione :
                risultato=x-y;
                printf("il risultato dell'operazione è : %.2f\n",risultato);
                break;
            case Moltiplicazione:
                risultato=x*y;
                printf("il risultato dell'operazione è : %.2f\n",risultato);
                break;
            case Divisione: 
                if (y==0) { //non è possibile fare divisione con 0
                printf("non puoi dividere per lo zero\n");
                }
                else {
                risultato=x/y;
                printf("il risultato dell'operazione è : %.2f\n",risultato);
                }
                break;
        }
    }
    else if (scelta == Esci) { // solo per escludere dal caso di else
            printf("Uscita dal programma in corso...\n");
        }
        else { //considerare casi  strani
            printf("scelta non valida da riprovare con le opzioni date \n");
        }
    } while(scelta!=Esci);
    return 0;
}