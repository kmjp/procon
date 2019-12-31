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
vector<pair<int,int>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	V.push_back({2,0});
	cin>>N;
	FOR(i,N) {
		cin>>x;
		x ^= i%2;
		if(V.back().first==x) V.back().second++;
		else V.push_back({x,1});
	}
	V.push_back({2,0});
	
	int ma=0;
	for(i=1;i<V.size()-1;i++) {
		ma=max(ma,V[i].second+V[i-1].second+V[i+1].second);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
