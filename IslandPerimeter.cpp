#include <iostream>
#include <vector>

using namespace std;

int countPerimeter(vector<vector<int>>& grid, int i, int j) {
	int count = 0;
	if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || grid[i][j] == 2) {
		return count;
	}
	if (i - 1 < 0 || grid[i - 1][j] == 0) {
		count++;
	}
	if (i + 1 == grid.size() || grid[i + 1][j] == 0) {
		count++;
	}
	if (j - 1 < 0 || grid[i][j - 1] == 0) {
		count++;
	}
	if (j + 1 == grid[0].size() || grid[i][j + 1] == 0) {
	count++;
	}
	grid[i][j] = 2;
	return count + countPerimeter(grid, i + 1, j) + countPerimeter(grid, i - 1, j) +
		countPerimeter(grid, i, j + 1) + countPerimeter(grid, i, j - 1);
}

int islandPerimeter(vector<vector<int>>& grid) {
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 1) {
				return countPerimeter(grid, i, j);
			}
		}
	}
	return 0;
}

//int main() {
//	vector<vector<int>> grid{ {0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{1, 1, 0, 0} };
//	cout << islandPerimeter(grid);
//}