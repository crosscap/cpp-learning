#include <vector>
#include <string>
#include <functional>
using namespace std;

template<typename elemType, typename Comp = less<elemType> >
class LessThanPred {
public:
    LessThanPred(const elemType &val) : _val(val) {}
    bool operator()(const elemType &val) const {return Comp(val, _val);}
    void val(const elemType &newval) { _val = newval; }
    elemType val() const { return _val; }
private:
    elemType _val;
};

class StringLen {
public:
    bool operator()(const string &s1, const string &s2) const
    { return s1.size() < s2.size(); }
};