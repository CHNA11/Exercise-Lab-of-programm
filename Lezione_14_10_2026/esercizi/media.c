# include <stdio.h>
# include <stdlib.h>

//dichiarazione funzione prototipo
void inserimento(int **array);
void mediariga(int **array);
void mediacolonna(int **array);

int main(){
    //allocazione dinamico array da inserire
    int **array=(int **) malloc(5*sizeof(int *));
    //controllo
    if(array==NULL){
        printf("allocazione insuccesso");
        return 1;
    }
    //chiede di inserire valori nell'array
    inserimento(array);
    //calcola media di ogni riga
    mediariga(array);
    //calcola media di ogni colonna
    mediacolonna(array);
    //liberazione ogni riga per cicli
    for(int i=0; i<5; i++){
        free(array[i]);
    }
    //liberazione totale
    free(array);
    return 0;
}

void inserimento(int **array){
    for (int i=0; i<5;i++){
        //allocazione dinamico ogni riga
        array[i]=(int*) malloc(5*sizeof(int));
        if (array[i]==NULL){ //controllo di ogni riga
            printf("allocazione insuccesso");
            exit(1);
        }
    }
    //inserimento valori
    for(int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            printf("inserisci valore nella riga %d e colonna %d : ",i+1,j+1);
            scanf("%d",&array[i][j]);
        }
    }
}

void mediariga(int **array){
    for(int i=0; i<5; i++){
        int somma=0; //inizializzare somma di ogni riga
        for(int j=0; j<5; j++){
            somma=somma+array[i][j];
        }
        //dopo somma stampa media
        printf("la media della riga %d è %.2f\n", i+1, (float)somma/5);
    }
}

void mediacolonna(int **array){
    for(int j=0; j<5; j++){
        int somma=0; //inizializzazione di somma per ogni riga
        for(int i=0; i<5; i++){
            somma=somma+array[i][j]; //sommare scorrendo riga per ogni colonna
        }
        //dopo somma stampa media della colonna
        printf("la media della colonna %d è %.2f\n", j+1, (float)somma/5);
    }
}