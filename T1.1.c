/*
    Autor: Igor Voloc
    Grupa: Calculatoare 10202
    IDE: Code::Blocks IDE
    Compilator: GNU GCC Compiler
    OS: Ubuntu 14.04 LTS
*/

// Concatenarea a 2 liste simplu inlantuite astfel: se adauga lista mai scurta la sfirsitul celei mai lungi

#include <stdio.h>
#include <stdlib.h>
typedef struct lista{
    int inf;
    struct lista *urm;
}lista;
lista *q,*q2,*q3;
void afisare(lista *q){
    lista *p = q;
    printf("\n");
    for(p=q;p!=NULL;p=p->urm)
        printf("%d -> ",p->inf);
    printf("NULL");
}
lista *creare(){
    lista *p,*q;
    int x;
    q=NULL;

    printf("info:");scanf("%d",&x);

    while(x!=0){
        p = (lista *)malloc(sizeof(lista));
        p->inf = x;
        p->urm = q;
        q = p;

        printf("info:");scanf("%d",&x);
    }
    return q;
}
int count(lista *a){
    int k=0;
    lista *l1 = a;
    for(l1=a;l1!=NULL;l1=l1->urm)
        k+=1;

    return k;
}
lista * concatenare(lista * l1,lista * l2)
{
    lista * l3, *p, *q;
    for(p=l1;p->urm!=NULL;p=p->urm);
    l3=l1;
    q=l2;
    p->urm=q;
    q=p;

    return l3;
}
int main(){
    q = creare();
    afisare(q);
    q2 = creare();
    afisare(q2);

    if(count(q) < count(q2))
        q3 = concatenare(q,q2);
    else
        q3 = concatenare(q2,q);
    afisare(q3);

    return 0;
}
