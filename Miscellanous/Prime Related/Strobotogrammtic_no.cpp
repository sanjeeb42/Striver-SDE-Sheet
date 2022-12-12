// C++ program to print all
// Strobogrammatic number of length n
#include <bits/stdc++.h>
using namespace std;

// definition function
vector<string> numdef(int n, int length)
{
	vector<string> result;
	if (n == 0)
		return result;
	if (n == 1) {
		result.push_back("1");
		result.push_back("0");
		result.push_back("8");
		return result;
	}

	vector<string> middles = numdef(n - 2, length);

	for (string middle : middles) {
		if (n != length)
			result.push_back("0" + middle + "0");

		result.push_back("8" + middle + "8");
		result.push_back("1" + middle + "1");
		result.push_back("9" + middle + "6");
		result.push_back("6" + middle + "9");
	}
	return result;
}

// strobogrammatic function
vector<string> strobogrammatic_num(int n)
{
	vector<string> result = numdef(n, n);
	return result;
}

// Driver Code
int main()
{
	// Print all Strobogrammatic
	// number for n = 3
	for (string num : (strobogrammatic_num(3)))
		cout << num << " ";
}

// This code is contributed by phasing17
