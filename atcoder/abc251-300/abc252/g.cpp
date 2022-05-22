#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
const ll mo=998244353;
int P[505];

ll F[505][505];
ll G[505][505];


ll par(int L,int R);

ll top(int L,int R) {
	if(L+1>=R) return 1;
	if(F[L][R]>=0) return F[L][R];
	return F[L][R]=par(L+1,R);
}
ll par(int L,int R) {
	if(L+1>=R) return 1;
	if(G[L][R]>=0) return G[L][R];
	
	ll ret=top(L,R);
	for(int i=L+1;i<R;i++) if(P[L]<P[i]) (ret+=top(L,i)*par(i,R))%=mo;
	return G[L][R]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i];
	MINUS(F);
	MINUS(G);
	cout<<top(0,N)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
