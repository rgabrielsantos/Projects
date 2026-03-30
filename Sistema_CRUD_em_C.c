#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} DATA;

typedef struct
{
    char nome[120];
    int cpf;
    DATA data_nasc;
} Pessoa;


void adicionarCadastro(Pessoa *p, int* quantidade);
void atualizarCadastro(Pessoa *p, int* count_pessoa);
void removerCadastro(Pessoa *p, int* count_pessoa);
void exibirCadastro(Pessoa *p, int count_pessoa);

int main()
{
    int capacidade = 2;
    int resposta, count_pessoa = 0;

    Pessoa *p = malloc(capacidade * sizeof(Pessoa));
    if(p == NULL)
    {
        printf("\nMemoria insuficiente para iniciar o sistema.\n");
        return 1;
    }

    do
    {
        printf("\n1 - Adicionar Cadastro\n2 - Atualizar Cadastro\n3 - Remover Cadastro\n4 - Exibir Cadastro\n0 - Sair\nEscolha: ");
        scanf("%d", &resposta);

        switch (resposta)
        {
        case 1:
            if (count_pessoa == capacidade)
            {
                capacidade *= 2;
                Pessoa *temp = realloc(p, capacidade * sizeof(Pessoa));
                if (temp == NULL)
                {
                    printf("\nMemoria insuficiente para expandir o sistema.\n");
                    return 1;
                }
                p = temp;
            }
            adicionarCadastro(p, &count_pessoa);
            break;

        case 2:
            if(count_pessoa == 0)
            {
                printf("\nNão há usuarios cadastrados no momento\n\n");
                break;
            }
            atualizarCadastro(p, &count_pessoa);
            break;

        case 3:

            if(count_pessoa == 0)
            {
                printf("\nNão há usuarios cadastrados no momento\n\n");
                break;
            }
            removerCadastro(p, &count_pessoa);
            break;

        case 4:
            if(count_pessoa == 0)
            {
                printf("\nNão há usuarios cadastrados no momento\n\n");
                break;
            }
            exibirCadastro(p, count_pessoa);
            break;

        case 0:
            printf("\nEncerrando o sistema...\n");
            break;

        default:
            printf("\nOpção inválida! Tente novamente!\n");
            break;
        }
    }
    while (resposta != 0);


    free(p);

    return 0;
}



void adicionarCadastro(Pessoa *p, int* quantidade)
{
    int i = (*quantidade);
    printf("Nome completo: ");
    scanf(" %[^\n]", p[i].nome);
    printf("CPF (somente números): ");
    scanf("%d", &p[i].cpf);

    printf("Data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &p[i].data_nasc.dia, &p[i].data_nasc.mes, &p[i].data_nasc.ano);

    printf("    Cadastro realizado com sucesso!\n");
    (*quantidade)++;
}

void atualizarCadastro(Pessoa *p, int *count_pessoa)
{
    printf("Buscar pelo CPF (somente números): ");
    int busca, count_busca = (*count_pessoa), achou = -1;
    scanf("%d", &busca);

    for (int i = 0; i < count_busca; i++)
    {
        if (p[i].cpf == busca)
        {
            achou = i;
            break;
        }
    }

    if (achou != -1)
    {
        printf("\n  Cadastro encontrado!\n");
        printf("Escolha qual o tipo de alteração:\n1 - Nome\n2 - CPF\n3 - Data de nascimento\n0 - Retornar ao menu principal\nEscolha: ");

        int escolha;
        scanf("%d", &escolha);

        switch(escolha)
        {
        case 1:
            printf("\nDigite o novo Nome: ");
            scanf(" %[^\n]", p[achou].nome);
            printf("\nNome alterado com sucesso!\n");
            return;

        case 2:
            printf("\nDigite o novo CPF: ");
            scanf("%d", &p[achou].cpf);
            printf("\nCPF alterado com sucesso!\n");
            return;

        case 3:
            printf("\nDigite a nova Data de Nascimento (DD MM AAAA): ");
            scanf("%d %d %d", &p[achou].data_nasc.dia, &p[achou].data_nasc.mes, &p[achou].data_nasc.ano);
            printf("\nData alterada com sucesso!\n");
            return;

        case 0:
            printf("\nRetornando...\n");
            return;

        default:
            printf("\nOpção inválida! Tente novamente!\n");
            return;
        }
    }
    else
    {
        printf("\n  Cadastro não encontrado!\n");
    }
}

void removerCadastro(Pessoa *p, int *count_pessoa)
{
    printf("Buscar pelo CPF para remover (somente números): ");

    int busca, count_busca = (*count_pessoa), achou = -1;
    scanf("%d", &busca);


    for (int i = 0; i < count_busca; i++)
    {
        if (p[i].cpf == busca)
        {
            achou = i;
            break;
        }
    }


    if (achou != -1)
    {

        for (int i = achou; i < count_busca - 1; i++)
        {
            p[i] = p[i + 1];
        }


        (*count_pessoa)--;
        printf("\n  Cadastro removido com sucesso!\n");
    }
    else
    {
        printf("\n  Cadastro não encontrado!\n");
    }
}

void exibirCadastro(Pessoa *p, int count_pessoa)
{
    for(int i = 0; i < count_pessoa; i++)
    {
        printf("\n--- %dº Cadastrado ---\n", i + 1);
        printf("Nome: %s\n", p[i].nome);
        printf("CPF: %d\n", p[i].cpf);
        printf("Data de nascimento: %02d/%02d/%d\n", p[i].data_nasc.dia, p[i].data_nasc.mes, p[i].data_nasc.ano);
        printf("----------------------\n");
    }
}