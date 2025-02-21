struct Vector
{
    double* elem;
    int sz;
};

void vector_init(Vector& v, int s)
{
    v.elem = new double[s];
    v.sz = s;
}
