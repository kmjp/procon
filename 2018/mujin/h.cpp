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

int H,W;
ll mo=998244353;
ll step[32][32];
map<ll,int> S;
multiset<pair<ll,ll>> S2;

const int MAT=91;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

ll nex(int mask,int avail) {
	ll ret=0;
	
	if((mask&avail)!=mask) return 0;
	avail ^= mask;
	for(int vert=0;vert<1<<H;vert++) {
		if(vert&(vert<<1)) continue;
		int tmask= vert | (vert<<1);
		if((avail&tmask)!=tmask) continue;
		ret |= 1LL<<(avail^tmask);
	}
	return ret;
}

void dfs(ll v) {
	if(S.count(v)) return;
	S[v]=0;
	int i;
	
	for(int mask=0;mask<1<<H;mask++) {
		ll ne=0;
		FOR(i,1<<H) if(v&(1LL<<i)) ne |= step[i][mask];
		S2.insert({v,ne});
		dfs(ne);
	}
	
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int cand=0;
	FOR(i,1<<H) FOR(j,1<<H) step[i][j]=nex(i,j);
	dfs(1);
	
	Mat M;
	x=0;
	FORR(s,S) s.second=x++;
	FORR(s,S2) M.v[S[s.second]][S[s.first]]++;
	M=powmat(W,M,S.size());
	
	ll ret=0;
	FORR(s,S) {
		ll ne=0;
		FOR(i,1<<H) if(s.first&(1LL<<i)) ne |= step[i][0];
		if(ne==1) ret+=M.v[s.second][1];
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
