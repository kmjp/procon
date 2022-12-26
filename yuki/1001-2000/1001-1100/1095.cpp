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
ll A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	set<int> B,C;
	FOR(i,N) {
		cin>>A[i];
		C.insert(A[i]);
	}
	ll ret=1LL<<60;
	FOR(i,N) {
		C.erase(A[i]);
		
		if(B.size() && C.size()) {
			auto it=B.lower_bound(A[i]);
			auto it2=C.lower_bound(A[i]);
			if(it!=B.end() && it2!=C.end()) ret=min(ret,A[i]+*it+*it2);
			if(*B.begin()<A[i]&&*C.begin()<A[i]) ret=min(ret,A[i]+*B.begin()+*C.begin());
		}
		B.insert(A[i]);
		
	}
	
	if(ret==1LL<<60) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
