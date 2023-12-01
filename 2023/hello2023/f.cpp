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

int N,A[202020];
int P[202020];
vector<int> E[202020];
int C[202020];

vector<int> dp[202020][32];
vector<int> ret;

void dfs(int cur,int v) {
	if(dp[cur][v].back()==33) {
		ret.push_back(cur);
		ret.push_back(cur);
		return;
	}
	int k=E[cur].size();
	while(k) {
		int y=dp[cur][v][k];
		dfs(E[cur][k-1],y);
		k--;
		v^=y;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>P[i+1];
		P[i+1]--;
		E[P[i+1]].push_back(i+1);
	}
	
	for(i=N-1;i>=0;i--) {
		FOR(j,32) dp[i][j].resize(E[i].size()+1,-1);
		dp[i][A[i]][0]=0;
		C[i]=1;
		FOR(j,E[i].size()) {
			k=E[i][j];
			C[i]+=C[k];
			FOR(x,32) if(dp[i][x][j]!=-1) {
				FOR(y,32) if(dp[k][y].back()!=-1) {
					dp[i][x^y][j+1]=y;
				}
			}
		}
		if(C[i]%2==0) {
			dp[i][0].back()=33;
		}
	}
	
	if(dp[0][0].back()==-1) {
		cout<<-1<<endl;
	}
	else {
		dfs(0,0);
		if(N%2) ret.push_back(0);
		cout<<ret.size()<<endl;
		FORR(r,ret) cout<<r+1<<" ";
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
