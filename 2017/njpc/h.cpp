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
int B[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>B[i];
	while(Q--) {
		cin>>i>>l>>r;
		if(i==1) {
			cin>>x;
			for(j=l;j<=r;j++) B[j]+=x;
		}
		if(i==2) {
			cin>>x;
			for(j=l;j<=r;j++) {
				if(B[j]>=0) B[j] /= x;
				else B[j] = (B[j]-(x-1))/x;
			}
		}
		if(i==3) {
			int mi=1<<30;
			for(j=l;j<=r;j++) mi=min(mi,B[j]);
			cout<<mi<<endl;
		}
		if(i==4) {
			ll sum=0;
			for(j=l;j<=r;j++) sum+=B[j];
			cout<<sum<<endl;
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
