# include <stdio.h>
# include <stdlib.h>
int main(){
    int n=3; //inizializzare un variabile per numero di nomi
    int lung=30; //inizializzare una variabile per lunghezza di nomi
    char **array=(char **) malloc(n*sizeof(char *)); //alloca un array di puntatori pre dopo
    if (array==NULL){ //controllare allocazione
        printf("allocazione insuccesso\n");
        return 1;
    }
    for (int i=0; i<n; i++){
        array[i]=(char*) malloc(lung*sizeof(char)); //ad ogni componente allocare per stringhe
        if (array[i]==NULL){ //controllo
            printf("allocazione insuccesso\n");
            return 1;
        }
        else{
            printf("inserisci il nome nella posizione %d : ",i+1); //chiede all'utente
            scanf("%s",array[i]);
        };
    };
    for(int j=0; j<n; j++){
        printf("il nome nella posizione %d è : %s\n",j+1,array[j]); //stampare risultato
        free(array[j]); //liberare per ogni componente del array
    };
    free(array); //liberare l'array se stesso
    return 0;
}