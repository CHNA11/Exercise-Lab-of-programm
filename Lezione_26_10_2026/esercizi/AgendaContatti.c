# include <stdio.h>
# include <strings.h>
# include <stdlib.h>

typedef struct { //definizione globale della struttura Contatto
    char nome[50];
    char cognome[50];
    char telefono[15];
    char email[80];
} Contatto;

//dichiarazione prototipo delle funzioni
int richiesta();
void Aggiungi(Contatto *Rubrica,int n,int *p);
void cerca(Contatto *Rubrica,char *cognome, int c);
int menu();
void scelta(Contatto *Rubrica, int s, int n);
void salva(Contatto *Rubrica, int c);
void Visualizza(Contatto* Rubrica, int c);
void carica(Contatto* Rubrica, int* p, int n);

//una parte ripresa da esercizio di rubrica
int main(){
    int n=richiesta(); //inizializzare numero di contatti massimo che può contenere per allocazione dinamica
    Contatto* Rubrica=(Contatto*)malloc(n*sizeof(Contatto)); //allocazione dinamica secondo richiesta
    scelta(Rubrica,menu(),n); //menu e richiamo di funzione scelta, contiene anche liberazione
    return 0;
}
int menu() //ripreso da esercizio di prenotazione cinema e poi modificato
{
    int s;//dichiarazione variabile che registra scelta
    printf("i funzioni possibili sono i seguenti : \n");
    printf("1.Aggiungi nuovo contatto\n");
    printf("2.Visualizza tutti i contatti\n");
    printf("3.Cerca contatto per cognome\n");
    printf("4.Salva rubrica su file binario(rubrica.dat)\n");
    printf("5.Carica rubrica da file binario \n");
    printf("6.Esci\n");
    printf("inserisci la tua scelta : ");
    scanf("%d", &s); //chiedere scelta dal utente
    return s; //passare la scelta fatta
}

void scelta(Contatto* Rubrica, int s, int n) //ripreso da esercizio di prenotazione cinema e poi modificata
{
    int c=0; //inizializzare un contatore per numero di contatti inseriti
    int* p=&c; //inizializzare il puntatore per contatore per salvare cambiamenti nelle funzioni
    while (s != 6) // ha senso solo se non ha scelto uscire
    {
        switch (s)
        { //vari casi della scelta
        case 1:
            Aggiungi(Rubrica,n,p); //passare puntatore per incremento
            break;
        case 2:
        {
            Visualizza(Rubrica,c); //richiama funzione che stampa tutti i c contatti registrati
            break;
        }
        case 3:
            char cognome[50]; //dichiarazione variabile per ricerca
            printf("inserisci cognome che si intende cercare : ");
            scanf("%49s",&cognome); //lettura cognome da cercare
            cerca(Rubrica,cognome,c); //cercare contatti nei c contatti inseriti
            break;
        case 4:
            salva(Rubrica,c); //richiama funzione che salva in un file, con c per elementi da inserire
            break;
        case 5:
            carica(Rubrica,p,n); //richiama funzione per caricare file, con puntatore per salvare quanti contatti ci sono
            break;
        default: // se non è uno dei precedenti
            printf("scelta non valida, si chiede di scegliere funzione valida : \n");
        }
        s = menu(); // rinnovare scelta
    }
    printf("Uscita in corso........\n");
    free(Rubrica);//liberazione allocazione dinamica
}

//funzioni riprese da Esercizio su Contatti e modificate

int richiesta(){
    int n; //dichiarazione locale per numero di inserimento
    do{
        printf("inserisci numero di contatti massimo di cui vuole operare  : "); //inserimento
        scanf("%d",&n);
    } while (n<1); //controllare che sia un numero legale
    return n; //ritornare valore della variabile
}

void Aggiungi(Contatto *Rubrica, int n,int *p){
    int c=*p; //leggere valore indicato dal puntatore
    if(c<n){ //controllare che non ha superato dal limite
        //inserimento dati
        printf("inserisci nome del contatto nella posizione %d : ", c+1);
        scanf("%s",&Rubrica[c].nome);
        printf("inserisci cognome del contatto nella posizione %d : ", c+1);
        scanf("%s",&Rubrica[c].cognome);
        printf("inserisci numero di telefono del contatto nella posizione %d : ", c+1);
        scanf("%s",&Rubrica[c].telefono);
        printf("inserisci indirizzo email del contatto nella posizione %d : ", c+1);
        scanf("%s",&Rubrica[c].email);
        (*p)++; //incremento valore puntato, ovvero contatore c
    }
    else{ 
        printf("inserimento numero di contatti fuori dal limite inserito\n");
    }
}

void cerca(Contatto *Rubrica, char *cognome, int c){
    printf("i contatti con questo cognome sono : \n"); //stampa risultato di recerca
    printf("%-10s %-10s %-20s %-20s\n","nome", "cognome", "telefono","email"); //stampa risultato in modo corretto con tabulazione
    for(int i=0; i<c; i++){
        if (strcasecmp(Rubrica[i].cognome,cognome)==0){ //usando strcasecmp introdotto da libreria di strings per confronto
            printf("%-10s %-10s %-20s %-20s\n",Rubrica[i].nome,Rubrica[i].cognome,Rubrica[i].telefono,Rubrica[i].email); //stampa quelli con stesso cognome
        }
    }
}

void Visualizza(Contatto* Rubrica, int c){
    printf("%-20s %-20s %-20s %-20s\n","nome","cognome","telefono","email");
    for(int i=0; i<c; i++){ //stampa tutti usando contatore
        printf("%-20s %-20s %-20s %-20s\n",Rubrica[i].nome,Rubrica[i].cognome,Rubrica[i].telefono,Rubrica[i].email);
    }
}

void salva(Contatto *Rubrica, int c){
    FILE *fp; //dichiarazione puntatore per file
    int* p=&c; //inzializzare un puntatore per poi usare nel fwrite
    fp=fopen("rubrica.dat","wb"); //apertura file in scrittura
    if(fp==NULL)
    { //controllo del file
        printf("Errore apertura file\n");
        return;
    }
    size_t flag; //indicatore per valori scritti
    flag=fwrite(p,sizeof(int),1,fp); //scrive prima valore di numero di contatto
    if(flag!=1){ //controllo
        printf("Errore salvataggio file con numero di contatti");
        fclose(fp); //anche in questo caso si ricorda di chiudere il file
        return;
    }
    flag=fwrite(Rubrica,sizeof(Contatto),c,fp);
    if (flag!=c){ //controlla di aver scritto tutti i elementi
        printf("Errore salvataggio file\n");
        fclose(fp);
        return;
    }
    fclose(fp); //chiusura file
    printf("i dati sono stati salvati in modo successo nel file rubrica.dat\n");
    //stampa risultato di salvataggio
}

void carica(Contatto *Rubrica, int*p, int n){
    FILE *fp; //dichiarazione puntatore file
    fp=fopen("rubrica.dat","rb"); //apertura file in lettura
    if(fp==NULL){ //controllo che esiste
        printf("apertura file insuccesso\n");
        return;
    }
    size_t flag; //indicatore per quantità di lettura
    flag=fread(p,sizeof(int),1,fp); //prima si legge quanti sono i numero di contatti salvati
    if(flag!=1){ //controllo
        printf("Errore per lettura file\n");
        fclose(fp);
        return;
    }
    if(*p>n){ //controlla di non superare spazio allocato
        printf("File contiene numero di contatto superiore al limite dichiarato all'inizio\n");
        return;
    }
    flag=fread(Rubrica,sizeof(Contatto),*p,fp); //poi legge i valori e salva a Rubrica allocata
    if(flag!=*p){ //controllo
        printf("Errore per lettura file\n");
        fclose(fp);
        return;
    }
    printf("file caricato correttamente, ci sono %d contatti nel file\n",*p);
}