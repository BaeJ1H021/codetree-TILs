#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2e9;
int n,m;
int from, to;
int d[1010];
int trace[1010];
vector<pair<int,int>> vec[1010];

void find_trace()
{
    int x = to;
    vector<int> v;
    v.push_back(x);
    while(true)
    {
        v.push_back(trace[x]);
        if(trace[x] != from)
        {
            x =  trace[x];
        }
        else
        {
            break;
        }
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        cout << v[i] << " ";
    }
}

void djkstra()
{
    priority_queue<pair<int,int>> pq;
    // 현재, 거리, 들른 정점 개수. 
    pq.push({0, from});
    d[from] = 0;
    while(!pq.empty())
    {
        int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(int i=0;i<vec[cur].size();i++)
        {
            int next = vec[cur][i].first;
            int ndist = vec[cur][i].second;
            if(d[next]>dist+ndist)
            {
                d[next] = dist+ndist;
                trace[next] = cur;
                pq.push({-d[next], next});
            }
        }
    }
    cout << d[to] << "\n";
    find_trace();
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        vec[a].push_back({b,w});
        vec[b].push_back({a,w});
    }
    cin >> from >> to;
    
    for(int i=1;i<=n;i++)
        d[i] = INF;
    
    djkstra();

    return 0;
}