#include <iostream>

int Fib(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	return Fib(n - 1) + Fib(n - 2);
}


int main()
{

	std::cout << "Hello world!\n";

	int n;

	std::cin >> n;
	std::cout << Fib(n);

	return 0;
}