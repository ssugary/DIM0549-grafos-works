    # DIM0549-grafos-works

Este projeto implementa algoritmos de grafos em C++.

## Requisitos

- CMake >= 3.10
- Compilador C++ (recomendado: g++ >= 7)

## Como compilar e executar

1. Clone o repositório ou navegue até a pasta do projeto.

2. Gere os arquivos de build com o CMake:

```bash
cmake -S . -B build
```

3. Compile o projeto:

```bash
cmake --build build
```

4. Execute o programa:

```bash
./build/grafos <caminho-do-arquivo> <tipo-do-grafo>
```

onde: 

<caminho-do-arquivo> é o caminho do arquivo de leitura
<tipo-do-grafo> é o tipo que os vertices do grafo vão ter, podendo receber "-c" ou "--char" para vértices do tipo char e "-i" ou "--int" para vértices do tipo inteiro. 



## Estrutura

- `main.cpp`: ponto de entrada do programa
- `include/`: arquivos de cabeçalho
- `src/`: arquivos de implementação

## Autor


## Licença

Este projeto é acadêmico e livre para uso.
