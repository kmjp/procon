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

int T;
int H,W;
int A[1010][1010];
ll dp[1010][1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) FOR(x,W) {
			cin>>A[y][x];
			dp[y][x]=1LL<<60;
		}
		dp[0][0]=0;
		queue<pair<int,int>> Q;
		Q.push({0,0});
		ll mi=1LL<<60;
		while(Q.size()) {
			int cy=Q.front().first;
			int cx=Q.front().second;
			Q.pop();
			ll co=dp[cy][cx];
			if(cx==W-1) {
				if(co%H<=(1+cy)%H) mi=min(mi,co+(1+cy)%H-co%H);
				if(co%H>(1+cy)%H) mi=min(mi,co+H+(1+cy)%H-co%H);
			}
			if(cx<W-1) {
				if(A[(cy+1)%H][cx+1]==0&&chmin(dp[(cy+1)%H][cx+1],co+1)) Q.push({(cy+1)%H,cx+1});
			}
			if(A[(cy+1)%H][cx]==0&&A[(cy+2)%H][cx]==0&&chmin(dp[(cy+2)%H][cx],co+1)) Q.push({(cy+2)%H,cx});
		}
		if(mi==1LL<<60) mi=-1;
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
