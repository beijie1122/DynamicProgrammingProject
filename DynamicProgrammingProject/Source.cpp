#include <iostream>

int Fib(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	return Fib(n - 1) + Fib(n - 2);
}

int FibDP(int N, int* arr)
{
	if (N == 0 || N == 1)
	{
		return N;
	}

	if (arr[N] != 0)
	{
		return arr[N];
	}

	int Output = FibDP(N - 1, arr) + FibDP(N - 2, arr);
	arr[N] = Output; //Store for future use
	return Output;

}

int FibDP2(int N)
{
	int* arr = new int(N + 1);
	arr[0] = 0;
	arr[1] = 1;

	for (size_t i = 2; i < N; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	int StoredAnswer = arr[N];

	delete []arr;

	return StoredAnswer;
}


int main()
{

	std::cout << "Hello world!\n";

	int n;

	std::cin >> n;

	int* arr = new int(n + 1);
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
	
	
	std::cout << FibDP(n, arr);
	std::cout << Fib(n);
	//std::cout << FibDP2(n);

	return 0;
}