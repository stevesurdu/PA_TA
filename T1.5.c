/*
    Autor: Igor Voloc
    Grupa: Calculatoare 10202
    IDE: Code::Blocks IDE
    Compilator: GNU GCC Compiler
    OS: Deepin (Ubuntu 14.04 LTS)
*/

// Sa se stearga dintr-o lista simplu inlantuita de numere intregi toate elementele care sunt mai mici decit 60 si sa se afiseze elementele ramase

#include <stdio.h>
#include <stdlib.h>
typedef struct lista{
    int inf;
    struct lista *urm;
}lista;

lista *q,*q2;

void afisare(lista *q){
    lista *p = q;
    printf("\n");
    for(p=q;p!=NULL;p=p->urm)
        printf("%d -> ",p->inf);
    printf("NULL");
}
lista *creare(){
    lista *p,*q;
    int i,n;
    q=NULL;

    printf("\nDati numarul de elemente\n");
    scanf("%i",&n);
    for(i=1;i<=n;i++){
        p = (lista *)malloc(sizeof(lista));
        printf("numar:");scanf("%i",&p->inf);
        p->urm = q;
        q = p;
    }
    return q;
}
lista *delete(lista *q,int poz){
    lista *s,*p;
    int i;
    if(poz==1){
        s = q;
        q = q->urm;
        free(s);
    }else{
        p = q;
        for(i = 1;i < poz-1; i++)
            p = p->urm;
        s = p->urm;
        p->urm = s->urm;
        free(s);
    }
    return q;
}
lista *custom_delete(lista *q){
    lista *p = q;
    int k=1;
    for(p=q;p!=NULL;p=p->urm){
        if(p->inf < 60){
            q = delete(q,k);
            k--;
        }
        k++;
    }
    return q;
}
int main(){
    q = creare();
    afisare(q);

    q2 = custom_delete(q);
    afisare(q2);

    return 0;
}
