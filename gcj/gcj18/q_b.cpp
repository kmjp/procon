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

int T,testcase;
int N;

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> A[2],B;
	FOR(i,N) {
		cin>>x;
		A[i%2].push_back(x);
	}
	sort(ALL(A[0]));
	sort(ALL(A[1]));
	FOR(i,N) B.push_back(A[i%2][i/2]);
	FOR(i,N-1) {
		if(B[i]>B[i+1]) return _P("Case #%d: %d\n",TC, i);
	}
	
	_P("Case #%d: OK\n",TC);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
