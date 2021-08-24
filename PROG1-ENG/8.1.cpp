bool busca_sequencial(int v[], int n, int procurado)
{
    int i = 0;

    while (i < n)
    {
        if (v[i] == procurado)
        {
            return true;
        }
        else
        {
            i++;
        }
    }
    return false;
}
