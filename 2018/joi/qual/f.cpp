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


int N,K;
ll L;
int A[202020];
int B[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>L;
	FOR(i,N) cin>>A[i];
	int ret=1<<20;
	for(x=19;x>=0;x--) {
		int tmp=ret-(1<<x);
		ll num=0;
		
		FOR(i,N) B[i+1]=B[i]+(A[i]<=tmp);
		FOR(i,N) {
			y=lower_bound(B,B+N+1,B[i]+K)-B;
			num+=(N+1-y);
		}
		if(num>=L) ret=tmp;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
