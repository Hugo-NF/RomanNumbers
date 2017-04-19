
# RomanNumbers
Pequeno programa em linguagem C para converter números romanos em números arábicos.
Trabalho 2 - Métodos de Programação (201600)

1. Compilação.
	- Abra o diretório src no terminal e digite make
2. Arquivos gcov
	- Existe uma regra no makefile que move os arquivos gcov para a pasta src/gcov_files
	- Para utiliza-lá digite no terminal "make mv_gcov_files"
	- Para visualizar os arquivos gcov digite, dentro da pasta src/gcov, gcov (nome_do_modulo)
3. Cppcheck
	- Para utilizar o cppcheck nos arquivos, utilize o seguinte comando: cppcheck nome_do_arquivo.c --enable=warning
4. Doxygen
	- A documentação gerada pelo Doxygen encontra-se no diretório src/doxygen
5. gtest
	- Para alterar a localização do gtest, basta alterar a variável LIBS do makefile. No padrão, ele está instalado como biblioteca compartilhada do sistema.
