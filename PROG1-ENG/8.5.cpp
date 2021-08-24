bool buscaR(int v[], int n, int procurado, int esq, int dir)
{
    int meio = (esq + dir) / 2;
    if (esq <= dir)
    {
        if (v[meio] == procurado)
            return true;
        else if (v[meio] > procurado)
            return buscaR(v, n, procurado, esq, meio - 1);
        else if (v[meio] < procurado)
            return buscaR(v, n, procurado, meio + 1, dir);
    }
    return false;
}