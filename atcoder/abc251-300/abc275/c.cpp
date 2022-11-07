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

string S[9];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(y,9) cin>>S[y];
	int ret=0;
	int x1,y1,x2,y2;
	FOR(y1,9) FOR(x1,9) FOR(y2,9) FOR(x2,9) {
		int dx=x2-x1;
		int dy=y2-y1;
		if(dx==0&&dy==0) continue;
		int y3=y2-dx;
		int x3=x2+dy;
		int y4=y3-dy;
		int x4=x3-dx;
		if(y3<0||y3>=9||x3<0||x3>=9) continue;
		if(y4<0||y4>=9||x4<0||x4>=9) continue;
		if(S[y1][x1]=='.') continue;
		if(S[y2][x2]=='.') continue;
		if(S[y3][x3]=='.') continue;
		if(S[y4][x4]=='.') continue;
		ret++;
		
	}
	cout<<ret/4<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
