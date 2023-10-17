#include <iostream>
#include <string>
using namespace std;

class LibMat
{
public:
    LibMat() { cout << "LibMat::LibMat() default constructor!\n"; }
    virtual ~LibMat() { cout << "LibMat::~LibMat() destructor!\n"; }

    virtual void print() const
    {
        cout << "LibMat::print() -- I am a LibMat object!\n";
    }
    void check_in();
    void check_out();
    void due_date();
    void find();
    void location();
    void assess_fine();
    void notify_avaliable();

    bool is_late();
    bool waiting_list();
};

void loan_check_in(LibMat &mat)
{
    mat.check_in();

    if (mat.is_late())
        mat.assess_fine();

    if (mat.waiting_list())
        mat.notify_avaliable();
}

void print(const LibMat &mat)
{
    cout << "in global print(): about to print mat.print()\n";

    mat.print();
}