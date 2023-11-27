int main()
{
	int count = 999;
	auto f = [&count]() -> bool {if (count) --count; else return false; return true; };
}
