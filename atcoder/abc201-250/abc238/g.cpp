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


std::random_device rnd;
const int DI=3;
int N,Q;
ll P[1010101][DI][3];
vector<int> V[1010101];

ll H[1010101][3];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	std::mt19937 mt(rnd());
	for(i=1;i<=1000000;i++) {
		FOR(x,DI) {
			P[i][x][0]=1;
			P[i][x][1]=1LL*mt()*mt()%mo;
			P[i][x][2]=1LL*mt()*mt()%mo;
		}
	}
	cin>>N>>Q;
	FOR(i,N) {
		cin>>y;
		for(x=2;x*x<=y;x++) {
			while(y%x==0) {
				V[x].push_back(i);
				y/=x;
			}
		}
		if(y>1) V[y].push_back(i);
		FOR(x,DI) H[i+1][x]=1;
	}
	FOR(x,DI) H[0][x]=1;
	for(i=2;i<=1000000;i++) {
		int cur=0;
		while(cur<V[i].size()) {
			x=V[i][cur];
			int a=cur;
			while(cur<V[i].size()&&V[i][cur]==x) cur++;
			FOR(j,DI) {
				(H[x+1][j]*=modpow(P[i][j][a%3])*P[i][j][cur%3]%mo)%=mo;
			}
		}
	}
	
	for(i=1;i<=N;i++) FOR(j,DI) (H[i][j]*=H[i-1][j])%=mo;
	
		
	
	FOR(i,Q) {
		cin>>x>>y;
		x--;
		FOR(j,DI) if(H[x][j]!=H[y][j]) break;
		if(j==DI) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
