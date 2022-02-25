/* IF문 좀 대신 써줘 */

#include <bits/stdc++.h>
using namespace std;

vector<string> name;
vector<int> strength;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string x;
        int y;
        cin >> x >> y;

        name.push_back(x);
        strength.push_back(y);
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        cout << name[lower_bound(strength.begin(), strength.end(), x) - strength.begin()] << '\n';
    }

    return 0;
}