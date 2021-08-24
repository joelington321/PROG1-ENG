#include <iostream>

using namespace std;

class Elevador
{
public:
    Elevador(int, int);
    void set_andarAtual(int andar);
    void set_totalAndares(int);
    void set_capacidade(int);
    void set_lotacao(int);
    int get_andarAtual() { return andarAtual; }
    int get_totalAndares() { return totalAndares; }
    int get_capacidade() { return capacidade; }
    int get_lotacao() { return lotacao; }
    void entra();
    void sai();
    void sobe();
    void desce();
    void exibe();

private:
    int andarAtual;
    int totalAndares;
    int capacidade;
    int lotacao;
};

Elevador::Elevador(int nCapacidade, int nAndares)
{
    set_andarAtual(0);
    set_capacidade(nCapacidade);
    set_totalAndares(nAndares);
    set_lotacao(0);
}

void Elevador::set_andarAtual(int andar)
{
    andarAtual = andar;
}
void Elevador::set_totalAndares(int andares)
{
    totalAndares = andares;
}
void Elevador::set_capacidade(int nCapacidade)
{
    capacidade = nCapacidade;
}
void Elevador::set_lotacao(int nlotacao)
{
    lotacao = nlotacao;
}

void Elevador::entra()
{
    if (get_lotacao() >= get_capacidade())
    {
        cout << "\nlotado!";
        return;
    }
    else
    {
        set_lotacao(get_lotacao() + 1);
    }
}

void Elevador::sai()
{
    if (get_lotacao() <= 0)
    {
        cout << "\n Vazio!";
    }
    else
    {
        set_lotacao(get_lotacao() - 1);
    }
}

void Elevador::sobe()
{
    if (get_andarAtual() >= get_totalAndares())
    {
        cout << "\n Ultimo andar!";
        return;
    }
    else
    {
        set_andarAtual(get_andarAtual() + 1);
    }
}

void Elevador::desce()
{
    if (get_andarAtual() <= 0)
    {
        cout << "\n Terreo!";
    }
    else
    {
        set_andarAtual(get_andarAtual() - 1);
    }
}
void Elevador::exibe()
{
    cout << "\n[" << get_totalAndares() << " andares, " << get_capacidade() << " pessoas] andar " << get_andarAtual() << " com " << get_lotacao() << " pessoas";
}

int main()
{
    int menu = 1;
    int nAndares, nCapacidade;
    cout << "\n SIMULACAO DO ELEVADOR";
    cout << "\n----------------------------------------------------------------";
    cout << "\n Numero de andares: ";
    cin >> nAndares;
    cout << "\n Capacidade do elevador: ";
    cin >> nCapacidade;
    cout << "\n----------------------------------------------------------------";
    Elevador e1(nCapacidade, nAndares);
    e1.exibe();
    while (menu != 5)
    {
        cout << "\nEscolha uma opção: 1.entra 2.sai 3.sobe 4.desce 5.termina  => ";
        cin >> menu;
        if (menu == 1)
        {
            e1.entra();
        }
        else if (menu == 2)
        {
            e1.sai();
        }
        else if (menu == 3)
        {
            e1.sobe();
        }
        else if (menu == 4)
        {
            e1.desce();
        }
        else if (menu == 5)
        {
            return 0;
        }
        else
        {
            cout << "\nCodigo errado";
        }
        cout << "\n----------------------------------------------------------------";
        e1.exibe();
    }

    return 0;
}