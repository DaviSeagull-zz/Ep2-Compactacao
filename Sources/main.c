#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void cleanScreen() {
    system("cls||clear");
}

void menu() {

    printf("*****************************************************\n");
    printf("*                                                   *\n");
    printf("*          Projeto e Analise de Algoritmos          *\n");
    printf("*        Ep2 - Compactacao e Descompactacao         *\n");
    printf("*                                                   *\n");
    printf("*                    Criado Por:                    *\n");
    printf("*           31746357 - Davi Gomes Seagull           *\n");
    printf("*                                                   *\n");
    printf("*****************************************************\n");

    printf("\nMenu de escolha do exercicio \n");
    printf("0 - Sair\n");
    printf("1 - Exercicio 1\n");
    printf("2 - Exercicio 2\n");
    printf("3 - Exercicio 3\n");

    printf("\nOpcao: ");
    int opc;
    scanf("%d", &opc);

    while(true) {
        switch (opc) {
            case 0:
                cleanScreen();
                exit(0);
                break;
            case 1:
                cleanScreen();
                ex1();
                break;
            case 2:
                cleanScreen();
                ex2();
                break;
            case 3:
                cleanScreen();
                ex3();
                break;
            default:
              printf("Voce digitou uma opcao invalida. Tente novamente\n");
              break;
        }
    }
}

void ex1(){

}

void ex2(){

}

void ex3(){

}
int main() {

    menu();
    return 0;

}
