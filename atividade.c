#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct _estudante {
	int		  id;
	char	  nome[255];
	float	  nota; 
} estudante;

typedef struct _node {
	estudante k;
	struct _node *next; // ponteiro para o próximo elemento
} node, *lista;

void inserir_na_lista (lista *L, estudante k) {

	node *p;
	p = (node *) malloc(sizeof(node));
	p->k = k;
	p->next = *L;

	*L = p;

}

estudante *buscar_na_lista(lista L, int id) {

	node *p;

	for(p=L; p && p->k.id != id; p=p->next);

	if(p)
		return &p->k;
	else
		return NULL;

}

void criar_lista(lista *L) {

	*L = NULL;

}

void menu(lista C, estudante *p){

	system("cls");

	int id, opcao;
	printf("Informe a função desejada:\n[1] Buscar um estudante \n[2] Sair: \n");
	scanf("%d", &opcao);

	switch(opcao) {

		case 1:
			while(id != -1){

				printf("Insira o ID do aluno (-1 para finalizar): ");
				scanf("%d", &id);

				p = buscar_na_lista(C, id);

				if(id == -1)
					main();

				if(!p)
					printf("ID #%d não encontrado!\n", id);
				else
					printf("%d\t%s\t%0.2f\n", p->id, p->nome, p->nota);

			}
			break;

		case 2:
			printf("Até logo! \n");
			break;

	}

}

int main(){

	lista C;
	estudante s, *p;
	char arquivo[11] = "./List.txt";
	FILE *f;

	setlocale(LC_ALL, "Portuguese");

	f = fopen(arquivo, "r");
	if (!f) {
		perror("Erro ao abrir a lista de estudantes!");
		exit(1);
	}

	criar_lista(&C);

	while(!feof(f)){
		fscanf(f, "%d %s %f\n", &s.id, s.nome, &s.nota);
		inserir_na_lista(&C, s);
	}
	fclose(f);

	menu(C, &p);

	exit(0);

}