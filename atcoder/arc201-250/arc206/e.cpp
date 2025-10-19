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

int T,N;
ll U[505050],D[505050],L[505050],R[505050];

ll hoge(ll L[],ll R[]) {
	int i;
	multiset<ll> L1,L2,R1,R2;
	L1.insert(1LL<<50);
	R1.insert(1LL<<50);
	L2.insert(1LL<<50);
	R2.insert(1LL<<50);
	L1.insert(L[0]),R1.insert(R[0]);
	FOR(i,N) L2.insert(L[i]),R2.insert(R[i]);
	ll ret=1LL<<60;
	
	FOR(i,N) {
		ll a=*L1.begin()+*L2.begin();
		if(*L1.begin()==*L2.begin()&&L[i]==*L1.begin()) a=min(*L1.begin()+*next(L2.begin()),*L2.begin()+*next(L1.begin()));
		ll b=*R1.begin()+*R2.begin();
		if(*R1.begin()==*R2.begin()&&R[i]==*R1.begin()) b=min(*R1.begin()+*next(R2.begin()),*R2.begin()+*next(R1.begin()));
		
		ret=min(ret,a+b);
		L2.erase(L2.find(L[i]));
		R2.erase(R2.find(R[i]));
		L1.insert(L[i+1]);
		R1.insert(R[i+1]);
	}
	L1.clear();
	L2.clear();
	R1.clear();
	R2.clear();
	L1.insert(1LL<<50);
	L2.insert(1LL<<50);
	R1.insert(1LL<<50);
	R2.insert(1LL<<50);
	for(i=2;i<N;i++) L2.insert(L[i]),R2.insert(R[i]);
	for(i=0;i<N-1;i++) {
		ret=min(ret,L[i]+*L1.begin()+R[i+1]+*R2.begin());
		ret=min(ret,R[i]+*R1.begin()+L[i+1]+*L2.begin());
		L1.insert(L[i]);
		R1.insert(R[i]);
		if(i+2<N) {
			L2.erase(L2.find(L[i+2]));
			R2.erase(R2.find(R[i+2]));
		}
	}
	
	
	return ret;
}
pair<ll,ll> hoge2(ll L[],ll R[]) {
	int i;
	multiset<ll> L1,L2,R1,R2;
	L1.insert(1LL<<50);
	R1.insert(1LL<<50);
	L2.insert(1LL<<50);
	R2.insert(1LL<<50);
	L1.insert(L[0]),R1.insert(R[0]);
	for(i=1;i<N;i++) L2.insert(L[i]),R2.insert(R[i]);
	ll r1=1LL<<60,r2=1LL<<60;
	
	for(i=0;i<N-1;i++) {
		r1=min(r1,*L1.begin()+*next(L1.begin())+*R2.begin()+*next(R2.begin()));
		r2=min(r2,*L2.begin()+*next(L2.begin())+*R1.begin()+*next(R1.begin()));
		L1.insert(L[i+1]);
		R1.insert(R[i+1]);
		L2.erase(L2.find(L[i+1]));
		R2.erase(R2.find(R[i+1]));
	}
	return {r1,r2};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		N-=2;
		FOR(i,N) cin>>U[i];
		FOR(i,N) cin>>D[i];
		FOR(i,N) cin>>L[i];
		FOR(i,N) cin>>R[i];
		ll ret1=hoge(U,D);
		ll ret2=hoge(L,R);
		pair<ll,ll> p1=hoge2(U,D);
		pair<ll,ll> p2=hoge2(L,R);
		
		sort(U,U+N);
		sort(D,D+N);
		sort(L,L+N);
		sort(R,R+N);
		ret2+=U[0]+U[1]+D[0]+D[1];
		ret1+=L[0]+L[1]+R[0]+R[1];
		ll ret=min({ret1,ret2,p1.first+p2.first,p1.second+p2.second});
		
		if(N>=3) {
			// 5Žè
			ret=min(ret,U[0]+U[1]+U[2]+D[0]+D[1]+D[2]+L[0]+L[1]+R[0]+R[1]);
			ret=min(ret,L[0]+L[1]+L[2]+R[0]+R[1]+R[2]+U[0]+U[1]+D[0]+D[1]);
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
