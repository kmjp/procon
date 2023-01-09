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
int X[101010],L[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<ll,ll>> V;
	
	FOR(i,N) {
		cin>>x>>y;
		V.push_back({x-y,x+y});
	}
	set<pair<ll,int>> M;
	sort(ALL(V));
	int ma=0;
	int ret=0;
	FORR(v,V) {
		int num=0;
		while(M.size()&&M.begin()->first<=v.first) {
			ma=max(ma,M.begin()->second);
			M.erase(M.begin());
		}
		int x=ma+1;
		ret=max(x,ret);
		M.insert({v.second,x});
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}