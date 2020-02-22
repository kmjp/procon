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

ll N;
vector<int> A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if((N&(N+1))==0) {
		x=0;
		while(N) A.push_back(++x),N/=2;
		
		_P("%d\n",x*2);
		FOR(i,x) _P("%d ",A[i]);
		FOR(i,x) _P("%d%c",A[i],(i==x-1)?'\n':' ');
	}
	else {
		ll T=N/2;
		x=0;
		while(T) A.push_back(++x),T/=2;
		B=A;
		N -= (1LL<<x)-1;
		vector<int> C;
		y=x+1;
		FOR(i,A.size()) {
			C.push_back(A[i]);
			if(N&(1LL<<(x-1-i))) {
				C.push_back(y);
				B.insert(B.begin(),y);
				y++;
			}
		}
		_P("%d\n",B.size()+C.size());
		FORR(r,C) _P("%d ",r);
		FOR(i,B.size()) _P("%d%c",B[i],(i==B.size()-1)?'\n':' ');
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
