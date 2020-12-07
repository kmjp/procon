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
string T;
string S;
ll R=10000000000LL;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	
	FOR(i,200000) S+="110";
	ll ret=0;
	if(N==1) {
		if(T=="0") ret=R;
		else ret=2*R;
	}
	else if(N==2) {
		if(T=="00") ret=0;
		if(T=="11") ret=R;
		if(T=="10") ret=R;
		if(T=="01") ret=R-1;
	}
	else {
		FOR(i,3) {
			if(S.substr(i,N)==T) {
				ll la=i+T.size();
				ret=(R*3-la)/3+1;
			}
		}
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
