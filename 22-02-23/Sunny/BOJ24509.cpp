#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct student {
	int id;
	int a, b, c, d;
}student;

bool compare1(student x, student y) {
	if (x.a == y.a) {
		return x.id < y.id;
	}
	return x.a > y.a;
}

bool compare2(student x, student y) {
	if (x.b == y.b) {
		return x.id < y.id;
	}
	return x.b > y.b;
}

bool compare3(student x, student y) {
	if (x.c == y.c) {
		return x.id < y.id;
	}
	return x.c > y.c;
}

bool compare4(student x, student y) {
	if (x.d == y.d) {
		return x.id < y.id;
	}
	return x.d > y.d;
}



int main(void) {
	int n;
	cin >> n;
	vector<student> v(n);
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		cin >> v[i].id >> v[i].a >> v[i].b >> v[i].c >> v[i].d;
	}
	sort(v.begin(), v.end(), compare1);
	ans.push_back(v[0].id);
	v.erase(v.begin());
	sort(v.begin(), v.end(), compare2);
	ans.push_back(v[0].id);
	v.erase(v.begin());
	sort(v.begin(), v.end(), compare3);
	ans.push_back(v[0].id);
	v.erase(v.begin());
	sort(v.begin(), v.end(), compare4);
	ans.push_back(v[0].id);

	for (int i = 0; i < 4; i++) {
		cout << ans[i] << " ";
	}


	return 0;
}
