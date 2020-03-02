#include "funcoes.hpp"

using namespace std;

void Conta::criarConta()
{
    char opcaoConta;
    cin.ignore();
    cout << "Digite seu nome: ";
    cin >> nome;
    cout << "Digite sua senha (numérica): ";
    cin >> senha;
    conta = senha + (rand() % 10000);
    cout << conta << endl;

    cout << "Deseja fazer algum depósito?(S/N)" << endl;
    cin >> opcaoConta;
    if (opcaoConta == 's' || opcaoConta == 'S')
    {
        cout << "Digite o valor do depósito: ";
        cin >> saldo;

    }
    cout << "Conta criada com Sucesso!" << endl;
}

void Conta::mostrarConta() const
{
    cout << "\n\nNúmero da conta: " << conta << endl;
    cout << "Nome do proprietário: " << nome << "\n";
}

double Conta::deposito(double x)
{
    return saldo += x;
}

double Conta::retirar(double x)
{
    return saldo -= x;
}

int Conta::getConta()
{
    return conta;
}

int Conta::getSenha() const
{
    return senha;
}

void Conta::report() const
{
    cout << conta << setw(10) << " " << nome << setw(10) << " " << saldo << endl;
}

double Conta::getSaldo() const
{
    return saldo;
}

void salvarConta()
{
    Conta conta_;
    ofstream arquivo;
    arquivo.open("contas.dat", ios::binary | ios::app);
    conta_.criarConta();
    arquivo.write(reinterpret_cast<char *>(&conta_), sizeof(Conta));
    arquivo.close();
}
/* 
// Função para listar todas as contas no sistema
void todasContas()
{
    Conta conta_;
    ifstream arquivo;
    arquivo.open("contas.dat", ios::binary);

    if (!arquivo)
    {
        cout << "Arquivo não está abrindo!" << endl;
        return;
    }
    cout << "TODAS AS CONTAS"
         << "\n\n";
    while (arquivo.read(reinterpret_cast<char *>(&conta_), sizeof(Conta)))
    {
        conta_.report();
    }
    arquivo.close();
} */


void consultaSaldo(int conta){
 bool teste = false;

    Conta conta_;
    fstream Arquivo;
    Arquivo.open("contas.dat", ios::binary | ios::in | ios::out);
    if (!Arquivo)
    {
        cout << "Arquivo corrompido!" << endl;
    }
    while (!Arquivo.eof() && teste == false)
    {
        Arquivo.read(reinterpret_cast<char *>(&conta_), sizeof(Conta));
        if (conta_.getConta() == conta)
        {
            conta_.mostrarConta();
            cout << "O saldo é de: " << conta_.getSaldo();
            cout << "\n\n";
            
            int pos = (-1) * static_cast<double>(sizeof(conta_));
            Arquivo.seekg(pos, ios::cur);
            Arquivo.write(reinterpret_cast<char *>(&conta_), sizeof(Conta));
           
            teste = true;
        }
    }
    Arquivo.close();
    if (teste == false)
    {
        cout << "Falha!" << endl;
    }
}

void fazerDeposito(int conta, double valorDeposito)
{
    
    bool teste = false;

    Conta conta_;
    fstream Arquivo;
    Arquivo.open("contas.dat", ios::binary | ios::in | ios::out);
    if (!Arquivo)
    {
        cout << "Arquivo corrompido!" << endl;
    }
    while (!Arquivo.eof() && teste == false)
    {
        Arquivo.read(reinterpret_cast<char *>(&conta_), sizeof(Conta));
        if (conta_.getConta() == conta)
        {
            conta_.mostrarConta();
  
            conta_.deposito(valorDeposito);
            
            int pos = (-1) * static_cast<double>(sizeof(conta_));
            Arquivo.seekg(pos, ios::cur);
            Arquivo.write(reinterpret_cast<char *>(&conta_), sizeof(Conta));
            cout << "Transferência feita com sucesso." << endl;
            teste = true;
        }
    }
    Arquivo.close();
    if (teste == false)
    {
        cout << "Tranferẽncia falhou!" << endl;
    }
}

void fazerSaque(int conta, double valorRetirado)
{
    bool teste = false;
    Conta conta_;
    fstream Arquivo;
    Arquivo.open("contas.dat", ios::binary | ios::in | ios::out);
    if (!Arquivo)
    {
        cout << "Arquivo corrompido!" << endl;
    }

    while (!Arquivo.eof() && teste == false)
    {
        Arquivo.read(reinterpret_cast<char *>(&conta_), sizeof(Conta));
        if (conta_.getConta() == conta)
        {
            conta_.mostrarConta();
            conta_.retirar(valorRetirado);
            int pos = (-1) * static_cast<double>(sizeof(conta_));
            Arquivo.seekg(pos, ios::cur);
            Arquivo.write(reinterpret_cast<char *>(&conta_), sizeof(Conta));
            cout << "sqeu feita com sucess" << endl;
            teste = true;
        }
    }
    Arquivo.close();
    if (teste == false)
    {
        cout << "transferência falhou!" << endl;
    }
}

void transferencia(int contaOriginal, int contaTransferencia)
{
    double valorTransferido;

    cout << "Quanto deseja transferir para essa conta? ";
    cin >> valorTransferido;
    
    fazerDeposito(contaTransferencia, valorTransferido);
    fazerSaque(contaOriginal, valorTransferido);
}

void menuCliente()
{
    char opcao;
    int num, conta; 
    double valorDeposito, valorRetirado;

    do
    {

        cout << endl
             << "|----------------------|" << endl
             << "|-- MENU DO CLIENTE -- |" << endl
             << "|----------------------|" << endl
             << "|1) DEPÓSITO...........|" << endl
             << "|2) SAQUE..............|" << endl
             << "|3) SALDO..............|" << endl
             << "|4) TRANSFERÊNCIA......|" << endl
             << "|5) SAIR DA CONTA......|" << endl
             << "|----------------------|" << endl
             << "| Selecione uma das opções: ";

        cin >> opcao;
        switch (opcao)
        {
        case '1':
            cout << "Qual conta será destinada o depóstio? ";
            cin >> num;
            cout << "Quantia que será depositada: ";
            cin >> valorDeposito;
            fazerDeposito(num, valorDeposito);
            break;
        case '2':
            cout << "Digite o número da conta: ";
            cin >> num;
            cout << "Quanto deseja retirar da conta: " << endl;
            cin >> valorRetirado;
            fazerSaque(num, valorRetirado);
            break;

        case '3':
            cout << "Qual o número da conta?" << endl;
            cin >> conta;
            consultaSaldo(conta);
            break;

        case '4':
            int num1, num2;
            cout << "Digite sua conta por favor: ";
            cin >> num; 
            cout << "Para qual conta deseja transferir? ";
            cin >> num2;
            transferencia(num, num2);
            break;

        default:
        cout << "Opção inválida, digite outra!" << endl;
            break;
        }
    } while (opcao != '5');
    opcaoMenu();
}

void acessarConta(int conta)
{
    bool teste2 = false;
    int senha;
    Conta conta_;
    fstream Arquivo;
    Arquivo.open("contas.dat", ios::binary | ios::in | ios::out);
    if (!Arquivo)
    {
        cout << "Arquivo corrompido!" << endl;
    }

    while (!Arquivo.eof() && teste2 == false)
    {
        Arquivo.read(reinterpret_cast<char *>(&conta_), sizeof(Conta));
        if (conta_.getConta() == conta)
        {
            cout << "Digite sua senha: ";
            cin >> senha;
            if (conta_.getSenha() == senha)
            {
                menuCliente();
            }
        }
    }
    Arquivo.close();
}

char opcaoMenu()
{
    system("clear");
    cout << "Você já tem conta?" << endl
         << "(S) Sim || (N) Não" << endl;
    char opc;
    do
    {
        cin >> opc;
        if (opc == 's' || opc == 'S')
        {
            int conta;
            cout << "Conta: ";
            cin >> conta;
            acessarConta(conta);
        }
        else if (opc == 'n' || opc == 'N')
        {
            salvarConta();
            int conta2;
            cout << "Conta: ";
            cin >> conta2;
            acessarConta(conta2);
        }
        else
        {
            cout << "Opção inválida! Divite novamente!" << endl
                 << "Escolha uma opção >>>  ";
        }
    } while (opc != 's' || 'n');

    return opc;
}
