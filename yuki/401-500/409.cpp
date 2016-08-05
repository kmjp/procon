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

ll N,A,B,W;
int D[303030];

ll from[1200];
ll to[1200];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>W;
	FOR(i,N) cin>>D[i];
	
	if(B==0) return _P("%lld\n",W-A*N);
	
	FOR(i,1200) from[i]=1LL<<60;
	from[0]=W;
	
	FOR(i,N) {
		memset(to,0x3f,sizeof(to));
		FOR(j,1100) {
			// not eat
			to[j+1] = min(to[j+1],from[j]+B*(j+1)-A);
			// eat
			to[0] = min(to[0],from[j]+D[i]);
		}
		swap(from,to);
	}
	cout<<*min_element(from,from+1101)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
