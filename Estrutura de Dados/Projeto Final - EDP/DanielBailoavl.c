#include"final_avl.h"

int main() {

  L1 = criaLista();
  char nomeArquivo[20];
  int op,cont=1;
  SNo *arvore;

  while(cont!=0){
    printf("Digite a opção desejada\n");
    printf("[1]Ler o banco de dados\n");
    printf("[2]Printar\n");
    printf("[3]Inserir\n");
    printf("[4]Buscar\n");
    printf("[5]Remover\n");
    printf("[6]Sangue total doado\n");
    printf("[7]Limpar tela\n");
    printf("[8]Sair\n");
    scanf("%d",&op);
    printf("\n");

      switch (op) {
        case 1:
          printf("Qual o nome do arquivo: ");
          scanf("%s",nomeArquivo);
          leArquivo(nomeArquivo);
          arvore = passar_lista_p_arvore(L1);
        break;

        case 2:
          arvore = passar_lista_p_arvore(L1);
          em_ordem(arvore);
          printf("\n");
        break;

        case 3:
          printf("Digite os dados do usuário que você deseja inserir no banco de dados\n\n");
          printf("Nome: ");
          scanf(" %[^\n]s", No.Nome); //o espaço entre a primeira aspa dupla e a porcentagem
          printf("Idade: ");          //limpa o buffer do teclado e assim tbm é possivel
          scanf("%d",&No.idade);      //ler strings com espaços
          printf("Tipo sanguíneo: ");
          scanf("%s",No.tipo);
          printf("Fator RH: ");
          scanf("%s",No.fatorRh);
          printf("Quantidade de sangue doada: ");
          scanf("%f",&No.qtdSangue);
          insere_lista(L1, No.Nome, No.idade, No.tipo, No.fatorRh, No.qtdSangue);
          arvore = passar_lista_p_arvore(L1);
          printf("\nPaciente inserido com sucesso!\n");
        break;

        case 4:
          printf("Digite o nome do usuário que você deseja buscar\n");
          printf("Nome: ");
          scanf(" %[^\n]s", No.Nome);
          busca_nome(arvore,No.Nome);
          // if(verifica_nome(arvore,No.Nome) != 1)
            // printf("\nO paciente citado não está cadastrado no banco de dados!\n\n");
        break;

        case 5:
          printf("Digite o nome do usuário que você deseja remover\n");
          printf("Nome: ");
          scanf(" %[^\n]s", No.Nome);
          if(!busca_nome(arvore,No.Nome)){
            printf("Nome não encontrado\n");
            break;
          }
          printf("\nAgora, digite o código do paciente que você deseja remover\n");
          printf("Código: ");
          scanf("%d",&No.codigo);
          printf("\n");
          remover_lista(L1,No.codigo);
          remover_arvore(arvore,No.codigo);
          arvore = passar_lista_p_arvore(L1);
        break;

        case 6:
          printf("Sangue total doado: ");
          printf("%.2fml\n",somaNo(arvore));
          printf("Tipo sanguíneo: ");
          scanf("%s",No.tipo);
          quantsangue(arvore,No.tipo);
          printf("\nA quantidade total de sangue doado do tipo %s foi de %.2fml\n",No.tipo,qtotal);
          qtotal = 0;
        break;

        case 7:
          system("clear");
        break;

        case 8:
          printf("Saindo...");
          exit(1);
        break;

        default:
          printf("Por favor, digite uma opção valida!\n");
        break;
      }
    printf("\nDeseja continuar? [1]Sim ou [0]Não\n");
    scanf("%d",&cont);
    printf("\n");
    // system("clear");
    if(cont==0){
      printf("Saindo...");
      return cont;
    }
  }
	return 0;
}
