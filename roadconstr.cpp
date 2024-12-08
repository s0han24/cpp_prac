#include <bits/stdc++.h>
#define ll long long
#define MAX_SIZE 100007
#define swap(x,y) x=x^y;y=x^y;x=x^y;

using namespace std;

ll linked[MAX_SIZE];
ll sizeOf[MAX_SIZE];

ll find(ll x){
    while(x != linked[x]) x = linked[x];
    return x;
}

bool same(ll a, ll b){
    return find(a) == find(b);
}

void unite(ll a, ll b){
    a = find(a);
    b = find(b);
    if(sizeOf[a] < sizeOf[b]){swap(a,b);}
    sizeOf[a] += sizeOf[b];
    linked[b] = a;
}

int main(){
    int n,m;
    cin>>n>>m;
    int a,b;
    priority_queue<int> sizes;
    for(ll i = 0; i < n; i++){
        linked[i] = i;
        sizeOf[i] = 1;
    }
    sizes.push(1);
    int count = n;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a--;b--;
        if(!same(a,b)){
            count--;
            unite(a,b);
            sizes.push(sizeOf[find(a)]);
        }
        cout<<count<<" "<<sizes.top()<<endl;
    }
    return 0;
}