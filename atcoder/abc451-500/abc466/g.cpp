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
ll L[36],R[36],S[36];
int ma[36],vis[10];
const ll mo=998244353;
ll V[11];

map<vector<int>,ll> dp[31];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> V;
	cin>>N>>M;
	FOR(i,M) {
		cin>>L[i]>>R[i]>>S[i];
		L[i]--;
		S[i]-=R[i]-L[i];
		for(j=L[i];j<R[i];j++) {
			vis[j]=1;
			ma[i]|=1<<j;
		}
		V.push_back(S[i]);
	}
	
	
	dp[0][V]=1;
	int mask;
	FOR(i,30) {
		FORR2(a,b,dp[i]) {
			FOR(mask,1<<N) {
				vector<int> na;
				FOR(j,M) {
					int add=__builtin_popcount(mask&ma[j]);
					if(a[j]>=add&&(a[j]-add)%2==0) {
						na.push_back((a[j]-add)/2);
					}
					else {
						break;
					}
				}
				if(j==M) (dp[i+1][na]+=b)%=mo;
			}
		}
	}
	
	
	if(dp[30].size()) {
		FOR(i,N) if(vis[i]==0) {
			cout<<"Infinity"<<endl;
			return;
		}
		ll ret=dp[30].begin()->second;
		cout<<ret%mo<<endl;
	}
	else {
		cout<<0<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
