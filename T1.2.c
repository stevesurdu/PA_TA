/*
    Autor: Igor Voloc
    Grupa: Calculatoare 10202
    IDE: Code::Blocks IDE
    Compilator: GNU GCC Compiler
    OS: Deepin (Ubuntu 14.04 LTS)
*/

// Fiind date 6 numere cistigatoare la Loto si o lista simplu inlantuita cu numere alse de un jucator, sa se determina cite numere a ghicit jucatorul

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct lista{
    int inf;
    struct lista *urm;
}lista;

lista *q;
int loto[5];

void afisare(lista *q){
    lista *p = q;
    printf("\n");
    for(p=q;p!=NULL;p=p->urm)
        printf("%d -> ",p->inf);
    printf("NULL");
}
lista *creare(){
    lista *p,*q;
    int i;
    q=NULL;

    printf("\nAlegeti numerele cistigatoare la loto\n");
    for(i=1;i<=6;i++){
        p = (lista *)malloc(sizeof(lista));
        printf("numar:");scanf("%d",&p->inf);
        p->urm = q;
        q = p;
    }
    return q;
}
long random_int(long max) {
    unsigned long
    num_bins = (unsigned long) max + 1,
    num_rand = (unsigned long) RAND_MAX + 1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;
    long x;
    do {
        x = random();
    }
    while (num_rand - defect <= (unsigned long)x);

    return x/bin_size;
}
void init_loto(int loto[]){
    int i,r;
    srand(time(NULL));

    for(i=0;i<=5;i++)
        loto[i] = random_int(10);

    printf("\n<-- Biletul loto -->\n");
    for(i=0;i<=5;i++)
        printf("%i ",loto[i]);

}
int search(lista *q,int x){
    lista *p = q;
    int k=0;
    for(p=q;p!=NULL;p=p->urm){
        if(p->inf == x){
            k=1;
            break;
        }
    }
    return k;
}
int main(){
    int i,r=0;
    q = creare();

    init_loto(loto);

    for(i=0;i<=5;i++){
        r+=search(q,loto[i]);
    }

    printf("\nAi ghicit %i numere",r);

    return 0;
}
