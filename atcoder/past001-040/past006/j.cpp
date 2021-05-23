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

int N,C;
int X[202020],Y[202020];

double hoge(double p) {
	double sum=0;
	int i;
	FOR(i,N) {
		sum+=(p-X[i])*(p-X[i])+1LL*(C-Y[i])*(C-Y[i]);
	}
	return sum;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C;
	FOR(i,N) cin>>X[i]>>Y[i];
	
	double L=-100000,R=100000;
	FOR(i,100) {
		double M1=(L*2+R)/3;
		double M2=(L+R*2)/3;
		double V1=hoge(M1);
		double V2=hoge(M2);
		if(V1<=V2) R=M2;
		if(V2<=V1) L=M1;
	}
	_P("%.12lf\n",hoge(L));
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
