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

int T;
ll N,M;
ll A[202020];
ll B[202020];
pair<ll,ll> P[202020];
ll C[202020];

pair<ll,ll> hoge(ll num,ll v,ll a,ll b) {
	ll ret=0;
	num=min(num,a+b);
	ll mi=v*min(a,num)+(v+1)*max(0LL,num-a);
	ll ma=(v+1)*min(b,num)+v*max(0LL,num-b);
	return {mi,ma};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>B[i];
		FOR(i,N) {
			C[i]=0;
			P[i]={A[i],B[i]};
		}
		sort(P,P+N);
		FOR(i,N) {
			A[i]=P[i].first;
			B[i]=P[i].second;
		}
		
		ll ret=0;
		FOR(i,N) {
			ll a=min(B[i],M/A[i]);
			ret=max(ret,a*A[i]);
			
			if(i<N-1&&A[i+1]==A[i]+1) {
				ll cand=0;
				for(j=30;j>=0;j--) if(hoge(cand+(1<<j),A[i],B[i],B[i+1]).first<=M) cand+=1<<j;
				pair<ll,ll> p=hoge(cand,A[i],B[i],B[i+1]);
				ret=max(ret,min(M,p.second));
				
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
