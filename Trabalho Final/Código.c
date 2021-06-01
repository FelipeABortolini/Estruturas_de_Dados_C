#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// ================== VARI�VEIS GLOBAIS ==================

int numAlg = 0;

// ================== ESTRUTURAS ==================

typedef struct{
    char alg;
    char *codigo;
}dado;

typedef struct{
    int TABLE_SIZE;
    dado **item;
}hash;

// ================== DECLARA��O DE FUN��ES ==================

void removeEnter(char *str);

hash *criaHash(int TABLE_SIZE);

void percorreString(char *s, hash *h);

void insere(hash *h, char c);

int geraHash(char c);

dado *criaDado(char alg);

void insereCodigo(hash *h);

int numBits(int x);

void escreveComprimido(char *s, hash *h);

void escreveDicionario(FILE *f, hash *h);

void liberaHash(hash *h);

// ================== FUN��O MAIN ==================

int main(){
    char string[256];
    memset(string, '0', sizeof(string)); // Remove lixo de mem�ria da string.
    printf("Informe a cadeia de caracteres:\n");
    fgets(string, 256, stdin);
    removeEnter(string);
    hash *h = criaHash(128); // 128 ser� o tamanho da tabela hash.
    percorreString(string, h);
    insereCodigo(h);
    escreveComprimido(string, h);
    liberaHash(h);
}

// ================== IMPLEMENTA��O DE FUN��ES ==================

// O(1)
void removeEnter(char *str){ // Tem como objetivo excluir o caractere '\n' que a fun��o fgets atribui para a vari�vel string ap�s o usu�rio digitar enter.
	int len = strlen(str);
	str[len-1] = '\0';
}

// O(1)
hash *criaHash(int TABLE_SIZE){ // Fun��o para criar e inicializar os valores da vari�vel do tipo hash.
    hash *h = malloc(sizeof(hash));
    int i;
    h->TABLE_SIZE = TABLE_SIZE;
    h->item = malloc(TABLE_SIZE*sizeof(dado));
    for(i=0; i<h->TABLE_SIZE; i++){
        h->item[i] = NULL;
    }
    return h;
}

// O(n)
void percorreString(char *s, hash *h){ // Fun��o criada para percorrer a string e chamar a fun��o insere().
    int i;
    for(i=0; s[i]!='\0'; i++){
        insere(h, s[i]);
    }
}

// O(1)
void insere(hash *h, char c){ // Fun��o para inserir os dados, capazes de armazenar o algarismo e seu c�digo em bin�rio, na tabela hash. 
    int ha = geraHash(c);
    if(h->item[ha] == NULL){
        dado *p = criaDado(c);
        h->item[ha] = p;
        numAlg++; // Incrementa a vari�vel global numAlg que representa o n� de caracteres distintos na string.
        return;
    }
}

// O(1)
int geraHash(char c){ // Fun��o para gerar a hash de cada caractere.
    int i = c; /* Como a tabela hash possui 128 �ndices poss�veis e a tabela ASCII possui 128 caracteres (nos quais est�o inclu�dos letras mai�sculas, min�sculas e o espa�o), 
    		    caso haja colis�es � porque o caractere est� se repetindo na string, portanto n�o ser� considerado para a inser��o na tablea hash.*/
    return i;
}

// O(1)
dado *criaDado(char alg){ // Fun��o para criar a vari�vel do tipo dado e adicionar o caractere no campo alg.
    dado *a = malloc(sizeof(dado));
    a->alg = alg;
    a->codigo = calloc('\0', 8*sizeof(char));
    return a;
}

// O(1)
void insereCodigo(hash *h){
    int i, j, k = 0, numbit;
    numbit = numBits(numAlg);
    for(i=0; k!=numAlg; i++){ // Percorre o la�o at� que todos os caracteres distintos da string possuam c�digo.
        if(h->item[i] != NULL){ // Testa se no �ndice i da tabela hash h� algum dado, ou seja, s� haver� quando i for igual ao correspondente decimal (ASCII) de algum caractere presente da string.
            for(j=numbit; j>0; j--){ // Inicio do la�o de forma��o do c�digo bin�rio para cada caractere.
                if((k >> j-1) & 1){ // Operadores bitwise.        
                    h->item[i]->codigo[numbit-j] = '1';
                }
                else{
                    h->item[i]->codigo[numbit-j] = '0';
                }
            }
            h->item[i]->codigo[numbit-j] = '\0'; // Finalizar o c�digo, visto que o mesmo � uma string.
            k++; // Incrementa k para informar que mais um caractere recebeu o c�digo.
        }
    }
}

// O(1)
int numBits(int x){ // Fun��o que calcula o n�mero fixo de bits que ser� capaz de representar em bin�rio, sem ambiguidades, todos os caracteres que n�o se repetem na string.
    return (int) ceil(log2(x));
}

// O(n)
void escreveComprimido(char *s, hash *h){ // Fun��o que cria o arquivo texto.txt e escreve a frase comprimida.
    FILE *f = fopen("texto.txt", "w");
    int i;
    for(i=0; s[i]!='\0'; i++){
        if(h->item[s[i]] != NULL){
            fprintf(f, "%s", h->item[s[i]]->codigo);
        }
    }
    if(strlen(s)>1) fprintf(f, "\n");
    escreveDicionario(f, h);
    fclose(f);
}

// O(1)
void escreveDicionario(FILE *f, hash *h){ // Fun��o que escreve o dicion�rio do alfabeto criado.
    int i;
    for(i=0; i<h->TABLE_SIZE; i++){
        if(h->item[i]!=NULL){
            fprintf(f, "%c;%s\n", h->item[i]->alg, h->item[i]->codigo);
        }
    }
}

// O(1)
void liberaHash(hash *h){ // Fun��o que libera a tabela hash.
    if(h != NULL){
        int i;
        for(i=0; i<h->TABLE_SIZE; i++)
            if(h->item[i] != NULL){
                free(h->item[i]);
            }
        free(h->item);
        free(h);
    }
}
