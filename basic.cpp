#include <bits/stdc++.h>
#define ll long long
const ll N = 1e5 + 5;
ll arr[N];
using namespace std;
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int previous = factorial(n - 1);
    return previous * n;
}

ll fibonacchi(ll n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (arr[n] != -1)
    {
        return arr[n];
    }
    ll before = fibonacchi(n - 1);
    ll secondBefore = fibonacchi(n - 2);
    ll ans = before + secondBefore;
    arr[n] = ans;
    return ans;
}

int main()
{
    ll n;
    cin >> n;

    // cout << factorial(n) << endl;

    /* fibonacchi top down */
    for (ll i = 0; i < N; i++)
    {
        arr[i] = -1;
    }
    cout << fibonacchi(n) << endl;

    /* fibonacchi bottom up */
    ll arr2[n];
    arr2[0] = 0;
    arr2[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr2[i] = arr2[i - 1] + arr2[i - 2];
    }
    cout << arr2[n];
    return 0;
}