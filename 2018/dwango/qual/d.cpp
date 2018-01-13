#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int X[2020];
int S[1<<20];
int P[20];
int D[20];
vector<int> E[20];
int vis[1<<20];

int ok(int v) {
	ZERO(vis);
	queue<int> Q;
	vis[0]=1;
	Q.push(0);
	
	while(Q.size()) {
		int mask=Q.front();
		Q.pop();
		if(mask&1) return 1;
		
		int i;
		FOR(i,N) if(vis[mask^(1<<i)]==0) {
			if(mask&(1<<i)) {
				vis[mask^(1<<i)]=1;
				Q.push(mask^(1<<i));
			}
			else if((mask&D[i])==D[i] && S[mask^(1<<i)]<=v) {
				vis[mask^(1<<i)]=1;
				Q.push(mask^(1<<i));
			}
		}
	}
	return 0;
	
	
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i];
	for(i=1;i<N;i++) {
		cin>>P[i];
		P[i]--;
		E[P[i]].push_back(i);
		D[P[i]] |= 1<<i;
	}
	int mask;
	FOR(mask,1<<N) {
		FOR(i,N) if(mask&(1<<i)) S[mask] += X[i];
	}
	
	int mi=(1<<28);
	for(i=27;i>=0;i--) {
		if(ok(mi-(1<<i))) mi-=1<<i;
	}
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
