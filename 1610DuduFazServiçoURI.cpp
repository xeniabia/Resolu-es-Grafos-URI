#include <bits/stdc++.h>

using namespace std;
int cor[10002];

vector<int> g[30001];

// 0 para branco (não visitado)
// 1 para cinza (visitado)
// 2 para preto (vizinhos


bool dfs(int v){	
	cor[v] = 1;
	for(auto u: g[v]){
		if(cor[u] == 0){
			if(dfs(u))
				return true;
		}else if(cor[u] == 1){
			return true;
		}
		
	}
	cor[v] = 2;
	return false;
	
}

int main(){
	int t;
	int n, m;
	int x, y;
	cin >> t;
	int i;
	int ok;
	while(t>0){
		ok = 0;
		cin >> n >> m;
		for(i=1;i<=m;i++){
				cin >> x >> y;
				g[x].push_back(y);
		}
		for(i=1;i<=n;i++){
			if(cor[i] == 0){
				if(dfs(i)){
					ok = 1;
					break;
				}
			}
		}
		if(ok==1){
			cout << "SIM" << "\n";
		}else{
			cout << "NAO" << "\n";
		}
		
		for(i=1;i<=n;i++){
			g[i].clear();
			cor[i] = 0;		
		}	
	t--;
	}
	return 0;

}