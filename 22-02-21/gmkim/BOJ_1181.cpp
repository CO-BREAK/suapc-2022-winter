/* 기본 틀 */

#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
  if (a.length() == b.length())
    return a < b;
  return a.length() < b.length();
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  vector<string> v;
  string str;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> str;
    v.push_back(str);
  }

  sort(v.begin(), v.end(), cmp);

  cout << v[0] << "\n";
  for (int i = 1; i < n; i++)
  {
    if (v[i - 1] != v[i])
      cout << v[i] << "\n";
  }

  return 0;
}