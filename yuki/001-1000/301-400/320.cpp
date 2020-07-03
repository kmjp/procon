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
ll M;
ll A[100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	A[1]=1;
	for(i=2;i<=90;i++) A[i]=A[i-1]+A[i-2];
	
	int num=0;
	ll diff=A[N]-M;
	for(i=3;i<=N;i++) {
		ll v=A[N-i+1];
		if(v<=diff) diff -= v, num++;
	}
	
	if(diff) return _P("-1\n");
	_P("%d\n",num);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
