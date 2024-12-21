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

int H,W,Y,X;
string S[101];
string T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Y>>X;
	Y--;
	X--;
	FOR(y,H) cin>>S[y];
	set<pair<int,int>> C;
	C.insert({Y,X});
	cin>>T;
	FORR(c,T) {
		if(c=='L'&&S[Y][X-1]!='#') X--;
		if(c=='R'&&S[Y][X+1]!='#') X++;
		if(c=='U'&&S[Y-1][X]!='#') Y--;
		if(c=='D'&&S[Y+1][X]!='#') Y++;
		C.insert({Y,X});
	}
	
	int ret=0;
	FORR2(y,x,C) if(S[y][x]=='@') ret++;
	cout<<Y+1<<" "<<X+1<<" "<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
