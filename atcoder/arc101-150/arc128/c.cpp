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

int N,M,S;
int A[5050];
ll TS[5050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	FOR(i,N) {
		cin>>A[i];
	}
	reverse(A,A+N);
	double ma=0;
	
	FOR(i,N) {
		TS[i+1]=TS[i]+A[i];
	}
	double ret=0;
	FOR(x,N+1) for(y=0;x+y<=N;y++) {
		if(x*M>S) continue;
		double lef=min(S-x*M,y*M);
		double a=TS[x]*M;
		
		if(y) {
			a+=lef/y*(TS[x+y]-TS[x]);
		}
		ret=max(ret,a);
		
	}
	
	_P("%.12lf\n",ret);
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
