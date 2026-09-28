# include <stdio.h>
# include <windows.h> //per riconoscere è

int main(){
    SetConsoleOutputCP(65001); // trasformare forma in UTF-8
    const float pi = 3.1415926; // definisco pigreco come una costante
    float raggio; // dichiaro variabile raggio
    printf("dammi un raggio :  "); //chiedere raggio al utente
    scanf("%f", &raggio);
    printf("\n"); // vai a capo
    float circonferenza = 2*pi*raggio; // calcolare lunghezza e area
    float area=pi*raggio*raggio;
    printf("lungezza della circonferenza con questo raggio è %f\n", circonferenza); //stampare sullo schermo
    printf("l'area di un cerchio con questo raggio è %f\n", area);
    return 0;
}