#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
ll mo;

ll from[5050*100+100];
ll to[5050*100+100];
ll ret[101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>mo;
	
	
	for(x=1;x<=(N+1)/2;x++) {
		ZERO(from);
		ZERO(to);
		int mi=x*(x-1)/2*K;
		int ma=(N-x)*(N-x+1)/2*K;
		int cur=mi+50;
		from[cur]=K+1;
		mi=ma=cur;
		for(i=x-1;i>=1;i--) {
			int pma=ma;
			
			mi=min(mi,mi+K*(i-x));
			ma=max(ma,ma+K*(i-x));
			ll sum[101]={};
			for(y=ma;y>=mi;y--) {
				to[y]=from[y];
				if(y+(x-i)<=pma) to[y]+=to[y+(x-i)];
				if(y-(K+1)*(i-x)<=pma) to[y]+=mo-from[y-(K+1)*(i-x)];
				while(to[y]>=mo) to[y]-=mo;
			}
			swap(from,to);
		}
		for(i=x+1;i<=N;i++) {
			int pmi=mi;
			for(y=mi;y<=cur;y++) {
				to[y]=from[y];
				if(y+(x-i)>=mi) to[y]+=to[y+(x-i)];
				if(y-(K+1)*(i-x)>=pmi) to[y]+=mo-from[y-(K+1)*(i-x)];
				while(to[y]>=mo) to[y]-=mo;
			}
			swap(from,to);
		}
		ret[x]=(from[cur]+mo-1)%mo;
		ret[(N+1)-x]=ret[x];
	}
	
	for(i=1;i<=N;i++) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
