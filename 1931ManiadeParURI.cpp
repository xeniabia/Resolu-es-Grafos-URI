#include <bits/stdc++.h>

using namespace std;

#define INF ((int) 1e9)

typedef pair<int,int> r; //r - relação (cidade x associada a cidade y e a associada a preço p do pedágio)
typedef vector<r> r2;

vector<r2> g;
vector<int> dist;

int c, v;

void dijkstra(int s){
	int i, j;
	dist.assign(c, INF);
	dist[s]=0;
	priority_queue<r, vector<r>, greater<r>> q;
	q.push(r(0, s));
	while(!q.empty()){
		int u = q.top().second; q.pop();
		for(i=0; i<(int)g[u].size(); i++){
			int v = g[u][i].first;
			for(j=0; j<(int)g[v].size(); j++){
				int w = g[v][j].first;
				int z = g[v][j].second + g[u][i].second;
				if(dist[w]>dist[u]+z){
					dist[w] = dist[u] + z;
					q.push(r(dist[w], w));
				}
			}
		}
	}
}


int main (){
	int i;
	int x, y, p; //p - preço do pedágio

	cin >> c >> v;

	g.assign(c, r2());

	for(i=0;i<v;i++){
		cin >> x >> y >> p;
		x--;y--;
		g[x].push_back(r(y, p));
		g[y].push_back(r(x, p));	
	}

	dijkstra(0);

	if(dist[c-1]==INF){
		cout << "-1\n";
	} else{
		cout << dist[c-1] << "\n";
	}

	return 0;
}