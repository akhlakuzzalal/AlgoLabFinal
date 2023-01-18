#include <bits/stdc++.h>

using namespace std;

// 01 dynami knapshak function
int knapshak(int wt[], int val[], int n, int W)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // selected elements
    int i = n, j = W;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            cout << "Element " << i << " is selected" << endl;
            j = j - wt[i - 1];
            i--;
        }
        else
            i--;
    }
    return dp[n][W];
}

int main()
{
    int n, W;
    cout << "Enter the value of element & total weight" << endl;
    cin >> n >> W;
    int wt[n], val[n];
    cout << "enter all weight of elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    cout << "Enter all profits of all elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << endl
         << "The maximum profit from all elements: " << knapshak(wt, val, n, W) << endl
         << endl;

    return 0;
}