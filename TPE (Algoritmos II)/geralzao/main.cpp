#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "CadastroPessoa.txt"

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    char sexo;
} Pessoa;

void cadastrarPessoa();
void editarPessoa();
void exibirPessoas();
void deletarPessoa();
int gerarCodigo();

int main() {
    int menu;

    do {
        printf("\n Menu \n");
        printf("Para cadastrar nova pessoa, insira (1): \n");
        printf("Para editar uma pessoa existente, insira (2): \n");
        printf("Para exibir pessoas cadastradas, insira (3): \n");
        printf("Para deletar um cadastro, insira (4): \n");
        printf("Para sair, insira (5): \n");
        scanf("%d", &menu);
        getchar();

        switch (menu) {
        case 1:
            cadastrarPessoa();
            break;
        case 2:
            editarPessoa();
            break;
        case 3:
            exibirPessoas();
            break;
        case 4:
            deletarPessoa();
            break;
        case 5:
            printf("Saindo do menu...\n");
            break;
        default:
            printf("Informe uma opção válida!\n");
        }
    } while (menu != 5);

    return 0;
}

void cadastrarPessoa() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Pessoa p;
    p.codigo = gerarCodigo();
    printf("Nome: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = 0;
    printf("Idade: ");
    scanf("%d", &p.idade);
    getchar();
    printf("Sexo (m/f): ");
    scanf(" %c", &p.sexo);
    getchar();

    fwrite(&p, sizeof(Pessoa), 1, file);
    fclose(file);
    printf("Cadastro realizado! Código: %d\n", p.codigo);
}

void editarPessoa() {
    FILE *file = fopen(FILE_NAME, "r+b");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    int codigo;
    printf("Informe o código da pessoa para editar: ");
    scanf("%d", &codigo);
    getchar();

    Pessoa p;
    while (fread(&p, sizeof(Pessoa), 1, file)) {
        if (p.codigo == codigo) {
            printf("Novo nome: ");
            fgets(p.nome, 50, stdin);
            p.nome[strcspn(p.nome, "\n")] = 0;
            printf("Nova idade: ");
            scanf("%d", &p.idade);
            getchar();
            printf("Novo sexo (m/f): ");
            scanf(" %c", &p.sexo);
            getchar();

            fseek(file, -sizeof(Pessoa), SEEK_CUR);
            fwrite(&p, sizeof(Pessoa), 1, file);
            fclose(file);
            printf("Cadastro atualizado com sucesso!\n");
            return;
        }
    }

    printf("Código não encontrado!\n");
    fclose(file);
}

void exibirPessoas() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    Pessoa p;
    printf("\nLista de pessoas cadastradas:\n");
    while (fread(&p, sizeof(Pessoa), 1, file)) {
        printf("Código: %d, Nome: %s, Idade: %d, Sexo: %c\n", p.codigo, p.nome, p.idade, p.sexo);
    }

    fclose(file);
}

void deletarPessoa() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int codigo;
    printf("Informe o código da pessoa para deletar: ");
    scanf("%d", &codigo);
    getchar();

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(file);
        return;
    }

    Pessoa p;
    int found = 0;
    while (fread(&p, sizeof(Pessoa), 1, file)) {
        if (p.codigo == codigo) {
            found = 1;
        } else {
            fwrite(&p, sizeof(Pessoa), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Feito! Pessoa removida com sucesso!\n");
    } else {
        printf("Código não encontrado!\n");
    }
}

int gerarCodigo() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) return 1;

    Pessoa p;
    int codigo = 1;
    while (fread(&p, sizeof(Pessoa), 1, file)) {
        codigo = p.codigo + 1;
    }
    fclose(file);
    return codigo;
}#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "CadastroPessoa.txt"

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    char sexo;
} Pessoa;

void cadastrarPessoa();
void editarPessoa();
void exibirPessoas();
void deletarPessoa();
int gerarCodigo();

int main() {
    int menu;

    do {
        printf("\n Menu \n");
        printf("Para cadastrar nova pessoa, insira (1): \n");
        printf("Para editar uma pessoa existente, insira (2): \n");
        printf("Para exibir pessoas cadastradas, insira (3): \n");
        printf("Para deletar um cadastro, insira (4): \n");
        printf("Para sair, insira (5): \n");
        scanf("%d", &menu);
        getchar();

        switch (menu) {
        case 1:
            cadastrarPessoa();
            break;
        case 2:
            editarPessoa();
            break;
        case 3:
            exibirPessoas();
            break;
        case 4:
            deletarPessoa();
            break;
        case 5:
            printf("Saindo do menu...\n");
            break;
        default:
            printf("Informe uma opção válida!\n");
        }
    } while (menu != 5);

    return 0;
}

void cadastrarPessoa() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Pessoa p;
    p.codigo = gerarCodigo();
    printf("Nome: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = 0;
    printf("Idade: ");
    scanf("%d", &p.idade);
    getchar();
    printf("Sexo (m/f): ");
    scanf(" %c", &p.sexo);
    getchar();

    fwrite(&p, sizeof(Pessoa), 1, file);
    fclose(file);
    printf("Cadastro realizado! Código: %d\n", p.codigo);
}

void editarPessoa() {
    FILE *file = fopen(FILE_NAME, "r+b");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    int codigo;
    printf("Informe o código da pessoa para editar: ");
    scanf("%d", &codigo);
    getchar();

    Pessoa p;
    while (fread(&p, sizeof(Pessoa), 1, file)) {
        if (p.codigo == codigo) {
            printf("Novo nome: ");
            fgets(p.nome, 50, stdin);
            p.nome[strcspn(p.nome, "\n")] = 0;
            printf("Nova idade: ");
            scanf("%d", &p.idade);
            getchar();
            printf("Novo sexo (m/f): ");
            scanf(" %c", &p.sexo);
            getchar();

            fseek(file, -sizeof(Pessoa), SEEK_CUR);
            fwrite(&p, sizeof(Pessoa), 1, file);
            fclose(file);
            printf("Cadastro atualizado com sucesso!\n");
            return;
        }
    }

    printf("Código não encontrado!\n");
    fclose(file);
}

void exibirPessoas() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    Pessoa p;
    printf("\nLista de pessoas cadastradas:\n");
    while (fread(&p, sizeof(Pessoa), 1, file)) {
        printf("Código: %d, Nome: %s, Idade: %d, Sexo: %c\n", p.codigo, p.nome, p.idade, p.sexo);
    }

    fclose(file);
}

void deletarPessoa() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    int codigo;
    printf("Informe o código da pessoa para deletar: ");
    scanf("%d", &codigo);
    getchar();

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(file);
        return;
    }

    Pessoa p;
    int found = 0;
    while (fread(&p, sizeof(Pessoa), 1, file)) {
        if (p.codigo == codigo) {
            found = 1;
        } else {
            fwrite(&p, sizeof(Pessoa), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Feito! Pessoa removida com sucesso!\n");
    } else {
        printf("Código não encontrado!\n");
    }
}

int gerarCodigo() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) return 1;

    Pessoa p;
    int codigo = 1;
    while (fread(&p, sizeof(Pessoa), 1, file)) {
        codigo = p.codigo + 1;
    }
    fclose(file);
    return codigo;
}
