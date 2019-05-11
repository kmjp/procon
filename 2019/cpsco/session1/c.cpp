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

int N,K;
ll A[101];

vector<ll> C[7];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	C[0].push_back(0);
	FOR(i,N) {
		cin>>x;
		for(j=K-1;j>=0;j--) FORR(c,C[j]) C[j+1].push_back(c+x);
	}
	
	int mi=1<<20;
	FORR(c,C[K]) {
		int num=0;
		while(c) {
			x=c%10;
			if(x>=5) num+=x-4;
			else num+=x;
			c/=10;
		}
		mi=min(mi,num);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
