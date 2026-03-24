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

int T,N,A[303030];
vector<int> cand[303030];
int dp[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cand[i].clear();
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
			cand[A[i]].push_back(i);
		}
		int pre=0;
		FOR(i,N) {
			reverse(ALL(cand[i]));
			int cur=pre;
			if(i) {
				x=0;
				FORR(a,cand[i]) {
					while(x<cand[i-1].size()&&cand[i-1][x]>a) {
						cur=max(cur,dp[cand[i-1][x++]]);
					}
					cur=dp[a]=cur+1;
				}
				FORR(a,cand[i-1]) pre=max(pre,dp[a]);
			}
			else {
				cur=0;
				FORR(a,cand[i]) {
					dp[a]=++cur;
				}
			}
		}
		int ret=0;
		FOR(i,N) {
			ret=max(ret,dp[i]);
		}
		cout<<N-ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
