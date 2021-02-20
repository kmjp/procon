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


string X;
ll M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>M;
	int ma=0;
	FORR(x,X) ma=max(ma,x-'0');
	
	ll ret=0;
	if(X.size()>=4) {
		for(ll a=ma+1;;a++) {
			__int128 v=0;
			FORR(x,X) {
				if(v>M) break;
				v=v*a+x-'0';
			}
			if(v<=M) ret++;
			else break;
		}
	}
	else if(X.size()==3) {
		__int128 a=ma;
		for(i=30;i>=0;i--) {
			__int128 b=a+(1LL<<i);
			__int128 v=0;
			FORR(x,X) v=b*v+x-'0';
			if(v<=M) a=b;
		}
		ret=a-ma;
	}
	else if(X.size()==2) {
		__int128 a=ma;
		for(i=60;i>=0;i--) {
			__int128 b=a+(1LL<<i);
			__int128 v=0;
			FORR(x,X) v=b*v+x-'0';
			if(v<=M) a=b;
		}
		ret=a-ma;
	}
	else {
		if(ma<=M) ret=1;
		else ret=0;
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
