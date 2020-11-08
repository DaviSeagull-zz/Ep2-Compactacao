#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void cleanScreen() {
    system("cls||clear");
    //teste
}

char getString() {
    int counter = 0;
    char string[1000];
    for(int i = 0; i < 1000; i++){
        string[i] = NULL;
    }
    printf("String desejada: ");
    gets(string);
    for(int i = 0; i < 1000; i++){
        if(string[i] == NULL)
            break;
        counter ++;
    }
    char string2[counter];

    for(int i = 0; i < counter; i++){
        string2[i] = string[i];
    }

    puts(string2);

}

void menu() {

    printf("    ********************************************************\n");
    printf("    *                                                      *\n");
    printf("    *           Projeto e Analise de Algoritmos            *\n");
    printf("    *          Ep2 - Compactacao e Descompactacao          *\n");
    printf("    *                                                      *\n");
    printf("    *                      Criado Por:                     *\n");
    printf("    *            31746357 - Davi Gomes Seagull             *\n");
    printf("    *      41908406 - Pedro Henrique Rodrigues Correa      *\n");
    printf("    *                                                      *\n");
    printf("    ********************************************************\n");

    printf("\nMenu de escolha do exercicio \n");
    printf("0 - Sair\n");
    printf("1 - Exercicio 1\n");
    printf("2 - Exercicio 2\n");
    printf("3 - Exercicio 3\n");

    while(true) {
        printf("\nOpcao: ");
        int opc;
        scanf("%d", &opc);

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
                printf("\nVoce digitou uma opcao invalida. Tente novamente\n");
                break;
        }
    }
}

void ex1(){
//comecando o ex
    getString();
}

void ex2(){

}

void ex3(){

}

int main() {

    menu();
    return 0;

}
