#include <bits/stdc++.h>
using namespace std;

#define int         long long

#define F(a,b,i)    for(int i=a;i<b;i++)
#define FN(a,b,i)   for(int i=a-1;i>=b;i--)
#define f           first
#define s           second
#define all(x)      x.begin(), x.end()
#define check(x)    cout << ((x) ? "YES\n" : "NO\n")
#define checks(x)    cout << ((x) ? "Yes\n" : "No\n")
#define clz(x)      __builtin_clz(x)
typedef vector<int> vi;
typedef pair<int,int>           pii;
typedef vector<pair<int,int>>   vpii;
typedef vector<vector<int>>     vvi;

const int M   =  998244353;
const int inf = 1e18;


// DSU
//int par[(int)2e5+6],siz[(int)2e5+6];
//
//void make_set(int a){
//    par[a]=a;
//    siz[a]=1;
//}
//
//int find_set(int a){
//    if(par[a]==a) return a;
//    return par[a]=find_set(par[a]);
//}
//
//void union_set(int a,int b){
//    a=find_set(a);
//    b=find_set(b);
//    if(a!=b){
//        if(siz[a]<siz[b]) swap(a,b);
//        par[b]=a;
//        siz[a]+=siz[b];
//    }
//}

int binExp(int a,int n){
    int ans=1;
    while(n){
        if(n&1) ans=(ans*a)%M;
        a=(a*a)%M;
        n/=2;
    }
    return ans;
}

vi seg;

void build(vi &a,int &n){
    while(__builtin_popcount(n)!=1){
        n++;
        a.push_back(0);
    }
    seg.resize(2*n);
    F(0,n,i) seg[i+n]=a[i];
    FN(n,1,i){
        seg[i]=seg[2*i]+seg[2*i+1];
    }

}

int sm(int node, int nleft,int nright,int rleft,int rright){
    int md=(nleft+nright)/2;
    int lef=0,rig=0;
    if(nleft>=rleft && nright<=rright) return seg[node];
    if(max(nleft,rleft)<=min(md,rright)) lef=sm(2*node,nleft,md,rleft,rright);
    if(max(md+1,rleft)<=min(rright,nright)) rig=sm(2*node+1,md+1,nright,rleft,rright);
    return lef+rig;
}

void updt(int node, int ind,int nleft,int nright,int val){
    if(nleft==nright){
        seg[node]=val;
        return;
    }
    int md=(nleft+nright)/2;
    if(ind>=nleft && ind<=md) updt(2*node,ind,nleft,md,val);
    else updt(2*node+1,ind,md+1,nright,val);
    seg[node]=seg[2*node]+seg[2*node+1];
}

void solve(){

}

signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin) ;
    freopen("output.txt" , "w" , stdout) ;
    //freopen("error.txt" , "w" , stderr) ;
#endif
    ios_base::sync_with_stdio (false);
    cin.tie(nullptr);
    cout.tie(NULL);
    cout<<setprecision(30);
    int t = 1;
    cin>>t;
    for (int i=1;i<=t;i++) {
//        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}

/*
 *SOME FREQUENT MISTAKES:
 * MISINTERPRETING THE QUESTION
 * ARRAY INDEX GOING OUT BOUND
 * USING OTHER VARIABLE WITH SIMILAR NAME
 * SOME OBVIOUS BUT WRONG ASSUMPTIONS
 * INITIALIZING SOME VALUE THAT WILL STORE MAX/MIN NOT SMALL/LARGE ENOUGH
 * TREE MAY BE UNDIRECTED SO BE CAREFUL WHILE TAKING THE EDGES AS INPUT
 * USING SET WHERE MULTISET SHOULD HAVE BEEN USED
 */