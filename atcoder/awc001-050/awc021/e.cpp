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

ll N,A,B;

const int MAT=2;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	Mat r;
	r.v[0][0]=max(a.v[0][0]+b.v[0][0],a.v[0][1]+b.v[1][0]);
	r.v[0][1]=max(a.v[0][0]+b.v[0][1],a.v[0][1]+b.v[1][1]);
	r.v[1][0]=max(a.v[1][0]+b.v[0][0],a.v[1][1]+b.v[1][0]);
	r.v[1][1]=max(a.v[1][0]+b.v[0][1],a.v[1][1]+b.v[1][1]);
	
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	
	Mat v;
	v.v[0][0]=B;
	v.v[0][1]=B/2;
	v.v[1][0]=A;
	v.v[1][1]=A/2;
	Mat W=powmat(N,v);
	ll a=max({W.v[0][0],W.v[0][1],W.v[1][0],W.v[1][1]})-1;
	cout<<a<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
