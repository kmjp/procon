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
ll A[202020];
int B[22];
int C[22];
pair<int,int> P[202020];
vector<int> R[120];

int mi[21][202020];
pair<int,int> step[21][202020];

int dp[1<<20];
pair<int,int> from[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i];
		P[i]={A[i],i};
	}
	sort(P,P+N);
	
	FOR(i,M) {
		cin>>B[i];
		mi[i][N]=N+1;
		for(j=N-1;j>=0;j--) {
			y=P[j].first;
			x=(B[i]+y-1)/y;
			mi[i][j]=j+x;
			step[i][j]={j,x};
			if(mi[i][j+1]<mi[i][j]) {
				mi[i][j]=mi[i][j+1];
				step[i][j]=step[i][j+1];
			}
		}
	}
	int mask;
	FOR(mask,1<<M) dp[mask]=N+1;
	dp[0]=0;
	FOR(mask,1<<M) if(dp[mask]<N) {
		FOR(i,M) if((mask&(1<<i))==0) {
			if(chmin(dp[mask|(1<<i)],mi[i][dp[mask]])) {
				from[mask|(1<<i)]={mask,dp[mask]};
			}
		}
	}
	
	if(dp[(1<<M)-1]==N+1) {
		cout<<"NO"<<endl;
		return;
	}
	else {
		cout<<"YES"<<endl;
		int cur=dp[(1<<M)-1];
		mask=(1<<M)-1;
		while(cur) {
			x=from[mask].first;
			cur=from[mask].second;
			FOR(i,M) if((mask^x)&(1<<i)) {
				FOR(j,step[i][cur].second) R[i].push_back(P[j+step[i][cur].first].second+1);
			}
			mask=x;
		}
	}
	
	
	FOR(i,M) {
		sort(ALL(R[i]));
		cout<<R[i].size();
		FORR(r,R[i]) cout<<" "<<r;
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
