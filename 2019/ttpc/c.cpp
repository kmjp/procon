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
int X;
int A[505050];
vector<int> V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	int num=0,xo=X;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]==-1) V.push_back(i), A[i]=0;
		else xo^=A[i];
	}
	
	if(X==0) {
		if(xo) return _P("-1\n");
		
		FOR(i,N) cout<<"0 ";
		return;
	}
	x=0;
	while(1<<(x+1)<=X) x++;
	
	if(V.empty()) {
		if(xo) return _P("-1\n");
	}
	else if(V.size()==1) {
		if(xo<=X) {
			A[V[0]]=xo;
		}
		else {
			return _P("-1\n");
		}
	}
	else {
		if(xo>=(1<<x)*2)  return _P("-1\n");
		A[V[0]]=xo&(1<<x);
		A[V[1]]=xo&((1<<x)-1);
	}
	
	FOR(i,N) cout<<A[i]<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
