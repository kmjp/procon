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
ll K,A[40100],B[65537];

ll num(ll v) {
	ll tot=0;
	int x,i;
	FOR(x,N) {
		int y=0;
		for(i=15;i>=0;i--) {
			int y2=y+(1<<i);
			if(y2>N) continue;
			if(A[x]*B[y2-1]<=v) y=y2;
		}
		tot+=y;
	}
	return tot;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	sort(A,A+N);
	sort(B,B+N);
	
	ll V=(1LL<<61)-1;
	for(i=60;i>=0;i--) if(num(V-(1LL<<i))>=K) V-=1LL<<i;
	cout<<V<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
