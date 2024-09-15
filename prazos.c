#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define MAX_TASKS 100

// Estrutura para armazenar as tarefas
typedef struct {
    int id;
    char nome[50];
    char dataEntrega[11];  // Data no formato YYYY-MM-DD
    char responsavel[30];
    char status[20];
} Tarefa;

// Função para calcular a diferença em dias entre duas datas
int diferenca_dias(const char *data1, const char *data2) {
    struct tm tm1 = {0}, tm2 = {0};
    strptime(data1, "%Y-%m-%d", &tm1);
    strptime(data2, "%Y-%m-%d", &tm2);

    time_t t1 = mktime(&tm1);
    time_t t2 = mktime(&tm2);

    double seconds = difftime(t1, t2);
    return seconds / (60 * 60 * 24);
}

// Função para ler o CSV e preencher as tarefas
int lerTarefas(const char *filename, Tarefa tarefas[], int *numTarefas) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int taskIndex = 0;
    

    // Ignora a primeira linha (cabeçalho)
    fgets(line, MAX_LINE_LENGTH, file);

    // Lê cada linha e preenche a estrutura Tarefa
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        sscanf(line, "%d,%49[^,],%10[^,],%29[^,],%19[^\n]",
               &tarefas[taskIndex].id,
               tarefas[taskIndex].nome,
               tarefas[taskIndex].dataEntrega,
               tarefas[taskIndex].responsavel,
               tarefas[taskIndex].status);
        taskIndex++;
    }

    *numTarefas = taskIndex;
    fclose(file);
    return 1;
}

// Função para verificar as tarefas próximas do prazo
void verificarPrazos(Tarefa tarefas[], int numTarefas) {
    char dataAtual[11];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(dataAtual, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    printf("Tarefas próximas do prazo:\n");
    for (int i = 0; i < numTarefas; i++) {
        int diasRestantes = diferenca_dias(tarefas[i].dataEntrega, dataAtual);
        if (diasRestantes <= 3 && strcmp(tarefas[i].status, "Concluído") != 0) {
            printf("- Tarefa: %s (Responsável: %s) - Prazo em %d dias.\n",
                   tarefas[i].nome, tarefas[i].responsavel, diasRestantes);
        }
    }
}

int main() {
    Tarefa tarefas[MAX_TASKS];
    int numTarefas = 0;

    // Ler tarefas do arquivo CSV
    if (!lerTarefas("tarefas.csv", tarefas, &numTarefas)) {
        return 1;
    }

    // Verificar prazos
    verificarPrazos(tarefas, numTarefas);

    return 0;
}

