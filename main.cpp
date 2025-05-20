#include <iostream>
#include <stdio.h>
#include <string.h>
#define TAM 15

struct No{
  int valor;
  No* next;
  
  No(int valorNo):valor(valorNo), next(nullptr){} // : -> operador de inicialização de membros
                                            // ...ou lista de inicialização de membros de um construtor.
};

struct Fila{
    
};


struct Join{
    void teste(){
        int n;
        do{
            scanf("%d", &n);
            char nome;
            int timeJoin, timeProcess;
            
            
        }while(n > 1 && n < 16);
    }
};


int main(){
    struct Join entradaUm;

    entradaUm.teste();
}
