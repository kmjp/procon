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
int N,K;
ll dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		map<int,vector<int>> M;
		FOR(i,N) {
			cin>>x;
			M[x%K].push_back(x/K);
		}
		int odd=0;
		FORR2(a,b,M) if(b.size()%2) odd++;
		if(odd>1||odd!=N%2) {
			cout<<-1<<endl;
			continue;
		}
		ll sum=0;
		FORR2(a,b,M) {
			sort(ALL(b));
			if(b.size()%2==0) {
				for(i=0;i<b.size();i+=2) sum+=b[i+1]-b[i];
			}
			else {
				x=b.size();
				FOR(i,x+2) dp[i]=1LL<<60;
				dp[0]=0;
				FOR(i,x) {
					if(i%2==0) {
						dp[i+1]=min(dp[i+1],dp[i]);
					}
					dp[i+2]=min(dp[i+2],dp[i]+b[i+1]-b[i]);
				}
				sum+=dp[x];
				
			}
		}
		cout<<sum<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
