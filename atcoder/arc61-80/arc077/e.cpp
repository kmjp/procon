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

int N,M;
int A[202020];
ll sum=0;
ll dif[302020];
ll tot[302020];
ll ret[302020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i], A[i]--;
	FOR(i,N-1) {
		x=A[i];
		y=A[i+1];
		if(y<x) y+=M;
		sum += y-x;
		if(x+1<y) {
			dif[x+2]++;
			dif[y+1]--;
			tot[y+1]+=y-x-1;
			dif[M+x+2]++;
			dif[M+y+1]--;
			tot[M+y+1]+=y-x-1;
		}
	}
	
	
	ll mi=1LL<<60;
	FOR(i,3*M) {
		if(i) {
			dif[i]+=dif[i-1];
			tot[i]+=tot[i-1];
		}
		tot[i]-=dif[i];
		mi=min(mi,sum+tot[i]);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
