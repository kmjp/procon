#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll T;
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>T;
	ll sum=0;
	FOR(i,N) {
		cin>>x>>y;
		sum+=x;
		A[i]=y-x;
	}
	sum-=T;
	sort(A,A+N);
	int ret=0;
	FOR(i,N) {
		if(sum>0) {
			sum+=A[i];
			ret++;
		}
	}
	if(sum>0) _P("-1\n");
	else cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
