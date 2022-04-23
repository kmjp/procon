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
int P[202020];
vector<int> E[202020];
int A[202020];
int V[202020];
int C[202020];
int cand[202020];
int MA[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<N;i++) {
		cin>>P[i];
		P[i]--;
		E[P[i]].push_back(i);
	}
	FOR(i,N) cin>>A[i];
	cin>>M;
	FOR(i,M) {
		cin>>x;
		V[x-1]++;
		C[x-1]++;
	}
	for(i=N-1;i>=0;i--) {
		if(V[i]) cand[i]=1;
		FORR(e,E[i]) {
			if(C[e]&&C[i]) cand[i]=1;
			C[i]+=C[e];
		}
	}
	ll ret=0;
	FOR(i,N) {
		if(i) MA[i]=MA[P[i]];
		if(cand[i]) MA[i]=max(MA[i],A[i]);
		ret+=1LL*V[i]*MA[i];
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
