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
string A;
int L[101];
int R[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A;
	N=A.size();
	stack<int> S;
	FOR(i,N) {
		if(isdigit(A[i])) {
			L[i]=R[i]=i;
		}
		else {
			R[i]=S.top();
			S.pop();
			L[i]=S.top();
			S.pop();
		}
		S.push(i);
	}
	
	queue<int> Q;
	Q.push(S.top());
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		s+=A[x];
		if(!isdigit(A[x])) {
			Q.push(L[x]);
			Q.push(R[x]);
		}
		
	}
	reverse(ALL(s));
	cout<<s<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
