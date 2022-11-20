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
string S[3030];
int ok[3030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	ok[0][0]=1;
	string R=S[0].substr(0,1);
	for(i=0;i<H+W-2;i++) {
		char c='z';
		FOR(y,H) {
			x=i-y;
			if(x<0||x>=W) continue;
			if(ok[y][x]==0) continue;
			if(y+1<H) c=min(c,S[y+1][x]);
			if(x+1<W) c=min(c,S[y][x+1]);
		}
		R+=c;
		FOR(y,H) {
			x=i-y;
			if(x<0||x>=W) continue;
			if(ok[y][x]==0) continue;
			if(y+1<H&&S[y+1][x]==c) ok[y+1][x]=1;
			if(x+1<W&&S[y][x+1]==c) ok[y][x+1]=1;
		}
	}
	cout<<R<<endl;

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
