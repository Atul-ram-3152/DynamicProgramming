#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

int dp[1001][1001];

int solve(int i, int j, vector<vector<char>> &grid, int n)
{
    if(grid[i][j] == '*') return 0;
    if(i==n || j==n) return 0;
    if(i == n-1 && j == n-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if(j+1 < n && grid[i][j+1] == '.')
    {
        ans = (ans+solve(i, j+1, grid, n))%M;
    }
    if(i+1 < n && grid[i+1][j] == '.')
    {
        ans = (ans + solve(i+1, j, grid, n))%M;
    }

    return dp[i][j] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << solve(0,0,grid,n) << endl;
}