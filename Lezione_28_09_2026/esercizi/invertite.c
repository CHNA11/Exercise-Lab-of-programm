# include <stdio.h>
# include <windows.h> //per riconoscere è
//ho solo modificato un'po quello su Cifre

int main(){
    SetConsoleOutputCP(65001); // trasformare forma in UTF-8
    int intero; // dichiare variabile da inserire
    printf("dammi un numero intero a 3 cifre : ");
    scanf("%d",&intero);
    printf("\n");
    int unità = (intero %100) %10; // unità sarà l'intero tolta primo e secondo cifra a sinistra
    int decina= ((intero %100) - unità) /10; //decina sarà intero tolta la prima da sinistra e destra
    int centinaia= (intero - (intero %100))/100; //centinaia sarà intero tolta prima e seconda da destra
    int oretni = (unità*100) + (decina*10) + centinaia; // calcolare intero invertito usando cifre estratte
    printf("il numero inserito invertito è : %d538",oretni); // stampare risultato
    return 0;
}