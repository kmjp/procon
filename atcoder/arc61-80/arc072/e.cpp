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

int N,D;
ll Q;
ll X[505050];
ll L[505050];
int QQ[505050];
ll NG[501010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	L[0]=D;
	FOR(i,N) {
		cin>>X[i];
		L[i+1]=min(L[i],abs(L[i]-X[i]));
	}
	
	cin>>Q;
	FOR(i,Q) cin>>QQ[i];
	
	if(L[N]>0) {
		FOR(i,Q) cout<<"YES"<<endl;
	}
	else {
		NG[N]=1;
		for(i=N-1;i>=0;i--) {
			if(NG[i+1]<=X[i]/2) NG[i]=NG[i+1];
			else NG[i]=NG[i+1]+X[i];
		}
		
		FOR(i,Q) {
			x = QQ[i];
			if(L[x-1]==0 || NG[x]>L[x-1]) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
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
