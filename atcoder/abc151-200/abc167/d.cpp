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
ll K;
int A[202020][70];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	for(i=1;i<=N;i++) cin>>A[i][0];
	
	int cur=1;
	FOR(i,60) {
		for(j=1;j<=N;j++) A[j][i+1]=A[A[j][i]][i];
		if(K&(1LL<<i)) cur=A[cur][i];
	}
	
	cout<<cur<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
