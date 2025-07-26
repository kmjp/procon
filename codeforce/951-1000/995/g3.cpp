#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,Q;
vector<pair<int,int>> ev[20];
int las[20];
int sc[20][20];
int dp[1<<20][20];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) las[i]=1;
	FOR(i,Q) {
		int d;
		cin>>d>>s;
		if(s=="+") {
			ev[d-1].push_back({i,1});
			las[d-1]++;
		}
		else {
			ev[d-1].push_back({i,-1});
		}
	}
	FOR(x,N) FOR(y,N) if(x!=y) {
		int a=0,b=0;
		int MX=0,MY=0,ma=0;
		while(a<ev[x].size()||b<ev[y].size()) {
			if(a==ev[x].size()) {
				gob:
				if(ev[y][b].second==-1) {
					MY++;
				}
				b++;
			}
			else if(b==ev[y].size()) {
				goa:
				if(ev[x][a].second==1) {
					MX++;
				}
				ma=max(MX-MY,ma);
				a++;
			}
			else if(ev[x][a].first<ev[y][b].first) {
				goto goa;
			}
			else {
				goto gob;
			}
		}
		sc[x][y]=1+ma;
	}
	int mask;
	FOR(mask,1<<N) FOR(i,N) dp[mask][i]=1<<30;
	FOR(i,N) dp[1<<i][i]=0;
	FOR(mask,1<<N) FOR(i,N) if(dp[mask][i]<1<<30) {
		FOR(j,N) if((mask&(1<<j))==0) chmin(dp[mask|(1<<j)][j],dp[mask][i]+sc[i][j]);
	}
	int ret=1<<30;
	FOR(i,N) chmin(ret,dp[(1<<N)-1][i]+las[i]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
