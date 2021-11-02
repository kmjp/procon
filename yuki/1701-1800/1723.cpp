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

ll X,A,Y,B;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>A>>Y>>B;
	swap(X,Y);
	swap(A,B);
	for(ll a=2;a*a<=X;a++) if(X%a==0) {
		ll num=0;
		while(X%a==0) X/=a, num+=A;
		ll v=Y;
		while(v%a==0) v/=a, num-=B;
		if(num>0) return _P("No\n");
	}
	if(X>1) {
		ll v=X;
		ll num=0;
		while(v%X==0) v/=X, num+=A;
		v=Y;
		while(v%X==0) v/=X, num-=B;
		if(num>0) return _P("No\n");
	}
	cout<<"Yes"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
