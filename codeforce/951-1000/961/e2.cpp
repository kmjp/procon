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
ll A[202020];
ll B[202020];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		int a,b,c,v=0;
		FOR(a,2) FOR(b,2) FOR(c,2) {
			if((l&(1<<(a+b*2)))&&(r&(1<<(b+c*2)))) {
				v|=1<<(a+c*2);
			}
		}
		return v;
	};
	
	SegTree_1(){val=vector<V>(NV*2,9);};
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> st;

vector<int> ev[808080];

void update(int i,ll mi,ll ma) {
	ll a=B[i*2];
	ll b=B[i*2+1];
	ll c=B[(i*2-1+2*N)%(2*N)];
	ll d=B[(i*2+2+2*N)%(2*N)];
	int mask=0;
	if(a+b>=mi&&a+b<=ma) mask|=1;
	if(c+b>=mi&&c+b<=ma) mask|=2;
	if(a+d>=mi&&a+d<=ma) mask|=4;
	if(c+d>=mi&&c+d<=ma) mask|=8;
	st.update(i,mask);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,2*N) cin>>A[i];
		if(N==1) {
			cout<<0<<endl;
			continue;
		}
		if(N%2==0) {
			ll ma=0;
			ll mi=1LL<<60;
			FOR(i,N/2) {
				ll a=A[2*i];
				ll b=A[2*i+1];
				ll c=A[2*i+N];
				ll d=A[2*i+N+1];
				if(a>c) swap(a,c);
				if(b<d) swap(b,d);
				ma=max(ma,max(a+b,c+d));
				mi=min(mi,min(a+b,c+d));
				
			}
			cout<<ma-mi<<endl;
			continue;
		}
		
		FOR(i,N) st.update(i,0);
		x=0;
		FOR(i,N) {
			B[i*2]=A[x];
			x^=1;
			B[i*2+1]=A[x];
			x=(x+N)%(2*N);
			
		}
		vector<ll> cand;
		FOR(i,N) {
			ll a=B[i*2];
			ll b=B[i*2+1];
			ll c=B[(i*2-1+2*N)%(2*N)];
			ll d=B[(i*2+2+2*N)%(2*N)];
			cand.push_back(a+b);
			cand.push_back(c+b);
			cand.push_back(a+d);
			cand.push_back(c+d);
		}
		sort(ALL(cand));
		cand.erase(unique(ALL(cand)),cand.end());
		FOR(i,cand.size()+4) ev[i].clear();
		FOR(i,N) {
			ll a=B[i*2];
			ll b=B[i*2+1];
			ll c=B[(i*2-1+2*N)%(2*N)];
			ll d=B[(i*2+2+2*N)%(2*N)];
			vector<ll> C={a+b,c+b,a+d,c+d};
			FORR(v,C) {
				x=lower_bound(ALL(cand),v)-cand.begin();
				if(x) ev[x-1].push_back(i);
				ev[x].push_back(i);
				ev[x+1].push_back(i);
			}
		}
		ll ret=1LL<<60;
		for(int L=0,R=0;L<cand.size();L++) {
			FORR(e,ev[L]) {
				if(L==R) {
					update(e,-1,-1);
				}
				else {
					update(e,cand[L],cand[R-1]);
				}
			}
			while(((st.val[1]&9)==0)&&R<cand.size()) {
				FORR(e,ev[R]) update(e,cand[L],cand[R]);
				R++;
			}
			if(st.val[1]&9) {
				ret=min(ret,cand[R-1]-cand[L]);
			}
		}
		cout<<ret<<endl;
		
		FOR(i,N) st.update(i,9);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
