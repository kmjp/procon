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

const int MAT=21;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};
const ll mo=1000000007;

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


int T;
int N;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	Mat A;
	FOR(i,10) {
		A.v[i^1][i]=1;
		if(i%2==0) {
			for(j=1;j<10;j+=2) if(j>i+1) A.v[j][i]++;
			for(j=10;j<21;j++) A.v[j][i]++;
		}
	}
	for(i=10;i<21;i++) {
		for(j=i;j<21;j++) A.v[j][i]++;
	}
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		if(N<5) {
			cout<<0<<endl;
		}
		else {
			Mat B=powmat(N-4,A);
			cout<<B.v[20][0]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
