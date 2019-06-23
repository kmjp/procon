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

int N,K;
vector<pair<int,int>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	int lef=(N-1)*(N-2)/2;
	if(K>lef) return _P("-1\n");
	
	for(i=2;i<=N;i++) V.push_back({1,i});
	lef-=K;
	for(x=2;x<=N;x++) for(y=x+1;y<=N;y++) if(lef) {
		lef--;
		V.push_back({x,y});
	}
	
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v.first<<" "<<v.second<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
