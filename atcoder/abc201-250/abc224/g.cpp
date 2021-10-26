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

ll N,S,T,A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T>>A>>B;
	ll a=(ll)sqrt(2*B*N/A);
	double score=1e30;
	ll best=0;
	
	for(ll x=min(T,a-5);x<=min(T,a+5);x++) {
		if(x<=0||x>T) continue;
		double b=A*(x-1)/2.0+1.0*B*N/x;
		if(b<score) {
			score=b;
			best=x;
		}
	}
	
	if(T-best+1<=S&&S<=T) {
		cout<<A*(T-S)<<endl;
	}
	else {
		_P("%.12lf\n",score);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
