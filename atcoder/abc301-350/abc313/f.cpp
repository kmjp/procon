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

int N,M;
ll E[44];
int D[44];
int X[44],A[44],B[44];
double dp[44];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	int sum=0;
	FOR(i,N) {
		cin>>A[i]>>B[i];
	}
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		if(x==y) {
			if(A[x]<B[x]) swap(A[x],B[x]);
		}
		else {
			E[x]|=1LL<<y;
			E[y]|=1LL<<x;
		}
	}
	
	ll P=0,Q=0;
	FOR(i,N) {
		sum+=2*A[i];
		if(E[i]) {
			D[i]=A[i]-B[i];
			if(D[i]>=0) P|=1LL<<i;
			else Q|=1LL<<i;
		}
	}
	
	ll ret=-1LL<<60;
	
	if(__builtin_popcount(P)<=__builtin_popcount(Q)) {
		for(ll mask=P;mask>=0;mask--) {
			mask&=P;
			ll turn=mask;
			FOR(i,N) if((Q&(1LL<<i))&&(((mask|Q)&(E[i])))) turn |=1LL<<i;
			ll pat=sum;
			FOR(i,N) {
				if(turn&(1LL<<i)) pat-=D[i];
			}
			ret=max(ret,pat);
		}
	}
	else {
		ll start=0;
		FOR(i,N) FOR(j,i) if((Q&(1LL<<i))&&(Q&(1LL<<j))&&(E[i]&(1LL<<j))) start|=(1LL<<i)|(1LL<<j);
		FOR(i,N) if(start&(1LL<<i)) sum-=D[i];
		map<ll,ll> from;
		from[start]=sum;
		FOR(i,N) if(P&(1LL<<i)) {
			map<ll,ll> to=from;
			FORR2(a,b,from) {
				ll nm=a|(E[i]&Q);
				ll nv=b-D[i];
				FOR(j,N) if((nm^a)&(1LL<<j)) nv-=D[j];
				if(to.count(nm)==0) to[nm]=nv;
				to[nm]=max(to[nm],nv);
			}
			swap(from,to);
		}
		
		FORR2(a,b,from) ret=max(ret,b);
		
	}
	
	_P("%.12lf\n",ret/2.0);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
