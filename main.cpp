#include <stdio.h>
#include <string.h>
#define MAX 15

struct Processos {
	char nome[100];
	int tempoEntrada, tempoProcesso, id;
};


int SRT(struct Processos processo[], int *n){
    int i = 0;
    int idFirst = 0;
    int menorTempo = 0;
    
    for( i = 0; i < *n; i++){
        if(processo[i].tempoEntrada <= i && processo[i].tempoProcesso > 0){
            menorTempo = processo[i].tempoProcesso;
            if(processo[i].tempoProcesso < menorTempo){
                menorTempo = processo[i].tempoProcesso;
                idFirst = processo[i].id;
            }
        }
    }
    printf("%d", idFirst);
    int armazenar[MAX];
    
    for(i; i < *n; i++){
        if(idFirst == processo[i].id){
            armazenar[i] = processo[i].id;
        }else if(processo[i].tempoEntrada <= i && processo[i].tempoProcesso < menorTempo){
            armazenar[i] = processo[i].id;
            menorTempo = processo[i].tempoProcesso;
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
		processo->id = i + 1;
	}
	SRT(processo, n);
}


int main() {
	int n;
	struct Processos srt[15];
	entradas(srt, &n);

	return 0;
}
