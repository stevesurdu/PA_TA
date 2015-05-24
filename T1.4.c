/*
    Autor: Igor Voloc
    Grupa: Calculatoare 10202
    IDE: Code::Blocks IDE
    Compilator: GNU GCC Compiler
    OS: Deepin (Ubuntu 14.04 LTS)
*/

// Sa se citeasca de la tastatura n numere naturale. Sa se dormeze o lista simplu inlantuita care le contine numai pe acelea dintre ele care sunt prime

#include <stdio.h>
#include <stdlib.h>
typedef struct lista{
    int inf;
    struct lista *urm;
}lista;

lista *q;

void afisare(lista *q){
    lista *p = q;
    printf("\n");
    for(p=q;p!=NULL;p=p->urm)
        printf("%d -> ",p->inf);
    printf("NULL");
}
lista *creare(){
    lista *p,*q;
    int i,x,n;
    q=NULL;

    printf("\nDAti numarul de elemente\n");
    scanf("%i",&n);
    for(i=1;i<=n;i++){
        p = (lista *)malloc(sizeof(lista));
        printf("numar:");scanf("%i",&x);
        if(prim(x) == 1){
            p->inf = x;
            p->urm = q;
            q = p;
        }
    }
    return q;
}

int prim(int x)
{
    int pr,i;
    if(x<2)
        pr = 0;
    else{
        pr = 1;
        for(i=2;i<=x/2;i++){
            if(x%i==0)
                pr = 0;
        }
    }
    return pr;
}
int main(){

    q = creare();
    afisare(q);
    
    return 0;
}
