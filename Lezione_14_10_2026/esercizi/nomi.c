# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>  //per strcasecmp che fa compare tra nomi senza considerando maiuscola o minuscola
//dichiarazioen funzione prototipo

int numeronomi();
void inputnomi(char **elenco,int n);
void inputnome(char *nome);
void cercanome(char ** elenco, char *nome,int n);
void contanome(char **elenco, char *nome, int n);
void ordineelenco(char **elenco, int n);
void stampaelenco(char **elenco, int n);

int main(){
    //dichiarazione numeri di nomi dall'utente
    int n;
    //chiedere in input finché sia un valore legale
    do{
        n=numeronomi();
    } while(n<1 || n>10);
    //allocazione dinamico dell'elenco
    char **elenco=(char**)malloc(n*sizeof(char*));
    //controllo
    if (elenco==NULL){
        printf("allocazione insuccesso");
        return 1;
    }
    for (int i=0; i<n; i++){
        //allocazione dinamico per ogni nome
        elenco[i]=(char *)malloc(30*sizeof(char));
        //controllo per ogni nome
        if(elenco[i]==NULL){
            printf("allocazione insuccesso");
            exit(1);
        }
    }
    //allocazione dinamico nome da operare
    char *nome=(char *) malloc(30*sizeof(char));
    //chiedere di inserire nomi nell'elenco
    inputnomi(elenco,n);
    //chiedere nome da cercare
    inputnome(nome);
    //cercare solo presenza nell'elenco
    cercanome(elenco,nome,n);
    //contare quanti volta sono in effetti presenti
    contanome(elenco,nome,n);
    //ordinare elenco in ordine alfabetico
    ordineelenco(elenco,n);
    //stampare elenco, in questo caso ordinato
    stampaelenco(elenco,n);
    //liberare puntatore del nome
    free(nome);
    for(int i=0; i<n; i++){
        //liberazione di ogni nome
        free(elenco[i]);
    }
    //liberazione elenco
    free(elenco);
    return 0;
}

void inputnomi(char **elenco,int n){
    for(int i=0; i<n; i++){  //usare ciclo per chiedere input
        printf("inserisci nome nella posizione %d : ",i+1);
        scanf("%s",elenco[i]);
    }
}

void inputnome(char *nome){
    //chiedere nome da operare
    printf("inserisci il nome in cui desideri operare : ");
    scanf("%s",nome); //inserire nel posizione del puntatore 
}

int numeronomi(){
    int n; //dichiarazione variabile per numero di nomi
    printf("inserisci quanti nomi desideri inserire : "); //chiedere in input all'utente
    scanf("%d",&n);
    return n; //restituire come output
}

void cercanome(char **elenco, char *nome,int n){
    _Bool flag=0; //assumere che non sia presente
    for(int i=0; i<n; i++){
        if (strcasecmp(nome,elenco[i]) == 0){
            flag=1; //basta un caso che sia presente
            break; //evita ulteriori controlli
        }
    }
    if(flag==0){ //stampare risultato
        printf("il nome inserito non è presente nell'elenco\n");
    }
    else{ //può essere o 1 o 0
        printf("il nome inserito è presente nell'elenco\n");
    }
}

void contanome(char **elenco, char *nome, int n){
    int cont=0; //inizializzare un variabile come contatore
    for(int i=0; i<n; i++){
        if(strcasecmp(elenco[i],nome)==0){
            cont++; //ogni volta che verifica incremente contatore
        }
    }
    printf("il nome inserito è presente %d volte\n",cont); //stampa risultato
}


void ordineelenco(char **elenco, int n){ //ricopiato da quello degli esercizi vecchi sul vettore
    char temp[30];//dichiarare una variabile temporanea per scambio
    for(int i=0; i<n-1; i++){ //bubble sort
        for(int j=0; j<n-1-i; j++){
            if (strcasecmp(elenco[j],elenco[j+1])>0){  //maggiore di zero significa alfabeticamente viene dopo
                //usare questo comando riportato da strings.h evita differenza di maiuscola e minuscola
                strcpy(temp,elenco[j]); //scambio
                strcpy(elenco[j],elenco[j+1]);
                strcpy(elenco[j+1],temp);
            }
        }
    }
}

void stampaelenco(char **elenco, int n){ //stampare elenco
    for(int i=0; i<n; i++){
        //andare a capo stampato ogni nome
        printf("%s\n",elenco[i]);
    }
}