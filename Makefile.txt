stack:

gcc --std=c99 GenericDynamicStack.c GenericDynamicStack.h GenericDynamicStackTest.c -o stack
chmod +x stack
./stack

linkedlist:

gcc --std=c99 -DLOG_USE_COLOR log.h log.c linkedList.h - o linkedlist
chmod +x linkedlist
./linkedlist