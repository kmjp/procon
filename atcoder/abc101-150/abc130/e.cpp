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

int N,M;
int S[2020];
int T[2020];
ll num[2020][2020];
ll sum[2020][2020];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>S[i];
	FOR(i,M) cin>>T[i];
	
	FOR(x,2020) sum[x][0]=sum[0][x]=1;
	ll ret=1;
	FOR(x,N) FOR(y,M) {
		if(S[x]==T[y]) {
			num[x+1][y+1]=(sum[x][y])%mo;
			ret+=num[x+1][y+1];
		}
		sum[x+1][y+1]=(sum[x][y+1]+sum[x+1][y]+mo-sum[x][y]+num[x+1][y+1])%mo;
	}
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
