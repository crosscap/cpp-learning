template <typename T, class... Args>
T *make_shared(Args &&...args)
{
	return new T(std::forward<Args>(args)...);
}