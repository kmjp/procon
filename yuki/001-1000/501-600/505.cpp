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
int A[20];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	set<ll> S;
	cin>>x;
	S.insert(x);
	FOR(i,N-1) {
		set<ll> T;
		cin>>x;
		FORR(r,S) {
			T.insert(r+x);
			T.insert(r-x);
			T.insert(r*x);
			if(x!=0) T.insert(r/x);
		}
		S.clear();
		S.insert(*T.begin());
		S.insert(*T.rbegin());
	}
	cout<<*S.rbegin()<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
