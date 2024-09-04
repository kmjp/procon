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

int T,N,M;
vector<int> E[5555];
vector<int> RE[5555];
double dp[5050];

double hoge(vector<double> D) {
	static double dp[5050][5050];
	int N=D.size();
	int i,j,x,y;
	FOR(i,N+2) FOR(j,N+2) dp[i][j]=0;
	dp[0][0]=1;
	double ret=0;
	FOR(x,N) {
		FOR(y,N) if(dp[x][y]) {
			int lef=N-x;
			if(y>=lef) continue;
			//‰ó‚³‚ê‚½
			if(y) {
				dp[x+1][y-1]+=dp[x][y]*y/lef;
			}
			double can=dp[x][y]*(lef-y)/lef;
			//—¼•û‘I‘ð‚µ‚½
			ret+=can/(lef-y)*D[x];
			//‚¸‚ê‚½
			dp[x+1][y+1]+=can*(lef-y-1)/(lef-y);
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			E[i].clear();
			RE[i].clear();
			dp[i]=0;
		}
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			RE[y-1].push_back(x-1);
		}
		dp[N-1]=1;
		for(i=N-2;i>=0;i--) if(E[i].size()) {
			vector<double> D;
			FORR(e,E[i]) D.push_back(dp[e]);
			sort(ALL(D));
			reverse(ALL(D));
			dp[i]=hoge(D);
		}
		_P("%.12lf\n",dp[0]);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
