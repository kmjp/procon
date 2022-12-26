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

int H,W,N;
int X[3030],Y[3030];
pair<int,int> P[3030];

ll dp[3030][2];
ll dpD[3030][3030];

ll mo=1000000007;
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
	
	cin>>H>>W>>N;
	FOR(i,N+2) {
		if(i==1) Y[i]=H-1,X[i]=W-1;
		else if(i>0) {
			cin>>Y[i]>>X[i];
			Y[i]--;
			X[i]--;
		}
		P[i]={X[i]+Y[i],X[i]};
	}
	N+=2;
	sort(P,P+N);
	FOR(i,N) {
		X[i]=P[i].second;
		Y[i]=P[i].first-P[i].second;
	}
	
	dp[0][0]=1;
	FOR(x,N) {
		for(y=x+1;y<N;y++) if(X[x]<=X[y] && Y[x]<=Y[y]) {
			ll pat=comb(X[y]+Y[y]-X[x]-Y[x],X[y]-X[x]);
			(dp[y][0]+=dp[x][1]*pat)%=mo;
			(dp[y][1]+=dp[x][0]*pat)%=mo;
		}
	}
	
	cout<<(dp[N-1][1]+mo-dp[N-1][0])%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
