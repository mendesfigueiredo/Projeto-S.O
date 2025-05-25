#include <stdio.h>
#include <string.h>
#define MAX 15
#include <limits.h>

struct Processos {
	char nome[100];
	int tempoEntrada, tempoProcesso, tempoRestante, id;
};


void SRT(struct Processos processo[], int *n){
    printf("\n\n");
    int tempoAtual = 0;
    int idFirst = -1;
    int menorTempo = INT_MAX;
    int processoFim = 0;
    
    for(int i =0; i<*n; i++){
        processo[i].tempoRestante = processo[i].tempoProcesso;
    }
    
    while(processoFim < *n){
        menorTempo = INT_MAX;
        for(int i = 0; i < *n; i++){
            if(processo[i].tempoEntrada <= tempoAtual && processo[i].tempoRestante > 0){
                if(processo[i].tempoRestante < menorTempo){
                    menorTempo = processo[i].tempoRestante;
                    idFirst = i;
                }
            }
        }
        
        if(idFirst != -1){
            processo[idFirst].tempoRestante--;
            printf("Tempo %d: Executando processo %s\n", tempoAtual, processo[idFirst].nome);
            if(processo[idFirst].tempoRestante == 0){
                processoFim++;
                printf("Tempo %d: Processo %s finalizado\n", tempoAtual + 1, processo[idFirst].nome);
            }
        }
        tempoAtual++;
    }
    
}

void roundRobin(struct Processos processo[], int *n){
    printf("\n\n");
    int tempoAtual = 0;
    int quantum;
    int processoFim = 0;
    
    printf("Qual o valor do quantum: ");
    scanf("%d", &quantum);
    
    for(int i =0; i<*n; i++){
        processo[i].tempoRestante = processo[i].tempoProcesso;
    }
    
    while(processoFim < *n){    
        for(int i=0; i<*n; i++){
            if(processo[i].tempoEntrada <= tempoAtual && processo[i].tempoRestante > 0){
                int executado;
                if(processo[i].tempoRestante < quantum){
                    executado = processo[i].tempoRestante;
                }else{
                    executado = quantum;
                }
                
                printf("Tempo %d: Executando processo %s por %d unidades\n",tempoAtual, processo[i].nome, executado);
                processo[i].tempoRestante = processo[i].tempoRestante - executado;
                tempoAtual = tempoAtual + executado;
                
                if(processo[i].tempoRestante == 0){
                    processoFim++;
                    printf("Tempo %d: Processo %s finalizado\n", tempoAtual, processo[i].nome);
                }
            }
        }
    }
    
}

void entradas(struct Processos processo[], int *n) {
	do {
		printf("Quantas entradas serão? (entre 2 a 15): ");
		scanf("%d", n);
		while (getchar() != '\n');
	} while (*n < 2 || *n > MAX);

	for (int i = 0; i < *n; i++) {
		printf("Nome do processo: ");
		fgets(processo[i].nome, sizeof(processo[i].nome), stdin);
		processo[i].nome[strcspn(processo[i].nome, "\n")] = '\0'; 

		printf("Entrada do processo: ");
		scanf("%d", &processo[i].tempoEntrada);

		printf("Tempo do processo: ");
		scanf("%d", &processo[i].tempoProcesso);
		while (getchar() != '\n');
		processo[i].id = i;
		processo[i].tempoRestante = 0;
	}
	SRT(processo, n);
	roundRobin(processo, n);
}


int main() {
	int n;
	struct Processos srt[15];
	entradas(srt, &n);

	return 0;
}
