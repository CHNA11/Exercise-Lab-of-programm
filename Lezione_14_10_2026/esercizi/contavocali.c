# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

//dichiarazione prototipo per funzione di inserimento e contare vocali
char *inserimento(char * parola);
int contavocali(char * parola);

int main(){
    //inizializzazione lunghezza massima della parola
    int n=30;
    //dichiarazione a dimensione mobile la frase
    char *parola = (char*) malloc(n*sizeof(char));
    //controllo
    if(parola==NULL){
        printf("allocazione insuccesso");
        return 1;
    }
    //stampa risultato
    printf("il frase inserito ha %d vocali",contavocali(inserimento(parola)));
    //liberazione
    free(parola);
};

char *inserimento(char *parola){
    //chiedere a utente per inserire una parola
    printf("si chiede di inserire una parola : ");
    scanf("%s",parola);
    //resitutuisce puntatore della parola
    return parola;
};

int contavocali(char *parola){
    //inizializzazione contatore
    int cont=0;
    //contare con ciclo
    for(int i=0; i<strlen(parola); i++){
        if(tolower(parola[i])== 'a' || tolower(parola[i])== 'e' || tolower(parola[i])== 'i' || tolower(parola[i])== 'o' || tolower(parola[i])== 'u'){
            cont++;
        }
    }
    //restituire numero di vocali
    return cont;
}