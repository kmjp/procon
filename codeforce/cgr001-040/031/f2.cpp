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
ll H,W;

const int MAT=151;
const ll mo=1000000007;
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


ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	ll r2=modpow(2);
	ll r3=modpow(3);
	ll r4=modpow(4);
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		Mat A;
		FOR(y,H) {
			A.v[(y+1)*3][y*3]=9*r4%mo*r4%mo;
			A.v[y*3+1][y*3]=1*r4%mo*2*r3%mo*3*r4%mo;
			A.v[y*3+2][y*3]=3*r4%mo*2*r3%mo*r4%mo;
			A.v[(y+1)*3][y*3+1]=2*r3%mo*3*r4%mo;
			A.v[y*3+1][y*3+1]=r3%mo*(3*r4)%mo*(3*r4)%mo;
			A.v[y*3+2][y*3+1]=2*r3%mo*(r4)%mo*(3*r4)%mo;
			A.v[(y+1)*3][y*3+2]=3*r4%mo;
			A.v[y*3+2][y*3+2]=r4%mo*(3*r4)%mo;
		}
		A.v[H*3][H*3]=1;
		ll v1=1*r4%mo*3%mo*r4%mo*3*r4%mo; //左下で蓋をし、右上も右下も邪魔をしない
		ll v2=3*r4%mo*1%mo*r4%mo*3*r4%mo; 
		ll v3=9*r4%mo*r4%mo;
		
	
		ll ret=0;
		//下
		auto B=powmat(H-1+W-1,A,H*3+1);
		(ret+=B.v[H*3][1]*v1+B.v[H*3][2]*v2+B.v[H*3][3]*v3)%=mo;
		//右
		B=powmat(W-1,A,H*3+1);
		FOR(y,H) {
			(ret+=B.v[y*3+1][1]*v1+B.v[y*3+1][2]*v2+B.v[y*3+1][3]*v3)%=mo;
			(ret+=B.v[y*3+2][1]*v1+B.v[y*3+2][2]*v2+B.v[y*3+2][3]*v3)%=mo;
			B=mulmat(A,B,H*3+1);
		}
		
		ret=(mo+1-ret%mo)*modpow(4,(H+1)*(W+1));
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
