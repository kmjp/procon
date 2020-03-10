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

int W,H,SX,SY,GY,GX;
int N;

int dp[2010][4010];
vector<pair<short,short>> V[2020];
vector<pair<pair<short,short>,pair<short,short>>> E[1010][1010];

int nex(int now,int st,int per) {
	if(now<st) return st;
	if((now-st)%per==0) return now;
	else return now+(per-(now-st)%per);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>SX>>SY>>GX>>GY;
	cin>>N;
	FOR(i,N) {
		int T,X1,Y1,X2,Y2;
		cin>>X1>>Y1>>X2>>Y2>>T;
		int pe=2*((X2-X1)+(Y2-Y1));
		int cur=0;
		for(x=X1;x<X2;x++) V[i].push_back({x,Y1});
		for(y=Y1;y<Y2;y++) V[i].push_back({X2,y});
		for(x=X2;x>X1;x--) V[i].push_back({x,Y2});
		for(y=Y2;y>Y1;y--) V[i].push_back({X1,y});
		FOR(j,V[i].size()) {
			int cur=j-T;
			if(cur<0) cur+=pe;
			E[V[i][j].first][V[i][j].second].push_back(make_pair(make_pair(cur,pe),make_pair(1001+i,(j+1)%(int)V[i].size())));
		}
	}
	FOR(x,2001) FOR(y,4001) dp[x][y]=1<<30;
	dp[SX][SY]=0;
	priority_queue<pair<int,int>> Q;
	Q.push({0,SX*10000+SY});
	while(Q.size()) {
		int co=-Q.top().first;
		int cx=Q.top().second/10000;
		int cy=Q.top().second%10000;
		Q.pop();
		if(dp[cx][cy]!=co) continue;
		if(cx<1001) {
			FORR(e,E[cx][cy]) {
				int t=nex(dp[cx][cy],e.first.first,e.first.second)+1;
				x=e.second.first;
				y=e.second.second;
				if(dp[x][y]>t) {
					dp[x][y]=t;
					Q.push({-t,x*10000+y});
				}
			}
		}
		else {
			if(dp[cx][(cy+1)%V[cx-1001].size()]>co+1) {
				dp[cx][(cy+1)%V[cx-1001].size()]=co+1;
				Q.push({-(co+1),cx*10000+(cy+1)%V[cx-1001].size()});
			}
			x=V[cx-1001][cy].first;
			y=V[cx-1001][cy].second;
			if(dp[x][y]>co+1) {
				dp[x][y]=co+1;
				Q.push({-(co+1),x*10000+y});
			}
		}
	}
	cout<<dp[GX][GY]-1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
