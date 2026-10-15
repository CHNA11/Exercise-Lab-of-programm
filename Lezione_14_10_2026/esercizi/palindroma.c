# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>

//dihciarazione prototipo della funzione
void controllo(char * parola);
//ripreso da contavocali
void *inserimento(char *parola);

int main(){
    //allocazione dinamico
    char* parola= (char*)malloc(30*sizeof(char));
    //controllo
    if (parola==NULL){
        printf("allocazione insuccesso");
        return 1;
    }
    //inserisci la parola nella memoria
    inserimento(parola);
    //controllare se è palindroma
    controllo(parola);
    //liberazione
    free(parola);
    return 0;
}

void controllo(char *parola){
    //inizializzare lunghezza della parola
    int lunghezza=strlen(parola);
    _Bool flag=1; //si assume che sia palindroma
    for(int i=0; i<lunghezza/2.0; i++){ //basta controllare la prima metà
        if (tolower(parola[i])!=tolower(parola[lunghezza-1-i])){ //facendo controllo con parola inversa
            printf("la parola inserita non è palindroma"); //stampa risultato
            flag=0;
            break; //basta un caso si può uscire dal ciclo
        }
    }
    if (flag==1){ //se non è verificato falso
        //stampa risultato
        printf("la parola inserita è palindroma");
    }
}

void *inserimento(char *parola){
    //chiedere a utente per inserire una parola
    printf("si chiede di inserire una parola : ");
    scanf("%s",parola);
};


