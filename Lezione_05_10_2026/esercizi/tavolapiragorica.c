# include <stdio.h>
int main(){
    int matrice[10][10]; // dichiarare una matrice 10x10 per inserire numeri
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){ //invece di considerare simmetria come pensato prima, si passa ad ogni posizione per stampare direttamente dentro ciclo
            matrice[i][j]=(i+1)*(j+1); //più 1 perché parte da 0
            printf("%3d ",matrice[i][j]); //lasciare spazio
        }
        printf("\n"); //andare a capo ogni volta che cambia riga
    }
    return 0;
}