#include<bits/stdc++.h>

using namespace std;

#define INF ((int) 1e9)

typedef pair<int,int> r;
typedef vector<r>r2;

vector<r2>g;
vector<int> dist;
vector<int> vis;

int x, n , v;

void dijkstra(int s){
	int i;
	for(i=1; i<=v; i++){
		dist[i] = INF;
	}
    priority_queue<r, vector<r>, greater<r>> q;
	q.push(r(dist[s],s));
	while(true){
		int now = -1;
		while(!q.empty()){
			int atual = q.top().second;
			q.pop();
			if(!vis[atual]){
				now = atual;
				break;
			}
		}
		if(now==-1){
			break;
		}
		vis[now] = true;
		for(i=0; i<(int)g[now].size(); i++){
			int d = g[now][i].first;
			int atual = g[now][i].second;
			if(dist[atual] > dist[now] + d){
				dist[atual] = dist[now] + d;
				q.push(r(dist[atual],atual));
			}
		}
	}
}


int main(){
	int v1, v2;
	int i;
	int resp, hs, min;

	cin >> x >> n >> v;

	while(x!= 0){
		int t;
		string s1,s2;
		
		resp = 0;

		g.assign(n+2, r2());
		
		dist.resize(v);
		vis.resize(v);

		map<string,int> m;

		m.insert(make_pair("alto", v-1));
		m.insert(make_pair("varzea", 0));
		
		int cont = 2;

		for(i=0; i<n; i++){

			cin >> s1 >> s2 >> t;

			if(m.find(s1) == m.end()){
				m.insert(make_pair(s1,cont-1));
				cont++;
			}

			if(m.find(s2) == m.end()){
				m.insert(make_pair(s2,cont-1));
				cont++;
			}
		
			v1 = m[s1];
			v2 = m[s2];
			
			g[v1].push_back(r(t,v2));
		}

		if(x<=30){
			resp = 30;
		} else{
			resp = 50;
		}
			
		dijkstra(0);

		resp += dist[v-1];
		hs = (17 + (resp / 60)) % 24;
		min = resp % 60;

		printf("%02d:%02d\n",hs ,min);

		if(resp > 60){
				cout << "Ira se atrasar\n";
		}else{
				cout << "Nao ira se atrasar\n";
		}
		
		g.clear();
		vis.clear();
		dist.clear();

		cin >> x >> n >> v;
		
	}

	return 0;
}