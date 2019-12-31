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

int N,M,X;
ll S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	deque<ll> D;
	FOR(i,1000005) D.push_back(i);
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x;
		if(i<=1) {
			if(i==0) T+=x;
			else T-=x;
		}
		else {
			S+=x;
			for(j=1;j<=x;j++) D.push_front(D[j*2-1]);
			while(D.size()>1000005) D.pop_back();
		}
	}
	
	
	cin>>M;
	while(M--) {
		cin>>X;
		if(X>=S) {
			cout<<T+X-S<<endl;
		}
		else {
			cout<<T+D[X]<<endl;
		}
	}
	
		
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
