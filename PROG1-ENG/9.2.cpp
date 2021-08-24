#include <iostream>
using namespace std;

void ordena_insercao(int A[], int n)
{
    int aux, j;
    for (int i = 1; i < n; i++)
    {
        aux = A[i];
        j = i - 1;
        while (j >= 0 && A[j] < aux)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = aux;
    }
}

int main()
{
    int n;
    cin >> n;
    int vet[n];
    for (int i = 0; i < n; i++)
        cin >> vet[i];
    ordena_insercao(vet, n);

    for (int i = 0; i < n; i++)
    {
        cout << vet[i];
        if (i != n - 1)
            cout << " ";
    }
}