#include <bits/stdc++.h>

using namespace std;

vector<int> g[30];
bool vis[30];
vector<int> arm;
void dfs(int v){	
	arm.push_back(v);
	vis[v] = true;
	for(auto u: g[v]){
		if(vis[u] == false){
			dfs(u);
		}
	}
	
}


int main (){
	//vector<int> g[30];
	int v, e;
	char c1, c2;
	int x, y;
	int n;
	int i, j, k;
	cin >> n;
	for(k=1;k<=n;k++){
		
		cin >>  v >> e;
		for(i=0;i<e;i++){
			cin >> c1 >> c2;
			x = c1 - 'a';
			y = c2 - 'a';
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int cont = 0;
		cout << "Case #" << k << ":" << "\n";
		for(i = 0; i<v; i++){
			if(!vis[i]){
				dfs(i);
				sort(arm.begin(), arm.end());
				for(j=0;j<(int)arm.size();j++){
				cout << char(arm[j] + 'a') << ",";
				}
				cout << "\n";
				arm.clear();
				cont++;
			}
		}
		cout << cont << " connected components" << "\n\n" ;

		for(i=0;i<30;i++){
			g[i].clear();
			vis[i] = false;		
		}		

		/*for(i=0;i<v;i++){

		for(j=0;j<g[i].size();j++){
		cout << g[i][j] << " ";
		}
		cout << "\n";
		}*/
	}
}

