# include <stdio.h>
int main(){
   int numero; // dichiarazione della variabile
   numero = 20; // assegnazione di un nuovo valore alla variabile
printf("testo libero\n");
printf("il numero definito è : %d\n", numero);
scanf("%d", &numero);
printf("incremento postfisso: %d\n", numero++);
printf("incremento prefisso: %d\n", ++numero);
printf("il numero dell'adesso: %d\n", numero);
return 0;
}