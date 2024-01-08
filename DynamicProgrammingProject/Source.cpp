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

int MinStepsBottomUp(int n)
{
	int* DP = new int[n + 1];
	DP[0] = 0;
	DP[1] = 0;

	//DP[i] = min steps needed to move from i->1, ans = dp[n]

	for (size_t i = 2; i <= n; i++)
	{
		int x = DP[i - 1];
		int y = INT_MAX;
		int z = INT_MAX;

		if (i % 2 == 0)
		{
			y = DP[i/2];
		}

		if (i % 3 == 0)
		{
			z = DP[i/3];
		}
		DP[i] = std::fmin(x, std::fmin(y, z)) + 1;
	}

	int Answer = DP[n];

	delete[] DP;

	return Answer;
}

int ClimbingStairsRecursive(int n)
{
	//Base Case
	if (n <= 1)
	{
		return 1;
	}

	return ClimbingStairsRecursive(n-1) + ClimbingStairsRecursive(n - 2);

}

int ClimbStairsDP(int n)
{
	int* DP = new int[n + 1];

	//Base Case for 0 and 1 steps 

	DP[0] = 1;
	DP[1] = 1;


	for (int i = 2; i <= n; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	return DP[n];

}

int ClimbStairsGeneral(int n)
{
	int* DP = new int[n + 1];
	DP[0] = 1;
	int k = 2;

	for (int i = 1; i <= n; i++)
	{
		int Answer = 0;
		for (int Jump = 1; Jump <= k; Jump++)
		{
			if (i - Jump >= 0)
			{
				Answer += DP[i - Jump];
			}
			
		}
		DP[i] = Answer;
	}
	return DP[n];
}

int LongestCommonSubsequence(std::string ST1, int i, std::string ST2, int j)
{
	if (i == ST1.size() || j == ST2.size())
	{
		return 0;
	}

	if (ST1.at(i) == ST2.at(j))
	{
		return 1 + LongestCommonSubsequence(ST1, i + 1, ST2, j + 1);
	}

	if (ST1.at(i) != ST2.at(j))
	{
		
		return std::fmax(LongestCommonSubsequence(ST1, i, ST2, j + 1), LongestCommonSubsequence(ST1, i + 1, ST2, j));
	}

}

int LongestCommonSubsequenceDP(std::string S1, int m, std::string S2, int n)
{
	m = S1.size();
	n = S2.size();
	int DP[6][6];

	for (size_t i = 0; i <= m; i++)
	{
		for (size_t j = 0; j <= n; j++)
		{
			if(i == 0 || j == 0)
			{
				DP[i][j] == 0;
			}
			else if (S1[i - 1] == S2[j - 1])
			{
				DP[i][j] = 1 + DP[i - 1][j - 1];
			}
			else
			{
				DP[i][j] = std::fmax(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	return DP[m][n];


}

int MinDistance(std::string Word1, int m, std::string Word2, int n)
{

	//Base Case: if the word1 is empty 
	if (m == 0)
	{
		return n;
	}

	//Base Case: if word2 is empty
	if (n == 0)
	{
		return m;
	}

	if (Word1[m - 1] == Word2[n - 1])
	{
		return MinDistance(Word1, m - 1, Word2, n - 1);
	}
	int Ins = MinDistance(Word1, m, Word2, n - 1);
	int Del = MinDistance(Word1, m - 1, Word2, n);
	int Replace = MinDistance(Word1, m - 1, Word2, n - 1);

	return 1 + std::fmin(Ins, std::fmin(Del, Replace));

}

int MinDistanceDP(std::string Word1, int m, std::string Word2, int n)
{

	int DP[6][6];

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0)
			{
				DP[i][j] = j;
			}
			else if (j == 0)
			{
				DP[i][j] = i;
			}
			else if (Word1[i - 1] == Word2[j - 1])
			{
				DP[i][j] = DP[i - 1][j - 1];
			}
			else
			{
				int Ins = DP[i][j - 1];
				int Del = DP[i - 1][j];
				int Replace = DP[i - 1][j - 1];
				DP[i][j] = 1 + std::min(Ins, std::min(Del, Replace));
			}
		}
	}

	return DP[m][n];

}

int KnapsackRecursive(int PriceVecSize, int KnapsackWeight, std::vector<int> & PriceVec, std::vector<int> & WeightVec)
{

	//Base Case 
	if (PriceVecSize == 0 || KnapsackWeight == 0)
	{
		return 0;
	}

	if (WeightVec.at(PriceVecSize - 1) > KnapsackWeight)
	{
		return KnapsackRecursive(PriceVecSize - 1, KnapsackWeight, PriceVec, WeightVec);
	}
	else
	{
		int Include = PriceVec.at(PriceVecSize - 1) + KnapsackRecursive(PriceVecSize - 1, KnapsackWeight - WeightVec.at(PriceVecSize - 1), PriceVec, WeightVec);
		int Exclude = KnapsackRecursive(PriceVecSize - 1, KnapsackWeight, PriceVec, WeightVec);

		return std::max(Include, Exclude);

	}
}

int KnapsackDP(int PriceVecSize, int KnapsackWeight, std::vector<int>& PriceVec, std::vector<int>& WeightVec)
{
	if (PriceVecSize == 0 || KnapsackWeight == 0)
	{
		return 0;
	}
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

	//std::cout << MinStepsBrute(n) << "\n";
	//std::cout << MinStepsMemorization(n) << "\n";
	//std::cout << MinStepsBottomUp(n) << "\n";

	std::string String1 = "Apple";
	std::string String2 = "Mango";

	std::cout << LongestCommonSubsequence(String1, 0, String2, 0) << std::endl;

	std::cout << MinDistance(String1, String1.size(), String2, String2.size());

	std::vector<int> ItemPrice = { 55, 23, 34, 65 };
	std::vector<int> ItemWeight = { 2, 3, 5, 3 };

	int NumberOfItems = ItemPrice.size();
	int w = 10;

	std::vector<std::vector<int>> DP(NumberOfItems + 1, std::vector<int>(w + 1, 0));
	for (int i = 0; i <= NumberOfItems; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			if (i == 0 || j == 0)
			{
				DP[i][j] = 0;
			}
			else if (ItemWeight.at(i - 1) > w)
			{
				DP[i][j] = DP[i - 1][j];
			}
			else
			{
				int Ins = ItemPrice.at(i) + DP[i-1][j - ItemWeight.at(i - 1)];
				int Exc = DP[i - 1][j];
				DP[i][j] = std::max(Ins, Exc);
				//std::cout << DP[i][j] << std::endl;
			}
		}
	}

	return 0;
}