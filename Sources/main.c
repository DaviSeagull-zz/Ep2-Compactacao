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

void decompression(char *s){
    char s1[100];
	int i = 0,j = 0,k,n;
	while(s[i] != "\0")
	{
		s1[j]=s[i];
		 i++;j++;
		n = 0;
        while(s[i]>='1'&&s[i]<='9')
		{
			n *= 10;
			n += s[i] - '0';
			i++;
		}
		for(k = 0;k < n - 1;k++)

			s1[j+k] = s1[j-1];
		 if(n>0)
			j+=n-1;
		}
	 s1[j]='\0';
	printf("%s\n",s1);
 }


//funcao para executar o primeiro exercicio
void simpleCompression(char *s){

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
    s = &aux2;
    return s;

}

//funcao para deixar todas as letras da string em minusculo
void setLower(char * s) {

    char a[strlen(s)]; //vetor de char do tamanho da string
    strcpy(a,s); //copia dos valores da string para o vetor a
    for (int i = 0; i < (strlen(s)); i++)
        s[i] = tolower(a[i]);

}

//funcao que pergunta se quer descompactar a string compactada
void subMenuCompression(char *s) {

    int opc_menu;

    printf("\n\nDeseja descompactar a string compactada?");
    printf("\n1 - Sim");
    printf("\n2 - Nao");
    printf("\n\nOpcao: ");
    scanf("%i", &opc_menu);

    do {
        switch(opc_menu){
        case 1:
            decompression(s);
            break;
        case 2:
            cleanScreen();
            break;
        default:
            printf("Voce digitou uma opcao invalida. Tente novamente");
        }
    } while(opc_menu != 2);

}

//funcao para o ex1
void ex1(){

    char * s; //ponteiro para char
    s = setString(); //chamada da funcao setString
    setLower(s); //chamada da funcao setLower
    int t = strlen(s); //variavel para armazenar o tamanho da String
    printf("\nTamanho da string: %i\n", t);
    printf("String: ");
    puts(s);
    printf("String compactada: ");
    simpleCompression(s); //chamada da funcao simpleCompression
    subMenuCompression(s);

}

//funcao para o ex2 recebendo user input
void ex2UserInput(){



}

//funcao para o ex2 recebendo string compactada do Ex1 ou Ex3
void ex2CompressedString(){

}

//funcao para o ex3
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
