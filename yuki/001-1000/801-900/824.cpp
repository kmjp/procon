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
ll from[302][302][2];
ll to[302][302][2];
ll mo=1000000007;
ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	for(i=1;i<=min(N,K);i++) from[i-1][i][0]++;
	from[K][K+1][1]=1;
	FOR(i,K) {
		ZERO(to);
		for(x=0;x<=K;x++) for(y=x+1;y<=K+1;y++) FOR(j,2) {
			if(x==0) {
				// take y
				if(y-1>x) (to[x][y-1][j]+=from[x][y][j])%=mo;
				// other
				(to[x][y][j]+=from[x][y][j]*(N-1))%=mo;
			}
			else {
				// take x;
				(to[x-1][y][j]+=from[x][y][j])%=mo;
				// take y
				if(y-1>x) (to[x][y-1][j]+=from[x][y][j])%=mo;
				// other
				(to[x][y][j]+=from[x][y][j]*(N-2))%=mo;
			}
		}
		
		swap(from,to);
	}
	
	for(x=0;x<=K;x++) for(y=x+1;y<=K;y++) (ret+=y*from[x][y][0])%=mo;
	for(y=1;y<=K+1;y++) {
		ll pat=0;
		for(x=0;x<y;x++) pat+=from[x][y][1];
		pat%=mo;
		for(i=K+1;i<=N;i++) (ret+=pat*(i-(K+1-y)))%=mo;
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
