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

int X,M;
vector<int> A;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>M;
	A.resize(M);
	FOR(i,M) cin>>A[i];
	sort(ALL(A));
	reverse(ALL(A));
	
	int ret=0;
	while(A.size()) {
		ret++;
		x = X;
		
		FORR(r,A) {
			if(r<=x) {
				x-=r;
				r=-1;
			}
		}
		sort(ALL(A));
		reverse(ALL(A));
		while(A.size() && A.back()<0) A.pop_back();
		
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
