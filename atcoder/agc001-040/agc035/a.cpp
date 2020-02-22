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

int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	map<int,int> M;
	cin>>N;
	FOR(i,N) {
		cin>>x;
		M[x]++;
	}
	vector<pair<int,int>> V;
	FORR(m,M) V.push_back(m);
	
	if(V.size()==1) {
		if(V[0].first==0) _P("Yes\n");
		else _P("No\n");
	}
	else if(V.size()==2) {
		if(V[0].first==0 && V[0].second*2==V[1].second) _P("Yes\n");
		else _P("No\n");
	}
	else if(V.size()==3) {
		if(((V[0].first^V[1].first)==V[2].first) && V[0].second==V[1].second && V[0].second==V[2].second) _P("Yes\n");
		else _P("No\n");
	}
	else {
		_P("No\n");
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
