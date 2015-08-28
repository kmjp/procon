#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int L[2020],R[2020];
int vis[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>L[i]>>R[i];
	
	int left=0;
	FOR(i,N) {
		int y=-1;
		FOR(x,N) if(vis[x]==0) {
			
			if(M-1-R[x]<L[x]) {
				L[x]=M-1-L[x];
				R[x]=M-1-R[x];
				swap(L[x],R[x]);
			}
			
			if(left>L[x]) {
				L[x]=M-1-L[x];
				R[x]=M-1-R[x];
				swap(L[x],R[x]);
			}
			if(left>L[x]) return _P("NO\n");
			if(y==-1 || L[x]<L[y]) y=x;
		}
		if(y==-1) return _P("NO\n");
		left=R[y]+1;
		vis[y]=1;
	}
	_P("YES\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
