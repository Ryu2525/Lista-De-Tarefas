#include <stdio.h>
#include "biblioteca.h"

//Julian, Eric Antunes, Letizia

int main() {


    ListaDeTarefas lt; //criamos a lista de tarefas lt que servirá para
    int cod;
    char arquivo[] = "salvo.txt";


    cod = carregarLista(&lt, arquivo);// carrega o arquivo ao abrir o codigo
    if(cod == 1){
        lt.qtd = 0;
    }

    int opcao;
    do{ //Lista com as interações que o usuario pode fazer com o programa
        printMenu();
        printf(">>> ");
        scanf("%d", &opcao);

        if(opcao == 1){
            criarTarefa(&lt);
        }
        else if(opcao == 2){
            DeletarTarefa(&lt);
        }
        else if(opcao == 3){
            ListarTarefa(lt);
        }

    }while(opcao != 4); // permite que o usuário saia do programa

    //Logica que salva todas as funções feitas dentro do arquivo
    cod = salvarLista(&lt, "salvo.txt");
    if(cod != 0){
        printf("Erro ao salvar as tarefas");
    }
    return 0;
}
