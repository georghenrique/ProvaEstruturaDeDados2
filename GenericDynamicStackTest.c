#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "GenericDynamicStack.h"


int main(){
    GenericDynamicStack stack;

    init(&stack);

    void *aux = 1;

    push(&stack, aux);

}