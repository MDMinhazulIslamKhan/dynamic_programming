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

    bool dp[n + 1][s + 1];

    // initialization
    dp[0][0] = true;

    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
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
    vector<int> v;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (dp[i][j])
            {
                v.push_back(j);
            }
        }
        cout << endl;
    }
    int ans = INT_MAX;
    for (int val : v)
    {
        int s1 = val;
        int s2 = s - s1;
        ans = min(ans, abs(s1 - s2));
    }
    cout << ans;
}

/*
input ==>
4
1 5 4 1
*/