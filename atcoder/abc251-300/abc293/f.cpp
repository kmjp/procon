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
ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll ret=0;
		for(i=2;i<=100;i++) {
			int ok=1;
			ll v=N;
			while(v) {
				if(v%i>1) ok=0;
				v/=i;
			}
			if(ok) ret++;
		}
		int mask;
		FOR(mask,1<<10) if(mask) {
			ll L=1,R=N+1;
			while(L+1<R) {
				ll M=(L+R)/2;
				__int128 v=0,mp=1;
				FOR(i,10) {
					if(mask&(1<<i)) v+=mp;
					if(v>N) break;
					mp=min(mp*M,(__int128)(1LL<<60));
				}
				if(v>=N) R=M;
				else L=M;
			}
			ll M=L+1;
			__int128 v=0,mp=1;
			FOR(i,10) {
				if(mask&(1<<i)) v+=mp;
				if(v>N) break;
				mp=min(mp*M,(__int128)(1LL<<60));
			}
			if(v==N&&M>100) ret++;
			
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
