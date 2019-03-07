#include <stdio.h>

int main(){

	int matriz[5][3];
	int p1,p2,p3;
	int a1,a2,a3,a4;
	int custop1,custop2,custop3;
	int custoa1,custoa2,custoa3,custoa4;

	p1 = p2 = p3 = 0;
	a1 = a2 = a3 = a4 = 0;
	custop1 = custop2 = custop3 = 0;
	custoa1 = custoa2 = custoa3 = custoa4 = 0;

	for(int i=0; i<5; i++){
		for(int j=0; j<3; j++){
			if(i<4){
				printf("Armazém %d, Produto %d: ",i+1,j+1);	
			}
			if(i == 4) printf("\nInsira o preço: \n");
			scanf("%d",&matriz[i][j]);
			if(j == 0 && i != 4) p1 += matriz[i][j];
			if(j == 1 && i != 4) p2 += matriz[i][j];
			if(j == 2 && i != 4) p3 += matriz[i][j];
			if(i == 0) a1 += matriz[i][j];
			if(i == 1) a2 += matriz[i][j];
			if(i == 2) a3 += matriz[i][j];
			if(i == 3) a4 += matriz[i][j];
		}
	}

	printf("\n");
	for(int i=0; i<5; i++){
		if(i==4) printf("Preço dos produtos\n");
		for(int j=0; j<3; j++){
			printf("%3d ",matriz[i][j]);
		}
		printf("\n");
	}

	printf("\nQuantidade do Produto 1: %d\n", p1);
	printf("Quantidade do Produto 2: %d\n", p2);
	printf("Quantidade do Produto 3: %d\n", p3);
	printf("Quantidade de produtos no Armazém 1: %d\n", a1);
	printf("Quantidade de produtos no Armazém 2: %d\n", a2);
	printf("Quantidade de produtos no Armazém 3: %d\n", a3);
	printf("Quantidade de produtos no Armazém 4: %d\n", a4);

	if(a1 < a2 && a1 < a3 && a1 < a4) printf("\nArmazém 1 é o menor\n");
	else if(a2 < a1 && a2 < a3 && a2 < a4) printf("\nArmazém 2 é o menor\n");
	else if(a3 < a1 && a3 < a2 && a3 < a4) printf("\nArmazém 3 é o menor\n");
	else if(a4 < a1 && a4 < a2 && a4 < a3) printf("\nArmazém 4 é o menor\n");
	else printf("\nExiste mais de um armazém com a mesma quantidade de produtos que outro\n");

	return 0;
}