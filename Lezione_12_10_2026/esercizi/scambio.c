# include <stdio.h>
int main(){
    int x; //dichiarare variabili da dare in input
    int y;
    int *p=&x; //inizializzare puntatori per x e y
    int *q=&y;
    int *r; //dichairare un puntatore intermedio
    printf("inserire valore di x : "); //chiedere valori come input
    scanf("%d",p);
    printf("inserire valore di y : ");
    scanf("%d",q);
    //scambio
    *r=*p;
    *p=*q;
    *q=*r;
    printf("dopo scambio il valore di x è : %d\n",*p); //stampare risultati con puntatori
    printf("dopo scambio il valore di y è : %d\n",*q);
    return 0;
}