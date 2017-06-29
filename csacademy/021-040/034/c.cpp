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
int A[101010];
int nex[101010][30];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int tot=0;
	FOR(i,N) {
		cin>>A[i];
		tot |= A[i];
	}
	
	if(tot==0) return _P("1\n");
	
	FOR(i,30) nex[N][i]=N;
	int mi=N;
	for(i=N-1;i>=0;i--) {
		int mip=i;
		FOR(j,30) if(tot&(1<<j)) {
			nex[i][j]=nex[i+1][j];
			if(A[i]&(1<<j)) nex[i][j]=i;
			mip=max(mip,nex[i][j]);
		}
		if(mip<N) mi=min(mi,mip+1-i);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
