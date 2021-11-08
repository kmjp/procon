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


string S[3]={
	"",
	"BBCCCFACAC",
	"ACCACCCCCCCCABACAAFFE",
};

int T,N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	string V="1234567";
	do {
		x=strtol(V.c_str(),NULL,8);
		stringstream ss;
		ss<<std::hex<<x;
		s=ss.str();
		
		int ok=1;
		FORR(c,s) {
			if(c<'a'||c>'f') ok=0;
			c+='A'-'a';
		}
		if(ok) S[0]=s;
	} while(next_permutation(ALL(V)));
	
	cin>>T;
	while(T--) {
		cin>>N;
		string R;
		
		if(N%21==5) {
			R=S[0];
			FOR(i,N/21) R+=S[2];
		}
		if(N%21==10) {
			R=S[1];
			FOR(i,N/21) R+=S[2];
		}
		if(N%21==0) {
			FOR(i,N/21) R+=S[2];
		}
		
		if(R=="") R="-1";
		cout<<R<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
