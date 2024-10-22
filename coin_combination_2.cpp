#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD=1e9+7;    

int dp[105][1000005];
int solve(int n, int sum, vector<int>& coins)
{
    if(n < 0) return 0;
    if(sum == 0) return 1;
    if(dp[n][sum] != -1) return dp[n][sum];

    int ans = 0;
    for(int i = 0; i<=n; i++)
    {
        int op1 = solve(n-1, sum, coins);
        int op2 = 0;
        if(sum - coins[i] >= 0) op2 = solve(n, sum-coins[i], coins);

        ans = (op1 + op2)%MOD;
    }

    return dp[n][sum] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int T = 1;
    while (T--)
    {
        int n;
        int sum;
        cin >> n >> sum;

        vector<int> coins(n);
        for(int i = 0; i<n; i++)
        {
            cin >> coins[i];
        }

        cout << solve(n-1, sum, coins) << endl;
    }
}

    