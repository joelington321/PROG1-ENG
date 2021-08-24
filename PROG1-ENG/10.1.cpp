
#include <iostream>
#include <iomanip>

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
        while (v[i].pontuacao > pivo)
            i++;
        while (v[j].pontuacao < pivo)
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

Time *aux; // Variável global

void intercala(Time v[], int esq, int meio, int dir)
{
    int i, j;
    i = meio + 1;
    while (i > esq)
    {
        aux[i - 1] = v[i - 1];
        i--;
    }
    j = meio;
    while (j < dir)
    {
        aux[dir + meio - j] = v[j + 1];
        j++;
    }
    for (int k = esq; k <= dir; k++)
    {
        if (aux[j].pontuacao > aux[i].pontuacao)
        {
            v[k] = aux[j];
            j--;
        }
        else
        {
            v[k] = aux[i];
            i++;
        }
    }
}

void mergesort(Time v[], int esq, int dir)
{
    if (esq < dir)
    {
        int meio = (esq + dir) / 2;
        mergesort(v, esq, meio);
        mergesort(v, meio + 1, dir);
        intercala(v, esq, meio, dir);
    }
}

void mergeSort(Time v[], int n)
{
    aux = new Time[n];
    mergesort(v, 0, n - 1);
    delete[] aux;
}

int main()
{
    int select;
    int n;

    cin >> select;
    cin >> n;

    Time vet[n];

    for (int i = 0; i < n; i++)
    {
        cin >> vet[i].nome;
        cin >> vet[i].pontuacao;
    }

    if (select == 1)
    {
        quickSort(vet, n);
    }
    else if (select == 2)
    {
        mergeSort(vet, n);
    }

    for (int i = 0; i < n; i++)
    {
        cout << vet[i].nome;
        cout << "\t" << setw(1) << vet[i].pontuacao << endl;
    }

    return 0;
}
