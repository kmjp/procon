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
string S[1010101];

bool inc(string sub,string full) {
	int cur=0;
	FORR(r,full) if(cur<sub.size() && sub[cur]==r) cur++;
	return cur==sub.size();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	i=j=0;
	vector<string> C;
	FOR(i,W) if(S[0][i]!=S[1][i]) break;
	for(j=W-1;j>=0;j--) if(S[0][j]!=S[1][j]) break;
	C.push_back(S[0].substr(0,i+1)+S[1].substr(i));
	C.push_back(S[1].substr(0,i+1)+S[0].substr(i));
	
	int ok=0;
	
	FORR(c,C) {
		FOR(y,H) if(inc(S[y],c)==0) break;
		ok+=y==H;
	}
	cout<<ok<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
