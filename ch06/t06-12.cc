#include<cstdio>

void swap(int &i1, int &i2)
{
    int tmp = i1;
    i1 = i2;
    i2 = tmp;
}

int main()
{
    int a = 40, b = 50;

    printf("before swap: a = %d, b = %d\n", a, b);
    swap(a, b);
    printf("after swap: a = %d, b = %d\n", a, b);

    return 0;
}