#include <vector>
#include <string>
#include <functional>
using namespace std;

template<typename elemType, typename BinaryComp>
class Compare {
public:
    LessThanPred(const elemType &val) : _val(val) {}
    bool operator()(const elemType &val) const {return BinaryComp(val, _val);}
    void val(const elemType &newval) { _val = newval; }
    elemType val() const { return _val; }
private:
    elemType _val;
};