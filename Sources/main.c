#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

  printf("\nPara sair do programa digite qualquer caracter\n");
  printf("1 - Exercicio 1\n");
  printf("2 - Exercicio 2\n");
  printf("3 - Exercicio 3\n\n");

  printf("Opcao: ");
  int opc;
  scanf("%d", &opc);

  bool quit = false;
  while(!quit) {
    switch (opc) {
    case 1:
//      ex1();
      quit = true;
    case 2:
//      ex2();
      quit = true;
    case 3:
//      ex3();
      quit = true;
    default:
      quit = true;
    }
  }

}

int main()
{

  menu();
  return 0;

}
