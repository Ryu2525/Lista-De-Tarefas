#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

void printMenu(){ // usada para printar o menu toda vez que acontece alguma ação no programa
    printf("\nGerenciador de Tarefas\n");
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

///////////////////////////////////////////////////////////////////////////////////////////////////

int criarTarefa(ListaDeTarefas *lt) { // Cria as tarefas para dentro do struct

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

        printf("Digite o estado da atividade (completo|em andamento|nao iniciado): ");
        scanf(" %[^\n]", lt->tarefas[lt->qtd].estado);

        printf("Tarefa adicionada com sucesso!\n");
    }
    else{ // se a lista tiver mais de 100 nao vai deixar criar mais tarefas
        printf("Sua lista de tarefas esta cheia!");
    }
    lt->qtd++;// estrutura que pula pra proxima linha do arquivo para que o usuario nao salve as novas tarefas em cima das outras
    return 0;
}

int DeletarTarefa(ListaDeTarefas *lt){ // deleta a tarefa escolhida pelo indice dela que esta entre 0 a 99
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


int ListarTarefa(ListaDeTarefas lt){ // lista as tarefas sem filtro
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

int AlterarTarefa(ListaDeTarefas *lt){ // Se houver algum erro na hora da criação da tarefa, o usuario pode trocar alguma informação escolhendo o indice da tarefa
    int tarefaEscolhida;
    int escolha;
    int tarefaEncontrado = 0;

    printf("Escolha a Tarefa: ");
    scanf("%d", &tarefaEscolhida);
    clearBuffer();

    for(int i = 0; i < lt->qtd; i++){
        if(i == tarefaEscolhida){
            printf("Escolha a opcao que deseja modificar(1 Descricao, 2 Categoria, 3 Prioridade, 4 Estado): "); // escolhe a area que deseja modificar
            scanf("%d", &escolha);
            clearBuffer();

            // logica de modificar a area que deseja
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
        if(!tarefaEncontrado){ // caso nao exista a tarefa
            printf("Tarefa não encontrado!\n");
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int FiltrarPrioridade(ListaDeTarefas lt){// Função para filtrar pela prioridade
    int prioridade;

    printf("Escolha a prioridade (0 a 10): ");//O usuario vai poder escolher qual vai ser a prioridade que deseja ver
    scanf("%d", &prioridade);
    clearBuffer();
    int verificar = 0;

    for(int i = 0; i < lt.qtd; i++){
        if(lt.tarefas[i].prioridade == prioridade){ // comparação que filtra pelas prioridades iguais encontrado na lista
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
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

int FiltrarEstado(ListaDeTarefas lt){ // filtra pelo estado da tarefa: Completo, em andamento ou nao iniciada
    char estado[15];

    printf("Escolha o estado (completo|em andamento|nao iniciado): ");//O usuario vai poder escolher qual vai ser a prioridade que deseja ver
    scanf(" %[^\n]", estado);
    clearBuffer();
    int verificar = 0;

    for(int i = 0; i < lt.qtd; i++){
        if(strcmp(lt.tarefas[i].estado, estado) == 0){ // logica de comparação para ver o estado que as tarefas estão
            printf("Estado: %s\n", lt.tarefas[i].estado);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("\n");
            
            verificar = 1;
        }    
    }
    if (!verificar){
        printf("Não existe tarefa com esse estado\n");
    }  

    return 0;
}

///////////////////////////////////////////////////////////////////categoria
int FiltrarCategoria(ListaDeTarefas lt){//preciso terminar
    char categoria[50];
    char categorias_impressas[100][50];
    int num_categorias_impressas = 0;

    printf("Categorias disponiveis: ");
    //função de printar as categorias existentes
    for (int i = 0; i < lt.qtd; i++) {
        int categoria_repetida = 0;
        for (int j = 0; j < num_categorias_impressas; j++) {
            if (strcmp(lt.tarefas[i].categoria, categorias_impressas[j]) == 0) {
                categoria_repetida = 1;
                break;
            }
        }

        if (!categoria_repetida) {
            printf("%s, ", lt.tarefas[i].categoria);
            strcpy(categorias_impressas[num_categorias_impressas], lt.tarefas[i].categoria);
            num_categorias_impressas++;
        }
    }

    printf("Escolha a categoria: \n");//O usuario vai poder escolher qual vai ser a prioridade que deseja ver
    scanf(" %[^\n]", categoria);
    clearBuffer();
    int verificar = 0;

    for(int i = 0; i < lt.qtd; i++){
        if(strcmp(lt.tarefas[i].categoria, categoria) == 0){
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Estado: %s\n", lt.tarefas[i].estado);
            printf("\n");
            
            verificar = 1;
        }    
    }
    if (!verificar){
        printf("Não existe tarefa com essa categoria\n");
    }  


    return 0;
}
/////////////////////////////////////////////////////////////////////categoria

int FiltrarPrioridadeCategoria(ListaDeTarefas lt){ // filtrar por duas coisas: categoria e prioridade. Então se essas duas condições não forem satisfeita a tarefa nao aparece
    char categoria[50];
    int prioridade;

    printf("Categorias disponiveis: ");

    char categorias_impressas[100][50];
    int num_categorias_impressas = 0;

    //função de printar as categorias existentes
    for (int i = 0; i < lt.qtd; i++) {
        int categoria_repetida = 0;
        for (int j = 0; j < num_categorias_impressas; j++) {
            if (strcmp(lt.tarefas[i].categoria, categorias_impressas[j]) == 0) {
                categoria_repetida = 1;
                break;
            }
        }

        if (!categoria_repetida) {
            printf("%s, ", lt.tarefas[i].categoria);
            strcpy(categorias_impressas[num_categorias_impressas], lt.tarefas[i].categoria);
            num_categorias_impressas++;
        }
    }

    printf("\nEscolha a categoria: ");
    scanf(" %[^\n]", categoria);

    printf("Escolha a prioridade (0 a 10)");
    scanf("%d", &prioridade);

    int verificar = 0;

    for(int i = 0; i < lt.qtd; i++){
        if(lt.tarefas[i].prioridade == prioridade && strcmp(lt.tarefas[i].categoria, categoria) == 0){ // logica de comparação da prioridade e categoria
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Descricao: %s\n", lt.tarefas[i].descricao);
            printf("Estado: %s\n", lt.tarefas[i].estado);
            printf("\n");

            verificar = 1;
        }
    }
    if (!verificar){
        printf("Não existe essa tarefa\n");
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ExportarPrioridadeParaArquivo(ListaDeTarefas lt) { // Exportar para o arquivo exportar.txt as tarefas que apresentam prioridade iguais
    int prioridade;

    printf("Escolha a prioridade (0 a 10): ");//O usuario vai poder escolher qual vai ser a prioridade que deseja ver
    scanf("%d", &prioridade);
    clearBuffer();

    FILE *arquivo;
    arquivo = fopen("exportar.txt", "w"); // Abre o arquivo para escrita (cria um novo arquivo se não existir)

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo para escrita.\n");
        return 1; // Retorna um código de erro
    }

    int verificar = 0;

    for (int i = 0; i < lt.qtd; i++) {
        if (lt.tarefas[i].prioridade == prioridade) { // logica de printar no arquivo txt
            fprintf(arquivo, "Prioridade: %d\n", lt.tarefas[i].prioridade);
            fprintf(arquivo, "Categoria: %s\n", lt.tarefas[i].categoria);
            fprintf(arquivo, "Estado: %s\n", lt.tarefas[i].estado);
            fprintf(arquivo, "Descricao: %s\n", lt.tarefas[i].descricao);
            fprintf(arquivo, "\n");

            verificar = 1;
        }
    }

    fclose(arquivo); // Fecha o arquivo

    if (!verificar) {
        printf("Não existe tarefa com essa prioridade.\n");
        return 1; // Retorna um código de erro
    }

    printf("Tarefas exportadas com sucesso para o arquivo 'exportar.txt'.\n");
    return 0;
}

/////////////////////////////categoria
int ExportarCategoria(ListaDeTarefas lt){
    char categoria[50];
    char categorias_impressas[100][50];
    int num_categorias_impressas = 0;

    printf("Categorias disponiveis: ");

    //função de printar as categorias existentes
    for (int i = 0; i < lt.qtd; i++) {
        int categoria_repetida = 0;
        for (int j = 0; j < num_categorias_impressas; j++) {
            if (strcmp(lt.tarefas[i].categoria, categorias_impressas[j]) == 0) {
                categoria_repetida = 1;
                break;
            }
        }

        if (!categoria_repetida) {
            printf("%s, ", lt.tarefas[i].categoria);
            strcpy(categorias_impressas[num_categorias_impressas], lt.tarefas[i].categoria);
            num_categorias_impressas++;
        }
    }

    printf("\nEscolha a categoria: ");//O usuario vai poder escolher qual vai ser a prioridade que deseja ver
    scanf(" %[^\n]", categoria);
    clearBuffer();

    FILE *arquivo;
    arquivo = fopen("exportar.txt", "w"); // Abre o arquivo para escrita (cria um novo arquivo se não existir)

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo para escrita.\n");
        return 1; // Retorna um código de erro
    }

    int verificar = 0;

    for (int i = 0; i < lt.qtd; i++) {
        if (strcmp(lt.tarefas[i].categoria, categoria) == 0) { // logica de ver se a categoria e a prioridade são existem em alguma tarefa
            fprintf(arquivo, "Prioridade: %d\n", lt.tarefas[i].prioridade);
            fprintf(arquivo, "Categoria: %s\n", lt.tarefas[i].categoria);
            fprintf(arquivo, "Estado: %s\n", lt.tarefas[i].estado);
            fprintf(arquivo, "Descricao: %s\n", lt.tarefas[i].descricao);
            fprintf(arquivo, "\n");

            verificar = 1;
        }
    }

    fclose(arquivo); // Fecha o arquivo

    if (!verificar) {
        printf("Não existe essa tarefa.\n");
        return 1; // Retorna um código de erro
    }

    printf("Tarefas exportadas com sucesso para o arquivo 'exportar.txt'.\n");
    return 0;
}
//////////////////////////////////////////

int ExportarPrioridadeCategoria(ListaDeTarefas lt){ // exportar informações para o arquivo exportar.txt
    char categoria[50];
    int prioridade;

    printf("Categorias disponiveis: ");

    char categorias_impressas[100][50];
    int num_categorias_impressas = 0;

    //função de printar as categorias existentes
    for (int i = 0; i < lt.qtd; i++) {
        int categoria_repetida = 0;
        for (int j = 0; j < num_categorias_impressas; j++) {
            if (strcmp(lt.tarefas[i].categoria, categorias_impressas[j]) == 0) {
                categoria_repetida = 1;
                break;
            }
        }

        if (!categoria_repetida) {
            printf("%s, ", lt.tarefas[i].categoria);
            strcpy(categorias_impressas[num_categorias_impressas], lt.tarefas[i].categoria);
            num_categorias_impressas++;
        }
    }

    printf("\nEscolha a categoria: ");
    scanf(" %[^\n]", categoria);

    printf("Escolha a prioridade (0 a 10): ");
    scanf("%d", &prioridade);

    FILE *arquivo;
    arquivo = fopen("exportar.txt", "w"); // Abre o arquivo para escrita (cria um novo arquivo se não existir)

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo para escrita.\n");
        return 1; // Retorna um código de erro
    }

    int verificar = 0;

    for (int i = 0; i < lt.qtd; i++) {
        if (lt.tarefas[i].prioridade == prioridade && strcmp(lt.tarefas[i].categoria, categoria) == 0) { // logica de ver se a categoria e a prioridade são existem em alguma tarefa
            fprintf(arquivo, "Prioridade: %d\n", lt.tarefas[i].prioridade);
            fprintf(arquivo, "Categoria: %s\n", lt.tarefas[i].categoria);
            fprintf(arquivo, "Estado: %s\n", lt.tarefas[i].estado);
            fprintf(arquivo, "Descricao: %s\n", lt.tarefas[i].descricao);
            fprintf(arquivo, "\n");

            verificar = 1;
        }
    }

    fclose(arquivo); // Fecha o arquivo

    if (!verificar) {
        printf("Não existe essa tarefa.\n");
        return 1; // Retorna um código de erro
    }

    printf("Tarefas exportadas com sucesso para o arquivo 'exportar.txt'.\n");
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