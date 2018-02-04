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

int N,M;
pair<int,int> P[202020];
int L[202020],R[202020];

int X[202020],C[202020];
int cnt[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i].second;
	FOR(i,N) cin>>P[i].first;
	sort(P,P+N);
	FOR(i,N) {
		X[i]=P[i].first;
		C[i]=P[i].second;
	}
	cin>>M;
	FOR(i,M) cin>>L[i];
	FOR(i,M) cin>>R[i];
	FOR(i,M) {
		x=L[i];
		y=R[i];
		L[i]=lower_bound(X,X+N,x-y)-X;
		R[i]=lower_bound(X,X+N,x+y+1)-X;
		cnt[L[i]]++;
		cnt[R[i]]--;
	}
	ll S=0;
	FOR(i,N) {
		if(i) cnt[i]+=cnt[i-1];
		if(cnt[i]==0) S+=C[i];
		if(cnt[i]==1) bt.add(i,C[i]);
	}
	ll ma=S;
	FOR(i,M) {
		ll cnt=S+(bt(R[i]-1)-bt(L[i]-1));
		ma=max(ma,cnt);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
