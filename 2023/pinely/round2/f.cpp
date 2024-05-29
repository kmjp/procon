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

int T,N;
ll A[10101];
ll X[10101];
ll Lmask[10101],Rmask[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		set<int> G;
		FOR(i,N) {
			cin>>A[i];
			X[i+1]=X[i]^A[i];
			G.insert(i);
		}
		FOR(i,N+1) {
			Lmask[i]=Rmask[i]=0;
		}
		
		for(int len=N;len>=1;len--) {
			for(int L=0;L+len<=N;L++) {
				ll v=X[L+len]^X[L];
				int ok=(len==N)||(v&Lmask[L])||(v&Rmask[L+len]);
				if(Lmask[L]&(1LL<<61)) ok=1;
				if(Rmask[L+len]&(1LL<<61)) ok=1;
				if(len==1) {
					cout<<ok;
					continue;
				}
				if(ok==0) continue;
				if(v==0) {
					Lmask[L]|=1LL<<61;
					Rmask[L+len]|=1LL<<61;
				}
				else {
					x=63-__builtin_clzll(v);
					ll w=1LL<<x;
					Lmask[L]|=w;
					Rmask[L+len]|=w;
				}
			}
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
