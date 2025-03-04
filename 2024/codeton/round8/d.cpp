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

int T,N,K;
int A[1010][1010];
ll dp[1050][5050];
ll dp2[1050][5050];
int id[1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(y,N) {
			for(x=y;x<N;x++) cin>>A[y][x];
		}
		FOR(i,N+2) FOR(j,K+2) dp[i][j]=dp2[i][j]=-1LL<<60;
		dp[0][0]=0;
		FOR(i,N) {
			//切れる物を狙う
			if(i>=1) {
				priority_queue<pair<ll,int>> V;
				FOR(j,i) {
					id[j]=0;
					V.push({dp2[j+1][0]+A[j][i-1],j});
				}
				FOR(j,K) {
					auto p=V.top();
					V.pop();
					dp[i+1][j]=p.first;
					x=p.second;
					id[x]++;
					V.push({dp2[x+1][id[x]]+A[x][i-1],x});
				}
			}
			//新規スタート
			priority_queue<pair<ll,int>> V;
			FOR(j,i+1) {
				id[j]=0;
				V.push({dp[j][0],j});
			}
			FOR(j,K) {
				auto p=V.top();
				V.pop();
				dp2[i+1][j]=p.first;
				x=p.second;
				id[x]++;
				V.push({dp[x][id[x]],x});
			}
		}
		
		vector<ll> ret;
		{
			priority_queue<pair<ll,int>> V;
			FOR(i,N+1) {
				id[i]=0;
				V.push({dp[i][0],i});
			}
			FOR(j,K) {
				auto p=V.top();
				V.pop();
				ret.push_back(p.first);
				x=p.second;
				id[x]++;
				V.push({dp[x][id[x]],x});
			}
		}
		{
			priority_queue<pair<ll,int>> V;
			for(i=1;i<=N;i++) {
				id[i]=0;
				V.push({dp2[i][0]+A[i-1][N-1],i});
			}
			FOR(j,K) {
				auto p=V.top();
				V.pop();
				ret.push_back(p.first);
				x=p.second;
				id[x]++;
				V.push({dp2[x][id[x]]+A[x-1][N-1],x});
			}
		}
		sort(ALL(ret));
		reverse(ALL(ret));
		FOR(i,K) cout<<ret[i]<<" ";
		
		
		cout<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
