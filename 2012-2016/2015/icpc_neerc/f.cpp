#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[1010],B[1010];
int need[1010];
vector<int> add[100001];
vector<int> del[100001];
set<pair<int,int> > S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i]>>B[i], add[A[i]].push_back(i),del[B[i]].push_back(i);
	
	for(int can=1;can<=10000/N+2;can++) {
		FOR(i,N) need[i]=can;
		
		S.clear();
		for(i=0;i<=10000;i++) {
			FORR(r,del[i]) if(need[r]) {
				cout<<(can-1)*N<<endl;
				return;
			}
			FORR(r,add[i]) S.insert({B[r],r});
			if(S.size()) {
				auto r=S.begin();
				if(--need[r->second]==0) S.erase(S.begin());
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
