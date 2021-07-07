#include <iostream>
#include <vector>

using namespace std;

void fill(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
	if (sr >= 0 && sr < image.size() && sc >= 0 && sc < image[0].size() && image[sr][sc] != newColor && image[sr][sc] == oldColor) {
		image[sr][sc] = newColor;
		fill(image, sr - 1, sc, newColor, oldColor);
		fill(image, sr, sc - 1, newColor, oldColor);
		fill(image, sr + 1, sc, newColor, oldColor);
		fill(image, sr, sc + 1, newColor, oldColor);
	}
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	if (image[sr][sc] != newColor) {
		fill(image, sr, sc, newColor, image[sr][sc]);
	}
	return image;
}

void printVector(const vector<vector<int>>& image) {
	for (int i = 0; i < image.size(); i++) {
		for (int j = 0; j < image[0].size(); j++) {
			cout << image[i][j] << " ";
		}
		cout << endl;
	}
}

//int main() {
//	vector<vector<int>> image;
//	vector<int> line1;
//	line1.push_back(1);
//	line1.push_back(1);
//	line1.push_back(1);
//	image.push_back(line1);
//	vector<int> line2;
//	line2.push_back(1);
//	line2.push_back(1);
//	line2.push_back(0);
//	image.push_back(line2);
//	vector<int> line3;
//	line3.push_back(1);
//	line3.push_back(0);
//	line3.push_back(1);
//	image.push_back(line3);
//	printVector(floodFill(image, 1, 1, 2));
//
//	return 0;
//}