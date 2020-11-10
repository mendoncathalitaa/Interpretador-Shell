# Interpretador-Shell


Disciplina: SIN 351 - Sistemas Operacionais
Professor: Rodrigo Moreira
Projeto: Interpretador Shell

Integrantes do projeto:
Amanda Oliveira Nascimento - 5149
Thalita Mendonça Antico - 5141
Vinicius Hideyuki Ikehara -5191

Este arquivo readme serve como um manual para o nosso Interpretador Shell.
No nosso .zip também terá um arquivo .pdf que falará mais sobre o processo da criação e entendimento das funções e também com prints das nossas telas testando diversos comandos no nosso Shell.

Link para o repositório do github: https://github.com/mendoncathalitaa/Interpretador-Shell

Iniciando o Shell:

No nosso .zip temos os arquivos "makefile" e "shell.c".
Para compilar o código você deve abrir a pasta onde está localizado os arquivos "makefile" e "shell.c".
Após abrir a pasta será necessário abrir o terminal dentro deste diretório, do contrário o código não será encontrado pelo terminal.
Com o terminal aberto no diretório correto, agora para compilar o código é só digitar no terminal a palavra "make" e apertando o enter.
Se tudo tiver dado certo o seu terminal não irá acusar nenhum erro e agora é possível executar o código.
Para executar o código é necessário digitar no terminal "./output" e apertar o enter.

Shell em execução:

Se após os processos de inicialização no seu terminal ao invés do seu user Linux estiver aparecendo "meu-shell>" então é porque agora você já está utilizando o nosso Interpretador Shell e pode começar a explorar e digitar comandos para o terminal Linux.

Alguns comandos testados que obtiveram êxito:
"ls";
"grep";
"cat";
"quit";
“poweroff”;
"touch";
“clear.

PS: Este foram os comandos conhecidos e testados por nós, testamos apenas estes pois são os comandos que conhecemos.

Na descrição do trabalho disponibilizada pelo professor Rodrigo, o nosso Shell deveria ser capaz de interpretar comandos concatenados por ",", exemplo: ls -l, cat file1.

No entanto não obtivemos êxito com relação aos comandos concatenados com "," o máximo que conseguimos fazer foi comandos que começam com "," e que não temos nenhum espaço em branco do tipo " ".

Portanto considerando a aceitação de comandos com "," os comandos testados que obtiveram êxito foram os que começam com a “,”:
",ls";
",quit";
",poweroff".
“,clear.
PS: Caso tenha outros comandos que não tenham espaços do tipo “ “ entre eles, acredito que estes também obteriam êxitos.

Situações de erro que deveriam ser consideradas pela descrição do trabalho que obtiveram êxito:

Número de argumentos:
Comando inexistente ou impossível de ser executado: caso tenhamos um input de comando inexistente este será simplesmente ignorado;
A quantidade de caracteres por linha de comando é limitada a 512: caso tenhamos um input de comando com a quantidade de caracteres maior que 512 uma mensagem de erro será printada avisando que o tamanho de entrada foi excedido;
Entrada vazia como comando não deve ser 
considerada: Caso o usuário simplesmente de enter e o input seja “\n” este será simplesmente ignorado;
Espaços extra entre comandos deverão ser desconsiderados: Caso um comando seja digitado com espaços extras este comando será ignorado;

Não foram encontradas situações em que o interpretador teve que ser encerrado forçadamente apertando o “x” no canto superior direito em sua última versão, porém nas primeiras versões houveram momentos que digitando uma certa sequência de códigos, o shell travava num loop em que não importava o que fosse digitado que nenhum comando seria computado, nem mesmo o quit.

