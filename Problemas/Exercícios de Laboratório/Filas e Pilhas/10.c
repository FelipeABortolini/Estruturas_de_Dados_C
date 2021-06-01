#include <stdio.h>
#include <stdlib.h>

void limpa_buffer(){
	int ch;
	while((ch=getchar()) != '\n' && ch != EOF);
}

typedef struct lstItem{
   char caractere;
   struct lstItem *next;
}pilhaItem;


typedef struct{
   pilhaItem *top;	
}pilha;



pilha *criaPilha(){
   pilha *p = malloc(sizeof(pilha));
   p->top = NULL;
   return p;
}

void *push(pilha *p){
	int i = 0;
	char caractere;
    printf("Digite uma frase: ");
    limpa_buffer();
    do{
    	pilhaItem *novo = malloc(sizeof(pilhaItem));
    	caractere = getchar();
    	novo->caractere = caractere;
		i++;
		novo->next = p->top; 
    	p->top = novo;
    } while(caractere != '\n' && caractere != '\0');
    printf("\n");
}


void *pop(pilha *p){
   pilhaItem *item = p->top;
   if(item!=NULL)
      p->top = p->top->next;
}



char peek(pilha *p){
   if(p->top!=NULL)
      return p->top->caractere;
   else
      return '\0';
}

void print(pilha *p){
   pilhaItem *item = p->top;
   while(item!=NULL){
      printf("%c",item->caractere);
      item = item->next;
   }
   printf("\n\n");
}


int main(){
   
   pilha *p = criaPilha();
   int opcao = 1, i; 

   while(opcao!=3){
      printf("1 - Digitar frase\n");
      printf("2 - Imprimir a frase invertida\n");
      printf("3 - Sair\n");
      printf("\nDigite uma opcao: ");
      scanf("%d",&opcao);
      if(opcao==1){
         push(p);
      }else
      if(opcao==2)  {
         print(p);
      }
   }
}
