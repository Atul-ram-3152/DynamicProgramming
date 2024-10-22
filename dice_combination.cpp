#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

int dp[1000001];

ll solve(int sum)
{
    if(sum == 0)
    {
        return 1;
    }
    if(dp[sum] != -1) return dp[sum];

    ll ans = 0;

    for(int i = 1; i<=6; i++)
    {
        if(sum - i >= 0)
        {
            ans =(ans + solve(sum - i)) % M;
        }
    }

    return dp[sum] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    cout << solve(n) << endl;
}