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
ll K;
ll A[101010],B[101010];
int NG[101010];

ll ok(int D) {
	int i;
	if(D<0) {
		ll low=0;
		FOR(i,N) if(NG[i]==0) low+=B[i];
		return low;
	}
	if(K&(1<<D)) {
		ll low=0;
		FOR(i,N) if(NG[i]==0 && ((A[i]&(1<<D))==0)) low+=B[i];
		return max(low,ok(D-1));
	}
	else {
		FOR(i,N) if((A[i]&(1<<D))) NG[i]=1;
		return ok(D-1);
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i]>>B[i];
	cout<<ok(30)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
