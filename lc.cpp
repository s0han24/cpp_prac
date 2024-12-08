#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> up;
    vector<int> parent;
    vector<int> depth;
    vector<vector<int>> children;
    int n;
    void dfs(int u){
        for(auto v: children[u]){
            up[v][0] = u;
            depth[v] = depth[u]+1;
            for(int i=1; i<32; i++){
                up[v][i] = up[up[v][i-1]][i-1];
            }
            dfs(v);
        }
    }

    TreeAncestor(int n, vector<int>& parent) {
        this->parent = parent;
        this->n = n;
        up.assign(n, vector<int>(32, 0));
        depth.assign(n,0);
        children.assign(n,vector<int>());
        for(int i=1; i<n; i++){
            children[parent[i]].push_back(i);
        }
        dfs(0);
    }
    
    int getKthAncestor(int node, int k) {
        if(k>depth[node]) return -1;
        for(int i=31; i>=0; i--){
            if(k&(1<<i)){
                node = up[node][i];
            }
        }
        return node;
    }
};
int main(){
    int n = 7;
    vector<int> parent = {-1,0,0,1,1,2,2};

    TreeAncestor* obj = new TreeAncestor(n, parent);
    int param_1 = obj->getKthAncestor(3, 1);
    cout<<param_1;
    return 0;
}
