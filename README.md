Projeto de Extensão Linguagem C


Este projeto busca otimizar a organização interna de uma instiuição por meio de 2 soluções práticas e gratuitas.


O primeiro código se chama "Prazos". Ele foi organizado em 4 etapas para ajudar no acompanhamento dos prazos de todos os projetos:

Explicação do Código PRAZO:

A) Estrutura de Dados: Cria uma estrutura Tarefa para armazenar as informações de cada trabalho.

B) Função de Leitura CSV: A função lerTarefas() lê o arquivo CSV e preenche um array com as informações das tarefas.

C) Verificação de Prazos: A função verificarPrazos() compara as datas de entrega com a data atual e avisa se algum prazo está próximo (3 dias ou menos).

D) Diferença de Dias: A função diferenca_dias() é usada para calcular a diferença entre a data de entrega e a data atual.


O segundo código é para Monitoramento de Alterações em Planilhas. Para isso, nós verificamos o tempo de modificação do arquivo no sistema. Em C, nós fazemos isso utilizando a função stat() da biblioteca sys/stat.h, que permite verificar o timestamp de um arquivo.

Com esses 2 modelo básico, é possível obtermos uma otimização no sistema de gerenciamento e comunicação para a empresa, automatizando a verificação de prazos e monitoramento de alterações em arquivos.


Além disso, a utilização do google drive local, com a possibilidade da função offline, auxilia a manter o sistema todo funcionando e integrado para a equipe.
