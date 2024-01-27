#include <iostream>

int main()
{
    int currval = 0, val = 0;

    if (std::cin >> currval)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if (currval == val)
                ++cnt;
            else
            {
                std::cout << currval << " occures "
                          << cnt << " times" << std::endl;
                currval = val;
                cnt = 1;
            }
        }
        std::cout << currval << " occures "
                  << cnt << " times" << std::endl;
    }
    return 0;
}
