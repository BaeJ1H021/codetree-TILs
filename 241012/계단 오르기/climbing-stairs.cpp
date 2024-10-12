#include <iostream>
using namespace std;

int dp[1010];

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    cin >> n;

    dp[2] = 1;
    dp[3] = 1;

    for(int i=4;i<=n;i++)
        dp[i] = (dp[i-2]+dp[i-3])%10007;

    cout << dp[n];
    return 0;
}