#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

// int dp[1000001];

// int solve(int amount, vector<int> &coins)
// {
//     if(amount == 0) return 1;
//     if(dp[amount] != -1) return dp[amount];

//     int ans = 0;

//     for(int i = 0; i<coins.size(); i++)
//     {
//         if(amount - coins[i] >= 0)
//         {
//             ans = (ans + solve(amount-coins[i], coins))%M;
//         }
//     }

//     return dp[amount] = ans;
// }

int main()
{
    // memset(dp, -1, sizeof(dp));
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for(int i = 0; i<n; i++)
    {
        cin >> coins[i];
    }
    vector<int> dp(x+1);
    dp[0] = 1;

    for(int i = 0; i<=x; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i - coins[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i-coins[j]])%M;
            }
        }
    }
    cout << dp[x];
}