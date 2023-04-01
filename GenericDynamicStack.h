//
//  GenericDynamicStack.h
//  Estrutura de Dados 2
//
//	Enviar implementação C, conforme segue:
//	Para: preti.joao@ifmt.edu.br
//	Assunto: Prova 1 de Estrutura de Dados 2
//  Mensagem: <Nome Completo do Estudante>
//  Anexo: GenericDynamicStack.c

#ifndef EstruturaDeDados_GenericDynamicStack_h
#define EstruturaDeDados_GenericDynamicStack_h

typedef struct Node {
    void *data;
    struct Node *under;
}Node;

typedef struct GenericDynamicStack {
    Node *top;
    int size;
}GenericDynamicStack;

typedef void (*printNode)(void*);

void init(GenericDynamicStack *stack); 					//1,0pt
int push(GenericDynamicStack *stack, void *data);		//2,0pt
void* pop(GenericDynamicStack *stack);					//2,0pt
void* top(GenericDynamicStack *stack);					//1,0pt
void* get_as_array(GenericDynamicStack *stack);			//2,0pt
void show(GenericDynamicStack *stack, printNode print);	//2,0pt

#endif
