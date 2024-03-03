#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int diff, needSum;
    cin >> diff;
    needSum = (sum + diff) / 2;

    int dp[n + 1][needSum + 1];

    // initialization
    dp[0][0] = true;

    for (int i = 1; i <= needSum; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= needSum; j++)
        {
            if (arr[i - 1] <= j)
            {
                int opt1 = dp[i - 1][j - arr[i - 1]];
                int opt2 = dp[i - 1][j];
                dp[i][j] = opt1 + opt2;
            }
            else
            {
                int opt = dp[i - 1][j];
                dp[i][j] = opt;
            }
        }
    }
    cout << dp[n][needSum];

    return 0;
}

/*
input ==>
4
1 1 2 3
1
*/