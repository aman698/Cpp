//dfs of graph
#include<bits/stdc++.h>
using namespace std;

void print(int** edges, int n, int sv, bool* visited){
    cout<<sv<<endl;
    visited[sv] = true;
    for(Int i=0;i<n;i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
            print(edges,n,i,visited);
        }
    }
}

void printBFS(int** edges, int n, int sv){
    queue<int>pendingVertices;
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    pendingVertices.push(sv);
    visited[sv] = true;
    int currentVertex;
    while(!pendingVertices.empty()){
        currentVertex = pendingVertices.pop();
        cout<<currentVertex<<endl;
        for(int i=0;i<n;i++){
            if(i == currentVertex){
                continue;
            }
            if(edges[currentVertex][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    int n;
    int e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    cout<<"DFS"<<endl;
    print(edges,n,0,visited);

    cout<<"BFS"<<endl;
    printBFS(edges, n, 0);
    // Delete all the memory

    delete [] visited;
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;
}

// use for bfs dfs for disconnected graph
#include<bits/stdc++.h>
using namespace std;

void printDFS(int** edges, int n, int sv, bool* visited){
    cout<<sv<<endl;
    visited[sv] = true;
    for(Int i=0;i<n;i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
            print(edges,n,i,visited);
        }
    }
}

void printBFS(int** edges, int n, int sv){
    queue<int>pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    int currentVertex;
    while(!pendingVertices.empty()){
        currentVertex = pendingVertices.pop();
        cout<<currentVertex<<endl;
        for(int i=0;i<n;i++){
            if(i == currentVertex){
                continue;
            }
            if(edges[currentVertex][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int** edges, int n){
    bool *visited = new bool[n];
   for(int i=0;i<n;i++){
       visited[i] = false;
   }
   for(int i=0;i<n;i++){
       if(!visited[i])
       printBFS(edges,n,i,visited);
   }
   delete [] visited; 
}

void DFS(int** edges, int n){
   bool *visited = new bool[n];
   for(int i=0;i<n;i++){
       visited[i] = false;
   }
   for(int i=0;i<n;i++){
       if(!visited[i])
       printDFS(edges,n,i,visited);
   }
   delete [] visited;
}

int main(){
    int n;
    int e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    cout<<"DFS"<<endl;
    printDFS(edges,n,0,visited);

    cout<<"BFS"<<endl;
    printBFS(edges, n, 0);
    // Delete all the memory

    delete [] visited;
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;
}

