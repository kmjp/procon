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
int X[101010],Y[101010],Z[101010];
vector<int> ev[303030];

map<int,int> M;
int ng[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	M[-1]=1<<20;
	M[1<<20]=-1;
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>Z[i];
		ev[Z[i]].push_back(i);
	}
	
	for(i=10000;i>=0;i--) if(ev[i].size()) {
		FORR(e,ev[i]) {
			auto it=M.lower_bound(X[e]);
			if(it->second>=Y[e]) ng[e]=1;
		}
		FORR(e,ev[i]) {
			x=X[e];
			y=Y[e];
			auto k=M.lower_bound(x);
			if(k->second>=y) continue;
			while(prev(M.lower_bound(x))->second<=y) M.erase(prev(M.lower_bound(x)));
			M[x]=y;
		}
		FORR(e,ev[i]) {
			auto it=M.lower_bound(X[e]);
			if(it->second>Y[e]) ng[e]=1;
			it=M.lower_bound(X[e]+1);
			if(it->second>=Y[e]) ng[e]=1;
		}
	}
	
	
	FOR(i,N) if(ng[i]==0) cout<<(i+1)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
