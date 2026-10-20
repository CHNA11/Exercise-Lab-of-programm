# include <stdio.h>


struct Studente { //definizione globale della struttura Studente
    char nome[50];
    char cognome[50];
    int matricola;
    float media_voti;
};
//dichiarazione prototipo delle funzioni
Studente inserimento();

void stampadati(Studente studente);

int main(){
    studente=inserimento();
    stampadati(studente);
}