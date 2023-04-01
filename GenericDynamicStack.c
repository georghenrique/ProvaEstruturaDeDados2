#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include "GenericDynamicStack.h"



void init(GenericDynamicStack *stack){
    log_info("Incializando a pilha");
    log_trace("init <-");
    stack->top=NULL;
    stack->size=0;
    log_debug("stack->top: %p", stack->top);
    log_debug("stack->size: %d", stack->size);
    log_trace("init -> \n");

}

bool isEmpty(GenericDynamicStack *stack){
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
    log_trace("push <-");
    log_info("Add um elemento a Pilha");
    
    Node *newNode = (Node*) malloc(sizeof(Node));

    if(newNode==NULL){
        log_error("**ERRO: No ñ alocado");
        log_trace("push -> \n");
        return -1;
    }
    
    newNode->data = data;
    newNode->under=NULL;
    log_debug("newNode->data: %d", newNode->data);
    log_debug("newNode->under: %p", newNode->under);


    if(stack->top==NULL || stack->size==0){
        log_trace("if <-");
        log_info("Add o primeiro elemento da pilha");
        stack->top=newNode;
        log_debug("o topo aponta para o newNode: %p", stack->top);
        log_trace("if ->");
    }
    else{
        log_trace("else <-");
        log_info("ha elementos na pilha");
        newNode->under=stack->top;
        stack->top=newNode;
        log_debug("newNode->under recebe o endereço do topo da pilha (stack->top): %d", newNode->under);
        log_debug("o topo aponta para o newNode: %p", stack->top);
        log_trace("else ->");
    }
    
    stack->size++;
    log_debug("stack->size é incrementado: %d", stack->size);
    log_trace("push -> \n");
    return 0;
}

void* pop(GenericDynamicStack *stack){
    log_trace("pop <-");
    log_info("Retirando um No da pilha");

    if(stack->top==NULL || stack->size==0){
        log_trace("if <-");
        log_error("**ERRO: a lista esta vazia");
        log_trace("if ->");
        log_trace("pop -> \n");
        return NULL;
    }
    
    void * data = stack->top->data;
    Node * lixo = stack->top;
    stack->top = lixo->under;
    log_debug("data recebe o dado a ser excluido: %d", data);
    log_debug("lixo recebe o topo da pilha(stack->top): %p", lixo);
    log_debug("stack->top recebe o endereço de lixo->under: %p", stack->top);
    free(lixo);
    stack->size--;
    log_debug("stack->size é decrementado: %d", stack->size);
    log_trace("pop -> \n");
    return data;
}

void* top(GenericDynamicStack *stack){
    log_trace("top <-");
    log_info("verificando o topo da pilha");

    if(stack->top==NULL || stack->size==0){
        log_trace("if <-");
        log_error("**ERRO: a lista esta vazia");
        log_trace("if ->");
        log_trace("top -> \n");
        return NULL;
    }
    else{
        log_trace("else <-");
        //return (stack->top);  //fiz errado
        log_debug("stack->top->data: %d", stack->top->data);
        log_trace("else ->");
        log_trace("top -> \n");
        return (stack->top->data);
    }
}

void show(GenericDynamicStack *stack, printNode print){
    log_trace("show <-");
    log_info("Imprimindo os dados da pilha");
    
    Node *aux= stack->top;
    while(aux!=NULL){
        log_trace("while <-");
        print(aux->data);
        aux=aux->under;
    }
    log_trace("while ->");
    log_trace("show -> \n");
}


