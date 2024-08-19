#include <stdio.h>
#include <stdlib.h>
#include <sys/mmap.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo.txt>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("Erro ao obter o tamanho do arquivo");
        close(fd);
        return 1;
    }

    size_t file_size = file_stat.st_size;
    printf("Tamanho do arquivo: %ld bytes\n", file_size);

    // Mapeia o arquivo para a memória
    void *map = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        perror("Erro ao mapear o arquivo para a memória");
        close(fd);
        return 1;
    }

    // Exibe o endereço da página de memória
    printf("Endereço da página de memória: %p\n", map);

    // Desmapear a memória e fechar o arquivo
    if (munmap(map, file_size) == -1) {
        perror("Erro ao desmapear a memória");
    }

    close(fd);
    return 0;
}
