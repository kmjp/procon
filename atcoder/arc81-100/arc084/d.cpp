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

int K;
int mi[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	FOR(i,K) mi[i]=1<<30;
	priority_queue<pair<int,int>> P;
	for(i=1;i<=9;i++) {
		mi[i%K]=min(mi[i%K],i);
		P.push({-mi[i%K],i%K});
	}
	
	while(P.size()) {
		int cur=P.top().second;
		int cost=-P.top().first;
		P.pop();
		if(cost!=mi[cur]) continue;
		FOR(i,10) {
			int nc=cost+i;
			int nex=(cur*10+i)%K;
			if(mi[nex]>nc) {
				mi[nex]=nc;
				P.push({-mi[nex],nex});
			}
		}
	}
	
	cout<<mi[0]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
