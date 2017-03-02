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

int N,Q;
int A[505050];
int L[2020202],R[2020202];
vector<int> V;
ll cnt[404040];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	
	multiset<int> X,Y;
	FOR(i,Q) {
		cin>>x>>y;
		int L=0,R=0;
		ll ret=0;
		FOR(j,N) {
			while(R<=j) Y.insert(A[R++]);
			while(L<=j) X.insert(A[L++]);
			while(*Y.rbegin()-*Y.begin()<=y && R<N) Y.insert(A[R++]);
			while(*Y.rbegin()-*Y.begin()>y) { Y.erase(Y.find(A[--R]));}
			while(*X.rbegin()-*X.begin()<x && L<N) X.insert(A[L++]);
			while(*X.rbegin()-*X.begin()>=x) { X.erase(X.find(A[--L]));}
			ret+=R-L;
			
			X.erase(X.find(A[j]));
			Y.erase(Y.find(A[j]));
		}
		cout<<ret<<endl;
		
		
		
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
