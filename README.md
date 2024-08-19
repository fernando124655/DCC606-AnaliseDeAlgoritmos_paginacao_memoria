# Memória Virtual em C

Este projeto demonstra como mapear um arquivo de texto para a memória virtual do sistema operacional usando a função `mmap` em C. O programa aceita um arquivo `.txt` como entrada e retorna o tamanho do arquivo e o endereço da página de memória onde os dados foram mapeados.

## Requisitos

- Sistema operacional Linux
- Compilador GCC instalado

## Instruções de Compilação e Execução

### Passo 1: Clonar ou Baixar o Código

Primeiro, você deve obter o código fonte. Você pode cloná-lo de um repositório Git ou simplesmente copiar e colar o código fonte em um arquivo chamado `main.c`.

### Passo 2: Compilar o Código

Abra o terminal e navegue até o diretório onde o arquivo `main.c` está localizado. Em seguida, use o GCC para compilar o código:

```gcc -o main main.c```
Este comando compila o código e gera um executável chamado mmap_program.

### Passo 3: Executar o Programa
Para executar o programa, você precisa fornecer o caminho para um arquivo .txt que deseja mapear na memória. Por exemplo:


```./main file-5mb.txt```
Substitua seu_arquivo.txt pelo caminho real do arquivo de texto que você deseja usar. O programa exibirá o tamanho do arquivo em bytes e o endereço da página de memória onde os dados foram mapeados.

### Exemplo de Saída

Copiar código
Tamanho do arquivo: 1024 bytes
Endereço da página de memória: 0x7f9bc3a45000