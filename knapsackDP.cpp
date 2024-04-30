#include <iostream>
#include <cstring>

using namespace std;

int static dp[102][1002];


int knapsack(int wt[], int val[], int capacity, int n)
{
    if (n == 0 || capacity == 0)
    {
        return 0;
    }
    if (dp[n][capacity] != -1)
    {
        return dp[n][capacity];
    }
    if(wt[n-1] <= capacity)
    {
        dp[n][capacity] = max(val[n-1] + knapsack(wt, val, capacity-wt[n-1], n-1), knapsack(wt, val, capacity, n-1));
    }
    else if(wt[n-1] > capacity)
    {
        dp[n][capacity] = knapsack(wt, val, capacity, n-1);
    }
    return dp[n][capacity];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int wt[4] = {1, 3, 4, 5};
    int val[5] = {1, 4, 5, 7};
    int a = knapsack(wt, val, 7, 5);
    cout << "Maximum value that can be put in the bag is: " << a;
}