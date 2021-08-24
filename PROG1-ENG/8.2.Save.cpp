
#include <iostream>

using namespace std;

struct Time
{
    string nome;
    int pontuacao;
};

void particiona(Time v[], int esq, int dir)
{
    int i = esq;
    int j = dir;
    int pivo = v[((i + j) / 2)].pontuacao;
    do
    {
        while (v[i].pontuacao < pivo)
            i++;
        while (v[j].pontuacao > pivo)
            j--;
        if (i <= j)
        {
            Time aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);

    if (esq < j)
        particiona(v, esq, j);
    if (i < dir)
        particiona(v, i, dir);
}

void quickSort(Time v[], int n)
{
    particiona(v, 0, n - 1);
}

int main()
{
    int n;
    cout << "Quicksort" << endl;
    cin >> n;
    Time vet[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i].nome;
        cin >> vet[i].pontuacao;
    }

    quickSort(vet, n);
    cout << "\n\n";
    for (int i = 0; i < n; i++)
    {
        cout << vet[i].nome;
        cout << " " << vet[i].pontuacao << endl;
    }

    return 0;
}
