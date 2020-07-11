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

int N,M,K;
vector<pair<int,int>> nex[303];

ll from[303][303];
ll to[303][303];

const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y>>r;
		nex[x-1].push_back({y-1,r});
	}
	
	FOR(i,300) from[i][K]=1;
	FOR(i,N-1) {
		ZERO(to);
		FOR(x,300) FOR(y,301) if(from[x][y]) {
			FORR(n,nex[x]) {
				if(n.second<=y) (to[n.first][y-n.second]+=from[x][y])%=mo;
			}
		}
		swap(from,to);
	}
	
	ll ret=0;
	FOR(i,300) ret+=from[i][0];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
