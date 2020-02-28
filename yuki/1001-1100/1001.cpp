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
vector<int> V[2];

ll dp[3030][3030];
const ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		V[x].push_back(y-1);
	}
	
	dp[0][0]=1;
	FOR(i,N) {
		int cand0=0;
		int cand1=0;
		FORR(v,V[0]) cand0+=v>=i;
		FORR(v,V[1]) cand1+=i>=v;
		FOR(x,V[0].size()+1) {
			y=i-x;
			if(y<0||y>V[1].size()) continue;
			if(x<V[0].size()) (dp[x+1][y]+=dp[x][y]*(cand0-(V[0].size()-x-1)))%=mo;
			if(y<V[1].size()) (dp[x][y+1]+=dp[x][y]*(cand1-y))%=mo;
		}
	}
	ll ret=0;
	FOR(i,N+1) ret+=dp[i][N-i];
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
