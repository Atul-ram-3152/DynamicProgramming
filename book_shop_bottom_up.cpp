#include <bits/stdc++.h>
using namespace std;

// int dp[100001][1001];
// int solve(int amount, int idx, vector<int> &price, vector<int> &pages)
// {
//     if(idx < 0) return 0;
//     if(dp[amount][idx] != -1) return dp[amount][idx];

//     int ans = solve(amount, idx-1, price, pages);

//     if(amount - price[idx] >= 0)
//     {
//         ans = max(ans, solve(amount - price[idx], idx - 1, price, pages) + pages[idx]);
//     }

//     return dp[amount][idx] = ans;
// }

int main()
{
    
    int n, x;
    cin >> n >> x;

    vector<int> price(n+1);
    vector<int> pages(n+1);

    for(int i = 1; i<=n; i++)
    {
        cin >> price[i];
    }

    for(int i = 1; i<=n; i++)
    {
        cin >> pages[i];
    }

    int dp[n+1][x+1];

    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=x; j++)
        {
            if(j == 0 || i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = (i == 1) ? 0 : dp[i-1][j];
                if(j - price[i] >= 0)
                {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-price[i]] + pages[i]);
                }
            }
        }
    }
    cout << dp[n][x] << endl;
}