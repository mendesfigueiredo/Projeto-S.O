#include <stdio.h>
#include <string.h>
#define MAX 15

struct Processos {
	char nome[100];
	int tempoEntrada, tempoProcesso;
};

void desenvolvimento(struct Processos processo[], int *n) {
	do {
		printf("Quantas entradas serão? (entre 2 a 15): ");
		scanf("%d", n);
		while (getchar() != '\n');
	} while (*n < 2 || *n > MAX);

	for (int i = 0; i < *n; i++) {
		printf("Nome do processo %d: ", i + 1);
		fgets(processo[i].nome, sizeof(processo[i].nome), stdin);
		processo[i].nome[strcspn(processo[i].nome, "\n")] = '\0'; 

		printf("Tempo de entrada do processo %d: ", i + 1);
		scanf("%d", &processo[i].tempoEntrada);

		printf("Tempo de execução do processo %d: ", i + 1);
		scanf("%d", &processo[i].tempoProcesso);
		while (getchar() != '\n'); 
	}
	//SRT
	int fila[MAX];
	int escalonamento[MAX];
    for(int i = 0;i < *n; i++){
       if(escalonamento[i] == 0){
           escalonamento[i] = processo[i].tempoProcesso 
       }
    }
}


int main() {
	struct Processos srt[15];
	int n, menuOpcao;

	desenvolvimento(srt, &n);

	printf("\nProcessos inseridos:\n");
	for (int i = 0; i < n; i++) {
		printf("Nome: %s / Entrada: %d / Duração: %d\n",
			srt[i].nome,
			srt[i].tempoEntrada,
			srt[i].tempoProcesso);
	}

	return 0;
}
