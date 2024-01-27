// template <typename T>
// class SP
// {
// 	SP(const T &elem, void (*del)(T *))
// 		: p(new T(elem)), i(0), use(new std::size_t(1)), del(nullptr) { }
// 	SP(const SP &orig)
// 		: p(orig.p), i(orig.i), use(orig.use), del(orig.del) { ++*use; }
// 	SP(SP &&p) noexcept
// 		: p(p.p), i(p.i), del(p.del) { p.ps = 0; }
// 	~SP();

// 	SP &operator=(SP);

// private:
// 	T *p;
// 	int i;
// 	std::size_t *use;
// 	void (*del)(T *);
// };

// template <typename T>
// SP<T>::~SP()
// {
// 	if (!--*use) {
// 		if (!del)
// 			delete p;
// 		else
// 			del(p);
// 		delete use;
// 	}
// }
