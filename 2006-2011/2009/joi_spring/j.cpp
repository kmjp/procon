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

int N,M;
int A[101010];
vector<int> E[10101];
vector<ll> V[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x>>A[i];
		if(x) E[x-1].push_back(i);
	}
	
	for(i=N-1;i>=0;i--) {
		if(E[i].empty()) {
			V[i]={0,A[i]};
		}
		else {
			V[i]={0};
			FORR(e,E[i]) {
				vector<ll> W(V[i].size()+V[e].size()-1);
				if(W.size()>M+1) W.resize(M+1);
				FOR(x,V[i].size()) FOR(y,V[e].size()) {
					if(x+y>=W.size()) break;
					W[x+y]=max(W[x+y],V[i][x]+V[e][y]);
				}
				swap(W,V[i]);
			}
			for(x=1;x<V[i].size();x++) V[i][x]+=A[i];
		}
	}
	ll ret=0;
	FOR(i,min((int)V[0].size(),M+1)) ret=max(ret,V[0][i]);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
