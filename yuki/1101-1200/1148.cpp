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
ll W;
ll A[101010];
ll S[101010];
map<int,set<int>> M;
set<int> NG;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W;
	FOR(i,N) {
		cin>>A[i];
		M[A[i]].insert(i);
		if(M[A[i]].size()==2) NG.insert(i);
		S[i+1]=S[i]+A[i];
	}
	int ma=0;
	FOR(i,N) {
		x=lower_bound(S+i,S+N+1,S[i]+W+1)-S-1;
		if(NG.size()) x=min(x,*NG.begin());
		ma=max(ma,x-i);
		
		M[A[i]].erase(i);
		if(M[A[i]].size()) {
			auto it=M[A[i]].begin();
			NG.erase(*it);
			it++;
			if(it!=M[A[i]].end()) NG.insert(*it);
		}
		
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
