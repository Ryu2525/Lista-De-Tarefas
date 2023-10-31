#include <stdio.h>
#include "biblioteca.h"

//Julian, Eric Antunes, Letizia

int main() {


    ListaDeTarefas lt; //criamos a lista de tarefas lt que servirá para
    int cod;
    int cod1;
    char arquivo[] = "salvo.txt";
    char arquivo1[] = "exportar.txt";


    cod = carregarLista(&lt, arquivo);// carrega o arquivo ao abrir o codigo
    cod1 = carregarExportar(&lt, arquivo1);
    if(cod == 1 && cod1 == 1){
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
        else if(opcao == 4){
            AlterarTarefa(&lt);
        }
        else if(opcao == 5){
            FiltrarPrioridade(lt);
        }
        
        else if(opcao == 6){
            FiltrarEstado(lt);
        }
        
        else if(opcao == 7){
            // int FiltrarCategoria(lt);
        }
        
        else if(opcao == 8){
            FiltrarPrioridadeCategoria(lt);
        }
        
        else if(opcao == 9){
            ExportarPrioridadeParaArquivo(lt);
        }
        
        else if(opcao == 10){
            // int ExportarCategoria(lt);
        }
        
        else if(opcao == 11){
            // int ExportarPrioridadeCategoria(lt);
        }

    }while(opcao != 0); // permite que o usuário saia do programa

    //Logica que salva todas as funções feitas dentro do arquivo
    cod = salvarLista(&lt, "salvo.txt");
    cod1 = Exportar(&lt, "exportar.txt");
    if(cod != 0 && cod1 != 0){
        printf("Erro ao salvar as tarefas");
    }
    return 0;
}
