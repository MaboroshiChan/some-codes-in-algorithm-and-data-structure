#include<vector>
#include<iostream>
using namespace std;

vector<int> merge(vector<int>& a, vector<int>& b) {
	int indexA = 0, indexB = 0;
	vector<int> res;
	while (indexA < a.size() && indexB < b.size()) {
		if (a[indexA] < b[indexB]) {
			res.push_back(a[indexA]);
			indexA++;
		}
		else {
			res.push_back(b[indexB]);
			indexB++;
		}
	}
	while (indexA < a.size()) {
		res.push_back(a[indexA]);
		indexA++;
	}
	while (indexB < b.size()) {
		res.push_back(b[indexB]);
		indexB++;
	}
	return res;
}
vector<int> mergeSort(vector<int> nums, int l, int r) {
	if (l == r) return{ nums[l] };
	vector<int> L = mergeSort(nums, l, l + (r - l) / 2);
	vector<int> R = mergeSort(nums, l + (r - l) / 2 + 1, r);
	return merge(L, R);
}
int main()
{
	vector<int> a = {10,5,4,1,3,2,100,11,12,16,15};
	vector<int> b = { 1,3,2,3,1 };
	vector<int> c = mergeSort(a, 0, a.size() - 1);
	for (int i : b) {
		i = log(i)/log(2);
		cout << i << " ";
	}
	system("pause");
}
