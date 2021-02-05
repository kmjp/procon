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

int N,M;
ll L[5],R[5],A[5][101010];
vector<ll> B[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,5) {
		cin>>L[i]>>R[i];
		for(j=L[i];j<R[i];j++) cin>>A[i][j];
	}
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		B[x-1].push_back(y-1);
	}
	FOR(i,5) sort(ALL(B[i]));
	ll ret=0;
	FOR(y,5) FOR(x,y) {
		vector<ll> cand;
		if(R[y]<L[x]||R[x]<L[y]) continue;
		int TL=max(L[x],L[y]);
		int TR=min(R[x],R[y]);
		ll D=0,DC=0;
		for(i=L[x];i<TL;i++) DC+=A[x][i];
		FORR(b,B[x]) cand.push_back(DC+b);
		DC=0;
		for(i=L[y];i<TL;i++) DC+=A[y][i];
		for(i=TL;i<TR;i++) D+=A[y][i]-A[x][i];
		FORR(b,B[y]) {
			ll s=b+DC;
			ll t=s+D+1;
			ret+=lower_bound(ALL(cand),t)-lower_bound(ALL(cand),s);
			
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
