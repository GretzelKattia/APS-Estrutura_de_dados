# Projeto de Comparação de Algoritmos de Ordenação

## Descrição

Este projeto tem como objetivo avaliar a performance de diversos algoritmos de ordenação aplicados a um conjunto de dados relacionado ao desmatamento na Amazônia. 
O projeto foi inicialmente dividido consolidado em um único, juntando todos os métodos e chmdas do arquivo `.txt` e depois foi separado em vários arquivos, cada um com funcionalidades específicas, para melhor compreensão e manutenção do código

## Fonte dos Dados 
Os dados utilizados neste projeto foram obtidos da plataforma [MapBiomas](https://plataforma.alerta.mapbiomas.org/) Alerta, que fornece um sistema de alertas de desmatamento em tempo real. 

## Algoritmos de Ordenação Implementados

1. **Bubble Sort**
   - **Descrição:** Algoritmo simples que percorre a lista várias vezes, trocando elementos adjacentes que estão na ordem errada.
   - **Complexidade:** O(n²)
   - **Vantagens:** Simplicidade e eficiência em listas pequenas ou quase ordenadas.
   - **Desvantagens:** Ineficiente para listas grandes devido ao elevado número de comparações necessárias.

2. **Tim Sort**
   - **Descrição:** Versão otimizada do Merge Sort que também utiliza o Insertion Sort para lidar com pequenas sublistas.
   - **Complexidade:** O(n log n)
   - **Vantagens:** Desempenho excelente em dados reais, adaptado para listas parcialmente ordenadas.
   - **Desvantagens:** Implementação mais complexa e uso de memória adicional.

3. **Merge Sort**
   - **Descrição:** Algoritmo de divisão e conquista que divide a lista em sublistas, ordena essas sublistas e, em seguida, combina-as em uma lista ordenada.
   - **Complexidade:** O(n log n)
   - **Vantagens:** Eficiência consistente e estabilidade na ordenação.
   - **Desvantagens:** Uso de memória adicional proporcional ao tamanho da lista.

4. **Radix Sort**
   - **Descrição:** Algoritmo de ordenação não comparativa que ordena inteiros ou strings baseando-se nos dígitos ou caracteres.
   - **Complexidade:** O(n)
   - **Vantagens:** Desempenho linear para certos tipos de dados.
   - **Desvantagens:** Limitação de tipo de dados (inteiros e strings) e uso de memória adicional.

5. **Heap Sort**
   - **Descrição:** Utiliza uma estrutura de dados de heap para ordenar elementos.
   - **Complexidade:** O(n log n)
   - **Vantagens:** Eficiência de tempo e baixo uso de memória adicional.
   - **Desvantagens:** Não é estável e pode ser ligeiramente mais lento que Merge Sort em implementações práticas.

## Estrutura do Projeto

### `imagem.h`

Define a estrutura `Imagem` que armazena os dados do desmatamento, incluindo:
- `codigo_alerta`: Código do alerta de desmatamento
- `area`: Área afetada
- `data_foto_antes`: Data da foto tirada antes do desmatamento
- `data_foto_depois`: Data da foto tirada depois do desmatamento
- `estado`: Sigla do estado brasileiro
- `municipio`: Nome do município

### `gerar_dados.h` e `gerar_dados.c`

Contém funções para gerar dados internos e salvar esses dados em um arquivo:
- `gerar_dados_internos`: Gera dados de desmatamento de forma aleatória
- `salvar_dados_aleatorios`: Salva os dados gerados em um arquivo

### `main.c`

O arquivo principal que:
- Lê os dados de um arquivo ou gera dados aleatórios
- Aplica os algoritmos de ordenação aos dados
- Mede e imprime o tempo de execução de cada algoritmo
- Salva os dados ordenados em arquivos de saída

## Como Executar

### Pré-requisitos

- Compilador C (como GCC)
- Ambiente de desenvolvimento configurado para C

### Demonstração
Como eu tive dificuldades de compilar o arquivo C no meu notebook, encontrei a plataforma chamado **online gbd**, que utilizei durante todo o desenvolvimento dos códigos. Irei compartilhar o link logo abaixo:

<div align="center">
https://onlinegdb.com/3OlpsFyKf
</div>

## Licença

Este projeto está licenciado sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
