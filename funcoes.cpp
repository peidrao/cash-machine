#include "funcoes.hpp"
using namespace std;

float Cliente::deposito(float x)
{
  return saldo_ += x;
}

float Cliente::retirar(float y)
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

float Cliente::get_saldo() const
{
  return saldo_;
}

void Cliente::mensagem() const
{
  cout << conta_ << setw(6) << "|" << nome_ << setw(6) << "| R$" << saldo_ << endl;
}

void Cliente::mostrar_conta() const
{
  cout << "Nome do Proprietário: " << setw(5) << this->nome_ << endl;
  cout << "Conta: " << setw(10) << this->get_conta() << endl;
  cout << "Saldo: " << setw(10) << this->get_saldo() << endl;
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

void listarClientes()
{
  ifstream arquivo;
  Cliente cliente_;

  arquivo.open("contas.dat", ios::binary);
  if (!arquivo)
    cout << "Não foi possível abrir o arquivo!" << endl;
  while (arquivo.read(reinterpret_cast<char *>(&cliente_), sizeof(Cliente)))
  {
    cliente_.mensagem();
  }
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
  if (opcao == 's' || 'S')
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
  bool validacao = false;

  arquivo.open("contas.dat", ios::in | ios::out | ios::binary);
  if (!arquivo)
  {
    cout << "Não foi possível abrir o arquivo!" << endl;
  }

  while (!arquivo.eof() && validacao == false)
  {
    arquivo.read(reinterpret_cast<char *>(&cliente_), sizeof(Cliente));
    if (conta == cliente_.get_conta())
    {
      cout << "Digite sua senha: ";
      cin >> senha;
      if (cliente_.get_senha() == senha)
      {
        menu_cliente();
      }
    }
  }
  arquivo.close();
}

/**
 * OPERAÇÕES QUE O USUÁRIO VAI REALIZAR:
 * DEPÓSITO      -> depositar(int, float);
 * SAQUE         -> sacar(int, float);
 * SALDO         -> saldo_atual(int); 
 * TRANSFERÊNCIA -> transferir(int, int)
*/

void depositar(int conta, float valorDepositado)
{
  bool validacao = false;
  Cliente cliente_;
  fstream arquivo;
  arquivo.open("contas.dat", ios::binary | ios::in | ios::out);
  if (!arquivo)
  {
    cout << "Arquivo não foi aberto" << endl;
  }

  while (!arquivo.eof() && validacao == false)
  {
    arquivo.read(reinterpret_cast<char *>(&cliente_), sizeof(Cliente));
    cout << cliente_.get_conta() << endl;

    if (cliente_.get_conta() == conta)
    {
      cout << "teste4" << endl;
      cliente_.mostrar_conta();
      cliente_.deposito(valorDepositado);

      int pos = (-1) * static_cast<float>(sizeof(cliente_));
      arquivo.seekg(pos, ios::cur);
      arquivo.write(reinterpret_cast<char *>(&cliente_), sizeof(Cliente));
      cout << "Depósito realizado com sucesso! " << endl;

      validacao = true;
    }
    arquivo.close();
  }
}

void menu_cliente()
{
  Cliente cliente_;
  char opcao;
  int contaOrigem, contaDestino;
  float valorDepositado, valorRetirado;

  do
  {
    cout << endl
         << "|----------------------|" << endl
         << "|-- MENU DO CLIENTE -- |" << endl
         << "|[ 1 ] - Depositar ....|" << endl
         << "|[ 2 ] - Sacar ........|" << endl
         << "|[ 3 ] - Transferir ...|" << endl
         << "|[ 4 ] - Ver extrato ..|" << endl
         << "|[ 5 ] - Listar clie ..|" << endl
         << "|[ 0 ] - Sair .........|" << endl
         << "|----------------------|" << endl
         << "|> ";

    cin >> opcao;
    switch (opcao)
    {
    case '1':
      cout << "Depositar na conta: ";
      cin >> contaDestino;
      cout << "Valor: R$ ";
      cin >> valorDepositado;
      depositar(contaDestino, valorDepositado);
      break;
    case '2':
      cout << "sacar!" << endl;
      break;
    case '3':
      cout << "transferir!" << endl;
      break;
    case '4':
      cout << "extrato!" << endl;
      break;
    case '5':
      listarClientes();
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

    if (opcao == 'n' || opcao == 'N')
    {
      salvar_conta();
    }
     else if (opcao == 's' || opcao == 'S')
    {
      cout << "Digite sua conta: ";
      cin >> conta;
      acessar_conta(conta);
    }
  
    else
    {
      cout << "Digite uma opção válida!" << endl;
    }
  } while (opcao != 's' || 'S' || 'n' || 'N');

  return opcao;
}
