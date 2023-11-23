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
int N,P[1010],R[1010];
const ll mo=1000000007;
vector<int> E[1010];
ll dp[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		ZERO(R);
		cin>>N;
		FOR(i,N) {
			cin>>P[i];
		}
		ll ret=0;
		FOR(i,2) {
			vector<int> V;
			FOR(j,N) E[j].clear();
			FOR(j,N) if(j%2==i) {
				R[j]=V.size();
				V.push_back(P[j]);
			}
			int B=V.size();
			for(j=N-1;j>=0;j--) if(j%2!=i) {
				R[j]=V.size();
				if(j) E[R[j]].push_back(R[j-1]);
				if(j+1<N) E[R[j]].push_back(R[j+1]);
				V.push_back(P[j]);
			}
			
			FOR(x,N+1) FOR(y,N+1) dp[x][y]=0;
			FOR(x,N) if(x<B&&(V[x]==-1||V[x]==N)) dp[x][1]=1;
			for(int len=1;len<N;len++) {
				int nex=N-len;
				FOR(x,N) {
					//¶‚ÉL‚Î‚·
					if(V[(x+N-1)%N]==-1||V[(x+N-1)%N]==nex) {
						int ok=1;
						FORR(e,E[(x+N-1)%N]) {
							int o=0;
							if(x<=e&&e<x+len) o=1;
							if(x<=e+N&&e+N<x+len) o=1;
							ok&=o;
						}
						if(ok) (dp[(x+N-1)%N][len+1]+=dp[x][len])%=mo;
					}
					if(len==N-1) continue;
					//‰E‚ÉL‚Î‚·
					if(V[(x+len)%N]==-1||V[(x+len)%N]==nex) {
						int ok=1;
						FORR(e,E[(x+len)%N]) {
							int o=0;
							if(x<=e&&e<x+len) o=1;
							if(x<=e+N&&e+N<x+len) o=1;
							ok&=o;
						}
						if(ok) (dp[x][len+1]+=dp[x][len])%=mo;
					}
				}
			}
			FOR(j,N) ret+=dp[j][N];
		}
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
