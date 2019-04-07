/*
https://www.geeksforgeeks.org/bitmasking-dynamic-programming-set-2-tsp/
*/

#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define maxx 1000000

bool visited[105][105];
int dp[270000][105];
char arr[105][105];
int dist[20][20];
int row, col, k;
map<pair<int, int>, int> mp;

bool safe(int x, int y){
    return (x>=0) and (y>=0) and (x<row )and (y<col) and (arr[x][y] != '#');
}

void bfs(int i, int j){
    int move[2][8] = {{-1, -1, -1, 0, 0, 1, 1, 1} , {-1, 0, 1, -1, 1, -1, 0, 1}};
    memset(visited, false, sizeof(visited));
    int x, y, dx, dy, step;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {i, j}});
    visited[i][j] = true;
    while(!q.empty()){
        x = q.front().s.f;
        y = q.front().s.s;
        step = q.front().f;
        q.pop();
        if(mp.find({x, y}) != mp.end()){
            int d1 = mp[{x, y}];
            int d2 = mp[{i, j}];
            dist[d1][d2] = min(dist[d1][d2], step);
            dist[d2][d1] = min(dist[d2][d1], step);
        }
        for(int I=0; I<8; I++){
            dx = x + move[0][I];
            dy = y + move[1][I];
            if(safe(dx, dy) and !visited[dx][dy]){
                visited[dx][dy] = true;
                q.push({1+step, {dx, dy}});
            }
        }
    }
}

int solve(int mask, int idx){
    if(mask == ((1<<k)-1)){
        return dist[k][idx];
    }
    int d = maxx;
    for(int i=0; i<k; i++){
        if(!(mask & (1<<i)) ){
            d = min(d, dist[i][idx] + solve((mask | (1<<i)), i));
        }
    }
    return d;
}

int main(){
    int start_i, start_j;
    mp.clear();
    k = 0;
    cin>>row >>col;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='m'){
                start_i = i;
                start_j = j;
            }
            else if(arr[i][j]=='b'){
                mp[{i, j}] = k++;
            }
        }
    }
    mp[{start_i, start_j}] = k;
    for(int i=0; i<=k; i++){
        for(int j=0; j<=k; j++){
            if(i==j) dist[i][j] = 0;
            else{
                dist[i][j] = maxx;
                dist[j][i] = maxx;
            }
        }
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j]=='b'){
                bfs(i, j);
            }
        }
    }

    int d = maxx;
    for(int i=0; i<k; i++){
        d = min(d, dist[k][i] + solve((1<<i), i));
    }
    if(d >= maxx) cout<<-1;
    else cout<<d;
    cout<<endl;
    return 0;
}
