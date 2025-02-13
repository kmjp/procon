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

int N,M;
int P[101010];
vector<pair<int,double>> E[101010];
int in[202020];
double dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>P[i];
		dp[i]=-1e10;
	}
	FOR(i,M) {
		double d;
		cin>>x>>y>>d;
		E[y-1].push_back({x-1,d});
		in[x-1]++;
	}
	dp[N-1]=P[N-1];
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		FORR2(e,p,E[cur]) {
			if(dp[cur]>=0) chmax(dp[e],dp[cur]*p+P[e]);
			in[e]--;
			if(in[e]==0) Q.push(e);
		}
	}
	if(dp[0]<0) {
		cout<<-1<<endl;
	}
	else {
		_P("%.12lf\n",dp[0]);
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
