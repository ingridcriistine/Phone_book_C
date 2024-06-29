#include <stdio.h>  
#include <string.h>  
#ifndef HEADER_H 
#define HEADER_H 

//Struct endereço 
typedef struct {  

    char rua[50]; 
    char num[10]; 
    char complemento[10]; 
    char bairro[30]; 
    char CEP[15]; 
    char cidade[30]; 
    char estado[30]; 
    char pais[30]; 

} Endereco; 

//Struct telefone 
typedef struct {  

    int ddd; 
    int numero; 

} Telefone; 

//Struct data de aniversário 
typedef struct {  

    int dia; 
    int mes; 
    int ano; 

} DataAniver; 

//Struct pessoa 
typedef struct {  

    char nome[50];  
    char email[50];  
    Endereco endereco; 
    Telefone telefone; 
    DataAniver aniversario; 
    char observacao[200]; 

} Pessoa; 

void addContato(Pessoa * pessoa){ 

    printf("\n\n\n---Novo contato---"); 

    printf("\n>>>Nome: "); 
    scanf("%s", &pessoa->nome); 

    printf("\n>>>E-mail: "); 
    scanf("%s", &pessoa->email); 

    printf("\n>>>Telefone: "); 
    printf("\n    DDD: "); 
    scanf("%i", &pessoa->telefone.ddd); 
    printf("\n    Numero: "); 
    scanf("%i", &pessoa->telefone.numero); 

    printf("\n>>>Endereco: "); 
    printf("\n    Rua: "); 
    scanf("%s", &pessoa->endereco.rua); 
    printf("\n    Numero: "); 
    scanf("%s", &pessoa->endereco.num); 
    printf("\n    Complemento: "); 
    scanf("%s", &pessoa->endereco.complemento); 
    printf("\n    CEP: "); 
    scanf("%s", &pessoa->endereco.CEP); 
    printf("\n    Bairro: "); 
    scanf("%s", &pessoa->endereco.bairro); 
    printf("\n    Cidade: "); 
    scanf("%s", &pessoa->endereco.cidade); 
    printf("\n    Estado: "); 
    scanf("%s", &pessoa->endereco.estado); 
    printf("\n    Pais: "); 
    scanf("%s", &pessoa->endereco.pais); 

    printf("\n>>>Data de aniversario: "); 
    printf("\n    Dia: "); 
    scanf("%i", &pessoa->aniversario.dia); 
    printf("\n    Mes: "); 
    scanf("%i", &pessoa->aniversario.mes); 
    printf("\n    Ano: "); 
    scanf("%i", &pessoa->aniversario.ano); 

    printf("\n\n>>>Observacao especial: "); 
    scanf("%s", &pessoa->observacao); 
} 

void ordenar(Pessoa * pessoa, int t) { 

    int cmp; 
    Pessoa aux; 

     for(int i = 0; i < t-1; i++)
     {  
        for(int j = 0; j < t-2; j++) 
        { 
            cmp = strcmp(pessoa[j].nome, pessoa[j+1].nome); 

            if(cmp > 0) 
            { 
                aux = pessoa[j+1]; 
                pessoa[j+1] = pessoa[j]; 
                pessoa[j] = aux; 
            } 
        } 
    }  
} 

void removerContato(char nome[], Pessoa * pessoa, int * tamanho) { 

    int cmp; 
    int a = 0; 

    for (int i = 0; i < *tamanho-1; i++) 
    { 
        cmp = strcmp(pessoa[i].nome, nome); 
        printf("%s  %s", pessoa[i].nome, nome); 

        if (cmp == 0) 
        { 
            *tamanho--; 

            for(int j = i; j < *tamanho-1; j++) 
            { 
                pessoa[j] = pessoa[j + 1]; 
            } 

            a = 1; 
        } 
    } 

    if(a != 1) 
    { 
        printf("\nNenhum contato encontrado."); 
    }
} 

void buscarPrimeiroNome(char nome[], Pessoa * pessoa, int tamanho) { 

    int cmp; 

    for (int i = 0; i < tamanho-1; i++) 
    { 
        cmp = strcmp(pessoa[i].nome, nome); 

        if (cmp == 0) 
        { 
            printf("\n\n\n--Dados do contato--"); 
            printf("\nNome: %s", pessoa[i].nome); 
            printf("\nEmail: %s", pessoa[i].email); 
            printf("\nTelefone: %i %i", pessoa[i].telefone.ddd, pessoa[i].telefone.numero); 
            printf("\nData de aniversario: %i/%i/%i", pessoa[i].aniversario.dia, pessoa[i].aniversario.mes, pessoa[i].aniversario.ano); 
        } 

        else 
        { 
            printf("\nNenhum contato encontrado."); 
        } 
    } 
} 

void buscarMesAniver(int mes, Pessoa * pessoa, int tamanho) { 

    for (int i = 0; i < tamanho-1; i++) 
    { 
        if (pessoa[i].aniversario.mes == mes) 
        { 
            printf("\n\n\n--Dados do contato--"); 
            printf("\nNome: %s", pessoa[i].nome); 
            printf("\nEmail: %s", pessoa[i].email); 
            printf("\nTelefone: %i %i", pessoa[i].telefone.ddd, pessoa[i].telefone.numero); 
            printf("\nData de aniversario: %i/%i/%i", pessoa[i].aniversario.dia, pessoa[i].aniversario.mes, pessoa[i].aniversario.ano); 
        } 

        else 
        { 
            printf("\nNenhum contato encontrado."); 
        } 
    } 
} 

void buscarDiaMesAniver(int dia, int mes, Pessoa * pessoa, int tamanho) { 

    for (int i = 0; i < tamanho-1; i++) 
    { 
        if (pessoa[i].aniversario.dia, dia && pessoa[i].aniversario.mes, mes) 
        { 
            printf("\n\n\n--Dados do contato--"); 
            printf("\nNome: %s", pessoa[i].nome); 
            printf("\nEmail: %s", pessoa[i].email); 
            printf("\nTelefone: %i %i", pessoa[i].telefone.ddd, pessoa[i].telefone.numero); 
            printf("\nData de aniversario: %i/%i/%i", pessoa[i].aniversario.dia, pessoa[i].aniversario.mes, pessoa[i].aniversario.ano); 
        } 

        else 
        { 
            printf("\nNenhum contato encontrado."); 
        } 
    } 
} 

void imprimir(Pessoa * pessoa, int t, int op) { 

    printf("\n\n\n-----------------AGENDA--------------------"); 
  
    for (int i = 0; i < t-1; i++) 
    { 
        if(op == 1) 
        { 
            printf("\n\n--------------Dados do contato--------------"); 
            printf("\nNome: %s", pessoa[i].nome); 
            printf("\nTelefone: %i %i", pessoa[i].telefone.ddd, pessoa[i].telefone.numero); 
            printf("\nE-mail: %s", pessoa[i].email); 
        } 
          
        else 
        { 
            printf("\n\n--------------Dados do contato--------------"); 
            printf("\nNome: %s", pessoa[i].nome); 
            printf("\nE-mail: %s", pessoa[i].email); 
            printf("\nEndereco: %s, %s - %s. %s", pessoa[i].endereco.rua, pessoa[i].endereco.num, pessoa[i].endereco.complemento, pessoa[i].endereco.CEP); 
            printf("\n          %s - %s - %s - %s", pessoa[i].endereco.bairro, pessoa[i].endereco.cidade, pessoa[i].endereco.estado, pessoa[i].endereco.pais); 
            printf("\nTelefone: %i %i", pessoa[i].telefone.ddd, pessoa[i].telefone.numero); 
            printf("\nData de aniversario: %i/%i/%i", pessoa[i].aniversario.dia, pessoa[i].aniversario.mes, pessoa[i].aniversario.ano); 
            printf("\nObservacao especial: %s", pessoa[i].observacao); 
        } 
    } 
} 

#endif 
