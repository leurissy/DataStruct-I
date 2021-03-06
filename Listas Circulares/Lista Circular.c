#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int info;
	struct no *prox;
}Tno;

typedef struct{
	Tno *inicio;
}TCircleList;

TCircleList* TCircleList_create(){
	TCircleList* nova = (TCircleList*)malloc(sizeof(TCircleList));
	if(nova){
		nova->inicio = NULL;
	}
	return(nova);
}

//Cria o TNO* e preenche com info

Tno* Tno_create(int info){
	Tno* novo = (Tno*) malloc(sizeof(Tno));
	if(novo){
		novo->info = info;
		novo->prox = NULL;
	}
	return(novo);
}

void TCircleList_insert(TCircleList* L, Tno* no){
	if(L->inicio==NULL){
        L->inicio = no;
        no->prox = L->inicio;
    }else{
        Tno* tmp = L->inicio;
        while(tmp->prox!=L->inicio){
            tmp=tmp->prox;
        }
        tmp->prox = no;
        no->prox = L->inicio;
    }
}

int TCircleList_remove(TCircleList* L, int info){
    if(!L){
    	return 0;
    }
    Tno* tmp=L->inicio, *tmp2;
    if(!tmp){
    	return 0;
    }

	if(tmp->info == info){
		if (tmp->prox == L->inicio){
			L->inicio = NULL;
		}
		else{
			tmp2 = tmp;
			while (tmp2->prox != L->inicio){
				tmp2 = tmp2->prox;
			}
			tmp2->prox = tmp->prox;
			L->inicio = tmp->prox;
		}
	}else{
		Tno* tmp2 = tmp;
		tmp = tmp->prox;
		while(tmp->info != info && tmp !=L->inicio){
			tmp2 = tmp;
			tmp = tmp->prox;
		}
		if (tmp == L->inicio){
			return 0;
		}
		tmp2->prox = tmp->prox;
	}

	free(tmp);
	tmp = NULL;
	tmp2 = NULL;
	return 1;
}

void TCircleList_print(TCircleList* L){
	Tno* tmp;
	for(tmp=L->inicio; tmp->prox!=L->inicio; tmp=tmp->prox){
		printf("%d\n", tmp->info);
	}
	printf("%d\n", tmp->info);
}

int main(){
	int i;
	Tno *temp;

	TCircleList* L = TCircleList_create();
	//TCircleList* L2 = TCircleList_create();
	if(L){
		for(i=0; i<10; i++){
			temp = Tno_create(i);
			if(temp){
				TCircleList_insert(L, temp);
			}
			//TCircleList_insert(L2, Tno_create(10-i));
		}
	}
	TCircleList_print(L);
	puts(" ");

	TCircleList_remove(L,0);
	TCircleList_print(L);
	puts(" ");
	return 0;
}
