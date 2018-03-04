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

int H,W,D,Q;
int A[303][303];
int dist[90909];

int DD[90909];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>D;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		DD[A[y][x]]=y*300+x;
	}
	for(i=1;i<=H*W;i++) {
		if(i+D>H*W) break;
		int cy=DD[i+D]/300;
		int cx=DD[i+D]%300;
		y=DD[i]/300;
		x=DD[i]%300;
		dist[i+D]=dist[i]+abs(y-cy)+abs(x-cx);
	}
	
	cin>>Q;
	int L,R;
	FOR(i,Q) {
		cin>>L>>R;
		cout<<dist[R]-dist[L]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
