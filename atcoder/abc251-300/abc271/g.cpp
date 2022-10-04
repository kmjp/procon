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

ll N,X,Y;
string C;

const int MAT=48;
ll mo=998244353;
ll ma[MAT][MAT],ma2[MAT][MAT],V[MAT],R[MAT];
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

ll rev(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

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

//çsÇ∆óÒÇåàÇﬂÇƒÇÃ
int mat_rank(int r,int c,ll ma_[MAT][MAT]) {
	static ll tmp[MAT][MAT];
	int y,x,step;
	FOR(y,r) FOR(x,c) tmp[y][x]=ma_[y][x];
	int ret=0;
	FOR(step,c) {
		for(y=ret;y<r;y++) if(tmp[y][step]) break;
		if(y==r) continue;
		for(x=step;x<c;x++) swap(tmp[ret][x],tmp[y][x]);
		int re=rev(tmp[ret][step]);
		for(x=step;x<c;x++) tmp[ret][x]=tmp[ret][x]*re%mo;
		
		FOR(y,r) if(y!=ret && tmp[y][step]) {
			re=tmp[y][step];
			for(x=step;x<c;x++) tmp[y][x]=((tmp[y][x]-re*tmp[ret][x])%mo+mo)%mo;
		}
		ret++;
	}
	FOR(y,r) FOR(x,c) ma_[y][x]=tmp[y][x];
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y>>C;
	X=X*modpow(100)%mo;
	Y=Y*modpow(100)%mo;
	FORR(c,C) c=c=='A';
	FOR(i,24) {
		ma[i][i+24]=1;
		if(C[i]==0) {
			ma[(i+1)%24][i]=modpow(X);
			ma[(i+1)%24][(i+1)%24]=(X-1)*modpow(X)%mo;
		}
		else {
			ma[(i+1)%24][i]=modpow(Y);
			ma[(i+1)%24][(i+1)%24]=(Y-1)*modpow(Y)%mo;
		}
	}
	mat_rank(24,48,ma);
	Mat ma2;
	FOR(y,24) {
		FOR(x,24) ma2.v[y][x]=ma[y][x+24];
	}
	ma2=powmat(N,ma2);
	ll ret=0;
	FOR(i,24) if(C[(i+23)%24]==1) ret+=ma2.v[0][i];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
