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

ll N,M,K;
const ll mo=998244353;

const int MAT=6;
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

map<ll,ll> memo;
Mat A,B;
ll pat(ll v) {
	if(v<0) return 0;
	if(memo.count(v)) return memo[v];
	auto B=powmat(v,A);
	return memo[v]=B.v[0][0];
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	A.v[0][0]=A.v[0][1]=A.v[0][2]=A.v[0][3]=A.v[0][4]=A.v[0][5]=1;
	A.v[1][0]=A.v[2][1]=A.v[3][2]=A.v[4][3]=A.v[5][4]=1;
	
	
	cin>>N>>M>>K;
	
	//合計を求める
	ll sum=0;
	FOR(i,6) {
		ll p=pat(1LL*N*M-6+i);
		for(k=1;k<=6;k++) if(1LL*N*M-6+i+k>=1LL*N*M) sum+=p;
	}
	sum%=mo;
	

	FOR(i,5) {
		// 1周の手前jマス
		FOR(j,5) {
			ll a=pat(N-5+j-(i+1));
			for(k=1;k<=6;k++) if(N-5+j+k>N) {
				(B.v[(N-5+j+k)-(N+1)][i]+=a)%=mo;
			}
		}
	}
	
	B=powmat(M-1,B,5);
	while(K--) {
		cin>>k;
		
		ll p[6]={};
		FOR(j,5) {
			ll a=pat(k-5+j);
			for(i=1;i<=6;i++) if(k-5+j+i>k) (p[(k-5+j+i)-(k+1)]+=a)%=mo;
		}
		ll q[5]={};
		FOR(x,5) FOR(y,5) (q[y]+=p[x]*B.v[y][x])%=mo;
		ZERO(p);
		ll ret=0;
		
		FOR(x,5) {
			if(k+1+x>=N) {
				ret+=q[x];
			}
			else {
				FOR(y,6) (p[y]+=q[x]*pat((N-6+y)-(k+1+x)))%=mo;
			}
		}
		FOR(y,6) for(x=1;x<=6;x++) if(y+x>=6) ret+=p[y];
		cout<<(sum-ret%mo+mo)%mo<<endl;
		
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
