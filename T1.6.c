/*
    Autor: Igor Voloc
    Grupa: Calculatoare 10202
    IDE: Code::Blocks IDE
    Compilator: GNU GCC Compiler
    OS: Deepin (Ubuntu 14.04 LTS)
*/

// O lista simplu inlantuita contine codurile unor persoane, sumele datoare si un indicator care are valoarea 1 daca suma a fost achitata si 0 in caz contrar. Sa se afiseze codurile persoanelor care eu restante si sumele datoare

#include <stdio.h>
#include <stdlib.h>
typedef struct lista{
    int id;
    int inf;
    int dator;
    struct lista *urm;
}lista;

lista *q;

lista *creare(){
    lista *p,*q;
    int i,n;
    q=NULL;

    printf("\nDati numarul de elemente\n");
    scanf("%i",&n);
    for(i=1;i<=n;i++){
        p = (lista *)malloc(sizeof(lista));
        printf("suma:");scanf("%i",&p->inf);
        printf("dator:");scanf("%i",&p->dator);
        p->id = i;
        p->urm = q;
        q = p;
    }
    return q;
}

void afisare_dator(lista *q){
    lista *p = q;
    printf("\nPersoanele care sunt datoare:");
    for(p=q;p!=NULL;p=p->urm){
        if(p->dator == 0)
            printf("\n%i : %i",p->id,p->inf);
    }
}

int main(){

    q = creare();
    afisare_dator(q);

    return 0;
}
