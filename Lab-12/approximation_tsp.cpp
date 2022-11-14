#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

class Edge{
	int src;
	int dest;
	int weight;
	public :
	Edge(){}
	void setEdge(int s,int d,int w){
		this->src = s;
		this->dest = d;
		this->weight = w;
	}
	int getSrc(){
		return this->src;
	}
	int getDest(){
		return this->dest;
	}
	int getWeight(){
		return this->weight;
	}
};

int doFind(int x,int *parent,int *rank){
	if(x == parent[x]){
		return x;
	}
	parent[x] = doFind(parent[x],parent,rank);
	return parent[x];
}

void doUnion(int x,int y,int *parent,int *rank){
	int x_rep = doFind(x,parent,rank);
	int y_rep = doFind(y,parent,rank);
	if(x_rep == y_rep){
		return;
	}
	if(rank[x_rep]<rank[y_rep]){
		parent[x_rep] = y_rep;
	}else if(rank[x_rep]>rank[y_rep]){
		parent[y_rep] = x_rep;
	}else{
		parent[y_rep] = x_rep;
		rank[x_rep] ++;
	}
}

bool myCmp(Edge e1,Edge e2){
	return e1.getWeight()<e2.getWeight();
}

Edge *mstByKruskal(Edge *gp,int total_vertex,int total_edges){

	sort(gp,gp+total_edges,myCmp);

	int parent[total_vertex];
	int rank[total_vertex];
	int minimum_cost = 0;
	
	Edge *mst = new Edge[total_edges];
	for(int i=0;i<total_vertex;i++){
		parent[i] = i;
		rank[i] = 0;
	}
	
	for(int i=0,s=0;s<total_vertex-1;i++){
		int x = doFind(gp[i].getSrc(),parent,rank);
		int y = doFind(gp[i].getDest(),parent,rank);
		if(x != y){
			mst[i] = gp[i];
			// cout<<"src "<<gp[i].getSrc()<<" Dest "<<gp[i].getDest()<<" Weight "<<gp[i].getWeight()<<endl;
			minimum_cost += gp[i].getWeight();
			doUnion(x,y,parent,rank);
			s++;
		}
	}
	return mst;
}

void dfs(vector<vector<pair<int,int>>> &graph,int s,vector<int> &tsppath,vector<bool> &visited){
	visited[s] = true;
	tsppath.push_back(s);
	for(auto adj : graph[s]){
		if(!visited[adj.first]){
			dfs(graph,adj.first,tsppath,visited);
			tsppath.push_back(s);
		}
	}
	
}

void getPreorderTSPPath(vector<vector<pair<int,int>>> &graph,int n,vector<int> &preorder_tsppath){
    vector<bool> visited(n+1,false);
	dfs(graph,1,preorder_tsppath,visited);
}

vector<int> getTSPPath(vector<int> &ptp,int n){
	vector<bool> visited(n+1,false);
	vector<int> tsp;
	tsp.push_back(ptp[0]);
	visited[ptp[0]] = true;
	for(int i=1;i<ptp.size()-1;i++){
		if(!visited[ptp[i]]){
			tsp.push_back(ptp[i]);
			visited[ptp[i]] = true;
		}
	}
	tsp.push_back(ptp[0]);
	return tsp;
}

int getTSPCost(vector<vector<int>> &adj_mat,vector<int> &tsppath){
	int cost = 0;
	for(int i=0;i<tsppath.size()-1;i++){
		cost += adj_mat[tsppath[i]][tsppath[i+1]];
	}
	return cost;
}

int main(){
	int total_vertex;
	// cout<<"Enter total Vertex :- ";
	cin>>total_vertex;
	int total_edges;
	// cout<<"\nEnter total Edges :- ";
	cin>>total_edges;
	vector<vector<int>> adj_mat(total_vertex+1,vector<int>(total_vertex,0));
	Edge *g = new Edge[total_edges];
	// cout<<"\nEnter all Edges :- \n";
	for(int i=0;i<total_edges;i++){
		int s,d,w;
		cin>>s>>d>>w;
		adj_mat[s][d]= adj_mat[d][s] = w;
		g[i].setEdge(s,d,w);
	}
	Edge *result = mstByKruskal(g,total_vertex,total_edges);
	
    vector<vector<pair<int,int>>> graph(total_vertex+1);
    for(int i=0;i<total_vertex-1;i++){
        graph[result[i].getSrc()].push_back({result[i].getDest(),result[i].getWeight()});
    }

    vector<int> preorder_tsppath;
    getPreorderTSPPath(graph,total_vertex,preorder_tsppath);

	// printing spanning tree nodes
	/*
    for(int i=0;i<total_vertex-1;i++){
        cout<<result[i].getSrc()<<"=>"<<result[i].getDest()<<" = "<<result[i].getWeight()<<endl;
    }
	*/
    // cout<<endl;
	// printing preorder tsp path
	cout<<"Preorder TSP Path :-\n";
	for(int p : preorder_tsppath)
		cout<<p<<" ";
	cout<<endl;
	
	vector<int> tsppath = getTSPPath(preorder_tsppath,total_vertex);
	cout<<"TSP Path :-\n";
	for(int p : tsppath)
		cout<<p<<" ";
	cout<<endl;
	int tsp_cost = getTSPCost(adj_mat,tsppath);
	cout<<"TSP Cost :- "<<tsp_cost;
	
	return 0;
}

// input
/*
5 10
1 2 3
1 3 4
1 4 5
1 5 6
2 5 4
2 4 3
2 3 5
3 5 4
3 4 4
4 5 5
*/

// output
/*
Preorder TSP Path :-
1 2 4 2 5 2 1 3 1 
TSP Path :-
1 2 4 5 3 1 
TSP Cost :- 19
*/