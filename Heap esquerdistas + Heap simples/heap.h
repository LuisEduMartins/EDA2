#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define tamanhoheap 100

//Heap esquerdista Prioridade 1
typedef struct no{
	int elemento;
	int s;

	struct no* esq;
	struct no* dir;
}p1;


void menu(void);
p1* cria_heap(int valor);
void troca_filhos (p1* a);
p1* uniao(p1* h1, p1* h2);
p1* uniao_heaps(p1* h1, p1* h2);
void imprime(p1 *h);

//Heap esquerdista Prioridade 2

typedef struct no2{
	int elemento;
	int s;
	struct no2 *esq;
	struct no2 *dir;
}p2;

void menu(void);
p2* cria_heap2(int valor);
void troca_filhos2(p2* a);
p2* uniao2(p2* h1, p2* h2);
p2* uniao_heaps2(p2* h1, p2* h2);

//Heap esquerdista Não Prioridade 1

typedef struct no3{
	int elemento;
	int s;
	struct no3 *esq;
	struct no3 *dir;
}np1;

void menu(void);
np1* cria_heap3(int valor);
void troca_filhos3(np1* a);
np1* uniao3(np1* h1, np1* h2);
np1* uniao_heaps3(np1* h1, np1* h2);

//Heap esquerdista Não Prioridade 2
typedef struct no4{
	int elemento;
	int s;
	struct no4 *esq;
	struct no4 *dir;
}np2;

void menu(void);
np2* cria_heap4(int valor);
void troca_filhos4(np2* a);
np2* uniao4(np2* h1, np2* h2);
np2* uniao_heaps4(np2* h1, np2* h2);

//Heap Simples
typedef struct {
    int* v;
    int tamanho;
} heap;

void menu();
heap* criar();
void heap_libera(heap *h);
void troca(int* a, int* b);
void sobe (heap *h, int i);
void desce (heap *h, int i);
void heap_insere (heap *h, int valor);
int heap_retira (heap *h);
void mostrar(heap *h);

typedef struct Cliente{
    int num;
    int pedido;
}cliente;

typedef struct Caixa
{
    int n;
    int prioridade;
    int poi;
    int contagem;
}caixa;
