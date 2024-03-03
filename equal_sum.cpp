#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s += arr[i];
    }
    if (s % 2 == 0)
    {
        int sum = s / 2;
        bool dp[n + 1][sum + 1];

        // initialization
        dp[0][0] = true;

        for (int i = 1; i <= s; i++)
        {
            dp[0][i] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    bool opt1 = dp[i - 1][j - arr[i - 1]];
                    bool opt2 = dp[i - 1][j];
                    dp[i][j] = opt1 || opt2;
                }
                else
                {
                    bool opt = dp[i - 1][j];
                    dp[i][j] = opt;
                }
            }
        }
        if (dp[n][sum] == true)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    else
    {
        cout << "NO";
    }
}

/*
input ==>
4
2 4 6 8

*/