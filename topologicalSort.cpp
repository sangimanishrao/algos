#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl "\n"
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
// for(int i = 0; i < n; i++)
 
using namespace std;

vector<int> graph[12345];
vector<int> visited;
stack<int> mine;

ll dfs(ll node) {
    visited[node] = 1;
    for(int i = graph[node].size()-1; i >= 0; i--) {
        if(visited[graph[node][i]] == 1) {
            return 1;
        }
        else if(visited[graph[node][i]] == 0) {
            ll x = dfs(graph[node][i]);
            if(x == 1)return 1;
        }
    }
    visited[node] = 2;
    mine.push(node);
    return -1;
}

void solve() {
    ll n,m,x,y;
    cin >> n >> m;
    visited.assign(n+1,0);
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for(int i = 1; i <= n; i++) {
        sort(graph[i].begin(),graph[i].end());
    }
    for(int i = n; i >= 1; i--) {
        if(visited[i] == 0) {
            ll x = dfs(i);
            if(x == 1) {
                cout << "Sandro fails." << endl;
                return;
            }
        }
    }
    while(!mine.empty()) {
        cout << mine.top() << " ";
        mine.pop();
    }
    cout << endl;
}
 
int main() {
    IOS
    ll t = 1;
    while(t--) {
        solve();
    }
}
