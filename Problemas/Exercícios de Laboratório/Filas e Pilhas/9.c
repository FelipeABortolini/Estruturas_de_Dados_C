#include <stdio.h>
#include <stdlib.h>

void limpa_buffer(){
	int ch;
	while((ch=getchar()) != '\n' && ch != EOF);
}

typedef struct lstItem{
   char marca[20];
   char casta[20];
   int ano;
   struct lstItem *next;
}Vinho;


typedef struct{
   Vinho *top;	
}pilha;



pilha *criaPilha(){
   pilha *p = malloc(sizeof(pilha));
   p->top = NULL;
   return p;
}

void print(Vinho *v){
	if(v != NULL){
		printf("Marca: %s", v->marca);
		printf("Casta da uva: %s", v->casta);
		printf("Ano de Safra: %d\n", v->ano);
	}
}

void *push(pilha *p){
   Vinho *novo = malloc(sizeof(Vinho));
   
   printf("Digite a marca do vinho: ");
   limpa_buffer();
   fgets(novo->marca, 20, stdin);
   
   printf("Digite a casta do vinho: ");
   //limpa_buffer();
   fgets(novo->casta, 20, stdin);
   
   printf("Digite o ano da safra do vinho: ");
   scanf("%d", &novo->ano);
   
   novo->next = p->top; 
   p->top = novo;
}


Vinho *pop(pilha *p){
    Vinho *item = p->top;
    if(item!=NULL){
   	    p->top = p->top->next;
        return item;
   }
   else return NULL;
}

int total_vinhos(pilha *p){
	int n = 1;
	if(p->top != NULL){
		Vinho *aux = p->top;
		while(aux->next != NULL){
			aux = aux->next;
			n++;
		}
		return n;
	}
	return 0;
}

void antigos(pilha *p){
    if(p->top != NULL){
    	Vinho *item = p->top;
	    int n = 0, j = 0;
	    if(total_vinhos(p) < 5) j = 5 - total_vinhos(p);
	    while(n < total_vinhos(p) - 5){
	       item = item->next;
	       n++;
	    }
	    while(item != NULL){
	    	if(j==0){
	    		printf("QUINTO VINHO MAIS ANTIGO:\n");
	    		print(item);
	    		printf("\n");
			}
	    	else if(j==1){
	    		printf("QUARTO VINHO MAIS ANTIGO:\n");
	    		print(item);
	    		printf("\n");
			}
	    	else if(j==2){
	    		printf("TERCEIRO VINHO MAIS ANTIGO:\n");
	    		print(item);
	    		printf("\n");
			}
	    	else if(j==3){
	    		printf("SEGUNDO VINHO MAIS ANTIGO:\n");
	    		print(item);
	    		printf("\n");
			}
	    	else if(j==4){
	    		printf("VINHO MAIS ANTIGO:\n");
	    		print(item);
	    		printf("\n");
			}
	    	j++;
			item = item->next;
	    }
	} else printf("Nao ha vinhos!\n"); 
}


int main(){
   
   pilha *p = criaPilha(); 
   int opcao = 1, i;
   char s[20];

   while(opcao!=4){
      printf("1 - Adicionar vinho na adega;\n");
      printf("2 - Abrir vinho;\n");
      printf("3 - Relacao das 5 aquisicoes mais antigas;\n");
      printf("4 - Sair\n");
      printf("\nDigite uma opcao: ");
      scanf("%d",&opcao);
      if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4){
      	printf("Opcao invalida!\n");
      	i = 8;
	  }
      if(opcao==1){
      	 printf("\n");
         push(p);
         printf("\n");
      }else
      if(opcao==2){
         Vinho *v = pop(p);
         printf("\n");
         if(v != NULL){
         	printf("Vinho que deve ser aberto:\n");
         	print(v);
		 }
    	 else printf("Nao ha vinhos para abrir! =(\n");
         printf("\n");
      }else
      if(opcao==3)  {
      	 printf("\n");
         antigos(p);
         printf("\n");
      }
   }
}
