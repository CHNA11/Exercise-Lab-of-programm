# include <stdio.h>


struct Studente { //definizione globale della struttura Studente
    char nome[50];
    char cognome[50];
    int matricola;
    float media_voti;
};
//dichiarazione prototipo delle funzioni
struct Studente inserimento();

void stampadati(struct Studente studente);

int main(){
    //inizializzare variabile di forma studente richiamando funzione inserimento
    struct Studente studente=inserimento();
    //stampare dati inseriti
    stampadati(studente);
    return 0;
}

struct Studente inserimento(){
    //dichiarazione della variabile da inserire
    struct Studente studente;
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

void stampadati(struct Studente studente){
    //stampare con tabulazioni
    printf("%-20s %-20s %-20s %-20s\n","Nome","Cognome","numero di matricola","media dei voti");
    printf("%-20s %-20s %-20d %-20.2f\n", studente.nome, studente.cognome, studente.matricola, studente.media_voti);
}

