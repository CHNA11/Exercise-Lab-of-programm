# include <stdio.h>
# include <stdlib.h>
int main(){
    int n; //dichiarare dimensione della matrice, riga
    do{
        printf("inserisci numero di riga della matrice : "); //chiedere a utente
        scanf("%d",&n);
    } while(n<1); //non deve essere negativo o nullo
    int m; //dichiarare dimensione della matrice, colonna
    do{
        printf("inserisci numero di colonna della matrice : "); //chiedere a utente
        scanf("%d",&m);
    } while(m<1); //non deve essere negativo o nullo
    int **mat=(int **) malloc(n*sizeof(int *)); //allocare matrice con prima la riga
    if(mat==NULL){ //controllo
        printf("allocazione insuccesso\n");
        return 1;
    };
    for(int i=0; i<n; i++){ //allocare ad ogni riga corrispondente colonna
        mat[i]=(int *) malloc(m*sizeof(int));
        if(mat[i]==NULL){ //controllo
            printf("allocazione insuccesso\n");
            return 1;
        };
    };
    int somma=0; //inizializzare variabile della somma
    for(int i=0; i<n; i++){  //doppio ciclo per inserimento di dati
        for(int j=0; j<m; j++){
            printf("inserisci valore nella riga %d colonna %d : ",i+1,j+1);
            scanf("%d",&mat[i][j]); //mat ij è un numero non puntatore
        };
    };
    for(int i=0; i<n; i++){
        int *q=mat[i]; //mat i è un puntatore
        for(int j=0; j<m; j++){
            somma=somma+*q;
            q++;
        }
        free(mat[i]); //liberazione
    }
    free(mat); //liberazione
    //stampa risultato
    printf("la somma degli elementi è : %d\n",somma);
    return 0;
}