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

int N,M;
ll K;
int A[50505],B[50505],C[50505],D[50505];

ll num(double v) {
	vector<double> cand;
	int i;
	FOR(i,N) {
		cand.push_back(A[i]-(A[i]+B[i])*v);
	}
	sort(ALL(cand));
	ll ret=0;
	FOR(i,M) {
		double t=C[i]-(C[i]+D[i])*v;
		ret+=cand.end()-lower_bound(ALL(cand),-t);
	}
	return ret;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>A[i]>>B[i];
	FOR(i,M) cin>>C[i]>>D[i];
	
	double L=0,R=1;
	FOR(i,60) {
		double T=(L+R)/2;
		if(num(T)>=K) L=T;
		else R=T;
	}
	_P("%.12lf\n",L*100);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
