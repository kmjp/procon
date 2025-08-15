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
ll K,N;
vector<int> D[101010];
int cache[101010];
ll ret[101010];
map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}

const int MAT=140;
ll G[MAT][MAT],G2[MAT][MAT];
const ll mo=998244353;
void powmat(ll p,int n,ll a[MAT][MAT],ll r[MAT][MAT]) {
	int i,x,y,z;
	ll a2[n][n];
	FOR(x,n) FOR(y,n) a2[x][y]=a[x][y];
	FOR(x,n) FOR(y,n) r[x][y]=(x==y);
	while(p) {
		__int128 h[n][n];
		if(p%2) {
			FOR(x,n) FOR(y,n) h[x][y]=0;
			FOR(x,n) FOR(z,n) FOR(y,n) h[x][y] += (r[x][z]*a2[z][y]);
			FOR(x,n) FOR(y,n) r[x][y]=h[x][y]%mo;
		}
		FOR(x,n) FOR(y,n) h[x][y]=0;
		FOR(x,n) FOR(z,n) FOR(y,n) h[x][y] += (a2[x][z]*a2[z][y]);
		FOR(x,n) FOR(y,n) a2[x][y]=h[x][y]%mo;
		p>>=1;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	map<string,int> C;
	for(i=1;i<=100000;i++) {
		for(j=i;j<=100000;j+=i) D[j].push_back(i);
		auto M=enumpr(i);
		string S;
		FORR2(a,b,M) S+=(char)b;
		sort(ALL(S));
		if(C.count(S)) {
			cache[i]=C[S];
		}
		else {
			C[S]=i;
		}
	}
	
	cin>>T;
	while(T--) {
		cin>>K>>N;
		
		for(i=1;i<=K;i++) {
			if(cache[i]==0) {
				j=D[i].size();
				FOR(x,j+1) FOR(y,j+1) G[x][y]=0;
				FOR(x,j) FOR(y,j) if(D[i][y]%D[i][x]==0) G[y][x]=1;
				FOR(x,j+1) G[j][x]++;
				
				powmat(N,j+1,G,G2);
				ret[i]=G2[j][0];
			}
			else {
				ret[i]=ret[cache[i]];
			}
			cout<<ret[i]<<" ";
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
