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

ll mo=1000000007;
ll mo2=4*mo*mo;

inline int mulmod(int a,int b,int mo) {
	int d,r;
	if(a==0 || b==0) return 0;
	if(a==1 || b==1) return max(a,b);
	__asm__("mull %4;"
	        "divl %2"
		: "=d" (r), "=a" (d)
		: "r" (mo), "a" (a), "d" (b));
	return r;
}

const int MAT=10;
struct Mat { ll v[MAT][MAT]; };
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

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

Mat revmat(Mat a,int n=MAT) {
	Mat m;
	int x,y,z;
	FOR(x,n) FOR(y,n) m.v[x][y]=x==y;
	
	FOR(x,n) {
		for(y=x;y<n;y++) if(a.v[y][x]) break;
		assert(y!=n);
		FOR(z,n) swap(a.v[x][z],a.v[y][z]),swap(m.v[x][z],m.v[y][z]);
		ll r=modpow(a.v[x][x]);
		FOR(y,n) a.v[x][y]=mulmod(a.v[x][y],r,mo),m.v[x][y]=mulmod(m.v[x][y],r,mo);
		FOR(y,n) if(y!=x) {
			r = a.v[y][x];
			FOR(z,n) {
				m.v[y][z] -= mulmod(r,m.v[x][z],mo);
				if(m.v[y][z]<0) m.v[y][z]+=mo;
				a.v[y][z] -= mulmod(r,a.v[x][z],mo);
				if(a.v[y][z]<0) a.v[y][z]+=mo;
			}
		}
	}
	return m;
	
}

Mat M[101010],S[101010],R[101010];
int N,Q;
string SS;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>SS;
	N=SS.size();
	
	FOR(i,MAT) S[0].v[i][i]=R[0].v[i][i]=1;
	
	FOR(i,N) {
		FOR(x,MAT) M[i+1].v[x][x]=1;
		FOR(x,MAT) M[i+1].v[SS[i]-'a'][x]=1;
		S[i+1]=mulmat(S[i],M[i+1]);
		Mat r=revmat(M[i+1]);
		R[i+1]=mulmat(r,R[i]);
	}
	cin>>Q;
	while(Q--) {
		int LL,RR;
		cin>>LL>>RR;
		Mat r=mulmat(R[LL-1],S[RR]);
		ll ret=0;
		FOR(i,MAT-1) ret+=r.v[i][MAT-1];
		_P("%lld\n",ret%mo);
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
