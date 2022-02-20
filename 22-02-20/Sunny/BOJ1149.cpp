#include <iostream>
#include <vector>
using namespace std;

int n;
int house[1005][4];
int dp[1005][4];


int main(void) {

	cin >> n;	

	for (int i = 1; i <= n; i++) {
		cin >> house[i][1] >> house[i][2] >> house[i][3];
	}

	dp[1][1] = house[1][1];
	dp[1][2] = house[1][2];
	dp[1][3] = house[1][3];

	for (int i = 2; i <= n; i++) {
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + house[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + house[i][2];
		dp[i][3] = min(dp[i - 1][2], dp[i - 1][1]) + house[i][3];
	}

	int cost = dp[n][1];
	for (int i = 2; i <= 3; i++) {
		if (dp[n][i] < cost) {
			cost = dp[n][i];
		}
	}

	cout << cost;

	return 0;
}
