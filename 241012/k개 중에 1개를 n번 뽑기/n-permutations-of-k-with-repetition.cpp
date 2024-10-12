#include <iostream>
using namespace std;

int n,k;
int arr[10];

void back_tracking(int cnt)
{
    // 기저사례
    if(cnt == n)
    {
        for(int i=0;i<n;i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=k;i++)
    {
        arr[cnt] = i;
        back_tracking(cnt+1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> k >> n;
    back_tracking(0);
    return 0;
}