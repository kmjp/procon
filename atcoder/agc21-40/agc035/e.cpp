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
ll mo;
ll from[155][155][155];
ll to[155][155][155];

ll hoge(int N) {
	ll from[151]={};
	ll to[151];
	
	from[0]=1;
	int i,j;
	FOR(i,N) {
		ZERO(to);
		FOR(j,K+1) {
			(to[0]+=from[j])%=mo;
			if(j+1<=K) (to[j+1]+=from[j])%=mo;
		}
		
		swap(from,to);
	}
	
	ll ret=0;
	FOR(i,N+1) ret+=from[i];
	return ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>mo;
	
	if(K%2==0) {
		K/=2;
		cout<<hoge(N/2)*hoge((N+1)/2)%mo<<endl;
	}
	else {
		from[0][1][154]=1;
		for(i=2;i<=N+1;i++) {
			ZERO(to);
			
			int a,b;
			for(a=0;a<i;a+=2) for(b=1;b<i;b+=2) for(j=max(a,b);j<=154;j++) if(from[a][b][j]) {
				ll v=from[a][b][j];
				//cout<<i<<" "<<a<<" "<<b<<" "<<j<<" "<<v<<endl;
				int nex;
				if(i%2==0) {
					// keep
					nex=j;
					if(b+2+K>=i) nex=154;
					(to[i][b][nex]+=v)%=mo;
					
					// remove
					if(i==j) continue;
					nex=j;
					if(b!=i-1 && a==i-2) nex=min({154,j,i+K});
					(to[a][b][nex]+=v)%=mo;
				}
				else {
					// keep
					nex=j;
					if(a+2+K>=i) nex=154;
					(to[a][i][nex]+=v)%=mo;
					
					// remove
					if(i==j) continue;
					nex=j;
					if(a!=i-1 && b==i-2) nex=min({154,j,i+K});
					(to[a][b][nex]+=v)%=mo;
				}
			
			}
			swap(from,to);
		}
		
		ll ret=0;
		FOR(x,155) FOR(y,155) FOR(j,155) ret+=from[x][y][j];
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
