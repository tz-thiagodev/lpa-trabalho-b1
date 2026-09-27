# lpa-trabalho-b1
# Trabalho B1 - Lógica de Programação e Algoritmos

## Descrição
esse código é um programa em linguagem C que simula o atendimento de uma transportadora. Durante uma sessão de uso, o programa processa múltiplos pedidos de entrega, coletando e processando os dados de cada sessão. Além de calcular o valor final de acordo com regras de tarifação estabelecidas pela empresa, e ao final mostrar um resumo geral da sessão.

## Funcionalidades
- Processamento de múltiplas entregas em uma mesma execução, com opção de continuar ou encerrar a sessão
- Validação de todas as entradas de domínio (distância, peso, modalidade, proteção, tentativas adicionais, opção de continuar), solicitando novamente quando o valor informado é inválido
- Cálculo do valor de cada entrega, incluindo:
  - Valor-base por faixa de distância + tarifa por km
  - Adicional percentual por faixa de peso
  - Adicional percentual por modalidade (Econômica, Expressa, Prioritária)
  - Valor fixo de serviço de proteção, quando contratado
  - Valor por tentativa adicional de entrega
- Resumo final da sessão com total de entregas, valor total, valor médio, quantidade de entregas por modalidade, maior e menor valor de entrega

## Organização da solução
O programa foi dividido em cinco funções auxiliares, além da `main`, cada uma responsável por calcular uma parcela específica do valor da entrega:

- `calcularValorBase(distancia)`: retorna o valor-base de acordo com a faixa de distância
- `calcularAdicionalPeso(peso, subtotalInicial)`: retorna o adicional de peso, calculado sobre o subtotal inicial
- `calcularAdicionalModalidade(modalidade, subtotalInicial)`: retorna o adicional de modalidade, também sobre o subtotal inicial
- `calcularAdicionalProtecao(servicoProtecao)`: retorna o valor fixo de proteção, se contratada
- `calcularAdicionalTentativas(tentativasEntrega)`: retorna o valor das tentativas adicionais

A `main` fica responsável por coordenra o fluxo geral: laço de processamento de entregas, leitura e validação dos dados, chamada das funções de cálculo, atualização dos contadores/acumuladores do resumo, e impressão do resumo final ao encerrar a sessão.

## Compilação
Este projeto foi desenvolvido e testado no VS Code com a extensão C/C++, usando o botão de compilar/executar (Run) da extensão. Mas, ele também pode ser compilado manualmente pelo terminal, na raiz do repositório.

## Execução

É simples, o programa vai pedir os dados de uma entrega, mostrar o valor calculado, perguntar se deseja processar outra, e repetir esse fluxo até que seja informado 0 na pergunta de continuidade, caso informado, ele mostra o resumo da sessão é exibido e o programa encerra.

## Uso de Inteligência Artificial
Utilizei o Claude como apoio de aprendizagem durante o desenvolvimento deste trabalho, com as seguintes finalidades:
- Esclarecer um enunciado do roteiro (Tirar dúvidas sobre o que seria "tentativa adicional de entrega")
- Revisar minha lógica de laços de repetição e validação de entrada
- Depurar erros de cálculo (como uso de vírgula em vez de ponto decimal, condições copiadas incorretamente)
- Orientar sobre como modularizar o código em funções, para que eu fizesse o resto sozinho.
- Ajuda para organizar o repositório Git (remoção de arquivos de build/debug do versionamento via `.gitignore`)

Todas as sugestões foram compreendidas, testadas e ajustadas por mim antes de serem incorporadas ao código final. Não houve geração de código pronto sem entendimento da lógica envolvida.
