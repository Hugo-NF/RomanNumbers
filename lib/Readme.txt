Trabalho 2 - M�todos de Programa��o (201600)

1. Compila��o.
	- Abra o diret�rio src no terminal e digite make
2. Arquivos gcov
	- Existe uma regra no makefile que move os arquivos gcov para a pasta src/gcov_files
	- Para utiliza-l� digite no terminal "make mv_gcov_files"
	- Para visualizar os arquivos gcov digite, dentro da pasta src/gcov, gcov (nome_do_modulo)
3. Cppcheck
	- Para utilizar o cppcheck nos arquivos, utilize o seguinte comando: cppcheck nome_do_arquivo.c --enable=warning
4. Doxygen
	- A documenta��o gerada pelo Doxygen encontra-se no diret�rio src/doxygen
 