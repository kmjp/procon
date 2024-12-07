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

int T,N,M;
vector<int> add[1010101],del[10101010];
int dp[1010101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N+1) add[i].clear(),del[i].clear(),dp[i]=0;
		FOR(i,M) {
			cin>>x>>y;
			add[x].push_back(y);
			del[y].push_back(x);
		}
		multiset<int> L,R;
		for(i=1;i<=N;i++) {
			dp[i]=max(dp[i],dp[i-1]);
			FORR(a,add[i]) {
				L.insert(i);
				R.insert(a);
			}
			if(L.size()) {
				chmax(dp[i],dp[*L.begin()-1]+(int)L.size());
			}
			FORR(a,del[i]) {
				L.erase(L.find(a));
				R.erase(R.find(i));
			}
		}
		cout<<dp[N]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
