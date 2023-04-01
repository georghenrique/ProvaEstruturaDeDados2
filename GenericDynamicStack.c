#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "GenericDynamicStack.h"



void init(GenericDynamicStack *stack){
    printf("init <-");
    stack->top=NULL;
    stack->size=0;
}

bool isEmpty(GenericDynamicStack *stack){
    printf("isEmpty <-");
    if(stack->top==NULL){
        printf("**ERRO: a lista esta vazia");
        return true;
        printf("isEmpty ->");

    }
    if(stack->size==0){
        printf("**ERRO: a lista esta vazia");
        printf("isEmpty ->");
        return true;
    }
    else{
        printf("a lista possui elementos");
        printf("isEmpty ->");
        return false;
    }
}

int push(GenericDynamicStack *stack, void *data){
    printf("push <-");
    
    Node *newNode = (Node*) malloc(sizeof(Node));
   
    if(newNode==NULL){
        printf("**ERRO: o No ñ foi alocado");
        return -1;
    }
    
    newNode->data = data;
    newNode->under=NULL;

    if(stack->top==NULL || stack->size==0){
        printf("add topo");
        stack->top=newNode;
    }
    else{
        printf("ha elementos na pilha");
        //node * aux = stack->top;
        newNode->under=stack->top;
        stack->top=newNode; 
    }
    
    stack->size++;
    printf("push ->");
    return 0;
}

void* pop(GenericDynamicStack *stack){
    printf("pop <-");

    if(stack->top==NULL || stack->size==0){
        printf("**ERRO: a lista esta vazia");
        return NULL;
    }
    
    void * data = stack->top->data;
    Node * lixo = stack->top;
    stack->top= lixo->under;
    free(lixo);
    stack->size--;
    printf("pop ->");
    return data;
}

void* top(GenericDynamicStack *stack){
    printf("top <-");

    return (stack->top);

}

void show(GenericDynamicStack *stack, printNode print){
    printf("top <-");
    Node *aux= stack->top;
    while(aux!=NULL){
        printf("while <-");
        print(aux->data);
        aux=aux->under;
    }
    printf("while <-");
}


