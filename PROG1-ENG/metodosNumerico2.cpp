#include <iostream>
#include <vector>

using namespace std;

int main()
{
    float h;
    int n;
    float aux = 0;
    float aux1 = 0;
    float result = 0;
    int menu = 0;

    cout << "\nDigite N: ";
    cin >> n;
    cout << "\nDigite H: ";
    cin >> h;
    cout << "\nDigite o modo =\nRegra do trapezio => 1\nPrimeira regra simpson => 2\nSegunda rregra de simpson => 3\n";
    cin >> menu;
    float v[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        cout << "\ndigite F(X[" << i << "]): ";
        cin >> v[i];
    }

    for (int i = 0; i < n + 1; i++)
    {
        cout << "\nX[" << i << "]= " << v[i];
    }

    if (menu == 1)
    {
        cout << "\nTrapezio";
        for (int i = 1; i < n; i++)
        {
            aux = aux + v[i];
            cout << "\nSomou o x[" << i << "]:";
        }
        result = (h / 2) * (v[0] + v[n] + 2 * (aux));
    }
    if (menu == 2)
    {
        cout << "\nPrimeira simpson";
        for (int i = 1; i < n; i++)
        {
            if (i % 2 == 0)
            {
                aux1 = aux1 + v[i];
            }
            else
            {
                aux = aux + v[i];
            }
        }
        result = (h / 3) * (v[0] + v[n] + 4 * (aux) + 2 * (aux1));
    }
    if (menu == 3)
    {
        cout << "\nSegunda simpson";
        for (int i = 1; i < n; i++)
        {
            if (i % 3 == 0)
            {
                aux1 = aux1 + v[i];
                cout << "\ni = " << i << "divisivel por 3";
            }
            else
            {
                aux = aux + v[i];
                cout << "\ni = " << i << "não e Divisivel por 3";
            }
        }
        aux = aux * 3;
        aux1 = aux1 * 2;
        result = h * 3 / 8 * (v[0] + v[n] + aux + aux1);
    }
    cout << "\nRESULTADO: " << result;
    return 0;
}