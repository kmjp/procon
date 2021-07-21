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

const int MAT=64;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};
const ll mo=998244353;

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

int H;
ll W;
Mat A;

void dfs(int mask,int cur,int sm) {
	if(cur==H) {
		A.v[sm][mask]++;
		return;
	}
	
	if(mask&(1<<cur)) {
		dfs(mask,cur+1,sm);
	}
	else {
		// 1*1
		dfs(mask,cur+1,sm);
		// yoko
		dfs(mask,cur+1,sm|(1<<cur));
		// tate
		if(cur<H-1&&(mask&(1<<(cur+1)))==0) {
			dfs(mask,cur+2,sm);
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int mask;
	FOR(mask,1<<H) dfs(mask,0,0);
	A=powmat(W,A);
	cout<<A.v[0][0]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
