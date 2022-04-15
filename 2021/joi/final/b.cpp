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
ll X[202020];
int Q;
ll W[202020];
ll C[202020];
ll R[202020];
ll L[202020];
ll S[202020];

ll ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	X[0]=-1LL<<60;
	FOR(i,N) cin>>X[i+1];
	X[N+1]=1LL<<60;
	
	FOR(i,Q) {
		cin>>W[i+1];
		C[i+1]=C[i]+W[i+1];
		L[i+1]=max(L[i],-C[i+1]);
		R[i+1]=max(R[i],C[i+1]);
		S[i+1]=L[i+1]+R[i+1];
	}
	
	FOR(i,N+1) {
		ll D=X[i+1]-X[i];
		if(D>=S[Q]) {
			ret[i]+=R[Q];
			ret[i+1]+=L[Q];
		}
		else {
			x=lower_bound(S,S+Q+1,D)-S;
			ret[i]+=R[x-1];
			ret[i+1]+=L[x-1];
			if(W[x]>0) ret[i]+=D-S[x-1];
			else ret[i+1]+=D-S[x-1];
			
		}
	}
	FOR(i,N) cout<<ret[i+1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
