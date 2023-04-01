stack:
	@echo
	@echo ================================================================================
	@echo      PILHA DINAMICA: PROVA 1
	@echo ================================================================================
	@echo Compilando o programa stack
	gcc --std=c99 -DLOG_USE_COLOR log.h log.c GenericDynamicStack.c GenericDynamicStack.h GenericDynamicStackTest.c -o stack
	@echo Tornando o arquivo executável
	chmod +x stack
	@echo Executando o programa stack
	@echo ================================================================================
	@echo
	./stack

clean:
	@echo
	@echo ================================================================================
	@echo APAGANDO TODOS OS PROGRAMAS
	@echo ================================================================================
	@echo Removendo o programa stack
	rm -f stack
