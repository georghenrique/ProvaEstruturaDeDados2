#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "GenericDynamicStack.h"


int main(){
    GenericDynamicStack stack;
    void *aux = (void*) 1;//add um transformador de tipo
    //push(&stack, aux);
    pop(&stack);
    top(&stack);
    init(&stack);


    push(&stack, aux);
    top(&stack);

    pop(&stack);
    aux = (void*) 10;
    push(&stack, aux);
    top(&stack);
}
