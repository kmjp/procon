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
int A[303030];
vector<int> L,R;
const ll mo=998244353;
ll dpL[303030];
ll dpR[303030];
ll p2[303030],r2[303030];
vector<int> pos[303030];

template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) { if(e<0) return 0; ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; v=(v%mo+mo)%mo; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<ll,20> bt,sum;



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=r2[0]=1;
	FOR(i,300010) {
		p2[i+1]=p2[i]*2%mo;
		r2[i+1]=r2[i]*(mo+1)/2%mo;
	}
	
	cin>>T;
	while(T--) {
		cin>>N;
		L.clear();
		R.clear();
		vector<int> As;
		FOR(i,N) {
			cin>>A[i];
			As.push_back(A[i]);
			pos[i].clear();
		}
		FOR(i,N+2) dpL[i]=dpR[i]=0;
		sort(ALL(As));
		As.erase(unique(ALL(As)),As.end());
		FOR(i,N) {
			A[i]=lower_bound(ALL(As),A[i])-As.begin();
			pos[A[i]].push_back(i);
			if(L.empty()||L.back()<A[i]) L.push_back(A[i]);
		}
		for(i=N-1;i>=0;i--) if(R.empty()||R.back()<A[i]) R.push_back(A[i]);
		
		FOR(i,L[0]+1) FORR(p,pos[i]) bt.add(p,1);
		FORR(p,pos[L[0]]) dpL[p]=1;
		for(i=1;i<L.size();i++) {
			FORR(p,pos[L[i-1]]) sum.add(p,dpL[p]*p2[bt(N)-bt(p)]%mo);
			FORR(p,pos[L[i]]) dpL[p]=sum(p)%mo*r2[bt(N)-bt(p)]%mo;
			FORR(p,pos[L[i-1]]) sum.add(p,mo-dpL[p]*p2[bt(N)-bt(p)]%mo);
			for(x=L[i-1]+1;x<=L[i];x++) FORR(p,pos[x]) bt.add(p,1);
		}
		
		FOR(i,N+1) {
			bt.add(i,-bt(i));
			sum.add(i,mo-sum(i));
		}
		FOR(i,R[0]+1) FORR(p,pos[i]) bt.add(p,1);
		FORR(p,pos[R[0]]) dpR[p]=1;
		for(i=1;i<R.size();i++) {
			FORR(p,pos[R[i-1]])	sum.add(p,dpR[p]*p2[bt(p-1)]%mo);
			FORR(p,pos[R[i]]) dpR[p]=(sum(N)%mo-sum(p)%mo+mo)%mo*r2[bt(p)]%mo;
			FORR(p,pos[R[i-1]]) sum.add(p,mo-dpR[p]*p2[bt(p-1)]%mo);
			for(x=R[i-1]+1;x<=R[i];x++) FORR(p,pos[x]) bt.add(p,1);
		}
		
		FOR(i,N+1) {
			bt.add(i,-bt(i));
			sum.add(i,mo-bt(i));
		}
		ll ret=0;
		ll s=0;
		FORR(p,pos[L.back()]) {
			(ret+=dpL[p]*dpR[p])%=mo;
			(ret+=dpR[p]*p2[p]%mo*s)%=mo;
			(s+=dpL[p]*r2[p+1])%=mo;
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
