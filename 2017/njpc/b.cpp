#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll H,W,N;
set<pair<int,int>> S;
set<pair<pair<int,int>,pair<int,int>>> NG;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(i,N) {
		cin>>y>>x;
		S.insert({y-1,x-1});
	}
	ll ret=(H-1)*W+H*(W-1);
	FORR(r,S) {
		if(r.first) NG.insert({{r.first-1,r.second},{r.first,r.second}});
		if(r.first<H-1) NG.insert({{r.first,r.second},{r.first+1,r.second}});
		if(r.second) NG.insert({{r.first,r.second-1},{r.first,r.second}});
		if(r.second<W-1) NG.insert({{r.first,r.second},{r.first,r.second+1}});
	}
	
	cout<<ret-NG.size()<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
