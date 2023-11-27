#include "heap.h"
#include <time.h>


void menu(){
	int op, valor,qmsou,pedido,pedido2,ordem = 100,ordem2 = 50,escolha,escolha2,hpm=100,contagempar,contagemimpar,caixaremover;
	int nc = 1;
    int contador = 1;
	int criacao = 2;
	int i = 1;
	int abertura = 0;
	int num;
	int contas=1,contas2=2;
	int caixas=0;
	int caixas2=1;
	int dq=0;
	int opcaocaixa=0;
    struct tm *data_atual;
    time_t segundos;
    time(&segundos);
    data_atual = localtime(&segundos);
	//--------- iniciando a estrutura --------------------//
    p1 *h = NULL;
    p2 *h2 = NULL;
    np1 *h3 = NULL;
    np2 *h4 = NULL;
    heap *s = criar();
    struct Cliente cliente[100];
    struct Caixa caixa[100];
    do{
    //--------------- Exibir menu ---------------------//
        system("cls");
        puts("\n\t\t\t\tLANCHONETE\n");
        puts("\t1 - ABERTURA DAS ATIVIDADES DA LANCHONETE\n\t2 - CHEGADA DE UM NOVO CLIENTE\n\t3 - REGISTRAR PEDIDO\n\t4 - PAGAMENTO DE UM PEDIDO\n\t5 - ABERTURA OU FECHAMENTO DE UM CAIXA DE COMPRA\n\t6 - CONCLUSAO DE UM PEDIDO NA COZINHA\n\t7 - FECHAMENTO DAS ATIVIDADES DA LANCHONETE");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op);//Escolha da Opção

        switch(op)
        {
         case 1:{
            printf("Nossas atividades comecaram! os caixas 1 e 2 estao abertos (1 prioritario, 2 nao prioritario)\n");
            for(int c=0;c<=1;c++)
            {
                caixa[c].n = c;
                caixa[c].prioridade = 1;
                caixa[c].poi = c+3;
                caixa[c].contagem=1;
            }
            contagemimpar =1;
            contagempar=1;
            abertura=1;
            break;
    		}
    		case 2:{
            if (abertura==1)
            {
            printf("Bem vindo, novo cliente, voce e o cliente %d!\n", nc);
            printf("O cliente entrou no sistema dia %d do mes %d do ano %d\nA entrada foi concluida as %d horas, %d minutos e %d segundos", data_atual->tm_mday, data_atual->tm_mon+1, data_atual->tm_year+1900, data_atual->tm_hour,data_atual->tm_min,data_atual->tm_sec);
            cliente[nc].num = nc;
            nc++;
            }else
            { printf("O estabelecimento nao abriu ainda");
            }
            break;
    		}
    		case 3:{
    		    if(abertura==1)
                {printf("Que cliente e voce? ");
                scanf("%d", &num);
                for(int c=1;c<=40;c++)
                {
                    if(cliente[c].num==num)
                    {
                        dq=1;
                    }
                }if(dq==1)
                {
                    printf("Qual caixa voce quer fazer o seu pedido?\n1-caixa prioritario\n2-caixa nao prioritario\n ");
                    scanf("%d", &opcaocaixa);
                    if(opcaocaixa == 1)
                    {
                        if(caixa[caixas].contagem==0)
                        {
                        printf("Digite qual o seu pedido:\n1-pedido 1\n2-pedido 2\n3-pedido 3\n4-pedido 4\n5-pedido 5:\n");
                        scanf("%d", &pedido);
                        cliente[num].pedido=pedido;
                        np1 *novo = cria_heap(ordem);
                        h3 = uniao3(h3, novo);
                        printf("Pedido anotado!\n");
                        printf("O pedido foi anotado no dia %d do mes %d do ano %d\nA entrada foi concluida as %d horas, %d minutos e %d segundos", data_atual->tm_mday, data_atual->tm_mon+1, data_atual->tm_year+1900, data_atual->tm_hour,data_atual->tm_min,data_atual->tm_sec);
                        ordem = ordem - 1;
                        caixa[caixas].contagem=1;
                        if(ordem == 50)
                        {
                            printf("Atingimos a meta do dia no caixa prioritario!");
                        }break;

                        }
                        if(caixa[caixas].contagem==1)
                        {
                        printf("Digite qual o seu pedido:\n1-pedido 1\n2-pedido 2\n3-pedido 3\n4-pedido 4\n5-pedido 5:\n");
                        scanf("%d", &pedido);
                        cliente[num].pedido=pedido;
                        p1 *novo = cria_heap(ordem);
                        h = uniao(h, novo);
                        printf("Pedido anotado!\n");
                        printf("O pedido foi anotado no dia %d do mes %d do ano %d\nA entrada foi concluida as %d horas, %d minutos e %d segundos", data_atual->tm_mday, data_atual->tm_mon+1, data_atual->tm_year+1900, data_atual->tm_hour,data_atual->tm_min,data_atual->tm_sec);
                        ordem = ordem - 1;
                        caixa[caixas].contagem=0;
                        if(ordem == 50)
                        {
                            printf("Atingimos a meta do dia no caixa prioritario!");
                        }break;

                        }

                    }if(opcaocaixa == 2)
                    {
                        if(caixa[caixas2].contagem==0)
                        {
                        printf("Digite qual o seu pedido: \n1-pedido 1\n2-pedido 2\n3-pedido 3\n4-pedido 4\n5-pedido 5:\n");
                        scanf("%d", &pedido2);
                        cliente[num].pedido=pedido2;
                        np2 *novo2 = cria_heap(ordem2);
                        h4 = uniao4(h4, novo2);
                        printf("Pedido anotado!\n");
                        printf("O pedido foi anotado no dia %d do mes %d do ano %d\nA entrada foi concluida as %d horas, %d minutos e %d segundos", data_atual->tm_mday, data_atual->tm_mon+1, data_atual->tm_year+1900, data_atual->tm_hour,data_atual->tm_min,data_atual->tm_sec);
                        ordem2 = ordem2 -1;
                        caixa[caixas2].contagem=0;
                        if(ordem == 0)
                        {
                            printf("Atingimos a meta do dia no caixa de nao prioridade!");
                        }break;
                        }
                        if(caixa[caixas2].contagem==1)
                        {
                        printf("Digite qual o seu pedido: \n1-pedido 1\n2-pedido 2\n3-pedido 3\n4-pedido 4\n5-pedido 5:\n ");
                        scanf("%d", &pedido2);
                        cliente[num].pedido=pedido2;
                        p2 *novo2 = cria_heap(ordem2);
                        h2 = uniao2(h2, novo2);
                        printf("Pedido anotado!\n");
                        printf("O pedido foi anotado no dia %d do mes %d do ano %d\nA entrada foi concluida as %d horas, %d minutos e %d segundos", data_atual->tm_mday, data_atual->tm_mon+1, data_atual->tm_year+1900, data_atual->tm_hour,data_atual->tm_min,data_atual->tm_sec);
                        ordem2 = ordem2 -1;
                        caixa[caixas2].contagem=0;
                        if(ordem == 0)
                        {
                            printf("Atingimos a meta do dia no caixa de nao prioridade!");
                        }break;
                        }

                    }
                }
                }else
                {
                    printf("O estabelecimento nao abriu ainda");
                    break;
                }

    		}

    		case 4:{
            if(abertura == 1)
            {
            printf("Digite aqui qual cliente voce e: ");
            scanf("%d", &num);
            for(int c=1;c<=40;c++)
                {
                    if(cliente[c].num==num)
                    {
                        dq=1;
                    }
                }
            if((dq==1) && (cliente[num].pedido!=0))
            {
                printf("Voce gostaria de pagar o pedido %d?\n1-Sim\n2-Nao\n", cliente[num].pedido);
                scanf("%d", &escolha);
                if(escolha==1)
                {
                 printf("Agora que seu pedido esta pago, ele sera encaminhado a fila da cozinha,\nAguarde o pedido ficar pronto\n");
                 printf("Nossa cozinha trabalha com ordem decrescente de pedidos\nLogo o seu pedido e o numero %d", hpm);
                 heap_insere(s,hpm);
                 hpm = hpm - 1;
                 break;
                }else
                {
                    printf("Entendido");
                    break;
                }

            }else
            {
                printf("\nVoce nao e cliente desse estabelecimento ou nao fez seu pedido ainda");
                break;
            }

            }else
            {
                printf("O estabelecimento ainda esta fechado!");
                break;
            }
            }

            case 5:{
                if(abertura == 1)
            {   printf("Voce deseja abrir(1) ou fechar(2) um caixa? ");
                scanf("%d", &escolha2);
                if(escolha2==1)
            {
                caixa[criacao].n = criacao;
                caixa[criacao].poi= criacao + 3;
                caixa[criacao].contagem = 1;
                printf("O caixa %d foi criado", criacao+1);
                 if(caixa[criacao].poi%2==1)
                 {
                     contagemimpar= contagemimpar+1;
                 }
                 if(caixa[criacao].poi%2==0)
                 {
                     contagempar= contagempar+1;
                 }
                if(contagemimpar>=2)
                {
                   for(int h=0;h<=100;h++)
                {
                    if(caixa[h].poi%2==1)
                    {
                        caixa[h].prioridade=0;
                    }
                }
                }
                if(contagempar>=2)
                {
                   for(int z=0;z<=100;z++)
                {
                    if(caixa[z].poi%2==0)
                    {
                        caixa[z].prioridade=0;
                    }
                }
                }
                criacao += 1;
                break;
            }if(escolha2==2)
            {
                printf("Digite aqui qual caixa voce quer fechar: ");
                scanf("%d", &caixaremover);
                if(caixaremover%2==1)
                {
             if(caixa[caixaremover-1].prioridade==0)
                {
                    if(caixa[caixaremover-1].contagem==0)
                    {
                    caixa[caixaremover-1].n=NULL;
                    caixa[caixaremover-1].poi=NULL;
                    h3 = uniao(h3,h);
                    contas = contas + 2;
                    caixas=caixas+2;
                    if(caixa[caixas].n!=NULL)
                    {
                        printf("O caixa %d foi fechado, os pedidos que ainda nao foram pagos foram movidos para o caixa %d\n", caixa[contas-2].n, caixa[contas].n);
                        imprime(h3);

                    }else
                    {
                        contas+=2;
                        printf("O caixa %d foi fechado, os pedidos que ainda nao foram pagos foram movidos para o caixa %d\n", caixa[contas-4].n, caixa[contas].n);
                        imprime(h3);

                    }caixa[caixaremover-1].contagem==1;
                    break;
                    }else
                    {
                    caixa[caixaremover-1].n=NULL;
                    caixa[caixaremover-1].poi=NULL;
                    h = uniao(h,h3);
                    contas = contas + 2;
                    caixas=caixas+2;
                    if(caixa[caixas].n!=NULL)
                    {
                        printf("O caixa %d foi fechado, os pedidos que ainda nao foram pagos foram movidos para o caixa %d\n", caixa[contas-2].n, caixa[contas].n);
                        imprime(h);

                    }else
                    {
                        contas+=2;
                        printf("O caixa %d foi fechado, os pedidos que ainda nao foram pagos foram movidos para o caixa %d\n", caixa[contas-4].n, caixa[contas].n);
                        imprime(h);

                    }caixa[caixaremover-1].contagem==0;
                    break;
                    }
                }if(caixaremover%2==0)
                {
             if(caixa[caixaremover-1].prioridade==0)
                {
                    if(caixa[caixaremover-1].contagem==0)
                    {
                    caixa[caixaremover-1].n=NULL;
                    caixa[caixaremover-1].poi=NULL;
                    h2 = uniao(h2,h4);
                    contas = contas + 2;
                    caixas=caixas+2;
                    if(caixa[caixas].n!=NULL)
                    {
                        printf("O caixa %d foi fechado, os pedidos que ainda nao foram pagos foram movidos para o caixa %d\n", caixa[contas-2].n,caixa[contas].n );
                        imprime(h2);
                    }else
                    {
                        contas+=2;
                        printf("O caixa %d foi fechado, os pedidos que ainda nao foram pagos foram movidos para o caixa %d\n", caixa[contas-4].n,caixa[contas].n );
                        imprime(h2);
                    }caixa[caixaremover-1].contagem==1;
                    break;
                }if(caixa[caixaremover-1].contagem==0)
                    {
                    caixa[caixaremover-1].n=NULL;
                    caixa[caixaremover-1].poi=NULL;
                    h4 = uniao(h4,h2);
                    contas = contas + 2;
                    caixas=caixas+2;
                    if(caixa[caixas].n!=NULL)
                    {
                        printf("O caixa %d foi fechado, os pedidos que ainda nao foram pagos foram movidos para o caixa %d\n", caixa[contas-2].n,caixa[contas].n );
                        imprime(h4);
                    }else
                    {
                        contas+=2;
                        printf("O caixa %d foi fechado, os pedidos que ainda nao foram pagos foram movidos para o caixa %d\n", caixa[contas-4].n,caixa[contas].n );
                        imprime(h4);
                    }caixa[caixaremover-1].contagem==0;
                    break;
                }
                    }
                }
                }if(caixaremover-1==0)
                {
                    if(caixa[caixaremover-1].prioridade!=1)
                    {
                    h3 = uniao3(h3, h);
                    caixa[caixaremover-1].n=NULL;
                    caixa[caixaremover-1].prioridade=NULL;
                    caixa[caixaremover-1].poi=NULL;
                    caixa[caixaremover-1].contagem=NULL;
                    contas = contas + 2;
                    caixas=caixas+2;
                    if(caixa[caixas].n!=NULL)
                    {
                        printf("O caixa 1 foi fechado, os pedidos que ainda nao foram pagos foram movidos para o caixa %d\n", caixa[contas].n);
                        imprime(h3);
                        break;
                    }else
                    {
                        contas+=2;
                        break;
                    }

                }else
                {
                    printf("Esse caixa nao pode ser removido, pois ele e o unico prioritario");
                    break;
                }
                }
                 if(caixaremover-1==1)
                {
                    if(caixa[caixaremover-1].prioridade!=1)
                    {
                        h4 = uniao4(h4, h2);
                    caixa[caixaremover-1].n=NULL;
                    caixa[caixaremover-1].prioridade=NULL;
                    caixa[caixaremover-1].poi=NULL;
                    caixa[caixaremover-1].contagem=NULL;
                    caixas2= caixas2 +2;
                    contas2=contas2+2;
                    if(caixa[caixas2].n!=NULL)
                    {
                        printf("O caixa 2 foi fechado, os pedidos que ainda nao foram pagos foram movidos para o caixa %d\n", caixa[contas2].n);
                        imprime(h4);
                        break;
                    }else
                    {
                        contas2+=2;
                        break;
                    }

                    }else
                {
                    printf("Esse caixa nao pode ser fechado, pois ele e o unico nao prioritario aberto");
                    break;
                }

                }
                break;

            }

            }else
            {
                printf("O estabelecimento nao abriu ainda!");
                break;
            }
        }

    		case 6:{
                if(abertura == 1)
            {
                if(cliente[contador].pedido!=0)
                {
                    printf("O pedido %d do cliente %d esta saindo do forno\n", cliente[contador].pedido,cliente[contador].num);
                     int removido = heap_retira(s);
                     printf("O pedido %d foi concluido\n", removido);
                     mostrar(s);
                     contador++;
                     break;


                }else
                {
                    printf("O pedido %d do cliente %d esta saindo do forno\n", cliente[contador+1].pedido,cliente[contador+1].num);
                     int removido = heap_retira(s);
                     printf("O pedido %d foi concluido\n", removido);
                     mostrar(s);
                     contador = contador + 2;
                     break;
                }

            }else
            {
                printf("O estabelecimento nao abriu ainda!");
                break;
            }

			}

        }
		getch();
	    }while(op!=7);
}


p1* cria_heap(int valor){
	p1 *h = (p1 *) malloc(sizeof(p1));
	h->esq = NULL;
	h->dir = NULL;
	h->elemento = valor;
	h->s = 1;
	return h;
}
p2* cria_heap2(int valor){
	p2 *h2 = (p2 *) malloc(sizeof(p2));
	h2->esq = NULL;
	h2->dir = NULL;
	h2->elemento = valor;
	h2->s = 1;
	return h2;
}
np1* cria_heap3(int valor){
	np1 *h3 = (heap *) malloc(sizeof(np1));
	h3->esq = NULL;
	h3->dir = NULL;
	h3->elemento = valor;
	h3->s = 1;
	return h3;
}
np2* cria_heap4(int valor){
	np2 *h4 = (np2 *) malloc(sizeof(np2));
	h4->esq = NULL;
	h4->dir = NULL;
	h4->elemento = valor;
	h4->s = 1;
	return h4;
}


void troca_filhos (p1* a){
	p1 *aux = a->esq;
	a->esq = a->dir;
	a->dir = aux;
}

p1* uniao(p1 * h1, p1* h2) {
	if(h1 == NULL) return h2;
	if(h2 == NULL) return h1;
	if(h1->elemento > h2->elemento)
		return uniao_heaps(h1, h2);
	else
		return uniao_heaps(h2, h1);
}

p2* uniao2(p2 * h1, p2* h2) {
	if(h1 == NULL) return h2;
	if(h2 == NULL) return h1;
	if(h1->elemento > h2->elemento)
		return uniao_heaps(h1, h2);
	else
		return uniao_heaps(h2, h1);
}

np1* uniao3(np1 * h1,np1* h2) {
	if(h1 == NULL) return h2;
	if(h2 == NULL) return h1;
	if(h1->elemento > h2->elemento)
		return uniao_heaps(h1, h2);
	else
		return uniao_heaps(h2, h1);
}

np2* uniao4(np2* h1, np2* h2) {
	if(h1 == NULL) return h2;
	if(h2 == NULL) return h1;
	if(h1->elemento > h2->elemento)
		return uniao_heaps(h1, h2);
	else
		return uniao_heaps(h2, h1);
}



p1* uniao_heaps(p1* h1,p1 * h2){
	if(h1->esq == NULL)
		h1->esq = h2;
	else{
		h1->dir = uniao(h1->dir, h2);
		if(h1->esq->s < h1->dir->s)
			troca_filhos(h1);
		h1->s = h1->dir->s+1;
	}
	return h1;
}

p2 * uniao_heaps2(p2* h1,p2* h2){
	if(h1->esq == NULL)
		h1->esq = h2;
	else{
		h1->dir = uniao(h1->dir, h2);
		if(h1->esq->s < h1->dir->s)
			troca_filhos(h1);
		h1->s = h1->dir->s+1;
	}
	return h1;
}

np1 * uniao_heaps3(np1* h1,np1 * h2){
	if(h1->esq == NULL)
		h1->esq = h2;
	else{
		h1->dir = uniao(h1->dir, h2);
		if(h1->esq->s < h1->dir->s)
			troca_filhos(h1);
		h1->s = h1->dir->s+1;
	}
	return h1;
}

np2 * uniao_heaps4(np2* h1,np2 * h2){
	if(h1->esq == NULL)
		h1->esq = h2;
	else{
		h1->dir = uniao(h1->dir, h2);
		if(h1->esq->s < h1->dir->s)
			troca_filhos(h1);
		h1->s = h1->dir->s+1;
	}
	return h1;
}


void imprime(p1 *h){
    if (h != NULL){
		printf("%d",h->elemento);

	    if(h->esq != NULL)
	        printf("(E:%d)",h->esq->elemento);
	    if(h->dir != NULL)
	        printf("(D:%d)",h->dir->elemento);
	    printf("\n");

	    imprime(h->esq);
	    imprime(h->dir);
 	}
}

heap* criar() {
    heap* h = (heap*)malloc(sizeof(heap));
    h->v = (int*)malloc(tamanhoheap * sizeof(int));
    h->tamanho = 0;
    return h;
}

void heap_libera(heap *h){
    free(h->v);
    free(h);
}

void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sobe(heap* h, int i) {
    int pai = (i - 1) / 2;
    while (i > 0 && h->v[i] > h->v[pai]) {
        troca(&h->v[i], &h->v[pai]);
        i = pai;
        pai = (i - 1) / 2;
    }
}

void desce(heap* h, int i) {
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
    int maior = i;

    if (esquerda < h->tamanho && h->v[esquerda] > h->v[maior])
        maior = esquerda;

    if (direita < h->tamanho && h->v[direita] > h->v[maior])
        maior = direita;

    if (maior != i) {
        troca(&h->v[i], &h->v[maior]);
        desce(h, maior);
    }
}

void heap_insere (heap *h, int valor) {
    if (h->tamanho == tamanhoheap) {
        printf("A cozinha esta cheia");
        return;
    }

    h->v[h->tamanho] = valor;
    sobe(h, h->tamanho);
    h->tamanho++;
}

int heap_retira (heap *h) {
    if (h->tamanho == 0) {
        printf("A cozinha esta vazia");
        return -1;
    }

    int max = h->v[0];
    h->v[0] = h->v[h->tamanho - 1];
    h->tamanho--;
    desce(h, 0);
    return max;
}

void mostrar(heap *h){

		int i=0;
		puts("Pedidos restantes na cozinha: ");
		for(int i=0;i<h->tamanho;i++)
			printf("%d -", h->v[i]);
}

