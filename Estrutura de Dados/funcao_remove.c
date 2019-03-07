void remover(Lista *L, int valor){
  SNo* temp=L->inicio;
  SNo* ant=NULL;

  if(temp==NULL){
      printf("Lista vazia\n");
  }

  else if(temp->prox==NULL){
      if(temp->chave==valor){
          criaLista();
          free(temp);
          temp=NULL;
      }
  }

  while(temp!=NULL){
  	if(temp->chave==valor){
  		// if(ant!=NULL&&temp->prox!=NULL){//No meio
  		// 	ant->prox=temp->prox;
  		// 	free(temp);
      //         ant=temp->prox;
      //         if(ant!=NULL){
      //             temp=ant->prox;
      //         }
      //         else{
      //             temp=ant;
      //         }
  		// }
          // else if(ant==NULL&&ant->prox!=NULL){//No comeco
          //     L->inicio=temp->prox;
          //     ant=temp;
          //     if(temp->prox!=NULL){
          //         temp=temp->prox;
          //     }
          //     else{
          //         temp=NULL;
          //     }
          //     free(ant);
          //     ant=NULL;
          // }
          if(temp==L->inicio){
            L->inicio = L->inicio->prox;
          }
          else{
            ant->prox = temp->prox;
          }
          if(temp->prox==NULL){//No final
              L->fim=ant;
              ant->prox=NULL;
              temp=NULL;
          }
  	}
      else{
      	ant=temp;
      	temp=temp->prox;
      }
  }
  // if(!f)printf("Lista nao mudou\n");
  // else imprime(L);
}
