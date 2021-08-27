// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;

// Returns the total sum of
// occurrences of all vowels
int vowel_calc(string s)
{
	int n = s.length();
	vector<int> arr;

	for (int i = 0; i < n; i++) {

		if (i == 0)
			// No. of occurrences of 0th character
			// in all the substrings
			arr.push_back(n);

		else
			// No. of occurrences of the ith character
			// in all the substrings
			arr.push_back((n - i) + arr[i - 1] - i);
	}

	int sum = 0;
	for (int i = 0; i < n; i++)

		// Check if ith character is a vowel
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
			|| s[i] == 'o' || s[i] == 'u')
			sum += arr[i];

	// Return the total sum
	// of occurrences of vowels
	return sum;
}

// Driver code
int main()
{
	string s = "daceh";
	cout << vowel_calc(s) << endl;

	return 0;
}
