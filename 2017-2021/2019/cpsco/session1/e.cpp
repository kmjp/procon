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

int N,Q;
set<int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>x;
		if(M.count(x)) M.erase(x);
		else M.insert(x);
	}
	
	FOR(i,Q) {
		int num=0,ret=0;
		int L,R,X;
		cin>>L>>R>>X;
		while(1) {
			auto it=M.lower_bound(L);
			if(it==M.end()||*it>R) break;
			num^=1;
			ret^=*it;
			M.erase(it);
		}
		
		cout<<ret<<endl;
		if(num) {
			if(M.count(X)) M.erase(X);
			else M.insert(X);
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
