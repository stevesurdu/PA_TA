/*
    Autor: Igor Voloc
    Grupa: Calculatoare 10202
    IDE: Code::Blocks IDE
    Compilator: GNU GCC Compiler
    OS: Deepin (Ubuntu 14.04 LTS)
*/

// Sa se transfere elementele pare dintr-un vector de dimensiune n intr-o lista simplu inlantuita de tip stiva

#include <stdio.h>

typedef struct stiva{
    int inf;
    struct stiva *urm;
}stiva;

stiva *st,*p;
int v[10];

void afisare(stiva *st){
    stiva *p = st;
    printf("\n");
    while(p!=NULL){
        printf("%d -> ",p->inf);
        p = p->urm;
    }
    printf("NULL");
}
stiva *push(stiva *vf, int x){
    stiva *nou;
    nou = (stiva*) malloc(sizeof(stiva));

    nou -> inf = x;
    nou -> urm = vf;
    vf = nou;

    return vf;
}

int main(){
    int n,i;

    printf("Dati lungimea vectorului: ");scanf("%d",&n);
    for(i=0;i<=n;i++){
        printf("v[%i]=",i);
        scanf("%i",&v[i]);
    }

    for(i=0;i<=n;i++)
        if(v[i]%2 == 0)
            st = push(st,v[i]);

    afisare(st);

    return 0;
}
