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
ll A[202020],B[202020],C[202020],D[202020],E[202020];
map<int,vector<int>> X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,N) cin>>C[i];
	FOR(i,N) cin>>D[i];
	FOR(i,N) {
		cin>>E[i];
		C[i]+=A[i];
		E[i]-=A[i];
		X[-D[i]].push_back(B[i]);
		Y[B[i]-D[i]].push_back(B[i]);
	}
	FORR2(a,b,X) sort(ALL(b));
	FORR2(a,b,Y) sort(ALL(b));
	
	FOR(i,N) {
		int ret=0;
		if(X.count(E[i])) {
			ret+=lower_bound(ALL(X[E[i]]),C[i]+1)-X[E[i]].begin();
		}
		if(Y.count(C[i]+E[i])) {
			ret+=Y[C[i]+E[i]].end()-lower_bound(ALL(Y[C[i]+E[i]]),C[i]+1);
		}
		cout<<ret<<" ";
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
