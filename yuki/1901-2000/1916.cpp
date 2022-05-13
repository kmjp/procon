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

int H,W;
string S[202];

const ll mo=1000000007;
ll dp[202][202][202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	if(S[0][0]!=S[H-1][W-1]) {
		cout<<0<<endl;
		return;
	}
	
	int y1,y2;
	dp[0][0][H-1]=1;
	FOR(i,(H+W-2)/2) {
		FOR(y1,H) FOR(y2,H) {
			int x1=i-y1;
			if(x1<0||x1>=W) continue;
			int x2=(H+W-2-i)-y2;
			if(x2<0||x2>=W) continue;
			
			vector<pair<int,int>> C1,C2;
			if(y1<H-1) C1.push_back({S[y1+1][x1],y1+1});
			if(x1<W-1) C1.push_back({S[y1][x1+1],y1});
			if(y2>0) C2.push_back({S[y2-1][x2],y2-1});
			if(x2>0) C2.push_back({S[y2][x2-1],y2});
			FORR2(c1,yy1,C1) FORR2(c2,yy2,C2) {
				if(c1==c2) (dp[i+1][yy1][yy2]+=dp[i][y1][y2])%=mo;
			}
		}
	}
	
	ll ret=0;
	FOR(y1,H) FOR(y2,H) {
		if((H+W)%2==0) {
			if(y1==y2) ret+=dp[(H+W-2)/2][y1][y2];
		}
		else {
			if(y1==y2||y1+1==y2) ret+=dp[(H+W-2)/2][y1][y2];
		}
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
