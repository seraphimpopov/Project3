#include <iostream>
#include <vector>

using namespace std;

vector<int> findIndexes(vector <int> arr, int targ)
{
	int left = 0;
	int right = arr.size() - 1;
	while (left < right) // we take the left and right ends of the vector,
						// look for their sum, if the sum is equal to the required transmitted parameter
	{
		int sum = arr[left] + arr[right];
		if (sum == targ)
			return { left, right }; // if the sum is less, then move the left end to the right and vice versa,
									// if the sum is greater, then move the right end to the left
		else 
			if (sum < targ)
				left++;
			else right--;
	}

	return {}; // we return an empty vector if we did not find the amount equal to the parameter passed
}

int main()
{
	// Tests
	vector<int> arr = { 1, 2, 3, 4, 5, 6 };
	int targ = 8;
	// Result: 1, 5
	vector<int> idx = findIndexes(arr, targ);
	if (idx.empty()) cout << "No indexes" << endl;
	else cout << idx[0] << ", " << idx[1] << endl;


	arr = { 1, 2, 3, 4, 5, 6 };
	targ = 10;
	// Result: 3, 5
	idx = findIndexes(arr, targ);
	if (idx.empty()) cout << "No indexes" << endl;
	else cout << idx[0] << ", " << idx[1] << endl;


	arr = { 1, 2, 3, 4, 5, 6 };
	targ = 12;
	// Result: No indexes
	idx = findIndexes(arr, targ);
	if (idx.empty()) cout << "No indexes" << endl;
	else cout << idx[0] << ", " << idx[1] << endl;


	arr = { 1, 2, 3, 4, 5, 6 };
	targ = 0;
	// Result: No indexes
	idx = findIndexes(arr, targ);
	if (idx.empty()) cout << "No indexes" << endl;
	else cout << idx[0] << ", " << idx[1] << endl;


	arr = { 1, 3, 5, 7, 9, 11 };
	targ = 9;
	// Result: No indexes
	idx = findIndexes(arr, targ);
	if (idx.empty()) cout << "No indexes" << endl;
	else cout << idx[0] << ", " << idx[1] << endl;


	arr = { 0, 100, 105, 200, 205, 10000, 100000 };
	targ = 100205;
	// Result: 4, 6
	idx = findIndexes(arr, targ);
	if (idx.empty()) cout << "No indexes" << endl;
	else cout << idx[0] << ", " << idx[1] << endl;

	arr = { 0, 1 };
	targ = 1;
	// Result: 0, 1
	idx = findIndexes(arr, targ);
	if (idx.empty()) cout << "No indexes" << endl;
	else cout << idx[0] << ", " << idx[1] << endl;

	return 0;
}