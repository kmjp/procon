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

int N,M,X;
int C[12],A[12][12];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>X;
	FOR(i,N) {
		cin>>C[i];
		FOR(x,M) cin>>A[i][x];
	}
	
	int mi=1<<30;
	int mask;
	FOR(mask,1<<N) {
		int sum=0;
		FOR(i,N) if(mask&(1<<i)) sum+=C[i];
		if(sum>=mi) continue;
		FOR(i,M) {
			int ok=0;
			FOR(j,N) if(mask&(1<<j)) ok+=A[j][i];
			if(ok<X) break;
		}
		if(i==M) mi=sum;
	}
	
	if(mi==1<<30) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
