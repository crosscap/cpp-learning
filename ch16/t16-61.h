template <typename T, template... Args>
T *make_shared(Args &&...args)
{
	return new T(std::forward<Args>(args)...);
}