#include <iostream>
#include <queue>
using namespace std;

int dy[4] ={-1,1,0,0};
int dx[4] ={0,0,-1,1};

bool visited[110][110];

int n,k;
int arr[110][110];
int ans = 0;

void bfs(int y, int x)
{
    // 이미 들른 경우.
    if(visited[y][x])
        return;

    queue<pair<int,int>> q;
    visited[y][x] = true;
    q.push({y,x});

    while(!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            if(ny<1 || ny>n || nx<1 || nx>n)
                continue;
            if(!visited[ny][nx] && arr[ny][nx] ==0)
            {
                visited[ny][nx] = true;
                q.push({ny,nx});
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=1;i<=k;i++)
    {
        int a, b;
        cin >> a >> b;
        bfs(a,b);
    }

    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(visited[i][j])
                cnt++;
        }
    }
    cout<< cnt;
    return 0;
}