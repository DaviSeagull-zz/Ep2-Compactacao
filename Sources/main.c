#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

/**
    GitHub: https://github.com/DaviSeagull/Ep2-Compactacao

    Integrantes do grupo:
        Davi Gomes Seagull (31746357)
        Gisely Garcia Pereira Souza (41903511)
        Pedro Henrique Rodrigues Correa (41908406)
**/

//funcao utilizada para limpar a tela do terminal
void cleanScreen() {
    system("cls||clear");
}

//funcao para preencher a string de null
void fillNull(char * s){

    int t = strlen(s);
    for(int i = 0; i <= t; i++)
        s[i] = NULL;

}

//funcao para receber a string desejada pelo usuario
char * setString() {

    char * s; //ponteiro para char
    char aux[100000]; //vetor para receber a string do usuario
    int string_counter = 0; //variavel para contar o tamanho da string

    printf("String desejada: ");
    fflush(stdin);
    gets(aux); //recebe a String desejada

    //for para contar quantos caracteres a String do usuario possui
    for(int i = 0; i < 100000; i++){
        if(aux[i] == "\0")
            break;
        string_counter++;
    }
    char aux2[string_counter]; //cria vetor com tamanho = a quantidade de caracteres na String

    //for para salvar todos os valores no vetor com tamanho correto
    for(int i = 0; i < string_counter; i++){
        aux2[i] = aux[i];
    }

    //salva os valores de aux2 no ponteiro s
    s = &aux2;

    return s;

}

//funcao para deixar todas as letras da string em minusculo
void setLower(char * s) {

    char a[strlen(s)]; //vetor de char do tamanho da string

    strcpy(a,s); //copia dos valores da string para o vetor a

    // for para salvar em lowercase cada posicao do vetor
    for (int i = 0; i < (strlen(s)); i++)
        s[i] = tolower(a[i]);

}

//funcao para remover o hifen da string recebida
void removeHyphen (char * s) {

    int size_s = strlen(s); //variavel com o tamanho da string

    char aux[size_s]; //vetor aux do tamanho da string
    char c[2] = "-"; //variavel com o hífen
    char * token; //ponteiro utilizado para salvar o token

    strcpy(aux, s); //copia do s para aux
    token = strtok(aux, c); //primeiro token

    fillNull(s);

    while( token != NULL ) {
        strcat(s,token);
        token = strtok(NULL, c);
    }

}

//funcao para descomprimir string
void decompression(char * s){

    char aux1[1000] = ""; //declaracao do vetor auxiliar 1
    char aux2[1000] = ""; //declaracao do vetor auxiliar 2
    int i = 0, j = 0, k, n;

    while(s[i]) {
        n = 0;

        //enquanto nao for numero ele salva no aux1
        while(!isdigit(s[i])){
            aux1[j] = s[i];
            i++;
            j++;
        }

        //calcula quantas vezes terá que repetir o que esta salvo em aux1
        while(isdigit(s[i])) {
            n *= 10;
            n += s[i] - '0';
            i++;
        }

        //for para repetir a string em aux1 n vezes
        for(k = 0; k < n; k++)
            strcat(aux2, aux1);

        if(n > 0)
            j+=n-1;

        fillNull(aux1); //preencher o aux1 de null

        //limpar o contador de aux1
        j = 0;
    }

    printf("\nString Compactada: %s", s);
	printf("\nString Descompactada: %s", aux2);

    return;
 }

//funcao para executar o primeiro exercicio
char * simpleCompression(char *s){

    char letters[strlen(s)]; //cria um vetor de char no tamanho da string
    int index[strlen(s)]; //cria um vetor de int no tamanho da string
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
            letters[index_counter] = s[i]; // salva no vetor store_letters a letra atual
            letter_counter++;

        }
        if(s[i] == s[i-1]){
            letter_counter++;
        }
    }

    //for para imprimir o vetor compactado
    for (int i = 0; i < strlen(letters); i++){
        if(i != strlen(letters) - 1) //if para verificar se ja esta no ultimo elemento do vetor
            printf("%c%i-", letters[i], index[i]);
        else
            printf("%c%i", letters[i], index[i]);
    }

}

//funcao para o ex1
void ex1(){

    char * s_ex1; //ponteiro para string recebida
    s_ex1 = setString(); //chamada da funcao setString

    setLower(s_ex1); //chamada da funcao setLower

    int t = strlen(s_ex1); //variavel para armazenar o tamanho da String

    printf("\nTamanho da string: %i\n", t);
    printf("String: ");
    puts(s_ex1);
    printf("String compactada: ");

    simpleCompression(s_ex1); //chamada da funcao simpleCompression
    return;

}

//funcao para o ex2
void ex2(){

    char * s_ex2; //ponteiro para string recebida
    s_ex2 = setString(); //chamada da funcao setString

    setLower(s_ex2); //chamada da funcao setLower
    removeHyphen(s_ex2); //chamada da funcao removeHyphen
    decompression(s_ex2); //chamada da funcao decompression

}

//funcao para o ex3
void ex3(){
    char * s_ex3; //ponteiro para char
    s_ex3 = setString(); //chamada da funcao setString

    setLower(s_ex3); //chamada da funcao setLower
    int t = strlen(s_ex3); //variavel para armazenar o tamanho da String

    printf("\nTamanho da string: %i\n", t);
    printf("String: ");
    puts(s_ex3);
    printf("String compactada: ");
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

