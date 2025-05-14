#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fptr;

// Função para exibir o menu de opções
// e solicitar a escolha do usuário
void mensagem (){
    printf("╔══════════════════════════════════════════╗\n");
    printf("║ Digite 1 para inserir um usuário\n");
    printf("║ Digite 2 para inserir vários usuários\n");
    printf("║ Digite 3 para buscar um usuário por id\n");
    printf("║ Digite 4 para transferir entre usuários\n");
    printf("║ Digite 5 para remover um usuário\n");
    printf("║ Digite 6 para sair\n");
    printf("╚══════════════════════════════════════════╝\n\n");
}

// Variáveis globais
// para armazenar os usuários
int numUsuarios = 0;
int proximoId = 1;

// Estrutura para armazenar os dados do usuário
// A estrutura contém os campos id, nome, idade e saldo
struct usuario {
    int id;
    char nome[101];
    int idade;
    float saldo;

};

struct usuario *usuarios = NULL;

// Função para inserir um usuário
// A função aloca memória para o novo usuário
void inserirUsuario (){
    usuarios = realloc(usuarios, (numUsuarios + 1) * sizeof(struct usuario));
    
    if (usuarios == NULL) {
        printf("Erro ao realocar memória!\n");
        close(fptr);
        free(usuarios);
        return; 
    }
    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║ Digite o nome, a idade e o saldo atual do usuário a ser inserido\n");
    printf("╚══════════════════════════════════════════════════════════════════╝\n\n");

    scanf(" %100[^,], %d, %f", usuarios[numUsuarios].nome, &usuarios[numUsuarios].idade, &usuarios[numUsuarios].saldo);
    usuarios[numUsuarios].id = proximoId++;
    fprintf(fptr, "%d, %s, %d, %.2f\n", usuarios[numUsuarios].id, usuarios[numUsuarios].nome, usuarios[numUsuarios].idade, usuarios[numUsuarios].saldo);

    printf("╔══════════════════════════════════════════════════════════════════╗\n");
    printf("║ Usuário inserido com id: %d\n", usuarios[numUsuarios].id);
    printf("║ %s tem %d anos e %.2f reais\n", usuarios[numUsuarios].nome, usuarios[numUsuarios].idade, usuarios[numUsuarios].saldo);
    printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
    numUsuarios++;
}

// EM CONSTRUÇÃO
int main(){
    int n;
    int quantidade;
    if (usuarios == NULL) {
        printf("Erro ao alocar memória inicial!\n");
        close(fptr);
        free(usuarios);
        return 1;
    }
    fptr = fopen("usuarios.txt", "a");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        fclose(fptr);
        free(usuarios);
        return 1;
    }

    printf("\nBem-vindo ao Uaibank!\n\n");

    while (1){
    mensagem();
    scanf("%d", &n);

    switch(n){
        case 1 :
        inserirUsuario();
        break;

        case 2:
            printf("╔════════════════════════════════════════════════════╗\n");
            printf("║ Digite a quantidade de usuários a serem inseridos\n");
            printf("╚════════════════════════════════════════════════════╝\n\n");
            scanf("%d", &quantidade);

            if (quantidade < 0){
                printf("\nDigite uma quantidade válida");
            }

            for (int i = 0; i < quantidade; i++){
                inserirUsuario();
            }

        break;

        case 3: printf("tres");
        break;

        case 4: printf("quatro");
        break;

        case 5: printf("cinco");
        break;

        case 6:
            printf("╔═══════════════════════════════════╗\n");
            printf("║ Obrigado por escolher o Uaibank!\n");
            printf("╚═══════════════════════════════════╝\n\n");
            fclose(fptr);
            free(usuarios);
            return 0;

        default:
            printf("╔════════════════════════╗\n");
            printf("║ Digite um valor válido\n");
            printf("╚════════════════════════╝\n\n");
    }

    }
}