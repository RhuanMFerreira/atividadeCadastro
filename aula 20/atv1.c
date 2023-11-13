#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Usuario
{
    int id;
    char nome[50];
    char email[50];
    char sexo[15];
    char endereco[100];
    double altura;
    int vacina;
};

int gerarId()
{
    return rand() % 10000 + 1;
}

void incluirUsuario(struct Usuario usuarios[], int *contador)
{
    if (*contador < 1000)
    {
        struct Usuario novoUsuario;
        novoUsuario.id = gerarId();

        printf("Nome completo: ");
        scanf(" %[^\n]s", novoUsuario.nome);

        printf("Email: ");
        scanf(" %s", novoUsuario.email);

        if (strstr(novoUsuario.email, "@") == NULL)
        {
            printf("Email invalido. O email deve conter '@'.\n");
            return;
        }

        printf("Sexo (Feminino/Masculino/Indiferente): ");
        scanf(" %s", novoUsuario.sexo);

        if (strcmp(novoUsuario.sexo, "Feminino") != 0 && strcmp(novoUsuario.sexo, "Masculino") != 0 && strcmp(novoUsuario.sexo, "Indiferente") != 0)
        {
            printf("Sexo invalido. Escolha entre Feminino, Masculino ou Indiferente.\n");
            return;
        }

        printf("Endereco: ");
        scanf(" %[^\n]s", novoUsuario.endereco);

        printf("Altura (entre 1 e 2 metros): ");
        scanf("%lf", &novoUsuario.altura);

        if (novoUsuario.altura < 1 || novoUsuario.altura > 2)
        {
            printf("Altura invalida. Digite um valor entre 1 e 2 metros.\n");
            return;
        }

        printf("Recebeu a vacina? (1 para sim, 0 para nao): ");
        scanf("%d", &novoUsuario.vacina);

        usuarios[*contador] = novoUsuario;
        (*contador)++;
        printf("Usuario cadastrado com sucesso!\n");
    }
    else
    {
        printf("Limite de usuarios atingido. Nao e possivel adicionar mais usuarios.\n");
    }
}

void editarUsuario(struct Usuario usuarios[], int contador)
{
    int idEditar;
    printf("Digite o ID do usuario que deseja editar: ");
    scanf("%d", &idEditar);

    int encontrado = 0;
    for (int i = 0; i < contador; i++)
    {
        if (usuarios[i].id == idEditar)
        {
            printf("Novo nome completo: ");
            scanf(" %[^\n]s", usuarios[i].nome);

            printf("Novo email: ");
            scanf(" %s", usuarios[i].email);

            if (strstr(usuarios[i].email, "@") == NULL)
            {
                printf("Email invalido. O email deve conter '@'.\n");
                return;
            }

            printf("Novo sexo (Feminino/Masculino/Indiferente): ");
            scanf(" %s", usuarios[i].sexo);

            if (strcmp(usuarios[i].sexo, "Feminino") != 0 && strcmp(usuarios[i].sexo, "Masculino") != 0 && strcmp(usuarios[i].sexo, "Indiferente") != 0)
            {
                printf("Sexo invalido. Escolha entre Feminino, Masculino ou Indiferente.\n");
                return;
            }

            printf("Novo endereco: ");
            scanf(" %[^\n]s", usuarios[i].endereco);

            printf("Nova altura (entre 1 e 2 metros): ");
            scanf("%lf", &usuarios[i].altura);

            if (usuarios[i].altura < 1 || usuarios[i].altura > 2)
            {
                printf("Altura invalida. Digite um valor entre 1 e 2 metros.\n");
                return;
            }

            printf("Recebeu a vacina? (1 para sim, 0 para nao): ");
            scanf("%d", &usuarios[i].vacina);

            printf("Usuario editado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Usuario nao encontrado.\n");
    }
}

void excluirUsuario(struct Usuario usuarios[], int *contador)
{
    int idExcluir;
    printf("Digite o ID do usuario que deseja excluir: ");
    scanf("%d", &idExcluir);

    int encontrado = 0;
    for (int i = 0; i < *contador; i++)
    {
        if (usuarios[i].id == idExcluir)
        {
            for (int j = i; j < *contador - 1; j++)
            {
                usuarios[j] = usuarios[j + 1];
            }
            (*contador)--;
            printf("Usuario excluido com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Usuario nao encontrado.\n");
    }
}

void buscarUsuarioPorEmail(struct Usuario usuarios[], int contador)
{
    char emailBusca[50];
    printf("Digite o email do usuario que deseja buscar: ");
    scanf(" %s", emailBusca);

    int encontrado = 0;
    for (int i = 0; i < contador; i++)
    {
        if (strcmp(usuarios[i].email, emailBusca) == 0)
        {
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereco: %s\n", usuarios[i].endereco);
            printf("Altura: %.2f metros\n", usuarios[i].altura);
            printf("Recebeu a vacina? %s\n", usuarios[i].vacina ? "Sim" : "Nao");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Usuario nao encontrado.\n");
    }
}

void imprimirUsuarios(struct Usuario usuarios[], int contador)
{
    for (int i = 0; i < contador; i++)
    {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Endereco: %s\n", usuarios[i].endereco);
        printf("Altura: %.2f metros\n", usuarios[i].altura);
        printf("Recebeu a vacina? %s\n", usuarios[i].vacina ? "Sim" : "Nao");
        printf("\n");
    }
}

int main()
{
    struct Usuario usuarios[1000];
    int contador = 0;
    char opcao;

    do
    {
        printf("Escolha uma opcao:\n");
        printf("1. Incluir usuario\n");
        printf("2. Editar usuario\n");
        printf("3. Excluir usuario\n");
        printf("4. Buscar usuario por email\n");
        printf("5. Imprimir todos os usuarios\n");
        printf("0. Sair\n");

        printf("Opcao: ");
        scanf(" %c", &opcao);

        switch (opcao)
        {
        case '1':
            incluirUsuario(usuarios, &contador);
            break;
        case '2':
            editarUsuario(usuarios, contador);
            break;
        case '3':
            excluirUsuario(usuarios, &contador);
            break;
        case '4':
            buscarUsuarioPorEmail(usuarios, contador);
            break;
        case '5':
            imprimirUsuarios(usuarios, contador);
            break;
        case '0':
            printf("Saindo do programa. Ate mais!\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != '0');

    return 0;
}