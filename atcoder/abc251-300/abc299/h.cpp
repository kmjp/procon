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

int R;
const ll mo=998244353;

const int MAT=12;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

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

pair<ll,ll> E2(int R) {
	//ÇøÇÂÇ§Ç«RêiÇﬁämó¶Ç∆âÒêî
	if(R<0) return {0,0};
	
	Mat M;
	M.v[0][0]=M.v[0][1]=M.v[0][2]=M.v[0][3]=M.v[0][4]=M.v[0][5]=modpow(6);
	M.v[6][6]=M.v[6][7]=M.v[6][8]=M.v[6][9]=M.v[6][10]=M.v[6][11]=modpow(6);
	M.v[6][0]=M.v[6][1]=M.v[6][2]=M.v[6][3]=M.v[6][4]=M.v[6][5]=modpow(6);
	int i;
	FOR(i,5) M.v[i+1][i]=M.v[i+7][i+6]=1;
	M=powmat(R,M);
	if(M.v[6][0]) (M.v[6][0]*=modpow(M.v[0][0]))%=mo;
	return {M.v[0][0],M.v[6][0]};
}
vector<ll> E(int R) {
	vector<ll> ret(7);
	
	if(R<=0) {
		ret[1-R]=1;
		return ret;
	}
	
	int i,j;
	for(i=1;i<=6;i++) {
		auto p=E2(R-i);
		for(j=1;j<=6;j++) if(i-j<=0) {
			(ret[0]+=p.first*modpow(6)%mo*(p.second+1))%=mo;
			(ret[1-(i-j)]+=p.first*modpow(6))%=mo;
		}
	}
	return ret;
}


ll ma[MAT][MAT],V[MAT],RR[MAT];
ll rev(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int Gauss(int n,ll mat_[MAT][MAT],ll v_[MAT],ll r[MAT]) {
	int i,j,k;
	ll mat[MAT][MAT],v[MAT];
	memmove(mat,mat_,sizeof(mat));
	memmove(v,v_,sizeof(v));
	
	FOR(i,n) {
		if(mat[i][i]==0) {
			for(j=i+1;j<n;j++) if(mat[j][i]) break;
			if(j>=n) return i;
			FOR(k,n) swap(mat[i][k],mat[j][k]);
			swap(v[i],v[j]);
		}
		(v[i]*=rev(mat[i][i]))%=mo;
		for(k=n-1;k>=i;k--) (mat[i][k]*=rev(mat[i][i]))%=mo;
		for(j=i+1;j<n;j++) {
			v[j]=((v[j]-v[i]*mat[j][i]%mo)+mo)%mo;
			for(k=n-1;k>=i;k--) mat[j][k]=((mat[j][k]-mat[i][k]*mat[j][i]%mo)+mo)%mo;
		}
	}
	
	for(i=n-1;i>=0;i--) {
		for(j=n-1;j>i;j--) v[i]=((v[i]-mat[i][j]*v[j]%mo)+mo)%mo;
		r[i]=v[i];
	}
	return n;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R;
	auto ret=E(R);
	
	
	ma[0][0]=1;
	for(i=1;i<=5;i++) {
		auto p=E(1000000000-i);
		FOR(x,6) {
			ma[i][x]=p[x+1];
		}
		(ma[i][i]+=mo-1)%=mo;
		V[i]=mo-p[0];
	}
	
	Gauss(6,ma,V,RR);
	
	ll tot=ret[0];
	FOR(i,6) (tot+=ret[i+1]*RR[i])%=mo;
	cout<<tot<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
