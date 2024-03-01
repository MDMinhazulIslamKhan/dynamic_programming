// ager complexity O(2 ^ n), now complexity O(n *W);
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000;
const int maxW = 1000;
int dp[maxN][maxW];
int knapsack(int n, int weight[], int value[], int W)
{
    /* base case for smallest valid input or bag empty */
    if (n == 0 || W == 0)
    {
        return 0;
    }
    // with memoization
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (weight[n - 1] <= W)
    {
        /* duita option, niye dekhbo or na niye dekhbo */
        int opt1 = knapsack(n - 1, weight, value, W - (weight[n - 1])) + value[n - 1];
        int opt2 = knapsack(n - 1, weight, value, W);
        /* without memoization */
        // return max(opt1, opt2);
        return dp[n][W] = max(opt1, opt2);
    }
    else
    {
        /* ekta option, nibo na */
        int opt = knapsack(n - 1, weight, value, W);

        /* without memoization */
        // return opt;
        return dp[n][W] = opt;
    }
}
int main()
{
    int n;
    cin >> n;
    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    int W;
    cin >> W;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << knapsack(n, weight, value, W);

    return 0;
}