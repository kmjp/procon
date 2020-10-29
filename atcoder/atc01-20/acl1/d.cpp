#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
ll X[202020];
int Q;
int L,R;
int le[21][202020];
int ri[21][202020];
ll LS[21][202020];
ll RS[21][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>X[i+1];
	X[0]=-1LL<<60;
	X[N+1]=1LL<<60;
	for(i=1;i<=N;i++) {
		ri[0][i]=lower_bound(X,X+N+2,X[i]+K)-X;
		le[0][i]=lower_bound(X,X+N+2,X[i]-K+1)-X-1;
		LS[0][i]=le[0][i];
		RS[0][i]=ri[0][i];
	}
	
	le[0][0]=0;
	ri[0][N+1]=N+1;
	FOR(j,20) {
		for(i=0;i<=N+1;i++) {
			le[j+1][i]=le[j][le[j][i]];
			ri[j+1][i]=ri[j][ri[j][i]];
			LS[j+1][i]=LS[j][i]+LS[j][le[j][i]];
			RS[j+1][i]=RS[j][i]+RS[j][ri[j][i]];
		}
	}
	
	
	cin>>Q;
	FOR(i,Q) {
		cin>>L>>R;
		ll dif=R-L+1;
		x=L,y=R;
		for(j=19;j>=0;j--) {
			if(ri[j][x]<=R) {
				dif+=LS[j][y]-RS[j][x]+(1<<j);
				x=ri[j][x];
				y=le[j][y];
			}
		}
		cout<<dif<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
