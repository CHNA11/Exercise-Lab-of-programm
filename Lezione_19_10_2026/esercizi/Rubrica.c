# include <stdio.h>
# include <strings.h>

typedef struct { //definizione globale della struttura Contatto
    char nome[50];
    char cognome[50];
    char numero_telefono[15];
} Contatto;

//dichiarazione prototipo delle funzioni
int richiesta();
void inserimento(Contatto *Rubrica,int n);
void ricerca(Contatto *Rubrica,char *cognome, int n);

int main(){
    Contatto Rubrica[10]; //dichiarazione array di tipo Contatto con massimo 10 contatti
    int n=richiesta(); //inizializzare numero di contatti da inserire
    inserimento(Rubrica,n); //richiama funzione che inserisce nella rubrica n contatti
    char cognome[50]; //dichiarazione cognome da cercare
    printf("inserisci cognome di cui si intende cercare : "); //chiedere input
    scanf("%s",&cognome);
    ricerca(Rubrica,cognome,n); //richiama funzione di ricerca nella rubrica
    return 0;
}

int richiesta(){
    int n; //dichiarazione locale per numero di inserimento
    do{
        printf("inserisci numero di contatti di cui vuole inserire con massimo 10 : "); //inserimento
        scanf("%d",&n);
    } while (n<1 || n>10); //controllare che sia un numero legale
    return n; //ritornare valore della variabile
}

void inserimento(Contatto *Rubrica, int n){
    for(int i=0; i<n; i++){ //con ciclo for inserisci le informazioni dei contatti
        printf("inserisci nome del contatto nella posizione %d : ", i+1);
        scanf("%s",&Rubrica[i].nome);
        printf("inserisci cognome del contatto nella posizione %d : ", i+1);
        scanf("%s",&Rubrica[i].cognome);
        printf("inserisci numero di telefono del contatto nella posizione %d : ", i+1);
        scanf("%s",&Rubrica[i].numero_telefono);
    }
}

void ricerca(Contatto *Rubrica, char *cognome, int n){
    printf("i contatti con questo cognome sono : \n"); //stampa risultato di recerca
    printf("%-10s %-10s %-20s\n","nome", "cognome", "numero di telefono"); //stampa risultato in modo corretto con tabulazione
    for(int i=0; i<n; i++){
        if (strcasecmp(Rubrica[i].cognome,cognome)==0){ //usando strcasecmp introdotto da libreria di strings per confronto
            printf("%-10s %-10s %-20s\n",Rubrica[i].nome,Rubrica[i].cognome,Rubrica[i].numero_telefono); //stampa quelli con stesso cognome
        }
    }
}