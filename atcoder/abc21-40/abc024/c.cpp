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

int N,D,K;
int L[10100],R[10100];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D>>K;
	FOR(i,D) cin>>L[i]>>R[i];
	while(K--) {
		cin>>x>>y;
		int ret=0;
		FOR(i,D) {
			if(x<L[i] || R[i]<x) continue;
			if(x>y) x=max(L[i],y);
			if(x<y) x=min(R[i],y);
			
			if(x==y) {
				_P("%d\n",i+1);
				break;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
