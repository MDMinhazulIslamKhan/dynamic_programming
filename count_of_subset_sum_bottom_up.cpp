#include <bits/stdc++.h>

using namespace std;
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

    int dp[n + 1][s + 1];

    // initialization
    dp[0][0] = 1;

    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
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

    // print all
    /*
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            cout << dp[i][j];
        }
        cout << endl;
    }
    return 0;
    */
    cout << dp[n][s];
}

/*
input ==>
4
2 4 6 8
9
*/