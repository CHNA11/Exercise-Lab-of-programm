# include <stdio.h>
//definizione globale della struttura libro
typedef struct{
    char titolo[100];
    char autore[50];
    int anno_pubblicazione;
    float prezzo;
} Libro;

//dichiarazione prototipo delle funzione, tutti in main perché applico direttamente sul puntatore del vettore
void inserimento(Libro *cassella,int grandezza);
void prezzomedio(Libro *cassella, int grandezza);
void costoso(Libro *cassella, int grandezza);

int main(){
    //dichiarazione di array di tipo Libro dimensione 5
    Libro cassella[5];
    //richiama funzioni
    inserimento(cassella,5);
    prezzomedio(cassella,5);
    costoso(cassella,5);
    return 0;
}

void inserimento(Libro *cassella, int grandezza){
    for(int i=0; i<grandezza; i++){ //inserimento dei dati di ogni libro
        printf("inserisci titolo del libro nella posizione %d : ",i+1);
        scanf("%s",&cassella[i].titolo);
        printf("inserisci autore del libro nella posizione %d : ",i+1);
        scanf("%s",&cassella[i].autore);
        printf("inserisci anno di pubblicazione del libro nella posizione %d : ",i+1);
        scanf("%d",&cassella[i].anno_pubblicazione);
        printf("inserisci prezzo del libro nella posizione %d : ",i+1);
        scanf("%f",&cassella[i].prezzo);
    }
}

void prezzomedio(Libro *cassella, int grandezza){
    int somma=0;// inizializzare variabile locale per la somma
    for(int i=0; i<grandezza; i++){
        somma=somma+cassella[i].prezzo; //sommare prezzo di ogni libro
    }
    printf("il prezzo medio dei libri è : %.2f\n",(float)somma/5); //stampare la media calcolata
}

void costoso(Libro *cassella, int grandezza){
    int ind_max=0; //inzializzare variabile per indice di libro con prezzo massimo
    for(int i=0; i<grandezza; i++){
        if (cassella[ind_max].prezzo<cassella[i].prezzo){ //se non è verificata cambia indice
            ind_max=i;
        }
    }
    //stampa risultato
    printf("il libro %s con il prezzo %.2f è quello più costoso tra gli inseriti\n",cassella[ind_max].titolo,cassella[ind_max].prezzo);
}