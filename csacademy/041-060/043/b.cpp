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

int H,W,N,M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N>>M;
	vector<int> A,B;
	A.push_back(0);
	A.push_back(H);
	B.push_back(0);
	B.push_back(W);
	FOR(i,N) cin>>x, A.push_back(x);
	FOR(i,M) cin>>x, B.push_back(x);
	
	sort(ALL(A));
	sort(ALL(B));
	map<int,int> M;
	FOR(i,A.size()-1) M[A[i+1]-A[i]]++;
	ll ret=0;
	FOR(i,B.size()-1) ret+=M[B[i+1]-B[i]];
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
