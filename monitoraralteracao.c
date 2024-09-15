#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

void verificarAlteracao(const char *filename, time_t *last_mod_time) {
    struct stat file_stat;

    if (stat(filename, &file_stat) == 0) {
        if (difftime(file_stat.st_mtime, *last_mod_time) != 0) {
            printf("O arquivo '%s' foi alterado.\n", filename);
            *last_mod_time = file_stat.st_mtime;
        }
    } else {
        printf("Erro ao acessar o arquivo.\n");
    }
}

int main() {
    const char *arquivo = "tarefas.csv";
    struct stat file_stat;

    // Obter o tempo de modificação inicial
    if (stat(arquivo, &file_stat) != 0) {
        printf("Erro ao acessar o arquivo.\n");
        return 1;
    }

    time_t ultimo_mod_time = file_stat.st_mtime;

    // Loop de monitoramento (sai após 30 verificações)
    for (int i = 0; i < 30; i++) {
        verificarAlteracao(arquivo, &ultimo_mod_time);
        sleep(10);  // Verifica a cada 10 segundos
    }

    return 0;
}
