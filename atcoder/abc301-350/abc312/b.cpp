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

int H,W;
string S[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	for(y=0;y+9<=H;y++) for(x=0;x+9<=W;x++) {
		int b=0,w=0;
		FOR(i,3) FOR(j,3) b+=S[y+i][x+j]=='#';
		FOR(i,3) FOR(j,3) b+=S[y+8-i][x+8-j]=='#';
		FOR(i,4) w+=S[y+3][x+i]=='.';
		FOR(i,4) w+=S[y+i][x+3]=='.';
		FOR(i,4) w+=S[y+5][x+8-i]=='.';
		FOR(i,4) w+=S[y+8-i][x+5]=='.';
		if(b==18&&w==16) cout<<y+1<<" "<<x+1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
