#include <bits/stdc++.h>
using namespace std;

void addBackEdg(vector<vector<int>> &graph,vector<int> &apath,int maxbc){
    for(int i=0;i<apath.size()-1;i++){
	   int weight = graph[i][i+1];
	   graph[i+1][i] += weight;
	   graph[i][i+1] -= maxbc;
	}
}

void augmentedPath(vector<vector<int>> &graph,vector<bool> &visited,vector<int> &temp,vector<int> &augmentPath,int currentbc,int &maxbc,int s,int t){
    
    if(s==t){
        temp.push_back(t);
        if(INT_MAX!=currentbc && maxbc<currentbc){
            maxbc = currentbc;
            augmentPath = temp;
        }
        // apath.push_back(temp);
        temp.pop_back();
        return;
    }
    
    visited[s] = true;
    temp.push_back(s);
    
    auto adj = graph[s];
    for(int j=0;j<=t;j++){
        if(0!=graph[s][j] && !visited[j]){
            currentbc = min(currentbc,graph[s][j]);
            augmentedPath(graph,visited,temp,augmentPath,currentbc,maxbc,j,t);
        }
    }
    
    visited[s] = false;
    temp.pop_back();
}

int main() {
	int nodes = 5;
	vector<vector<int>> graph(nodes,vector<int>(nodes,0));
	graph[0][1] = 3;
	graph[0][2] = 3;
	graph[2][1] = 1;
	graph[1][4] = 2;
	graph[2][3] = 2;
	graph[3][4] = 3;
	
	
	int max_flow = 0;
	
	while(true){
	    vector<bool> visited(nodes,false);
	    int source = 0;
	    int sink = 4;
	    int maxbc = INT_MIN;
	    vector<int> temp;
	    vector<int> apath;
	    augmentedPath(graph,visited,temp,apath,INT_MAX,maxbc,source,sink);
	    cout<<maxbc<<endl;
	    for(int w : apath){
	        cout<<w<<"->";
	    }
	    cout<<endl;
	   // for(auto a : apath){
	   //     for(int w : a){
	   //         cout<<w<<"->";
	   //     }
	   //     cout<<endl;
	   // }
	   
	   //vector<int> choosen_path = chooseBestPath(apath);
	   
	   if(INT_MIN==maxbc){
	       break;
	   }
	   max_flow += maxbc;
	   
	   addBackEdg(graph,apath,maxbc);
	}
    cout<<max_flow;
	
	return 0;
}
