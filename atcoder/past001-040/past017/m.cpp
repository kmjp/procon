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

double P[2],Q[2],R[2],S[2],U[2],V[2];

pair<double,double> hoge(double cd,double d,double v) {
	if(v<0) return hoge(-cd,d,-v);
	if(v==0) {
		if(abs(cd)<d) return {0,1<<30};
		return {0,0};
	}
	if(cd>d) return {0,0};
	double mi;
	if(cd>=-d) mi=0;
	else mi=(-d-cd)/v;
	double ma=(d-cd)/v;
	
	
	return {mi,ma};
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,2) cin>>P[i]>>Q[i]>>R[i]>>S[i]>>U[i]>>V[i];
	auto p=hoge((R[1]+P[1])/2-(R[0]+P[0])/2,(R[1]-P[1])/2+(R[0]-P[0])/2,U[1]-U[0]);
	auto q=hoge((S[1]+Q[1])/2-(S[0]+Q[0])/2,(S[1]-Q[1])/2+(S[0]-Q[0])/2,V[1]-V[0]);
	p.first=max(p.first,q.first);
	p.second=min(p.second,q.second);
	
	_P("%.12lf\n",max(0.0,p.second-p.first));
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
