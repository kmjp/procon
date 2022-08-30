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
int N;
ll K;
ll dp[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=100000;i++) {
		dp[i]=1;
		for(j=1;j<i;j++) {
			dp[i]+=dp[j];
			if(dp[i]>=1LL<<60) {
				dp[i]==1LL<<60;
				break;
			}
		}
	}
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		if(K>dp[N]) {
			cout<<-1<<endl;
			continue;
		}
		
		vector<int> V;
		for(i=1;i<=N;) {
			for(j=1;i+j<=N;j++) {
				if(dp[N-(i-1)-j]<K) {
					K-=dp[N-(i-1)-j];
				}
				else {
					break;
				}
			}
			FOR(x,j) V.push_back(i+j-1-x);
			i+=j;
		}
		FORR(v,V) cout<<v<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
