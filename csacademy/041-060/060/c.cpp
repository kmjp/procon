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

int N,M,K;
vector<int> V[101010];
vector<int> E[101010];
int in[101010];
int ret[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>M;
	FOR(i,N) {
		FOR(j,M) {
			cin>>x;
			V[i].push_back(x);
		}
	}
	
	FOR(i,N-1) {
		FOR(j,M) {
			if(V[i][j]!=V[i+1][j]) {
				E[V[i][j]].push_back(V[i+1][j]);
				in[V[i+1][j]]++;
				break;
			}
		}
		if(j==M) return _P("-1\n");
	}
	
	set<int> cand;
	int id=0;
	FOR(i,K) if(in[i]==0) cand.insert(i);
	while(cand.size()) {
		int nex=*cand.begin();
		if(id==0 && V[0][0]==nex) {
			nex=*cand.rbegin();
			if(V[0][0]==nex) return _P("-1");
		}
		ret[nex]=id++;
		cand.erase(nex);
		FORR(e,E[nex]) {
			in[e]--;
			if(in[e]==0) cand.insert(e);
		}
	}
	
	
	if(id!=K) return _P("-1\n");
	FOR(i,K) _P("%d%c",ret[i],(i==K-1)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
