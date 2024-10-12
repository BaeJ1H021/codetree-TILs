#include <iostream>
using namespace std;

int ans = -1;

int n,m;
int arr[22][22];

void brute_force(int y1, int x1, int y2, int x2)
{
    for(int i=y1;i<=y2;i++)
    {
        for(int j=x1;j<=x2;j++)
        {
            if(arr[i][j]<=0)
                return;
        }
    }
    ans =  max(ans, (y2-y1+1)*(x2-x1+1));
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;  

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> arr[i][j];
        }
    }  

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=i;k<=n;k++)
            {
                for(int l=j;l<=m;l++)
                {
                    brute_force(i,j,k,l);
                }
            }
        }
    }

    cout << ans;

    return 0;
}