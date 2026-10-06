# include <stdio.h>
# include <string.h>
# include <ctype.h>
int main() {
    char parola[20]; // dichiarare variabile che contiene parola inserito
    printf("Inserisci una parola non superiori a 20 caratteri : "); //chiedere a utente senza superare limite
    scanf("%s", &parola);
    printf("\n");
    int lunghezza = strlen(parola); // considero lunghezza effettiva inserita
    for(int i=0; i<lunghezza;i++){
        parola[i]=tolower(parola[i]); // converto in minuscolo per evitare errori di confronto
    }
    int cont=0; //inizializzare contatore per contare vocali
    for(int i=0; i<lunghezza;i++){
        if (parola[i]=='a' || parola[i]=='e' || parola[i]=='i' || parola[i]=='o' || parola[i]=='u')
        {
            cont++;
        }
    }
    printf("Il numero di vocali nella parola inserita è: %d\n", cont);
    return 0;
}