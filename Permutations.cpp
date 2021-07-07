#include <iostream>
#include <vector>

using namespace std;

void permute(vector<int>& nums, int start, vector<vector<int>>& perms) {
	if (start == nums.size())
	{
		perms.push_back(nums);
		return;
	}
	for (int i = start; i < nums.size(); i++)
	{
		swap(nums[start], nums[i]);
		permute(nums, start + 1, perms);
		swap(nums[start], nums[i]);
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> perms;
	permute(nums, 0, perms);
	return perms;

}

//int main() {
//	vector<int> numbers{ 1,2,3 };
//	vector<vector<int>> perms = permute(numbers);
//	for (int i = 0; i < perms.size(); i++) {
//		for (int j = 0; j < perms[i].size(); j++) {
//			cout << perms[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}