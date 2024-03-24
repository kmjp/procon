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

int H,W,N;
int Y[2020],X[2020];

ll dp[2020][2020];
ll ret[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	Y[0]=X[0]=1;
	Y[1]=H;
	X[1]=W;
	FOR(i,N) {
		cin>>Y[2*i+2]>>X[2*i+2];
		cin>>Y[2*i+3]>>X[2*i+3];
	}
	N=N*2+2;
	FOR(y,N) FOR(x,N) dp[x][y]=abs(Y[y]-Y[x])+abs(X[y]-X[x]);
	FOR(i,N/2) dp[2*i+2][2*i+3]=1;
	FOR(i,N) ret[i]=1LL<<60;
	priority_queue<pair<ll,int>> Q;
	ret[0]=0;
	Q.push({0,0});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(ret[cur]!=co) continue;
		FOR(i,N) if(ret[i]>ret[cur]+dp[cur][i]) {
			ret[i]=ret[cur]+dp[cur][i];
			Q.push({-ret[i],i});
		}
	}
	cout<<ret[1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
