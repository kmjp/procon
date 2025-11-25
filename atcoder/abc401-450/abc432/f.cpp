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
int A[20];
ll S;

int dp[1<<20];
int from[1<<20];
vector<array<int,3>> ret;

void dfs(int cur) {
	if(from[cur]==cur) {
		vector<pair<int,int>> V;
		int i;
		FOR(i,N) if(cur&(1<<i)) V.push_back({A[i],i});
		sort(ALL(V));
		reverse(ALL(V));
		FOR(i,V.size()-1) {
			assert(V[i].first>0);
			ret.push_back({V[i].second+1,V[i+1].second+1,V[i].first});
			V[i+1].first+=V[i].first;
		}
		assert(V.back().first==0);
	}
	else {
		dfs(from[cur]);
		dfs(cur^from[cur]);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S+=A[i];
	}
	if(S%N) {
		cout<<-1<<endl;
		return;
	}
	FOR(i,N) A[i]-=S/N;
	
	MINUS(from);
	int mask;
	
	FOR(mask,1<<N) if(mask) {
		int sum=0;
		FOR(i,N) if(mask&(1<<i)) sum+=A[i];
		dp[mask]=-100;
		if(sum) continue;
		dp[mask]=1;
		from[mask]=mask;
		x=0;
		FOR(i,N) if(mask&(1<<i)) x=(1<<i);
		for(int sm=mask^x;sm>0;sm=(sm-1)&mask) {
			if(chmax(dp[mask],dp[sm]+dp[mask^sm])) {
				from[mask]=sm;
			}
		}
		//cout<<mask<<" "<<dp[mask]<<" "<<from[mask]<<endl;
	}
	if(dp[(1<<N)-1]<0) {
		cout<<-1<<endl;
		return;
	}
	dfs((1<<N)-1);
	cout<<ret.size()<<endl;
	FORR(a,ret) cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
