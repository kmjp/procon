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
int K;
set<string> ret;

void dfs(string S) {
	if(S.size()==H*W) {
		string R="ZZZZZZZZZ";
		set<char> SS;
		int sy,sx,y,x;
		FOR(y,H) FOR(x,W) SS.insert(S[y*W+x]);
		if(SS.size()!=K) return;
		FOR(sy,H) FOR(sx,W) {
			string T;
			FOR(y,H) FOR(x,W) T+=S[(y+sy)%H*W+(x+sx)%W];
			R=min(R,T);
		}
		ret.insert(R);
		return;
	}
	int i;
	FOR(i,K) dfs(S+(char)('A'+i));
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	dfs("");
	
	cout<<ret.size()<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
