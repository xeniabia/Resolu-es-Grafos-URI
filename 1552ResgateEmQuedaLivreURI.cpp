#include <bits/stdc++.h>

using namespace std;

vector<int>pai;

struct aresta{
	double peso;
	int v1, v2;
};

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

double kruskal(vector<aresta> &g){
	int i;
	double nova = 0;	
	
	for(i=0 ; i<g.size(); i++){
		if(find(g[i].v1) != find(g[i].v2)){
				join(g[i]);
				nova+=g[i].peso;
			}
	}
	return nova;
}



int main (){
	int t; //numero de testes
	int n;
	vector< pair <double,double> > c;
	int i,j;
	double x, y;
	scanf("%d", &t);
	while(t>0){
		vector<aresta> g;
		scanf("%d", &n);
		
		for(i=0;i<n;i++){
			scanf("%lf %lf", &x, &y);
			c.push_back(make_pair(x,y));
		}

		
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				double saida;
				saida = (sqrt((c[j].first - c[i].first)*(c[j].first - c[i].first) + (c[j].second - c[i].second)*(c[j].second - c[i].second)));
				aresta teia{saida,i,j};
				g.push_back(teia);
			}
		}	
		
		sort(g.begin(), g.end(), comp);
		pai.resize(n+5);
		for(i=0;i<n;i++){
			pai[i] = i;
		}
		double minteia = kruskal(g)/100;
		printf("%.2lf\n", minteia);
		c.clear();
		pai.clear();
		t--;	
	}

	return 0;

}
