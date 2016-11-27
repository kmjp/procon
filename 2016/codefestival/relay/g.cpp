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
int A[101010],B[101010];
int D[101010];
int yes[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) D[i]=i;
	FOR(i,Q) {
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
	}
	for(i=Q-1;i>=0;i--) {
		swap(D[A[i]],D[B[i]]);
	}
	int cur=0;
	yes[D[0]]=1;
	if(cur) yes[D[cur-1]]=1;
	if(cur<N-1) yes[D[cur+1]]=1;
	FOR(i,Q) {
		if(A[i]==cur) cur=B[i];
		else if(B[i]==cur) cur=A[i];
		swap(D[A[i]],D[B[i]]);
		if(cur) yes[D[cur-1]]=1;
		if(cur<N-1) yes[D[cur+1]]=1;
	}
	
	
	
	cout<<count(yes,yes+N,1)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
