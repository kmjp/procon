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

int Q,N,C;
ll mo=1000000007;

int from[101010];
int to[101010];
int from2[101010];
int to2[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>Q;
	
	for(i=450;i>=1;i--) {
		if(100000-i*(i-1)/2<0) continue;
		for(x=0;x<=100000-i*(i-1)/2;x++) {
			if(x>2*(x-i)) {
				to[x]=x;
				to2[x]=1;
			}
			else {
				to[x]=to[x-i]+from[x-i];
				to2[x]=to2[x-i]+from2[x-i];
				if(to[x]>=mo) to[x]-=mo;
				if(to2[x]>=mo) to2[x]-=mo;
			}
		}
		swap(from,to);
		swap(from2,to2);
	}
	
	while(Q--) {
		cin>>N>>C;
		cout<<(1LL*from[N/C]*C+1LL*from2[N/C]*(N%C))%mo<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
