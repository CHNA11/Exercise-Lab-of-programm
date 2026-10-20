# include <stdio.h>

typedef struct { //definizione di struttura Giocatore richiesto
    char nome[50];
    int numero_maglia;
    int gol_segnati;
    char ruolo[20];
} Giocatore;

//dichiarazione funzioni prototipo secondo richiesta
void inserisci_giocatore(Giocatore *g);
void stampa_giocatore(Giocatore g);
Giocatore* trova_capocannoniere(Giocatore squadra[], int n);

int main(){
    Giocatore squadra[11]; //dichiarazione array di dimensione 11 con tipo Giocatore
    for(int i=0; i<11; i++){ //ciclo for per inserimento dei dati, poiché funzione legge dati di un giocatore
        printf("inserisci dati del giocatore nella posizione %d della squadra\n",i+1);
        inserisci_giocatore(&squadra[i]);
    }
    //per richiesta di funzione, si mette * sul output di funzione che trova capocannoniere
    stampa_giocatore(*trova_capocannoniere(squadra,11)); //stampa giocatore con più goal, poiché funzione esterno stampa dati di un generico giocatore
    return 0;
}

void inserisci_giocatore(Giocatore *g){ //inserimento dei dati di un giocatore, come richiesta ciclo messo fuori dalla funzione
        printf("nome del giocatore : ");
        scanf("%s",g->nome);
        printf("numero di maglia del giocatore : ");
        scanf("%d",&g->numero_maglia);
        printf("gol segnati del giocatore : ");
        scanf("%d",&g->gol_segnati);
        printf("ruolo del giocatore : ");
        scanf("%s",g->ruolo);
}

Giocatore* trova_capocannoniere(Giocatore squadra[], int n){
    int ind_max=0; //classico metodo per cercare il massimo
    for(int i=0; i<n; i++){
        if(squadra[ind_max].gol_segnati<squadra[i].gol_segnati){
            ind_max=i;
        }
    }
    printf("il giocatore con più goal è : \n");
    return &squadra[ind_max]; //come richiesta si ritorna puntatore per utilizzare da funzione stampa giocatore
}

void stampa_giocatore(Giocatore g){ //stampa dati di un generico giocatore, si può disordinare tabella se nome è troppo lungo
    printf(" %-10s %-20s %-10s %-20s\n", "nome","numero di maglia","gol segnati","ruolo");
    printf(" %-10s %-20d %-10d %-20s\n",g.nome,g.numero_maglia,g.gol_segnati,g.ruolo);
}