#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        cin >> tmp;
        a[i] = tmp;
    }
    // i: left end; j: right end
    vector<int> dp(n, 1);
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < j; i++)
        {
            if (a[i] > a[j])
            {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    int maxnumber = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        maxnumber = max(dp[i], maxnumber);
    }
    cout << maxnumber << endl;
    return 0;
}
