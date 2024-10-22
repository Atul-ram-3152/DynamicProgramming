#include <bits/stdc++.h>
using namespace std;

int dp[100001][1001];
int solve(int amount, int idx, vector<int> &price, vector<int> &pages)
{
    if(idx < 0) return 0;
    if(dp[amount][idx] != -1) return dp[amount][idx];

    int ans = solve(amount, idx-1, price, pages);

    if(amount - price[idx] >= 0)
    {
        ans = max(ans, solve(amount - price[idx], idx - 1, price, pages) + pages[idx]);
    }

    return dp[amount][idx] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> pages(n);

    for(int i = 0; i<n; i++)
    {
        cin >> price[i];
    }

    for(int i = 0; i<n; i++)
    {
        cin >> pages[i];
    }

    cout << solve(x, n-1, price, pages) << endl;
}