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

int N,U;
int B[505050];

const int NUM_=2000003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];


ll F[505050][22];
const ll mo=998244353;
vector<pair<int,int>> D[505050];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>U;
	FOR(i,N) {
		cin>>x;
		B[x]++;
	}
	
	for(i=2;i<=U;i++) {
		ll x=i;
		for(j=2;x*i<=U;j++) {
			x*=i;
			D[x].push_back({i,j});
		}
	}
	
	
	F[1][0]=1;
	FOR(l,20) {
		for(j=1;j<=U/2;j++) if(F[j][l]) {
			for(x=2;j*x<=U;x++) (F[j*x][l+1]+=F[j][l]*B[x])%=mo;
		}
	}
	
	for(i=2;i<=U;i++) {
		ll ret=0;
		for(j=1;j<=19;j++) {
			//cout<<i<<" "<<j<<" "<<F[i][j]<<"->";
			FORR2(a,b,D[i]) if(j%b==0) {
				(F[i][j]-=F[a][j/b])%=mo;
				ret+=F[a][j/b]*inv[j/b]%mo;
			}
			F[i][j]=(F[i][j]%mo+mo)%mo;
			ret+=F[i][j]*inv[j]%mo;
			//cout<<F[i][j]<<endl;
		}
		cout<<ret%mo<<" ";
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
