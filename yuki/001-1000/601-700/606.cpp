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

int N,K,Q;
string A[201010];
int B[201010],C[201010];
int la[2][201010];

ll ret[201010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>Q;
	FOR(i,Q) {
		cin>>A[i]>>B[i]>>C[i];
		B[i]--;
		C[i]--;
		la[A[i]=="C"][B[i]]=i;
	}
	
	ll rc=N,rr=N;
	for(i=Q-1;i>=0;i--) {
		if(la[A[i]=="C"][B[i]]==i) {
			if(A[i]=="C") {
				ret[C[i]]+=rr;
				rc--;
			}
			else {
				ret[C[i]]+=rc;
				rr--;
			}
		}
	}
	ret[0]+=rc*rr;
	
	FOR(i,K) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
