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
int N,K,C;
string S;
int nex[18];
int ng[18][1<<18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>C>>K>>S;
		S=S.back()+S;
		N++;
		FORR(c,S) c-='A';
		FOR(i,C) {
			nex[i]=N+K+1;;
			FOR(x,1<<C) ng[i][x]=0;
		}
		for(i=N-1;i>=0;i--) {
			x=0;
			FOR(j,C) if(nex[j]-i<=K) x|=1<<j;
			nex[S[i]]=i;
			x=x^((1<<C)-1);
			if(i!=N-1) ng[S[i]][x]=1;
		}
		int mi=C;
		int ma;
		FOR(i,C) {
			FOR(j,C) {
				FOR(ma,1<<C) if(ma&(1<<j)) ng[i][ma^(1<<j)]|=ng[i][ma];
			}
		}
		FOR(ma,1<<C) if(ma&(1<<S[0])) {
			int pat=1;
			FOR(i,C) if((ma&(1<<i))&&ng[i][ma]) pat=0;
			if(pat) mi=min(mi,__builtin_popcount(ma));
		}
		cout<<mi<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
