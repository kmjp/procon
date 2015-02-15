#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
ll mo=1000000007;
int A[101000],B[101000];
int mat[4200][4200];
int S[4200][4200];

ll combi(ll N_, ll C_) {
	const int NUM_=120001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

bool isok(int w) {
	ll num=0;
	int y,x;
	
	for(y=0;y+w<4100;y++) {
		for(x=0;x+w<4100;x++) {
			if(S[y+w][x+w]-S[y][x+w]-S[y+w][x]+S[y][x]>=K) return true;
		}
	}
	return false;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x>>y;
		x++,y++;
		A[i]=y,B[i]=x;
		mat[y][x]++;
	}
	for(y=1;y<=4100;y++) {
		for(x=1;x<=4100;x++) S[y][x]=S[y][x-1]+mat[y][x];
		for(x=1;x<=4100;x++) S[y][x]+=S[y-1][x];
	}
	
	int w=0;
	for(i=11;i>=0;i--) if(isok(w+(1<<i))==false) w+=1<<i;
	_P("%d\n",w);
	w++;
	
	
	ll ret=0;
	for(y=1;y<3003;y++) {
		for(x=1;x<3003;x++) {
			i=S[min(3002,y+w-1)][min(3002,x+w-1)]-S[y-1][min(3002,x+w-1)]-S[min(3002,y+w-1)][x-1]+S[y-1][x-1];
			if(i<K) continue;
			
			int my=mat[y][x];
			int mw=S[y][min(3002,x+w-1)]-S[y-1][min(3002,x+w-1)]-S[y][x]+S[y-1][x];
			int mh=S[min(3002,y+w-1)][x]-S[min(3002,y+w-1)][x-1]-S[y][x]+S[y][x-1];
			if(my+mw==0 || my+mh==0) continue;
			
			ret+=combi(i,K);
			ret+=mo-combi(i-my-mh,K);
			ret+=mo-combi(i-my-mw,K);
			ret+=combi(i-my-mh-mw,K);
			
			ret %= mo;
		}
	}
	_P("%lld\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
