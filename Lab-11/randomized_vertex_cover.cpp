#include <bits/stdc++.h>
using namespace std;


void minimumVertexCover(vector<vector<int>> &graph,int nodes,int edges){
	vector<pair<int,int>> edgev(edges);
	vector<int> solution;
	int sum = 0;
	for(int i=0;i<nodes;i++){
		for(int j=0;j<nodes;j++){
			if(1==graph[i][j]){
				edgev.push_back({i,j});
			}
		}
	}

	srand(time(NULL));
	
	int len = edgev.size();
	while(0 <= len){
		int ri = rand()%len; //random index
		int u = edgev[ri].first;
		int v = edgev[ri].second;
		solution.push_back(u);
		solution.push_back(v);
		int i=0;
		while(i<len){
			if(edgev[i].first==u || edgev[i].first==v || edgev[i].second==u || edgev[i].second==v){
				sum --;
				len --;
				swap(edgev[i],edgev[len]);
			}else{
				i ++;
			}
		}
	}

	cout<<"solution vertex:- "<<endl;
	for(int v : solution){
		cout<<v<<" ";
	}
}

int main(){
	int nodes,edges;
	cin>>nodes>>edges;

	vector<vector<int>> graph(nodes,vector<int>(nodes,0));
	for(int i=0;i<edges;i++){
		int u,v;
		cin>>u>>v;
		graph[u][v] = graph[v][u] = 1;
	}

	minimumVertexCover(graph,nodes,edges);
	return 0;
}