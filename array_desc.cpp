#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;

    vector<vector<int>> dp(n, vector<int>(m+1,0));
    if (a[0] == 0)
    {
        for (int i = 1; i <= m; i++)
        {
            dp[0][i] = 1;
        }
    }
    else
    {
        dp[0][a[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {

                for (int k : {j - 1, j, j + 1})
                {
                    if (k >= 1 && k <= m)
                    {
                        dp[i][j] = (dp[i][j] + dp[i-1][k]) % M;
                    }
                }
            }
        }
        else
        {
            for (int k : {a[i] - 1, a[i], a[i] + 1})
            {
                if (k >= 1 && k <= m)
                {
                    dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][k]) % M;
                }
            }
        }
    }
    
    for(int j = 1; j<=m; j++)
    {
        ans = (ans + dp[n-1][j])%M;
    }

    cout << ans << endl;
}


