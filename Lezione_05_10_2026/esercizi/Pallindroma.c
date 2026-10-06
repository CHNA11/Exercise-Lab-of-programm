# include <stdio.h>
# include <string.h>
# include <ctype.h>
int main(){
    char parola[20]; //dichiarare parola da inserire
    printf("si chiede di inserire una parola con lunghezza massima 20 : "); //chiede di inserire parola
    scanf("%s", &parola);
    printf("\n");
    _Bool flag=1; //assumiamo che sia vera
    for( int i=0; i<strlen(parola); i++){ //comincia a verificare
        if (tolower(parola[i])!=tolower(parola[strlen(parola)-i-1])){ //basta che una non sia verificata
            flag=0; // allora non è palindroma
            break; //esce dal ciclo for per evitare ulteriori conti
        }
    }
    if (flag==0){ //stampa risultati
        printf("la parola inserita non è palindroma\n");
    }
    else{
        printf("la parola inserita è palindroma\n");
    }
    return 0;
}