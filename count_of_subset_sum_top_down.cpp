#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
int dp[N][N];
int subsetSum(int n, int s, int arr[])
{
    if (n == 0)
    {
        if (s == 0)
            return 1;
        else
            return 0;
    }
    // memoization
    if (dp[n][s] != -1)
        return dp[n][s];

    if (arr[n - 1] <= s)
    {
        int opt1 = subsetSum(n - 1, s - arr[n - 1], arr);
        int opt2 = subsetSum(n - 1, s, arr);
        return dp[n][s] = opt1 + opt2;
    }
    else
        return dp[n][s] = subsetSum(n - 1, s, arr);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s;
    cin >> s;

    // initialization memoization
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << subsetSum(n, s, arr);

    return 0;
}