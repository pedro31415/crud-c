#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h> 

void voltar_menu();
void listar_livros();
void menu_principal();
void cadastrar_cliente();
void clientes_cadastrados();
void listar_clientes();
void menu_clientes();
void menu_estoque();
void menu_venderLivro();
void livro_vendido();
void listar_livroVendido();
void menu_funcionario();
void cadastrar_funcionario();
void listar_funcionario();
void desenvolvimento();

typedef struct
{
    char Nome[100];
    char Telefone[100];
} Tcliente;

typedef struct
{
    char nome[100];
    char quantidade[100]; 
}Tlivros;

typedef struct 
{
    char nome[100];
    char cpf[100];
}Tfuncionario;


int main()
{
    setlocale(LC_ALL, "Portuguese");
    menu_principal();

    return 0;
}

void menu_principal()
{
    int op;
    system("cls");
    printf("|-------------------------------------|\n");
    printf("|       LOJA, HARRY POTTER.           |\n");
    printf("|       1.Vender um livro:            |\n");
    printf("|       2.Estoque:                    |\n");
    printf("|       3.Clientes:                   |\n");
    printf("|       4.Cadastro do funcionario:    |\n");
    printf("|       5.Sair:                       |\n");
    printf("|-------------------------------------|\n");
    printf("|         Escolha uma opcao: ");
    scanf("%d", &op);
    printf("        |\n");
    printf("|-------------------------------------|\n");
    if(op == 1)
    {
      menu_venderLivro();
      voltar_menu();
    }
    if (op == 2)
    {
        menu_estoque();
        voltar_menu();
    }
    if (op == 3)
    {   
        menu_clientes();
        voltar_menu();
    }
     if(op==4)
    {
        menu_funcionario();
        voltar_menu();
    }
    if(op==5)
    {
        exit(0);
    }
}

void menu_clientes()
{
    int op;
    printf("|-------------------------------------|\n");
    printf("|       1.Cadastrar novo cliente:     |\n");
    printf("|       2.Mostra todos os clientes:   |\n");
    printf("|       3.Atualizar cadastro:         |\n");
    printf("|       4.Excluir cadastro:           |\n");
    printf("|       5.voltar:                     |\n");
    printf("|-------------------------------------|\n");
    printf("|         Escolha uma opcao: ");
    scanf("%d", &op);
    printf("        |\n");
    printf("|-------------------------------------|\n");

    if(op == 1)
    {
       cadastrar_cliente();
       voltar_menu();
    }
    if(op == 2)
    {
       listar_clientes();
       voltar_menu();
    }
    if(op == 3)
    {
       desenvolvimento();
       voltar_menu();
    }
    if(op == 4)
    {
        desenvolvimento();
        voltar_menu();
    }
    if(op == 5)
    {
        menu_principal();
    }
}

void menu_estoque()
{
   int op;
    printf("|-------------------------------------|\n");
    printf("|       1.Ver estoque:                |\n");
    printf("|       2.Atualizar estoque:          |\n");
    printf("|       3.voltar:                     |\n");
    printf("|-------------------------------------|\n");
    printf("|         Escolha uma opcao: ");
    scanf("%d", &op);
    printf("        |\n");
    printf("|-------------------------------------|\n");
    if(op == 1)
    {
        listar_livros();
        voltar_menu();
    }
    if(op == 2)
    {
        desenvolvimento();
        voltar_menu();
    }
    if(op == 3)
    {
        menu_principal();
    }
}

void menu_venderLivro()
{
    int op;
    printf("|-------------------------------------|\n");
    printf("|                                     |\n");
    printf("|    1.Venda um livro da J.K.Rowling  |\n");
    printf("|    2.Livros ja vendido:             |\n");
    printf("|    3.voltar:                        |\n");
    printf("|                                     |\n");
    printf("|-------------------------------------|\n");
    printf("|         Escolha uma opcao: ");
    scanf("%d", &op);
    printf("        |\n");
    printf("|-------------------------------------|\n");
    if(op == 1)
    {
      livro_vendido();
      voltar_menu();
    }
    if( op == 2)
    {
     listar_livroVendido();
     voltar_menu();
    }
    if(op == 3)
    {
      menu_principal();
    }
    

}

void menu_funcionario()
{
    int op;
    printf("|-------------------------------------|\n");
    printf("|                                     |\n");
    printf("|    1.Cadastrar novo funcionario:    |\n");
    printf("|    2.Mostrar todos os funcionarios: |\n");
    printf("|    3.Atualizar cadastro:            |\n");
    printf("|    4.Excluir cadastro:              |\n");
    printf("|    5.Voltar                         |\n");
    printf("|-------------------------------------|\n");
    printf("|         Escolha uma opcao: ");
    scanf("%d", &op);
    printf("        |\n");
    printf("|-------------------------------------|\n");
    if(op == 1)
    {
      cadastrar_funcionario();
      voltar_menu();
    }
    if(op == 2)
    {
     listar_funcionario();
     voltar_menu();    
    }
    if(op == 3)
    {
        desenvolvimento();
        voltar_menu(); 
    }
    if(op == 4)
    {
        desenvolvimento();
        voltar_menu();
    }
    if(op == 5)
    {
     menu_principal();
    }

}

void voltar_menu()
{
    int opt;
    printf("Se deseja voltar aperte 1, se deseja sair aperte 2: ");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
        menu_principal();
        break;

    case 2:
        exit(0);

    default:
        printf("Opcao invalida. Tente novamente!");
    }
}

void listar_livros()
{
    FILE *livros_csv  = fopen("livros.csv", "r");
 
    if (!livros_csv)
    {
        printf("Arquivo nao encontrado\n");
    }
    else {
        
        char buffer[1024];
 
        int row = 0;
        int column = 0;
 
        while (fgets(buffer,
                     1024, livros_csv)) {
            column = 0;
            row++;
 
           
            if (row == 1)
                continue;
 
            
            char *value = strtok(buffer, ",");
 
            while (value) {
               
                if (column == 0) {
                    printf("Nome :");
                }
 
                
                if (column == 1) {
                    printf("\tquantidade :");
                }
 
                printf("%s", value);
                value = strtok(NULL, ",");
                column++;
            }
 
            printf("\n");
        }
 
        fclose(livros_csv);
    }
}

void cadastrar_cliente()
{
    Tcliente cliente;
    FILE *clientes_csv;
    clientes_csv = fopen("clientes.csv", "a");
    if (clientes_csv)
    {
        puts("informe o seu primeiro nome: ");
        scanf("%s", cliente.Nome);
        puts("informe o seu celular: ");
        scanf("%s", cliente.Telefone);
        fprintf(clientes_csv, "%s,%s\n", cliente.Nome, cliente.Telefone);
        fclose(clientes_csv);
        voltar_menu();
    }
    else
    {
        perror("arquivo nao encontrado");
        return -1;
    }
}

void listar_clientes()
{
    
    FILE *clientes_csv  = fopen("clientes.csv", "r");
 
    if (!clientes_csv)
    {
        printf("Arquivo nao encontrado\n");
    }
    else {
        
        char buffer[1024];
 
        int row = 0;
        int column = 0;
 
        while (fgets(buffer,
                     1024, clientes_csv)) {
            column = 0;
            row++;
 
           
            if (row == 1)
                continue;
 
            
            char *value = strtok(buffer, ",");
 
            while (value) {
               
                if (column == 0) {
                    printf("Nome :");
                }
 
        
                if (column == 1) {
                    printf("\ttelefone :");
                }
 
                printf("%s", value);
                value = strtok(NULL, ",");
                column++;
            }
 
            printf("\n");
        }
 
        fclose(clientes_csv);
    }
}

void livro_vendido()
{
    Tlivros livros;
    FILE *livros_csv;
    livros_csv = fopen("vender_livros.csv", "a");
    if (livros_csv)
    {
        puts("informe o nome do livro: ");
        scanf("%s", livros.nome);
        puts("informe a quantidade de livros: ");
        scanf("%s", livros.quantidade);
        fprintf(livros_csv, "%s,%s\n", livros.nome, livros.quantidade);
        fclose(livros_csv);
        voltar_menu();
    }
    else
    {
        perror("arquivo nao encontrado");
        return -1;
    }
}

void listar_livroVendido()
{
    
    FILE *livros_csv  = fopen("vender_livros.csv", "r");
 
    if (!livros_csv)
    {
        printf("Arquivo nao encontrado\n");
    }
    else {
        
        char buffer[1024];
 
        int row = 0;
        int column = 0;
 
        while (fgets(buffer,
                     1024, livros_csv)) {
            column = 0;
            row++;
 
           
            if (row == 1)
                continue;
 
            
            char *value = strtok(buffer, ",");
 
            while (value) {
               
                if (column == 0) {
                    printf("Nome do livro: ");
                }
 
        
                if (column == 1) {
                    printf("\tquantidade vendida: ");
                }
 
                printf("%s", value);
                value = strtok(NULL, ",");
                column++;
            }
 
            printf("\n");
        }
 
        fclose(livros_csv);
    }
}

void desenvolvimento(){
    printf("Essa opcao esta em desenvolvimento\n");
}

void cadastrar_funcionario()
{
    Tfuncionario funcionario;
    FILE *funcionario_csv;
    funcionario_csv = fopen("funcionarios.csv", "a");
    if (funcionario_csv)
    {
        puts("informe o nome: ");
        scanf("%s", funcionario.nome);
        puts("informe o cpf: ");
        scanf("%s", funcionario.cpf);
        fprintf(funcionario_csv, "%s,%s\n", funcionario.nome, funcionario.cpf);
        fclose(funcionario_csv);
        voltar_menu();
    }
    else
    {
        perror("arquivo nao encontrado");
        return -1;
    }
}

void listar_funcionario()
{
    
    FILE *funcionario_csv  = fopen("funcionarios.csv", "r");
 
    if (!funcionario_csv)
    {
        printf("Arquivo nao encontrado\n");
    }
    else {
        
        char buffer[1024];
 
        int row = 0;
        int column = 0;
 
        while (fgets(buffer,
                     1024, funcionario_csv)) {
            column = 0;
            row++;
 
           
            if (row == 1)
                continue;
 
            
            char *value = strtok(buffer, ",");
 
            while (value) {
               
                if (column == 0) {
                    printf("Nome do funcionario: ");
                }
 
        
                if (column == 1) {
                    printf("\tcpf do funcionario: ");
                }
 
                printf("%s", value);
                value = strtok(NULL, ",");
                column++;
            }
 
            printf("\n");
        }
 
        fclose(funcionario_csv);
    }
}
