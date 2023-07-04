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

int H,W,K,T;
int C[88][88];
int D[88][88];

ll dp[88][88][333];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K>>T;
	FOR(i,K) {
		cin>>y>>x>>j>>k;
		y--,x--;
		C[y][x]=j;
		D[y][x]=k;
	}
	FOR(y,H) FOR(x,W) FOR(i,333) dp[y][x][i]=1LL<<60;
	
	priority_queue<pair<ll,ll>> Q;
	dp[0][0][160]=0;
	Q.push({0,900-160});
	
	while(Q.size()) {
		ll co=-Q.top().first;
		int cy=Q.top().second/100000;
		int cx=Q.top().second/1000%100;
		int ct=900-Q.top().second%1000;
		Q.pop();
		if(dp[cy][cx][ct]!=co) continue;
		if(cy==H-1&&cx==W-1&&ct-160<=T) {
			cout<<co<<endl;
			return;
		}
		if(C[cy][cx]) {
			int nt=max(0,ct-C[cy][cx]+1);
			if(chmin(dp[cy][cx][nt],co+D[cy][cx])) {
				Q.push({-dp[cy][cx][nt],cy*100000+cx*1000+900-nt});
			}
		}
		int d[4]={1,0,-1,0};
		FOR(i,4) {
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			int nt=ct+1;
			if(nt>320||ty<0||ty>=H||tx<0||tx>=W) continue;
			if(chmin(dp[ty][tx][nt],co)) {
				Q.push({-dp[ty][tx][nt],ty*100000+tx*1000+900-nt});
			}
		}
		
	}
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
