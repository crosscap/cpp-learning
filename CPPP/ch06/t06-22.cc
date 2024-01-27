void swap_pointer(int **pp1, int **pp2)
{
    int *tmp;
    tmp = *pp1;
    *pp1 = *pp2;
    *pp2 = tmp;
}