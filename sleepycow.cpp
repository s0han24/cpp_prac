#include <bits/stdc++.h>
#define ll long long
#define f(l, r, k) for(int i=l; i<r; i+=k)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>
#define vl vector<long long>

using namespace std;

void solve(){
    FILE* in = fopen("herding.in", "r");
    FILE* out = fopen("herding.out", "w");
    int a,b,c;
    fscanf(in, "%d %d %d", &a, &b, &c);
    int d1 = c-b-1;
    int d2 = b-a-1;
    int dmin = min({d1, d2});
    int dmax = max({d1, d2});
    if(dmin == 0){
        if(dmax == 0) fprintf(out, "0\n");
        else{
            if(dmax == 1) fprintf(out, "1\n");
            else fprintf(out, "2\n");
        }
    }
    else if(dmin == 1) fprintf(out, "1\n");
    else fprintf(out, "2\n");
    fprintf(out, "%d", dmax);
}

int main(){
    solve();
    return 0;
}