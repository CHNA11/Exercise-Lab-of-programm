#include <stdio.h>
//definizione globale di struttura studente con typedef
typedef struct {
    char nome[30];
    char cognome[30];
    int matricola;
    float media_voti;
} Studente;

//dichiarazione prototipo delle funzioni
Studente inserimento();
void confronto(Studente s1, Studente s2);

int main(){
    //chiede dati del primo studente
    printf("inseisci dati del primo studente\n");
    Studente s1=inserimento(); //richiama funzione di inserimento
    //chiede dati del secondo studente
    printf("inserisci dati del secondo studente\n");
    Studente s2=inserimento();
    //confronta i dati e stampa risultato
    confronto(s1,s2);
}

void confronto(Studente s1, Studente s2){
    if (s1.media_voti>s2.media_voti){ //confrontare la media
        printf("lo studente %s %s ha media voti più alta\n",s1.nome,s1.cognome);
    }
    else if(s1.media_voti<s2.media_voti){
        printf("lo studente %s %s ha media voti più alta\n",s2.nome,s2.cognome);
    }
    else { //se non valgono entrambi è uguale
        printf("Le medie sono uguali\n");
    }
}

//funzione ripreso da GestioneStudente modificato per typedef
Studente inserimento(){
    //dichiarazione della variabile da inserire
    Studente studente;
    //richiesta dei corrispondenti dati
    printf("inserisci nome e cognome dello studente : ");
    scanf("%s %s", &studente.nome,&studente.cognome);
    printf("inserisci il suo numero di matricola : ");
    scanf("%d", &studente.matricola);
    do {
        printf("inserisci la corrispondente media dei voti : ");
        scanf("%f", &studente.media_voti);
    } while(studente.media_voti<18 || studente.media_voti>30); //controllare che sia una media legale
    return studente; //ritornare risultato come variabile
}