#include "Triangular07.h"

extern void log_message(const char *);
bool has_elem(Triangular_iterator first, Triangular_iterator last, int elem)
{
    bool status = true;

    try {
        while (first != last) {
            if (*first == elem)
                return status;
            ++first;
        }
    }
    catch (iterator_overflow &iof){
        iof.what_happened();
        log_message("check if iterators address same container");
    }

    status = false;
    return false;
}