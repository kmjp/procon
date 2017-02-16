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

int Q;
ll L,C;
vector<int> V;
ll mi[101010];
ll ma[101010];

void hoge(int A,int B,ll C) {
	int i;
	if(B<A) return;
	C-=B-A;
	
	for(int i=0;i<=B-A;i++) {
		int x=i;
		int y=B-A+1-1-i;
		if(mi[x]+mi[y]<=C && ma[x]+ma[y]>=C) {
			ll D=max(mi[x],C-ma[y]);
			_P("%d ",A+i);
			hoge(A,A+i-1,D);
			hoge(A+i+1,B,C-D);
			return;
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=2;i<=100100;i++) {
		ma[i]=(i-1)+ma[i-1];
		mi[i]=(i-1)+mi[(i-1)/2]+mi[(i-1)-(i-1)/2];
	}
	
	cin>>Q;
	while(Q--) {
		cin>>L>>C;
		if(C<mi[L] || ma[L]<C) {
			_P("-1\n");
		}
		else {
			hoge(1,L,C);
			_P("\n");
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
