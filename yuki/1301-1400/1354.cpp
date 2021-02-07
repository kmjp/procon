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

int N,M,L,K;
int X[202020],Y[202020];
vector<int> S[202020];
ll dp[202020][103];
ll pat[103][103][103];
const ll mo=998244353;
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>L>>K;
	FOR(i,M) {
		cin>>X[i+1]>>Y[i+1];
		S[i].push_back(i);
		S[i].push_back(i+1);
	}
	X[M+1]=Y[M+1]=N;
	S[M].push_back(M);
	S[M].push_back(M+1);
	FOR(i,L) {
		j=i+M+2;
		cin>>X[j]>>Y[j];
		x=lower_bound(X,X+M+2,X[j])-X;
		if(X[x]==X[j]) {
			if(Y[x]==Y[j]) K--;
			if(Y[j]<Y[x]&&Y[x-1]<=Y[j]) S[x-1].push_back(j);
			if(Y[j]>Y[x]&&Y[j]<=Y[x+1]) S[x].push_back(j);
		}
		else {
			if(Y[j]>=Y[x-1]&&Y[j]<=Y[x]) S[x-1].push_back(j);
		}
	}
	if(K<0) return _P("0\n");
	K=min(K,L);
	
	dp[0][K]=1;
	FOR(i,M+1) {
		vector<pair<int,int>> C;
		FORR(s,S[i]) C.push_back({X[s]+Y[s],s});
		sort(ALL(C));
		FOR(x,C.size()) FOR(y,C.size()) FOR(r,C.size()+1) pat[x][y][r]=0;
		FOR(x,C.size()) pat[x][x][0]=1;
		for(int len=1;len<=C.size();len++) {
			for(int f=0;f+len<C.size();f++) {
				int t=f+len;
				//direct
				int a=C[f].second;
				int b=C[t].second;
				if(X[a]>X[b]||Y[a]>Y[b]) continue;
				pat[f][t][1]=comb(Y[b]+X[b]-Y[a]-X[a],Y[b]-Y[a]);
				for(int m=f+1;m<t;m++) {
					int x=C[m].second;
					if(X[a]>X[x]||Y[a]>Y[x]) continue;
					if(X[x]>X[b]||Y[x]>Y[b]) continue;
					(pat[f][t][1]+=mo-pat[f][m][1]*comb(Y[b]+X[b]-Y[x]-X[x],Y[b]-Y[x])%mo)%=mo;
					for(j=1;j<=C.size()-1;j++) (pat[f][t][1+j]+=pat[f][m][1]*pat[m][t][j])%=mo;
				}
			}
		}
		FOR(x,101) for(y=1;y<=x+1;y++) (dp[i+1][x-(y-1)]+=dp[i][x]*pat[0][C.size()-1][y])%=mo;
	}
	
	ll ret=0;
	FOR(x,K+1) ret+=dp[M+1][x];
	cout<<ret%mo<<endl;	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
