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
int main(){
    int capacidade = 2;
    int resposta,count_pessoa = 0;
    Pessoa *p = malloc(capacidade * sizeof(Pessoa));
    if(p == NULL){
        printf("\nMemoria insuficiente para iniciar o sistema.\n");
        return 1;
    }
    
    do
    {
        printf("1 - Adicionar Cadastro\n2 - Atualizar Cadastro\n3 - Remover Cadastro\n4 - Exibir Cadastro\n0 - Sair\nEscolha: ");
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            if (count_pessoa == capacidade){
                capacidade *= 2;
                Pessoa *temp = realloc(p, capacidade * sizeof(Pessoa));
                if (temp == NULL){
                    printf("\nMemoria insuficiete para iniciar o sistema.\n");
                    return 1;
                }
                p = temp;
            }
            adicionarCadastro(p,&count_pessoa);
            break;
        case 2:
            if(count_pessoa == 0){
                printf("\nNão há usuarios cadastrados no momento\n\n");
                break;
            }
            atualizarCadastro(p,&count_pessoa);
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            printf("\nEncerrando...\n");
            break;
        default:
            printf("\nOpção inválida! Tente novamente!\n");
            break;
        }
    } while (resposta != 0);
      free(p);
    
return 0;
}

void adicionarCadastro(Pessoa *p, int* quantidade){

    int i = (*quantidade);
    printf("Nome completo: ");
    scanf(" %[^\n]", p[i].nome);
    printf("CPF (somente números): ");
    scanf("%d", &p[i].cpf);
    printf("Data de nascimento (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &p[i].data_nasc.dia,&p[i].data_nasc.mes,&p[i].data_nasc.ano);
    
    printf("    Cadastro realizado com sucesso!\n");
    (*quantidade)++;
}

void atualizarCadastro(Pessoa *p,int* count_pessoa){

}