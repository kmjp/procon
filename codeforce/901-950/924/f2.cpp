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

// [0,l]‚ÌŠÔ‚É‹æØ‚è‚ğ“ü‚ê‚½‚èæ‚Á‚½‚èBadd/del‚Ìˆø”‚Í’·‚³

template<class V> struct RangeManager {
	V len;
	set<V> S;
	void add(V l) {
	}
	void del(V l) {
	}
	void init(V l) {
		len=l;
		S.clear();
		S.insert(0);
		S.insert(l);
		add(l);
	}
	bool change(V p) {
		if(p<=0||p>=len) return 0;
		if(S.count(p)) {
			merge(p);
			return 0;
		}
		else {
			split(p);
			return 1;
		}
	}
	bool split(V p) {
		if(p<=0||p>=len||S.count(p)) return 0;
		auto ri=S.lower_bound(p);
		auto lef=prev(ri);
		del(*ri-*lef);
		add(p-*lef);
		add(*ri-p);
		S.insert(p);
		return 1;
	}
	bool merge(V p) {
		if(p<=0||p>=len||S.count(p)==0) return 0;
		auto it=S.find(p);
		auto lef=prev(it),ri=next(it);
		del(p-*lef);
		del(*ri-p);
		add(*ri-*lef);
		S.erase(it);
		return 1;
		
	}
};

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};

ll ret;

template<class V> struct RangeManager2 {
	V len;
	set<V> S;
	map<V,int> M;
	BIT<int,19> bta,btb;
	BIT<ll,19> btc,btd;
	RangeManager2 *other;
	void add(V l) {
		M[l]++;
		bta.add(l,1);
		btb.add(l,l);
		btc.add(l,1LL*l*(l+1)/2);
		btd.add(l,1LL*l*(l+1)*(2*l+1)/6-1LL*l*l*(l+1)/2);
		if(other) {
			ll a=1;
			ll b=l;
			ll c=1LL*l*(l+1)/2;
			ll d=1LL*l*(l+1)*(2*l+1)/6-1LL*l*l*(l+1)/2;
			ret+=(d*(other->bta(303030)-other->bta(l))+c*(other->btb(303030)-other->btb(l)));
			ret+=(a*other->btd(l)+b*other->btc(l));
		}

	}
	void del(V l) {
		M[l]--;
		if(M[l]==0) M.erase(l);
		bta.add(l,-1);
		btb.add(l,-l);
		btc.add(l,-1LL*l*(l+1)/2);
		btd.add(l,-(1LL*l*(l+1)*(2*l+1)/6-1LL*l*l*(l+1)/2));
		if(other) {
			ll a=1;
			ll b=l;
			ll c=1LL*l*(l+1)/2;
			ll d=1LL*l*(l+1)*(2*l+1)/6-1LL*l*l*(l+1)/2;
			ret-=(d*(other->bta(303030)-other->bta(l))+c*(other->btb(303030)-other->btb(l)));
			ret-=(a*other->btd(l)+b*other->btc(l));
		}
	}
	void init(V l) {
		len=l;
		S.clear();
		S.insert(0);
		S.insert(l);
		add(l);
		other=NULL;
	}
	bool change(V p) {
		if(p<=0||p>=len) return 0;
		if(S.count(p)) {
			merge(p);
			return 0;
		}
		else {
			split(p);
			return 1;
		}
	}
	bool split(V p) {
		if(p<=0||p>=len||S.count(p)) return 0;
		auto ri=S.lower_bound(p);
		auto lef=prev(ri);
		del(*ri-*lef);
		add(p-*lef);
		add(*ri-p);
		S.insert(p);
		return 1;
	}
	bool merge(V p) {
		if(p<=0||p>=len||S.count(p)==0) return 0;
		auto it=S.find(p);
		auto lef=prev(it),ri=next(it);
		del(p-*lef);
		del(*ri-p);
		add(*ri-*lef);
		S.erase(it);
		return 1;
		
	}
};

int H,W,Q;
int A[303030],B[303030];

RangeManager2<int> AM,BM;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&H,&W,&Q);
	AM.init(H);
	BM.init(W);
	
	FOR(i,H) scanf("%d",&A[i]);
	FOR(i,H-1) {
		A[i]=A[i+1]-A[i];
		if(A[i]==0) AM.split(i+1);
	}
	FOR(i,W) scanf("%d",&B[i]);
	FOR(i,W-1) {
		B[i]=B[i+1]-B[i];
		if(B[i]==0) BM.split(i+1);
	}
	AM.other=&BM;
	BM.other=&AM;
	
	ret=0;
	FORR2(x,y,AM.M) {
		ll a=1;
		ll b=x;
		ll c=1LL*x*(x+1)/2;
		ll d=1LL*x*(x+1)*(2*x+1)/6-1LL*x*x*(x+1)/2;
		ret+=y*(d*(BM.bta(303030)-BM.bta(x))+c*(BM.btb(303030)-BM.btb(x)));
		ret+=y*(a*BM.btd(x)+b*BM.btc(x));
	}
	_P("%lld\n",ret);
	while(Q--) {
		
		int L,R,X;
		scanf("%d%d%d%d",&i,&L,&R,&X);
		L--;
		R--;
		if(i==1) {
			if(L) {
				if(A[L-1]==0) AM.merge(L);
				A[L-1]+=X;
				if(A[L-1]==0) AM.split(L);
			}
			if(R<H-1) {
				if(A[R]==0) AM.merge(R+1);
				A[R]+=-X;
				if(A[R]==0) AM.split(R+1);
			}
		}
		else {
			if(L) {
				if(B[L-1]==0) BM.merge(L);
				B[L-1]+=X;
				if(B[L-1]==0) BM.split(L);
			}
			if(R<W-1) {
				if(B[R]==0) BM.merge(R+1);
				B[R]+=-X;
				if(B[R]==0) BM.split(R+1);
			}
		}
		_P("%lld\n",ret);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
