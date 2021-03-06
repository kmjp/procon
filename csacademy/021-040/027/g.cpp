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

int N,X;
ll mo;

ll from[105][20202];
ll to[105][20202];

ll combi(ll N_, ll C_) {
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
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:combi(P_+Q_-1,Q_);}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>mo;
	
	from[0][0]=1;
	
	int ma=0;
	for(i=1;i<=N;i++) {
		FOR(j,i+1) ZERO(to[j]);
		FOR(j,i+1) {
			FOR(x,ma+1) if(from[j][x]) {
				// add new island
				(to[j+1][x] += from[j][x])%=mo;
				// add to island
				(to[j][x+i] += from[j][x] * (j*2))%=mo;
				// connect
				if(j>1) (to[j-1][x+2*i] += from[j][x] * (j* (j-1)))%=mo;
				ma=max(ma,x+i);
			}
		}
		swap(from,to);
	}
	
	ll ret=0;
	FOR(i,min(20002,X)) ret += from[1][i]*hcomb(N+1,X-1-i)%mo;
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
