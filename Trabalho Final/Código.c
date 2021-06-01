#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// ================== VARIÁVEIS GLOBAIS ==================

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

// ================== DECLARAÇÃO DE FUNÇÕES ==================

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

// ================== FUNÇÃO MAIN ==================

int main(){
    char string[256];
    memset(string, '0', sizeof(string)); // Remove lixo de memória da string.
    printf("Informe a cadeia de caracteres:\n");
    fgets(string, 256, stdin);
    removeEnter(string);
    hash *h = criaHash(128); // 128 será o tamanho da tabela hash.
    percorreString(string, h);
    insereCodigo(h);
    escreveComprimido(string, h);
    liberaHash(h);
}

// ================== IMPLEMENTAÇÃO DE FUNÇÕES ==================

// O(1)
void removeEnter(char *str){ // Tem como objetivo excluir o caractere '\n' que a função fgets atribui para a variável string após o usuário digitar enter.
	int len = strlen(str);
	str[len-1] = '\0';
}

// O(1)
hash *criaHash(int TABLE_SIZE){ // Função para criar e inicializar os valores da variável do tipo hash.
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
void percorreString(char *s, hash *h){ // Função criada para percorrer a string e chamar a função insere().
    int i;
    for(i=0; s[i]!='\0'; i++){
        insere(h, s[i]);
    }
}

// O(1)
void insere(hash *h, char c){ // Função para inserir os dados, capazes de armazenar o algarismo e seu código em binário, na tabela hash. 
    int ha = geraHash(c);
    if(h->item[ha] == NULL){
        dado *p = criaDado(c);
        h->item[ha] = p;
        numAlg++; // Incrementa a variável global numAlg que representa o n° de caracteres distintos na string.
        return;
    }
}

// O(1)
int geraHash(char c){ // Função para gerar a hash de cada caractere.
    int i = c; /* Como a tabela hash possui 128 índices possíveis e a tabela ASCII possui 128 caracteres (nos quais estão incluídos letras maiúsculas, minúsculas e o espaço), 
    		    caso haja colisões é porque o caractere está se repetindo na string, portanto não será considerado para a inserção na tablea hash.*/
    return i;
}

// O(1)
dado *criaDado(char alg){ // Função para criar a variável do tipo dado e adicionar o caractere no campo alg.
    dado *a = malloc(sizeof(dado));
    a->alg = alg;
    a->codigo = calloc('\0', 8*sizeof(char));
    return a;
}

// O(1)
void insereCodigo(hash *h){
    int i, j, k = 0, numbit;
    numbit = numBits(numAlg);
    for(i=0; k!=numAlg; i++){ // Percorre o laço até que todos os caracteres distintos da string possuam código.
        if(h->item[i] != NULL){ // Testa se no índice i da tabela hash há algum dado, ou seja, só haverá quando i for igual ao correspondente decimal (ASCII) de algum caractere presente da string.
            for(j=numbit; j>0; j--){ // Inicio do laço de formação do código binário para cada caractere.
                if((k >> j-1) & 1){ // Operadores bitwise.        
                    h->item[i]->codigo[numbit-j] = '1';
                }
                else{
                    h->item[i]->codigo[numbit-j] = '0';
                }
            }
            h->item[i]->codigo[numbit-j] = '\0'; // Finalizar o código, visto que o mesmo é uma string.
            k++; // Incrementa k para informar que mais um caractere recebeu o código.
        }
    }
}

// O(1)
int numBits(int x){ // Função que calcula o número fixo de bits que será capaz de representar em binário, sem ambiguidades, todos os caracteres que não se repetem na string.
    return (int) ceil(log2(x));
}

// O(n)
void escreveComprimido(char *s, hash *h){ // Função que cria o arquivo texto.txt e escreve a frase comprimida.
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
void escreveDicionario(FILE *f, hash *h){ // Função que escreve o dicionário do alfabeto criado.
    int i;
    for(i=0; i<h->TABLE_SIZE; i++){
        if(h->item[i]!=NULL){
            fprintf(f, "%c;%s\n", h->item[i]->alg, h->item[i]->codigo);
        }
    }
}

// O(1)
void liberaHash(hash *h){ // Função que libera a tabela hash.
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
