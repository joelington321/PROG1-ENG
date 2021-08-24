#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

class Ponto
{
public:
    Ponto();
    Ponto(float, float);
    void set_PontoX(float valorX);
    void set_PontoY(float valorY);
    float get_PontoX() { return x; }
    float get_PontoY() { return y; }
    void imprimir();
    float distancia(Ponto p);

private:
    float x, y;
};

Ponto::Ponto()
{
    x = 0;
    y = 0;
}

Ponto::Ponto(float valorX, float valorY)
{
    set_PontoX(valorX);
    set_PontoY(valorY);
}

void Ponto::set_PontoX(float valorX)
{
    x = valorX;
}

void Ponto::set_PontoY(float valorY)
{
    y = valorY;
}

void Ponto::imprimir()
{
    cout << "(" << get_PontoX() << ", " << get_PontoY() << ")." << endl;
}

float Ponto::distancia(Ponto p)
{
    float aux;
    aux = powf(((powf(((p.get_PontoX()) - (get_PontoX())), (2))) + (powf(((p.get_PontoY()) - (get_PontoY())), (2)))), 0.5);
    return aux;
}

int main()
{
    Ponto p1;
    cout << "Primeiro Ponto = ";
    p1.imprimir();
    Ponto p2(1, 10);
    cout << "Segundo Ponto = ";
    p2.imprimir();
    p1.set_PontoX(7);
    p1.set_PontoY(5);
    cout << "Primeiro Ponto apos alteracao = ";
    p1.imprimir();
    cout << "Distancia entre p1 e p2 = " << p1.distancia(p2);
}