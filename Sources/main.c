#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define EX1 1
#define EX2 2
#define EX3 3

void cleanScreen() {
    system("cls||clear");
}

void simpleCompression(char *s){
    char armazena[10];
    int index[10];
    int counter = 0;
    int counter2 = 0;

    for(int i = 0; i < 10; i++){
        armazena[i] = NULL;
    }
    for(int i = 0; i < 10; i++){
        index[i] = NULL;
    }
    for(int i = 0; i <= strlen(s); i++){
        if((s[i] != s[i-1]) || i == 0){
            if(i != 0){
                index[counter2] = counter;
                counter2++;
                counter = 0;
            }
            counter++;
            armazena[counter2] = s[i];
        }
        if(s[i] == s[i-1]){
            counter++;
        }
    }
    for (int i = 0; i < strlen(armazena); i++) {
        if(i != strlen(armazena) - 1)
            printf("%c %i - ", armazena[i], index[i]);
        else
            printf("%c %i", armazena[i], index[i]);
    }
}

char * setString(int ex) {
    if (ex == 1 || ex == 3){
        char * s;
        char aux[1000];
        int counter = 1;

        printf("String desejada: ");
        gets(aux);

        for(int i = 0; i < 1000; i++){
            if(aux[i] == "\0")
                break;
            counter++;
        }
        char aux2[counter];

        for(int i = 0; i < counter; i++){
            aux2[i] = aux[i];
        }
        s = &aux2;
        return s;
    }
}

void setLower(char * s) {
    char a[strlen(s)];
    strcpy(a,s);
    for (int i = 0; i < (strlen(s)); i++)
        s[i] = tolower(a[i]);
}

void ex1(){

    char * s;
    s = setString(EX1);
    setLower(s);
    int t = strlen(s);
    printf("\nTamanho da string: %i\n", t);
    printf("String: ");
    puts(s);
    simpleCompression(s);

}

void ex2(){

}

void ex3(){

}

void menu(){
    int opc;

    printf("    ********************************************************\n");
    printf("    *                                                      *\n");
    printf("    *           Projeto e Analise de Algoritmos            *\n");
    printf("    *          Ep2 - Compactacao e Descompactacao          *\n");
    printf("    *                                                      *\n");
    printf("    *                     Criado Por:                      *\n");
    printf("    *            31746357 - Davi Gomes Seagull             *\n");
    printf("    *        41903511 - Gisely Garcia Pereira Souza        *\n");
    printf("    *      41908406 - Pedro Henrique Rodrigues Correa      *\n");
    printf("    *                                                      *\n");
    printf("    ********************************************************\n");

    do {

        printf("\nMenu de escolha do exercicio \n");
        printf("0 - Sair\n");
        printf("1 - Exercicio 1\n");
        printf("2 - Exercicio 2\n");
        printf("3 - Exercicio 3\n");

        printf("\nOpcao: ");
        scanf("%d", &opc);
        fflush(stdin);

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
                cleanScreen();
                printf("\nVoce digitou uma opcao invalida. Tente novamente\n");
                break;
        }
    }
    while (opc != 0);
}

int main() {

    menu();
    return 0;
}
