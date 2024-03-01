#include <bits/stdc++.h>

using namespace std;

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
    int db[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                db[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (weight[i - 1] <= j)
            {
                int opt1 = db[i - 1][j - weight[i - 1]] + value[i - 1];
                int opt2 = db[i - 1][j];
                db[i][j] = max(opt1, opt2);
            }
            else
            {
                int opt = db[i - 1][j];
                db[i][j] = opt;
            }
        }
    }
    /* full table */
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= W; j++)
    //     {
    //         cout << db[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << db[n][W];

    return 0;
}