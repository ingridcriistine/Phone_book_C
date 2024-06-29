#include "contato.h" 
#include <string.h>  

int main() { 
  
    int tamanho = 1;  
    int op; 
    int im; 
    char del[50]; 
    char nome[50]; 
    int mes; 
    int dia; 

    //define o tamanho do array como 1 
    Pessoa * pessoa = malloc(tamanho * sizeof(Pessoa)); 

    while(1) 
    { 
        //menu de opcoes 
        printf("\n\n\n---------AGENDA--------"); 
        printf("\nFuncionalidades:"); 
        printf("\n1 - Adicionar contato"); 
        printf("\n2 - Remover contato"); 
        printf("\n3 - Buscar contato pelo primeiro nome"); 
        printf("\n4 - Buscar contato pelo mes de aniversario"); 
        printf("\n5 - Buscar contato pelo dia e mes de aniversario "); 
        printf("\n6 - Imprimir contato"); 

        printf("\n\nDigite o numero da funcionalidade desejada: "); 
        scanf("%i", &op); 
 
        switch (op) 
        { 
            case 1: 
              
                tamanho++; 
                pessoa = realloc(pessoa, tamanho* sizeof(Pessoa)); 

                addContato(&pessoa[tamanho-2]); 
                ordenar(pessoa, tamanho); 

                break; 
          
            case 2: 

                printf("Nome do contato: "); 
                scanf("%s", &nome); 

                removerContato(nome, pessoa, &tamanho); 

                break; 

            case 3: 

                printf("Digite o primeiro nome: "); 
                scanf("%s", &nome); 

                buscarPrimeiroNome(nome, pessoa, tamanho); 

                break; 

            case 4: 

                printf("Digite o mes de aniversario: "); 
                scanf("%i", &mes); 

                buscarMesAniver(mes, pessoa, tamanho); 

                break; 

            case 5: 

                printf("Digite o dia de aniversario: "); 
                scanf("%i", &dia); 

                printf("Digite o mes de aniversario: "); 
                scanf("%i", &mes); 

                buscarDiaMesAniver(dia, mes, pessoa, tamanho); 

                break; 

            case 6: 

                printf("\n   1 - Imprimir nome, telefone e e-mail"); 
                printf("\n   2 - Imprimir todos os dados"); 
                printf("\n   Escolha: "); 
                scanf("%i", &im); 

                imprimir(pessoa, tamanho, op); 

                break; 
        } 
    } 

    free(pessoa); 
    return 1; 
} 
