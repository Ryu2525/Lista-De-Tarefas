#ifndef UNTITLED3_BIBLIOTECA_H
#define UNTITLED3_BIBLIOTECA_H

typedef struct  { // struct que mostra onde vai ser salvo cada tipo de conteudo
    char descricao[300];
    char categoria[100];
    int prioridade;
    char estado[15];
}Tarefa;

typedef struct{ // struct que armazenará cada tarefa
    Tarefa tarefas[100];
    int qtd;
}ListaDeTarefas;

int criarTarefa(ListaDeTarefas *lt);
int DeletarTarefa(ListaDeTarefas *lt);
int ListarTarefa(ListaDeTarefas lt);

void printMenu();
void clearBuffer(); 

int salvarLista(ListaDeTarefas *lt, char nome[]);
int carregarLista(ListaDeTarefas *lt, char nome[]);

#endif //UNTITLED3_BIBLIOTECA_H
