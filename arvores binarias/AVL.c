#include <stdio.h>
#include <stdlib.h>

//altura: maior distância entre o nó raiz e o nó folha

typedef struct SArvore
{
    struct SArvore *esq;
    int dado;
    struct SArvore *dir;
    short altura;
} TNo;

TNo *novoNo(int x)
{
    TNo *novo = malloc(sizeof(TNo));

    novo->dado = x;
    novo->dir = novo->esq = NULL;
    novo->altura = 0;

    return novo;
}

short alturaDoNo(TNo *no)
{
    if (no == NULL)
        return -1;
    else
        return no->altura;
}

/* retornar o maior valor dentre a e b -> alturas de dois nós na árvore */
short maior(short a, short b)
{
    return (a > b) ? a : b;
}

short fatorDeBalanceamento(TNo *no)
{
    if (no)
        return (alturaDoNo(no->esq) - alturaDoNo(no->dir));
    else
        return -1;
}

TNo *rotacaoEsquerda(TNo *r)
{
    TNo *y = r->dir;
    TNo *f = y->esq;

    y->esq = r;
    r->dir = f;

    y->altura = maior(alturaDoNo(y->esq), alturaDoNo(y->dir)) + 1;
    r->altura = maior(alturaDoNo(r->esq), alturaDoNo(r->dir)) + 1;

    return y;
}

TNo * rotacaoDireita(TNo *r)
{
    TNo *y = r->esq;
    TNo *f = y->dir;

    y->dir = r;
    r->esq = f;

    y->altura = maior(alturaDoNo(y->esq), alturaDoNo(y->dir)) + 1;
    r->altura = maior(alturaDoNo(r->esq), alturaDoNo(r->dir)) + 1;

    return y;
}

TNo *rotacaoDireitaEsquerda(TNo *r)
{
    r->dir = rotacaoDireita(r->dir);
    return rotacaoEsquerda(r);
}

TNo *rotacaoEsquerdaDireita(TNo *r)
{
    r->esq = rotacaoEsquerda(r->esq);
    return rotacaoDireita(r);
}

TNo *balancear(TNo *no)
{
    short fb = fatorDeBalanceamento(no);

    if (fb < -1 && fatorDeBalanceamento(no->dir) <= 0)
    {
        return rotacaoEsquerda(no);
    }
    else if (fb > 1 && fatorDeBalanceamento(no->esq) >= 0)
    {
        return rotacaoDireita(no);
    }
    else if (fb > 1 && fatorDeBalanceamento(no->esq) < 0)
    {
        return rotacaoEsquerdaDireita(no);
    }
    else if (fb < -1 && fatorDeBalanceamento(no->dir) > 0)
    {
        return rotacaoDireitaEsquerda(no);
    }

    return no;
}

TNo *inserirNo(TNo *no, int informacao)
{

    // Árvore vazia
    if (no == NULL)
        return novoNo(informacao);

    if (informacao > no->dado)
    {
        no->dir = inserirNo(no->dir, informacao);
    }
    else if (informacao < no->dado)
    {
        no->esq = inserirNo(no->esq, informacao);
    }
    else
    {
        printf("\nInformacao ja existe na arvore!\n");
    }

    //Recalcula a altura de todos nós no caminho da raiz até o novo nó
    no->altura = maior(alturaDoNo(no->esq), alturaDoNo(no->dir)) + 1;

    //Verifica a necessidade de balanceamento para cada nó
    no = balancear(no);

    return no;
}

TNo * buscaBinaria(TNo *no, int chave)
{
    if (no == NULL)
    {
        return NULL;
    }

    if (chave > no->dado)
    {
        return buscaBinaria(no->dir, chave);
    }
    else if (chave < no->dado)
    {

        return buscaBinaria(no->esq, chave);
    }
    else
    {
        return no;
    }

}

TNo *remover(TNo *no, int chave)
{
    if (no == NULL)
    {
        printf("\n\nValor não encontrado!");
        return NULL;
    }
    else
    {

        if (no->dado == chave)
        {
            // no é uma folha
            if (no->esq == NULL && no->dir == NULL)
            {
                printf("\n\nValor %d eliminado!", chave);
                free(no);

                return NULL;
            }
            else
            {
                // nó possui dois filhos
                if (no->esq != NULL && no->dir != NULL)
                {

                    TNo *aux = no->esq;
                    while (aux->dir != NULL)
                        aux = aux->dir;

                    no->dado = aux->dado;
                    aux->dado = chave;
                    no->esq = remover(no->esq, chave);
                    return no;
                }
                else
                { 
                    // nó possui um filho
                    TNo *aux;

                    if (no->esq != NULL)
                        aux = no->esq;
                    else
                        aux = no->dir;

                    printf("\nElemento com 1 filho removido: %d\n", chave);
                    free(no);
                    return aux;
                }
            }
        }
        else
        {

            if (chave < no->dado)
            {
                no->esq = remover(no->esq, chave);
            }
            else
            {
                no->dir = remover(no->dir, chave);
            }
        }
    }

    //Recalcula a altura de todos nós no caminho da raiz até o novo nó
    no->altura = maior(alturaDoNo(no->esq), alturaDoNo(no->dir)) + 1;

    //Verifica a necessidade de balanceamento para cada nó
    no = balancear(no);

    return no;
}

void imprimir(TNo *no, int nivel)
{
    int i;
    if(no){
        imprimir(no->dir, nivel + 1);
        printf("\n\n");

        for(i = 0; i < nivel; i++)
            printf("\t");
    
        printf("%d", no->dado);
        imprimir(no->esq, nivel + 1);
    }
}

int main()
{
    int valor, opcao;

    TNo *resultado, *raiz = NULL;

    do{
        printf("\n\n\t1.Inserir\n\t2.Remover\n\t3.Buscar\n\t4.Imprimir\n\t5.Sair\n\nDigite um valor: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite um valor para inserir: ");
            scanf("%d", &valor);

            raiz = inserirNo(raiz, valor);
            break;
        
        case 2:
            printf("\nDigite um valor para remover: ");
            scanf("%d", &valor);

            raiz = remover(raiz, valor );
            break;

        case 3:
            printf("\nDigite um valor para buscar: ");
            scanf("%d", &valor);

            resultado = buscaBinaria(raiz, valor);

            if(resultado != NULL){
                printf("\nValor %d encontrado!", resultado->dado);
            } else {
                printf("\nValor nao encontrado!");
            }
            break;

        case 4:
            imprimir(raiz, 1);
            break;
        
        case 5:
            printf("\nSaindo...\n");
            break; 

        default:
            printf("\nOpcao invalida!!!\n");
            break;
        }
    }while(opcao != 5);

    return 0;
}