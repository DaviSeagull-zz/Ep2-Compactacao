#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define EX1 1
#define EX2 2
#define EX3 3

//funcao utilizada para limpar a tela do terminal
void cleanScreen() {
    system("cls||clear");
}

//funcao para executar o primeiro exercicio
void simpleCompression(char *s){
    char letters[10]; //cria um vetor de char no tamanho da string
    int index[10]; //cria um vetor de int no tamanho da string
    int letter_counter = 0; //variavel para contar quantas vezes uma letra repete
    int index_counter = 0; //variavel para receber em qual indice do store_letters e index ja foi preenchido

    //for para preencher os vetores com NULL
    for(int i = 0; i < 10; i++){
        letters[i] = NULL;
        index[i] = NULL;
    }

    //for para fazer a compressao
    for(int i = 0; i <= strlen(s); i++){
        if((s[i] != s[i-1]) || i == 0){ //if para verificar se esta na posicao inicial e se a ultima letra eh igual a atual
            if(i != 0){
                index[index_counter] = letter_counter; //salva no vetor index quantas vezes a letra atual se repetiu
                index_counter++;
                letter_counter = 0; //zera o contador de letras
            }
            letter_counter++;
            letters[index_counter] = s[i]; // salva no vetor store_letters a letra atual
        }
        if(s[i] == s[i-1]){
            letter_counter++;
        }
    }


    //for para imprimir o vetor compactado
    for (int i = 0; i < strlen(letters); i++) {
        if(i != strlen(letters) - 1) //if para verificar se ja esta no ultimo elemento do vetor
            printf("%c%i - ", letters[i], index[i]);
        else
            printf("%c%i", letters[i], index[i]);
    }
}

//funcao para receber a string desejada pelo usuario
char * setString(int ex) {
    if (ex == 1 || ex == 3){
        char * s; //ponteiro para char
        char aux[1000]; //vetor para receber a string do usuario
        int string_counter = 0; //variavel para contar o tamanho da string

        printf("String desejada: ");
        fgets(aux, 1000, stdin); //recebe a String desejada

        //for para contar quantos caracteres a String do usuario possui
        for(int i = 0; i < 1000; i++){
            if(aux[i] == "\0")
                break;
            string_counter++;
        }
        char aux2[string_counter]; //cria vetor com tamanho = a quantidade de caracteres na String

        //for para salvar todos os valores no vetor com tamanho correto
        for(int i = 0; i < string_counter; i++){
            aux2[i] = aux[i];
        }
        s = &aux2;
        return s;
    }
}

//funcao para deixar todas as letras da string em minusculo
void setLower(char * s) {
    char a[strlen(s)]; //vetor de char do tamanho da string
    strcpy(a,s); //copia dos valores da string para o vetor a
    for (int i = 0; i < (strlen(s)); i++)
        s[i] = tolower(a[i]);
}

//funcao para o ex1
void ex1(){
    char * s; //ponteiro para char
    s = setString(EX1); //chamada da funcao setString
    setLower(s); //chamada da funcao setLower
    int t = strlen(s); //variavel para armazenar o tamanho da String
    printf("\nTamanho da string: %i\n", t);
    printf("String: ");
    puts(s);
    printf("String compactada: ");
    simpleCompression(s); //chamada da funcao simpleCompression
}

void ex2(){

}

void ex3(){

}

//funcao do Menu
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

        printf("\n\nMenu de escolha do exercicio \n");
        printf("0 - Sair\n");
        printf("1 - Exercicio 1\n");
        printf("2 - Exercicio 2\n");
        printf("3 - Exercicio 3\n");

        printf("\nOpcao: ");
        scanf("%d", &opc); //recebe a funcao desejada
        fflush(stdin); //limpa o buffer de entrada

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
