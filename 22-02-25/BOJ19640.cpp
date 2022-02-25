/*
선두 중 근무일수 우선,
화장실 급한 정도,
줄 번호 가장 낮게

우선순위 큐...?
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 각 줄 별로 큐를 만든다
*/

typedef struct person {
	int d; // 근무일수
	int h; // 똥 급한 정도
	int l; // 들어가는 줄
	int n; // 들어간 순서
};

// 비교 함수를 잘 작성해야 한다
struct compare { // 오퍼레이터 처음 써 봤는데 c++ pq 검색하면 꽤 나온다
	bool operator()(person& a, person& b) {
		if (a.d == b.d) {
			if (a.h == b.h) {
				return a.l > b.l; // l, 줄 수는 낮을수록
			}
			return a.h < b.h; // h, 똥 급한 정도는 높을수록
		}
		return a.d < b.d; // d, 근무일수가 많을 수록 --> 우선도가 높다
	}
};


vector<person> v;
vector<queue<person>> line;

int main(void) {

	int n, m, k;
	cin >> n >> m >> k;
	priority_queue<person, vector<person>, compare> pq;

	// 입력
	for (int i = 0; i < m; i++) {
		queue<person> q;
		line.push_back(q);
	}
	for (int i = 0; i < n; i++) {
		int d, h;
		cin >> d >> h;
		line[i % m].push({ d, h, i % m, i });
	}

	// 우선순위 큐에 저장해야 함
	for (int i = 0; i < m; i++) {
		if (line[i].empty()) {
			continue; // 비어있으면 넘어가기
		}
		else {
			pq.push(line[i].front()); // 맨 앞에 있는 값을 넣는다
			line[i].pop();
		}
	}

	int ans = 0;
	while (true) {
		if (pq.top().n == k) {
			break;
		}
		int tmp = pq.top().l;
		pq.pop();
		ans++;
		if (!line[tmp].empty()) {
			pq.push(line[tmp].front());
			line[tmp].pop();
		}
	}

	cout << ans;

	return 0;
}
