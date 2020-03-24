#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int H,W,K;
string S[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) cin>>S[y];
	int mi=1<<30;
	
	int mask;
	FOR(mask,(1<<(H-1))) {
		int to[10]={};
		int tar=0;
		FOR(i,H) {
			to[i]=tar;
			if(mask&(1<<i)) tar++;
		}
		tar++;
		int ret=__builtin_popcount(mask);
		int cnt[10]={};
		FOR(x,W) {
			FOR(y,H) {
				if(S[y][x]=='1') cnt[to[y]]++;
			}
			int ng=0;
			FOR(i,tar) if(cnt[i]>K) {
				ret++;
				FOR(y,tar) cnt[y]=0;
				FOR(y,H) if(S[y][x]=='1') cnt[to[y]]++;
				break;
			}
			FOR(i,tar) if(cnt[i]>K) ret=1LL<<30;
		}
		mi=min(mi,ret);
		
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
