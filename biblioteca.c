#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

void printMenu(){ // usada para printar o menu toda vez que acontece alguma ação no programa
    printf("\nGerenciador de Tarefas\n");
    printf("Escolha a funcao:\n");
    printf("1 Adicionar nova tarefa\n");
    printf("2 Deletar tarefa\n");
    printf("3 Listar tarefas\n");
    printf("4 Alterar Tarefa\n");
    printf("5 Filtrar por prioridade\n");
    printf("6 Filtrar por estado\n");
    printf("7 Filtrar por Categoria\n");
    printf("8 Filtrar por Prioridade e Categoria\n");
    printf("9 Exportar por Prioridade\n");
    printf("10 Exportar por Categoria\n");
    printf("11 Exportar por Prioridade e Categoria\n");
    printf("0 Sair\n");
}

int criarTarefa(ListaDeTarefas *lt) {

    if (lt->qtd < 100) { // se a lista tiver menos que 100 tarefas, é possivel configurar uma
        printf("Digite a descricao: ");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].descricao);
        clearBuffer();

        printf("Digite a prioridade (0 a 10):");
        scanf(" %d", &lt->tarefas[lt->qtd].prioridade);
        clearBuffer();

        printf("Digite a categoria:");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].categoria);
        clearBuffer();

        printf("Digite o estado da atividade (completo|em andamento|não iniciado): ");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].estado);

        printf("Tarefa adicionada com sucesso!\n");
    }
    else{
        printf("Sua lista de tarefas esta cheia!");
    }
    lt->qtd++;// estrutura que pula pra proxima linha do arquivo para que o usuario nao salve as novas tarefas em cima das outras
    return 0;
}

int DeletarTarefa(ListaDeTarefas *lt){
    int tarefaEscolhida;
    printf("Qual tarefa voce deseja deletar? (0 a 99)"); // informa a tarefa a ser deletada
    scanf("%d", &tarefaEscolhida);
    clearBuffer();

    for (int i = tarefaEscolhida; i < 100; i++){
        lt->tarefas[i] = lt->tarefas[i + 1];
    }

    lt->qtd--;// ao deletar uma tarefa, as posições das restante devem "descer" para uma posição abaixo da que estava
    return 0;
}


int ListarTarefa(ListaDeTarefas lt){
        for (int i = 0; i < lt.qtd; i++){ //apenas aparece as tarefas já estabelecidas
            printf("Tarefa %d\n", i);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Estado: %s\n", lt.tarefas[i].estado);
            printf("\n");
        }
    return 0;
}

int AlterarTarefa(ListaDeTarefas *lt){
    int tarefaEscolhida;
    int escolha;
    int tarefaEncontrado = 0;

    printf("Escolha a Tarefa: ");
    scanf("%d", &tarefaEscolhida);
    clearBuffer();

    for(int i = 0; i < lt->qtd; i++){
        if(i == tarefaEscolhida){
            printf("Escolha a opcao que deseja modificar(1 Descricao, 2 Categoria, 3 Prioridade, 4 Estado): ");
            scanf("%d", &escolha);
            clearBuffer();

            if(escolha == 1){
                printf("Escreva a nova descricao: ");
                scanf(" %[^\n]", lt->tarefas[i].descricao);
                clearBuffer();
                printf("Alteracao realizada com sucesso!\n");

            }else if(escolha == 2){
                printf("Escreva a nova categoria: ");
                scanf(" %[^\n]", lt->tarefas[i].categoria);
                clearBuffer();
                printf("Alteracao realizada com sucesso!\n");

            }else if(escolha == 3){
                printf("Escreva a nova prioridade(0 a 10): ");
                scanf(" %d", &lt->tarefas[i].prioridade);
                clearBuffer();
                printf("Alteracao realizada com sucesso!\n");

            }else if(escolha == 4){
                printf("Escreva o novo estado: ");
                scanf(" %[^\n]", lt->tarefas[i].estado);
                clearBuffer();
                printf("Alteracao realizada com sucesso!\n");

            }
            tarefaEncontrado = 1;
            }
        }
        if(!tarefaEncontrado){
            printf("Tarefa não encontrado!\n");
    }
    return 0;
}


int FiltrarPrioridade(ListaDeTarefas lt){// Função para filtrar pela prioridade
    int prioridade;

    printf("Filtrar pela prioridade (0 a 10)\n");//O usuario vai poder escolher qual vai ser a prioridade que deseja ver
    scanf("%d", &prioridade);
    clearBuffer();
    int verificar = 0;

    for(int i = 0; i < lt.qtd; i++){
        if(lt.tarefas[i].prioridade == prioridade){
            printf("Tarefa %d\n", i);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Estado: %s\n", lt.tarefas[i].estado);
            printf("\n");

            verificar = 1;
        }
    }
    if (!verificar){
        printf("Não existe tarefa com essa prioridade\n");
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void clearBuffer(){ //evita erros com a função scanf
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int salvarLista(ListaDeTarefas *lt, char nome[]){ // "escreve" em uma arquivo a lista de tarefas em binário para salvá-la
    FILE *f = fopen(nome, "wb");
    if(f == NULL){
        return 1;
    }else {
        fwrite(lt, sizeof(ListaDeTarefas), 1, f);
        fclose(f);
    }
    return 0;
}
int carregarLista(ListaDeTarefas *lt, char nome[]){ // "lê" as informações em binário para que sejam usadas no programa toda vez que for iniciado
    FILE *f = fopen(nome, "rb");
    if (f == NULL){
        return 1;
    }
    else{
        fread(lt, sizeof(ListaDeTarefas),1, f);
        fclose(f);
    }
    return 0;
}
