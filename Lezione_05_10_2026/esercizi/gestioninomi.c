# include <stdio.h>
# include <string.h>
# include <strings.h>
int main(){
    int lunghezza; //dichiarare lunghezza che desidera utente
    int limite=20; //inizializzare una variabile per dare limite su caratteri di ogni riga
    do{
        printf("dimmi quanti nomi desideri inserire, non oltre 10 : "); //chiede a utente lunghezza
        scanf("%d", &lunghezza);
        printf("\n");
    } while (lunghezza>10 || lunghezza<0);
    char elenco[lunghezza][limite]; //inizializzare un array per stringhe
    for(int i=0; i<lunghezza; i++){
        printf("inserisci il nome nella posizione %d con al massimo lunghezza 20 : ", i+1); //chiedere inserimento all'utent
        scanf("%s", &elenco[i]);
        printf("\n");

    };
    char nomespecial[20]; //dichiarare una variabile per nome specifico
    printf("inserisci il nome che intendi cercare : "); // chiedere a utente nome in cui desidera operare
    scanf("%s", &nomespecial);
    printf("\n");
    int cont=0; //inizializzare un contatore
    for(int i=0; i<lunghezza; i++){
        if( strcasecmp(nomespecial, elenco[i]) == 0){ //controlla se sono uguali
            cont++;
        }
    }
    printf("il nome inserito compare %d volte\n",cont);
    char temp[20];//dichiarare una variabile temporanea per scambio
    for(int i=0; i<lunghezza-1; i++){ //bubble sort
        for(int j=0; j<lunghezza-1-i; j++){
            if (strcasecmp(elenco[j],elenco[j+1])>0){  //maggiore di zero significa alfabeticamente viene dopo
                //usare questo comando riportato da strings.h evita differenza di maiuscola e minuscola
                strcpy(temp,elenco[j]); //scambio
                strcpy(elenco[j],elenco[j+1]);
                strcpy(elenco[j+1],temp);
            }
        }
    }
    for(int i=0; i<lunghezza; i++){
        printf("%s\n",elenco[i]);
    }
    return 0;
}