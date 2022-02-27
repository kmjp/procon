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

int N;
long double A[505],B[505],C[505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<long double,long double>> cand;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i];
		cand.push_back({C[i]/A[i],0});
		cand.push_back({0,C[i]/B[i]});
	}
	FOR(x,N) FOR(y,x) {
		if(abs(A[x]*B[y]-B[x]*A[y])<1e-12) continue;
		double nx=(C[x]*B[y]-C[y]*B[x])/(A[x]*B[y]-B[x]*A[y]);
		double ny=(C[x]*A[y]-C[y]*A[x])/(B[x]*A[y]-A[x]*B[y]);
		if(nx>0&&ny>0) cand.push_back({nx,ny});
	}
	
	double ret=0;
	FORR2(x,y,cand) if(x+y>ret) {
		FOR(i,N) if(x*A[i]+y*B[i]-1e-7>=C[i]) break;
		if(i==N) ret=x+y;
	}
	_P("%.12lf\n",ret);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
