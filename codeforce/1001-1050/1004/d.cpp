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
int N,C,M;
int A[10100];
vector<int> pos[101];
int num[10100];
const ll mo=1000000007;

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

ll from[10101];
ll to[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>C>>M;
		int ok=1;
		FOR(i,N+1) pos[i].clear();
		FOR(i,M) {
			cin>>A[i];
			pos[A[i]].push_back(i);
		}
		
		
		int NZ=pos[0].size();
		FOR(i,M+1) from[i]=0;
		from[0]=1;
		for(i=1;i<=N;i++) {
			vector<pair<int,int>> cand;
			int sum=0;
			FOR(j,M) {
				if(A[j]==0) sum++;
				if(A[j]>=i||A[j]==0) cand.push_back({j,sum});
			}
			FOR(j,M+1) to[j]=0;
			FOR(j,M+1) if(from[j]&&j+C-1<cand.size()) {
				y=cand[j+C-1].first;
				if(pos[i].size()&&y<pos[i].back()) continue;
				int unfix=C-pos[i].size();
				int n0=cand[j+C-1].second-j;
				FOR(x,unfix+1) (to[j+x]+=from[j]*comb(n0,x))%=mo;
				
			}
			FOR(j,M+1) from[j]=to[j];
		}
		cout<<from[NZ]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
