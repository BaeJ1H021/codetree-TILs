#include <iostream>
#include <vector>
using namespace std;

int n,m;
int ans = 0;
bool visited[1010];

vector<int> vec[1010];

void dfs(int x)
{
    visited[x] = true;
    for(int i=0;i<vec[x].size();i++)
    {
        int next = vec[x][i];
        if(!visited[next])
        {
            ans++;
            dfs(next);
        }
    }
}


int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    dfs(1);
    cout << ans;
    return 0;
}