#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>

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

int MinStepsBrute(int n)
{

	//Base Case 
	if (n <= 1)
	{
		return 0;
	}

	//Recursive
	int x = MinStepsBrute(n-1);
	int y = INT_MAX;
	int z = INT_MAX;

	if (n % 2 == 0)
	{
		y = MinStepsBrute(n / 2);
	}
	
	if (n % 3 == 0)
	{
		z = MinStepsBrute(n / 3);
	}
	
	//Final Output 

	int Answer = std::fmin(x, std::fmin(y, z)) + 1;

	return Answer;

}

int Helper(int n, int* Ans)
{
	//Base Case 
	if (n <= 1)
	{
		return 0;
	}

	//Check if Output exists already 
	if (Ans[n] != -1)
	{
		return Ans[n];
	}

	//Recursive
	int x = Helper(n - 1, Ans);
	int y = INT_MAX;
	int z = INT_MAX;

	if (n % 2 == 0)
	{
		y = Helper(n / 2, Ans);
	}

	if (n % 3 == 0)
	{
		z = Helper(n / 3, Ans);
	}

	//Final Output 

	int Output = std::fmin(x, std::fmin(y, z)) + 1;

	//Save Your Answer for Future Use 

	Ans[n] = Output;

	return Output;

}

int MinStepsMemorization(int n)
{
	int* DP = new int[n + 1];
	for (size_t i = 0; i <= n; i++)
	{
		DP[i] = -1;
	}
	return Helper(n, DP);
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


	//std::cout << FibDP(n, arr);
	//std::cout << Fib(n);
	//std::cout << FibDP2(n);

	std::cout << MinStepsBrute(n) << "\n";
	std::cout << MinStepsMemorization(n) << "\n";

	return 0;
}