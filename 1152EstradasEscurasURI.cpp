#include <bits/stdc++.h>

using namespace std;

vector<int> pai;

struct aresta{
	int peso;
	int v1, v2;
};

void pai_inicial(int n){
	int i;
	for(i=1;i<=n;i++){
	pai[i] = i;
	}
	}

bool comp(aresta xy, aresta wz){
	return xy.peso < wz.peso;
}


int find(int x){
	if(pai[x] == x)
		return x;
		return find(pai[x]);
}

void join(aresta edge){
    	int a,b;
    	a = find(edge.v1);
    	b = find(edge.v2);
    	if(a==b) return ;
    	pai[a] = b;
}



int main (){
	int n, m;
	int i;
	int x, y, p;
	int soma;
	int nova;
	cin >> n >> m;
	while(n!=0 && m!=0){
		soma = 0;
		nova = 0;
		vector<aresta> g;
		pai.resize(m+5);

		for(i=0;i<m;i++){
			cin >> x >> y >> p;
			soma+= p;
			aresta a{p,x,y};
			g.push_back(a);
		}

		pai_inicial(m+1);

		sort(g.begin(), g.end(), comp);

		for(i=0;i<m;i++){
			if(find(g[i].v1) != find(g[i].v2)){
				join(g[i]);
				nova+=g[i].peso;
			}
		}

		cout << (soma - nova) << "\n";
		pai.clear();
		cin >> n >> m;

	}

	return 0;

}
