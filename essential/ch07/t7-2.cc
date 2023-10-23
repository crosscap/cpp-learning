#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int *allocate_array(int);
void sort_array(int *, int);
void register_data(int *);

class noMem{};

int *alloc_and_init(string file_name)
{
    int *pi = nullptr;
    try {
        ifstream infile(file_name); // 可能打开文件失败
        int elem_cnt;
        infile >> elem_cnt;
        pi = allocate_array(elem_cnt); // 可能申请int数组失败

        int elem;
        int index = 0;
        while (infile >> elem)
            pi[index++] = elem;

        sort_array(pi, elem_cnt);
        register_data(pi);
    }
    catch (int) {
        cerr << "sort array wrong!" << endl;
    }
    catch (string) {
        cerr << "register data wrong!" << endl;
    }
    catch (const noMem &memFail) {
        cerr << "allocate array wrong!" << endl;
    }

    return pi;
}