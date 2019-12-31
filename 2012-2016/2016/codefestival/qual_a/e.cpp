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

int N,M,Q;
int A[101010];
int did[101010];
int ind[101010];
vector<int> V;
int num[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,Q) cin>>A[i];
	for(i=Q-1;i>=0;i--) {
		did[A[i]]++;
		if(did[A[i]]==1) {
			ind[A[i]]=V.size();
			V.push_back(A[i]);
		}
	}
	FOR(i,M) if(did[i+1]==0) {
		ind[i+1]=V.size();
		V.push_back(i+1);
	}
	
	while(V.size()>=2 && V[V.size()-2]<V[V.size()-1]) V.pop_back();
	V.pop_back();
	
	num[0]=N;
	for(i=Q-1;i>=0;i--) if(num[ind[A[i]]]) {
		num[ind[A[i]]]--;
		num[ind[A[i]]+1]++;
	}
	
	FOR(i,V.size()) if(num[i]) return _P("No\n");
	_P("Yes\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
