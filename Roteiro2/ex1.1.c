/*
Crie uma estrutura chamada ContaBancaria para encapsular os detalhes de uma conta bancária. A estrutura deve conter as seguintes informações: número da conta, saldo e nome do
titular da conta. Implemente as seguintes funções para interagir com a conta bancária:
• void criarConta(ContaBancaria* c, int numero, char *titular)
– Cria uma nova conta bancária com o número e titular especificados.
– Inicializa o saldo como zero.
• void depositar(ContaBancaria *c, double valor)
– Deposita o valor especificado na conta.
• void sacar(ContaBancaria *c, double valor)
– Realiza um saque da conta, desde que haja saldo suficiente.
• double consultarSaldo(ContaBancaria *c)
– Retorna o saldo atual da conta.
• void imprimirInfo(ContaBancaria *c)
– Imprime as informa¸c˜oes da conta, incluindo n´umero, titular e saldo.
*/
