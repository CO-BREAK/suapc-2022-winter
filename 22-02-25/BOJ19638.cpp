#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {

	int n, h, t;
	cin >> n >> h >> t;

	priority_queue<int> pq;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		pq.push(input);
		
	}

	int cnt = 0;
	while (t--) {		
		int tmp = pq.top();

		if (tmp >= h) {
			if (tmp != 1) {
				tmp /= 2;
				pq.pop();
				pq.push(tmp);
				cnt++;
			}
		}
		else {
			cout << "YES\n" << cnt;
			return 0;
		}


	}

	int maxi = pq.top();

	if (maxi >= h) {
		cout << "NO\n" << maxi;
	}
	else {
		cout << "YES\n" << cnt;
	}

	return 0;
}
