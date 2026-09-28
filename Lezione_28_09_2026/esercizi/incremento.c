# include <stdio.h>
# include <windows.h> //per riconoscere è

 int main(){
    SetConsoleOutputCP(65001); // trasformare forma in UTF-8
    int x = 5; //inizializzare valore x
    printf("il valore x con incremento suffisso è : %d\n ", x++); //stampare risultato usando incremento
    x = 5; //riassegnare per vedere la differenza
    printf("il valore x con incremento prefisso è : %d\n", ++x);
    return 0;
 }