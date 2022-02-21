/* 역원소 정렬 */

#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> v;
string str;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> str;
    reverse(str.begin(), str.end());
    v.push_back(stoll(str));
  }
  sort(v.begin(), v.end());

  for (auto i : v)
    cout << i << '\n';

  return 0;
}