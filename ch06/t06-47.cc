#include <iostream>
#include <vector>

// #define NDEBUG

using std::vector;
void show_vector_re(const vector<int> &vi, int length);

int main()
{
    vector<int> vi{2, 3, 5, 6, 7};
    show_vector_re(vi, vi.size() - 1);

    return 0;
}

void show_vector_re(const vector<int> &vi, int length)
{
    if (length > 0) {
        show_vector_re(vi, length - 1);
    }
    std::cout << vi[length] << ' ';
    # ifndef NDEBUG
        std::cout << vi.size() << std::endl;
    # endif
    return;
}