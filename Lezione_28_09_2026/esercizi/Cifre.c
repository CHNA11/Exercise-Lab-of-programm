# include <stdio.h>
# include <windows.h> //per riconoscere è

int main(){
    SetConsoleOutputCP(65001); // trasformare forma in UTF-8
    int intero; // dichiare variabile da inserire
    printf("dammi un numero intero a 3 cifre : ");
    scanf("%d",&intero);
    printf("\n");
    int unità = (intero %100) %10; // unità sarà l'intero tolta primo e secondo cifra a sinistra
    int decina= ((intero %100) - unità) /10; //decina sarà intero tolta la prima da sinistra e destra
    int centinaia= (intero - (intero %100))/100; //centinaia sarà intero tolta prima e seconda da destra
    printf("la cifra centinaia dell'intero è : %d\n",centinaia); //stampare risultati
    printf("la cifra decina dell'intero è : %d\n",decina);
    printf("la cifra unità dell'intero è : %d\n",unità);
    return 0;
}