#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
set<int> S;
vector<int> v;

int hoge(int d,vector<int>& v) {
	if(v.size()<=1) return 0;
	int i,j;
	vector<int> w[2];
	FOR(i,v.size()) {
		int x=v[i];
		w[(x>>d)&1].push_back(x^(x&(1<<d)));
	}
	
	if(w[0].size()==0) return hoge(d-1,w[1]);
	if(w[1].size()==0) return hoge(d-1,w[0]);
	
	return (1<<d)+min(hoge(d-1,w[0]),hoge(d-1,w[1]));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,N) cin>>x, S.insert(x);
	ITR(it,S) v.push_back(*it);
	
	cout<<hoge(29,v)<< endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
