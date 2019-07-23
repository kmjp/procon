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
ll mo=1000000007;
ll pat[55][55][5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>K;
	
	pat[0][0][0]=1;
	for(i=1;i<=N;i++) {
		FOR(x,i) FOR(y,N*N) if(pat[i-1][x][y]) {
			ll v=pat[i-1][x][y];
			// close
			if(x) (pat[i][x-1][y+2*x]+=v*(x*x))%=mo;
			// open
			(pat[i][x+1][y+2*x]+=v)%=mo;
			// concat+self
			(pat[i][x][y+2*x]+=v*(2*x+1))%=mo;
		}
		
	}
	cout<<pat[N][0][K]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
