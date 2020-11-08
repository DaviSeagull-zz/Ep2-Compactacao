#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EX1 1
#define EX2 2
#define EX3 3

void cleanScreen() {
    system("cls||clear");
}

//void getString(char * s, int ex){
//    if (ex == 1 || ex == 3){
//        printf ("Insira a string que deseja compactar: ");
//        scanf("%s", s);
//        printf("nome: %s", s);
//    }
//}

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



    while(true) {

        printf("\nMenu de escolha do exercicio \n");
        printf("0 - Sair\n");
        printf("1 - Exercicio 1\n");
        printf("2 - Exercicio 2\n");
        printf("3 - Exercicio 3\n");

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

    char s[] = gets();
    printf("%s" , s)
}

void ex2(){

}

void ex3(){

}

int main() {

    menu();
    return 0;

}
