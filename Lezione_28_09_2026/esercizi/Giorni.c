# include <stdio.h>
# include <windows.h> //per riconoscere è

int main(){
    SetConsoleOutputCP(65001); // trasformare forma in UTF-8
    enum GiorniDellaSettimana {  //enumerazione
        Lunedì = 1, //iniziare da 1 è più comodo per me
        Martedì,
        Mercoledì,
        Giovedì,
        Venerdì,
        Sabato,
        Domenica
    };
    printf("il numero corrispondente a Lunedì è : %d\n",Lunedì);
    printf("il numero corrispondente a Martedì è : %d\n",Martedì);
    printf("il numero corrispondente a Mercoledì è : %d\n",Mercoledì);
    printf("il numero corrispondente a Giovedì è : %d\n",Giovedì);
    printf("il numero corrispondente a Venerdì è : %d\n",Venerdì);
    printf("il numero corrispondente a Sabato è : %d\n",Sabato);
    printf("il numero corrispondente a Domenica è : %d\n",Domenica);
    return 0;
}