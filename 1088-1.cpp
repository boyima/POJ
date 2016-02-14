#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;

class Point {
public:
	int x;
	int y;
	int h;
	Point(int xcor, int ycor, int height) {
		x = xcor;
		y = ycor;
		h = height;
	}
	Point() {
		x = 0;
		y = 0;
		h = 0;
	}
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool smaller(Point* a, Point* b) {
	return a->h < b->h;
}

bool inBound(int x, int y, int R, int C) {
	return (x >= 0 && y >= 0 && x < R && y < C);
}

int main() {
	int R, C;
	int res = 0;
	cin >> R >> C;
	vector<vector<int>> height(R, vector<int>(C, 0));
	vector<Point*> points;
	vector<vector<int>> dp(R, vector<int>(C, 1));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> height[i][j];
			points.push_back(new Point(i, j, height[i][j]));
		}
	}
	sort(points.begin(), points.end(), smaller);
	for (vector<Point*>::iterator it = points.begin(); it != points.end(); it++) {
		for (int dir = 0; dir < 4; dir++) {
			int neighborX = (*it)->x + dx[dir];
			int neighborY = (*it)->y + dy[dir];
			if (!inBound(neighborX, neighborY, R, C) || height[neighborX][neighborY] <= (*it)->h || dp[neighborX][neighborY] > dp[(*it)->x][(*it)->y]) continue;
			dp[neighborX][neighborY] = dp[(*it)->x][(*it)->y] + 1;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			res = max(res, dp[i][j]);
		}
	}
	cout << res << endl;
	system("pause");
	return 0;
}
