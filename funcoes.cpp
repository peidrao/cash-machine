#include "funcoes.hpp"
using namespace std;

void Cliente::mostrar_conta() const
{
  cout << "Nome do Proprietário: " << setw(5) << nome_ << endl;
  cout << "Conta: " << setw(10) << conta_ << endl;
  cout << "Saldo: " << setw(10) << saldo_ << endl;
}

double Cliente::deposito(double x)
{
  return saldo_ += x;
}

double Cliente::retirar(double y)
{
  return saldo_ -= y;
}

int Cliente::get_conta() const
{
  return conta_;
}

int Cliente::get_senha() const
{
  return senha_;
}

double Cliente::get_saldo() const
{
  return saldo_;
}

void Cliente::mensagem() const
{
  cout << conta_ << setw(6) << "|" << nome_ << setw(6) << "| R$" << saldo_ << endl;
}
void salvar_conta()
{
  Cliente cliente_;
  ofstream arquivo;
  arquivo.open("contas.dat", ios::binary | ios::app);
  cliente_.criar_conta();
  arquivo.write(reinterpret_cast<char *>(&cliente_), sizeof(Cliente));
  arquivo.close();
}

void Cliente::criar_conta()
{
  char opcao;
  cin.ignore();
  cout << "Nome: ";
  cin >> nome_;
  cout << "Senha (Apenas números): ";
  cin >> senha_;
  conta_ = senha_ + (rand() % 1000);
  cout << "Conta: " << conta_ << endl;

  cout << "+=============================+" << endl
       << "| DESEJA FAZER ALGUM DEPÓSITO |" << endl
       << "| | ( S ) SIM ||| ( N ) NÃO | |" << endl
       << "+=============================+" << endl
       << "|DIGITE UMA OPCAO >>>>> ";

  cin >> opcao;
  if (opcao == 's' || opcao == 'S')
  {
    cout << "QUANTO DESEJA DEPOSITAR: R$ ";
    cin >> saldo_;
  }
  else
  {
    cout << "Opção inválida! Digite novamente!" << endl;
  }

  cout << "Conta criada com sucesso!" << endl;
  acessar_conta(conta_);
}

void acessar_conta(int conta)
{

  Cliente cliente_;
  fstream arquivo;
  int senha;
  bool validacao = true;

  arquivo.open("contas.dat", ios::in | ios::out | ios::binary);
  if (!arquivo)
  {
    cout << "Não foi possível abrir o arquivo!" << endl;
  }

  while (!arquivo.eof() && validacao == true)
  {
    arquivo.read(reinterpret_cast<char *>(&cliente_), sizeof(Cliente));
    if (conta == cliente_.get_conta())
    {
      cout << "Digite sua senha: ";
      cin >> senha;
      if (senha == cliente_.get_senha())
      {
        menu_cliente();
      }
    }
  }
  arquivo.close();
}

void menu_cliente()
{
  char opcao;
  int contaOrigem, contaDestino;
  double valorDepositado, valorRetirado;

  do
  {
    cout << endl
         << "|----------------------|" << endl
         << "|-- MENU DO CLIENTE -- |" << endl
         << "|[ 1 ] - Depositar ....|" << endl
         << "|[ 2 ] - Sacar ........|" << endl
         << "|[ 3 ] - Transferir ...|" << endl
         << "|[ 4 ] - Ver extrato ..|" << endl
         << "|[ 0 ] - Sair .........|" << endl
         << "|----------------------|" << endl
         << "|> ";

    cin >> opcao;
    switch (opcao)
    {
    case '1':
      cout << "Depóstio!" << endl;
      break;
    case '0':
      exit(EXIT_SUCCESS);
    default:
      cout << "Opção inválida, digite novamente" << endl;
      break;
    }
  } while (opcao != '0');
}

char opcao_menu()
{
  int conta;
  char opcao;
  system("clear");
  cout << "+==============================+" << endl
       << "| JÁ POSSUI CONTA NESSE BANCO  |" << endl
       << "| | ( S ) SIM ||| ( N ) NÃO |  |" << endl
       << "+=============================+" << endl
       << "|> ";

  do
  {
    cin >> opcao;
    if (opcao == 's' || opcao == 'S')
    {
      cout << "Digite sua conta: ";
      cin >> conta;
      acessar_conta(conta);
    }
    else if (opcao == 'n' || opcao == 'N')
    {
      salvar_conta();
    }
    else
    {
      cout << "Digite uma opção válida!" << endl;
    }
  } while (opcao != 's' || 'S' || 'n' || 'N');

  return opcao;
}
