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

const int prime_max = 20000005;
int NP,divp[prime_max];
int prep[prime_max];

int can[1001][1001];

int ok(int p,int q,int m) {
	int i;
	for(i=q;i<=m;i++) if(__gcd(p,i)>1) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(int i=2;i<prime_max;i++) {
		prep[i]=prep[i-1];
		if(divp[i]==0) {
			prep[i]=i;
			for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
		}
	}
	
	cin>>T;
	while(T--) {
		int N,M,L,R;
		cin>>N>>M>>L>>R;
		
		int q=prep[M];
		int p=N;
		while(!ok(p,q,M)) p--;
		
		int w1=N-p;
		int w2=M-q;
		FOR(x,w1+1) FOR(y,w2+1) can[x][y]=0;
		can[0][0]=1;
		ll ret=0;
		FOR(x,w1+1) FOR(y,w2+1) if(can[x][y]) {
			ret=max(ret,1LL*L*(p+x)+1LL*R*(q+y));
			if(p+x<=M&&q+y<=N) ret=max(ret,1LL*R*(p+x)+1LL*L*(q+y));
			if(p+x+1<=N&&__gcd(p+x+1,q+y)==1) can[x+1][y]=1;
			if(q+y+1<=M&&__gcd(p+x,q+y+1)==1) can[x][y+1]=1;
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
