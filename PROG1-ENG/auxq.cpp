int busca(int vet[], int i, int f, int v)
{
    int k;
    if (i > f)
        return -1;
    else
    {
        k = (i + f) / 2;
        if (vet[k] == v)
            return k;
        else if (v < vet[k])
            return busca(vet, i, k - 1, v);
        else
            return busca(vet, k + 1, f, v);
    }
}
