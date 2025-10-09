#include <iostream>

int main(){

	int n, sum = 0;
	std::cin >> n;

	if (n > 0)
	{
		for (int i = 1; i <= n; i++)
		{
			sum = sum + i;
		}
	}
	else
	{
		for (int i = 1; i >= n; i--)
		{
			sum = sum + i;
		}
	}
	std::cout << sum << std::endl;

}
