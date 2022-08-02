
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

int N,A[55];
int tma[55][55][55];
int tmi[55][55][55];
int memo[55][55][55][55];

int hoge(int L,int R,int mi,int ma) {
	if(L>=R) return 0;
	mi=tmi[L][R][mi];
	ma=tma[L][R][ma];
	if(mi>ma) return 0;
	if(memo[L][R][mi][ma]>=0) return memo[L][R][mi][ma];
	int ret=0;
	
	//íœ
	ret=max(ret,hoge(L+1,R,mi,ma));
	//•ªŠ„
	int M,m;
	for(m=mi;m<=ma;m++) for(M=L+1;M<R;M++) ret=max(ret,hoge(L,M,mi,m)+hoge(M,R,m,ma));
	//Å‰‚Éæ‚é‚©ÅŒã‚Éæ‚é
	if(A[L]>=mi&&A[L]<=ma) {
		ret=max(ret,1+hoge(L+1,R,A[L],ma));
		ret=max(ret,1+hoge(L+1,R,mi,A[L]));
	}
	
	return memo[L][R][mi][ma]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	FOR(x,N) {
		for(y=x+1;y<=N;y++) {
			for(i=1;i<=50;i++) {
				int t=-1;
				for(k=x;k<y;k++) if(A[k]<=i) t=max(t,A[k]);
				tma[x][y][i]=t;
				t=55;
				for(k=x;k<y;k++) if(A[k]>=i) t=min(t,A[k]);
				tmi[x][y][i]=t;
			}
		}
	}
	
	
	MINUS(memo);
	cout<<hoge(0,N,1,50)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
