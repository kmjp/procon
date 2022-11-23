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

int N;
int X;
int Y[2020],Z[2020];
ll dp[5050][5050][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	vector<pair<int,int>> V;
	V.push_back({0,0});
	V.push_back({X,0});
	FOR(i,N) {
		cin>>Y[i+1];
		V.push_back({Y[i+1],-(i+1)});
	}
	FOR(i,N) {
		cin>>Z[i+1];
		V.push_back({Z[i+1],(i+1)});
	}
	sort(ALL(V));
	FOR(x,2*N+2) FOR(y,2*N+2) dp[x][y][0]=dp[x][y][1]=1LL<<60;
	FOR(i,2*N+2) if(V[i].first==0) dp[i][i][0]=dp[i][i][1]=0;
	ll ret=1LL<<60;
	for(int len=0;len<=2*N+2;len++) {
		for(int L=0;L<2*N+2;L++) {
			int R=L+len;
			if(R>=2*N+2) break;
			if(V[L].first==X) ret=min(ret,dp[L][R][0]);
			if(V[R].first==X) ret=min(ret,dp[L][R][1]);
				
			if(L) {
				if(V[L-1].second<0) {
					if(Z[-V[L-1].second]>=V[L].first&&Z[-V[L-1].second]<=V[R].first) {
						dp[L-1][R][0]=min(dp[L-1][R][0],dp[L][R][0]+V[L].first-V[L-1].first);
						dp[L-1][R][0]=min(dp[L-1][R][0],dp[L][R][1]+V[R].first-V[L-1].first);
					}
				}
				else {
					dp[L-1][R][0]=min(dp[L-1][R][0],dp[L][R][0]+V[L].first-V[L-1].first);
					dp[L-1][R][0]=min(dp[L-1][R][0],dp[L][R][1]+V[R].first-V[L-1].first);
				}
			}
			if(R+1<2*N+2) {
				if(V[R+1].second<0) {
					if(Z[-V[R+1].second]>=V[L].first&&Z[-V[R+1].second]<=V[R].first) {
						dp[L][R+1][1]=min(dp[L][R+1][1],dp[L][R][0]+V[R+1].first-V[L].first);
						dp[L][R+1][1]=min(dp[L][R+1][1],dp[L][R][1]+V[R+1].first-V[R].first);
					}
				}
				else {
					dp[L][R+1][1]=min(dp[L][R+1][1],dp[L][R][0]+V[R+1].first-V[L].first);
					dp[L][R+1][1]=min(dp[L][R+1][1],dp[L][R][1]+V[R+1].first-V[R].first);
				}
			}
		}
	}
	if(ret==1LL<<60) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
