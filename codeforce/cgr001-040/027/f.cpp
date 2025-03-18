#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N,X;
ll A[2020];
vector<int> E[2020];

int L[202020],R[202020],re[202020],D[2020],P[2020];
int id;

ll tar[2020];

void dfs(int cur) {
	L[cur]=id++;
	re[L[cur]]=cur;
	FORR(e,E[cur]) if(e!=P[cur]) D[e]=D[cur]+1, P[e]=cur, dfs(e);
	R[cur]=id;
}

ll ok(int cur) {
	ll need=0;
	FORR(e,E[cur]) if(P[e]==cur) {
		need+=ok(e);
		need=min(need,1LL<<60);
	}
	if(A[cur]>tar[cur]) {
		need+=A[cur]-tar[cur];
		need=min(need,1LL<<60);
	}
	else {
		if(need<=tar[cur]-A[cur]) {
			ll dif=tar[cur]-A[cur]-need;
			return dif%2;
		}
		need-=tar[cur]-A[cur];
	}
	return need;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>X;
		X--;
		FOR(i,N) E[i].clear(), P[i]=-1;
		ll SN=0;
		FOR(i,N) {
			cin>>A[i];
			SN+=A[i];
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		id=0;
		dfs(X);
		
		ll ret=1LL<<60;
		FOR(i,N) {
			ll cur=(1LL<<32)-1;
			for(j=31;j>=0;j--) {
				ll sum=(cur-(1LL<<j))*2*N+i;
				if(sum%2!=SN%2) break;
				FOR(k,N) tar[k]=(cur-(1LL<<j))*2;
				FOR(k,i) tar[k]++;
				if(ok(X)==0) {
					ret=min(ret,sum);
					cur-=1LL<<j;
				}
			}
			cur=(1LL<<32)-1;
			for(j=31;j>=0;j--) {
				ll sum=((cur-(1LL<<j))*2+1)*N+i;
				if(sum%2!=SN%2) break;
				FOR(k,N) tar[k]=(cur-(1LL<<j))*2+1;
				FOR(k,i) tar[k]++;
				if(ok(X)==0) {
					ret=min(ret,sum);
					cur-=1LL<<j;
				}
			}
			
		}
		
		
		cout<<ret<<endl;
		
		
			
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
