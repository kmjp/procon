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
int A[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	while(1) {
		cin>>N;
		if(N==0) break;
		FOR(i,N) {
			cin>>s;
			if(s=="x") A[i]=1<<30;
			else {
				sscanf(s.c_str(),"%d",&A[i]);
			}
		}
		set<int> cand;
		FOR(i,N) if(A[i]!=1<<30) {
			for(j=A[i]-2;j<=A[i]+2;j++) {
				int ok=1;
				FOR(x,N-1) {
					if(x%2==0) ok &= ((A[x]==1<<30)?j:A[x])<((A[x+1]==1<<30)?j:A[x+1]);
					else ok &= ((A[x]==1<<30)?j:A[x])>((A[x+1]==1<<30)?j:A[x+1]);
				}
				if(ok) cand.insert(j);
			}
		}
		
		if(cand.size()==1) {
			cout<<*cand.begin()<<endl;
		}
		if(cand.size()==0) {
			cout<<"none"<<endl;
		}
		if(cand.size()>1) {
			cout<<"ambiguous"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
