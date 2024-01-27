int fact(int val)
{
    int answer = 1;
    for (int ix = 1; ix <= val; ++ix)
        answer *= ix;

    return answer;
}