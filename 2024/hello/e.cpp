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

int T,N,P[5050];
const ll mo=998244353;
ll from[2][2][5050];
ll to[2][2][5050];

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(ll P_,ll Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		map<int,int> M;
		M[0]++;
		FOR(i,N) {
			cin>>P[i];
			M[P[i]]++;
		}
		P[N]=0;
		sort(P,P+N);
		FOR(i,N-1) if(P[i]+1<P[i+1]) break;
		if(i!=N-1) {
			cout<<0<<endl;
			continue;
		}
		sort(P,P+N+1);
		FOR(i,N) if(P[i]+1<P[i+1]) break;
		if(i!=N) {
			cout<<0<<endl;
			continue;
		}
		ZERO(from);
		from[1][1][M[P[0]]]=1;
		for(i=P[0]+1;i<=P[N];i++) {
			int a=M[i-1];
			int b=M[i];
			ZERO(to);
			FOR(x,2) FOR(y,2) FOR(k,a+1) if(from[x][y][k]) {
				ll v=from[x][y][k];
				// ->00
				if(b>=k-1) (to[0][0][1+(b-(k-1))]+=v*hcomb(k-1,b-(k-1)))%=mo;
				if(x&&b>=k) (to[1][0][1+(b-k)]+=v*hcomb(k,b-k))%=mo;
				if(y&&b>=k) (to[0][1][1+(b-k)]+=v*hcomb(k,b-k))%=mo;
				if(x&&y&&b>=k+1) (to[1][1][1+(b-(k+1))]+=v*hcomb(k+1,b-(k+1)))%=mo;
			}
			
			
			swap(from,to);
			if(i==0) {
				FOR(j,b+1) from[0][0][j]=from[0][1][j]=0;
			}
			if(i>0) {
				FOR(j,b+1) from[1][0][j]=from[1][1][j]=0;
			}
		}
		ll ret=0;
		ret+=from[0][0][1]+from[0][1][1]+from[1][0][1]+from[1][1][1];
		cout<<ret%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
