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
int A[4040],B[4040];
set<ll> S;
ll ma;
int w,h;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		S.insert(A[i]),S.insert(B[i]);
		if(A[i]>B[i]) swap(A[i],B[i]);
	}
	
	FORR(r,S) {
		vector<int> v;
		FOR(i,N) {
			if(A[i]>=r) v.push_back(B[i]);
			else if(B[i]>=r) v.push_back(A[i]);
		}
		sort(ALL(v));
		FOR(i,v.size()) {
			if(ma < r*v[i]*(v.size()-i)) {
				ma = r*v[i]*(v.size()-i);
				w = r;
				h = v[i];
			}
		}
	}
	
	cout<<ma<<endl;
	cout<<w<<" "<<h<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
