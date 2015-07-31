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

int N;
int V[1010];
int ma[2020];
int from[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>V[i];
	for(i=N-1;i>=0;i--) {
		for(x=i+2;x<N+2;x++) if(ma[i]<ma[x]+V[i]) {
			ma[i]=ma[x]+V[i];
			from[i]=x;
		}
	}
	
	int id=0;
	FOR(i,N) if(ma[i]>ma[id]) id=i;
	
	_P("%d\n",ma[id]);
	while(1) {
		_P("%d",id+1);
		id=from[id];
		if(id>=N) {
			_P("\n");
			break;
		}
		_P(" ");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
