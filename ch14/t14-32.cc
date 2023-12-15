#include "StrBlob.h"

class PrtToPrt{
public:
	StrBlobPtr &operator->() const;
private:
	StrBlobPtr *pointerd;
};

inline StrBlobPtr &PrtToPrt::operator->() const
{
	return *pointerd;
}