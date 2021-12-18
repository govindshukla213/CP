#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define M 1000000001
int lastans = 0;
vector<int> temp;
void solve()
{
    int T, k;
    cin >> T >> k;
    temp.push_back(T);
    vector<int> que(k, -1);
    for (int i = 0; i < k; i++)
    {
        cin >> que[i];
    }
    int x = 0;
    for (int i = 0; i < k; i++)
    {
        x = que[i] % M;
        x += lastans % M;
        x = x % M;
        lastans = x;
        for (int j = 0; j < temp.size(); j++)
        {
            if (lastans < temp[j])
            {
                lastans += 1;
            }
            else if (lastans > temp[j])
            {
                lastans -= 1;
            }
        }

        cout << lastans << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int i = 0;
    while (i < t)
    {
        solve();
        i++;
    }

    return 0;
}
