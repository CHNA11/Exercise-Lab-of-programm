# include <stdio.h>
 int main(){
    int intero; // dichiare variabile da inserire
    _Bool flag = 0; // assumiamo che utente da un numero non intero
    while (flag==0){ //in realtà è inutile perché se inserisce un numero non intero ma intero è una variabile del tipo int
    printf("dammi un numero intero : ");
    scanf("%d",&intero); //inserire numero dato da utente
    printf("\n");
    if (intero%2==0)
    {// se è uguale a 0 modulo 2 è un numero pari
        printf("il numero inserito è pari\n");
        flag = 1;// non richiedere più all'utente
    }
    else if (intero%2==1)
    { // uguale 1 modulo 2 è dispari
        printf("il numero inserito è dispari\n");
        flag = 1;
    }
    else{ //alrimenti non è un numero intero
        printf("il numero inserito non è un numero intero\n");
    }
}
}