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
const int MAT=20;
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

ll N;

string m[10]={
	"0.........",
	"1012...1..",
	"210112....",
	"3210212.1.",
	"1.1201....",
	"2.21101...",
	"1..2.101..",
	"...1...0..",
	"21....1.0.",
	".1231212.0",
};

Mat A,AD,B;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,10) FOR(x,10) {
		if(m[y][x]=='.') {
			A.v[y][x]=AD.v[y][x]=0;
		}
		else {
			A.v[y][x]=1;
			AD.v[y][x]=m[y][x]-'0';
			if(y>=1 && y<=6) AD.v[y][x]+=2;
			if(y>=7 && y<=8) AD.v[y][x]+=4;
		}
		B.v[y][x]=B.v[y+10][x+10]=A.v[y][x];
		B.v[y+10][x]=AD.v[y][x];
	}
	
	cin>>N;
	Mat T;
	T=powmat(N,B);
	ll ret=0;
	FOR(i,10) {
		ret+=T.v[19][i]*A.v[i][0]%mo;
		ret+=T.v[19][10+i]*AD.v[i][0]%mo;
	}
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
