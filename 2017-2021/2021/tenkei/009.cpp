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
ll X[2020],Y[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	double pi=atan(1)*4;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	double ma=0;
	FOR(x,N) {
		vector<double> V;
		FOR(y,N) if(x!=y) {
			double a=atan2(Y[y]-Y[x],X[y]-X[x]);
			V.push_back(a);
			V.push_back(a+2*pi);
		}
		sort(ALL(V));
		int L=0,R=0;
		FOR(L,V.size()) {
			while(R<V.size()&&V[R]-V[L]<=pi) R++;
			if(R<V.size()) ma=max(ma,min(V[R]-V[L],2*pi-(V[R]-V[L])));
			if(R>L) ma=max(ma,min(V[R-1]-V[L],2*pi-(V[R-1]-V[L])));
		}
	}
	_P("%.12lf\n",ma*180/pi);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
