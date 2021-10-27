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

int N,D;
int P[1010],Q[1010];

int ok(ll v) {
	int dp[1010];
	int i,j;
	FOR(i,N+1) dp[i]=-1<<30;
	FOR(i,D) {
		vector<pair<int,int>> C;
		if(i==0) {
			C.push_back({0,N});
		}
		else {
			C.push_back({1<<30,N});
		}
		FOR(j,N) if(dp[j]>=-1<<29) {
			C.push_back({-dp[j],j});
		}
		sort(ALL(C));
		FOR(j,N) {
			int tar=(C[0].second==j);
			if(-C[tar].first-P[j]<v) {
				dp[j]=-1<<30;
			}
			else {
				dp[j]=-C[tar].first-P[j]+Q[j];
			}
		}
		
	}
	FOR(i,N) if(dp[i]>=v) return 1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	FOR(i,N) cin>>P[i]>>Q[i];
	ll ret=-1LL<<28;
	for(i=28;i>=0;i--) if(ok(ret+(1LL<<i))) ret+=1LL<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
