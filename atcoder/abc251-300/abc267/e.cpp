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
int A[202020];
int U[202020],V[202020];
vector<int> E[202020];
ll C[202020];
int did[202020];

int ok(ll v) {
	int i;
	FOR(i,N) {
		C[i]=0, did[i]=0;
		FORR(e,E[i]) C[i]+=A[e];
	}
	queue<int> Q;
	FOR(i,N) {
		if(C[i]<=v) {
			did[i]=1;
			Q.push(i);
		}
	}
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		FORR(e,E[cur]) {
			if(did[e]==0&&C[e]-A[cur]<=v) {
				did[e]=1;
				Q.push(e);
			}
			C[e]-=A[cur];
		}
	}
	FOR(i,N) if(did[i]==0) return 0;
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	ll ret=(1LL<<60)-1;
	for(i=59;i>=0;i--) if(ok(ret-(1LL<<i))) ret-=1LL<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
