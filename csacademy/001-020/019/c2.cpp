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

int N,X,K;
pair<int,int> P[101010];
ll S[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>K;
	P[0]={-1<<30,0};
	ll ex=0;
	FOR(i,N) {
		cin>>P[i+1].first>>P[i+1].second;
		P[i+1].first -= X;
	}
	P[N+1]={1<<30,0};
	sort(P,P+N+2);
	for(i=1;i<=N+1;i++) S[i]=S[i-1]+P[i].second;
	ll ma=0;
	x=0;
	while(P[x+1].first<0) x++;
	for(i=1;i<=N;i++) {
		if(P[i].first < -K) continue;
		if(P[i].first > K) continue;
		ll v=0;
		if(P[i].first<0) {
			int left=K+2*P[i].first;
			v=S[x]-S[i-1];
			//_P("%d %lld %lld %lld %d\n",i,v,S[x],S[i-1],left);
			if(left>0) {
				y = lower_bound(P,P+N+2,make_pair(left+1,0))-P-1;
				v+=S[y]-S[x];
			}
		}
		else {
			int left=K-2*P[i].first;
			v=S[i]-S[x];
			//_P("%d %lld %d\n",i,v,left);
			if(left>0) {
				y = lower_bound(P,P+N+2,make_pair(-left,0))-P;
				v+=S[x]-S[y-1];
			}
		}
		//_P("%d %lld\n",i,v);
		ma=max(ma,v);
	}
	
	
	cout<<ma+ex<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
