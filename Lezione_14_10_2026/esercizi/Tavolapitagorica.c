# include <stdio.h>
# include <stdlib.h>

//dichiarazione funzioni prototipo
void calcola(int ** array);
void stampa(int ** array);

int main(){
    //allocazione dinamico, puntatori dei puntatori
    int ** array=(int**) malloc(10*sizeof(int*));
    //controllo
    if(array==NULL){
        printf("allocazione insuccesso");
        return 1;
    }
    //richiama funzione per inserire valori della tavola
    calcola(array);
    //stampare tavola calcolata
    stampa(array);
    //liberazione
    free(array);
    return 0; 
}

void calcola(int **array){
    //cilco di allocazione
    for(int i=0; i<10; i++){
        array[i]=(int*) malloc(10*sizeof(int));
        //controllo
        if(array[i]==NULL){
            printf("allocazione insuccesso");
            exit(1);//uscita da tutta programma
        }
    }
    //calcolo elementi della tavola
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            array[i][j]=(i+1)*(j+1);
        }
    }
}

void stampa(int **array){
    //stampa risultato
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("%4d",array[i][j]); //tutti gli valori di stessa riga allineata
        }
        printf("\n"); //dopo ogni riga vada a capo
        free(array[i]); //liberazione per ogni riga
    }
}