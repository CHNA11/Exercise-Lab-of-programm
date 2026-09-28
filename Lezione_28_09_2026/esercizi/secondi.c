# include <stdio.h>

int main(){
    int ore; // dichiare variabili di ore minuti e secondi
    int minuti;
    int secondi;
    printf("dammi il numero di ore : "); //chiedere a utente numero di ore
    scanf("%d", &ore); //legge la tastiera
    printf("\n"); //saltare la riga
    printf("dammi il numero di minuti : "); //chiedere a utente numero di minuti
    scanf("%d", &minuti); //legge la tastiera
    printf("\n"); //saltare la riga
    printf("dammi il numero di secondi : "); //chiedere a utente numero di secondi
    scanf("%d", &secondi); //legge la tastiera
    printf("\n"); //saltare la riga
    int tot=(ore*3600)+(minuti*60)+secondi;
    printf("il numero totale sono %d secondi",tot);
    return 0;
}