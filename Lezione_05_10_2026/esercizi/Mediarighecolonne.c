# include <stdio.h>
int main(){
    int matrice[5][5]; //dichiarare una matrice da inserire
    float mediariga[5]; //dichiarare un vettore che inserisce media di ogni riga
    float mediacolonna; //dichiarare una varibaile per media di colonna, perché non c'è bisogno 
    for (int i=0; i<5; i++){
        int somma=0; //inizializzare somma
        for (int j=0; j<5; j++){
            printf("inserisci elemento della matrice nella riga %d e colonna %d : ", i+1, j+1); //chiede di inserire elementi
            scanf("%d", &matrice[i][j]);
            printf("\n");
            somma=somma+matrice[i][j]; //sommare ogni volta numero inserito nella stessa riga
        }
        mediariga[i]=(float)somma/5; //inserire media sul vettore
    }
    //per semplicità logica fare separatamente un ciclo per riga
    for (int j=0; j<5; j++){
        int somma=0; //inizializzare di nuovo la somma evitando usare altre variabile
        for (int i=0; i<5; i++){
            if (j==0){ //stampare solo una volta per ogni riga
                printf("la media dei valori nella riga %d è %.2f\n", i+1, mediariga[i]); //sfruttare questo ciclo per stampare media di ogni riga
            }    
            somma=somma+matrice[i][j]; // sommare questa volta per colonna
        }
        mediacolonna=(float)somma/5; //una volta inizializzato, cambia automaticamente ogni volta dentro ciclo
        printf("la media dei valori nella colonna %d è %.2f\n", j+1, mediacolonna);
    }
    return 0;
}