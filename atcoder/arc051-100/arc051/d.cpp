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

int W,H;
int A[2020];
int B[2020];
ll SA[2020];
ll SB[2020];
int Q;
int a,b;

ll maX[2020][2020];
ll maY[2020][2020];

struct Rat {
	ll d,n;
	void norm() {
		if(d==0) {n=1;return;}
		if(n<0) d=-d,n=-n;
		ll g=__gcd((d>0)?d:-d,n);
		if(g>1) d/=g; n/=g;
	}
	Rat(ll d=0,ll n=1) : d(d),n(n) { norm();};
	Rat &set(ll d,ll n=1){ this->d=d; this->n=n; return *this;};
	Rat &operator+=(const Rat &v) {return set(d*v.n+n*v.d,n*v.n);};
	Rat &operator-=(const Rat &v) {return set(d*v.n-n*v.d,n*v.n);};
	Rat &operator*=(const Rat &v) {return set(d*v.d,n*v.n);};
};
Rat operator + (const Rat &a, const Rat &b) { return Rat(a) += b;};
Rat operator - (const Rat &a, const Rat &b) { return Rat(a) -= b;};
bool operator < (const Rat &a, const Rat &b) { return a.d*b.n<a.n*b.d;};
bool operator <= (const Rat &a, const Rat &b) { return !(b < a); };
Rat operator * (const Rat &a, const Rat &b) { return Rat(a) *= b;};

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	int cmptype=1; // 0-min 1-max
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		return cmptype^((B.second-C.second)*(B.first-A.first)<=(A.second-B.second)*(C.first-B.first));
	}
	void add(V a, V b) { // add ax+b
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	void add(vector<pair<V,V>> v) {
		sort(v.begin(),v.end());
		if(cmptype==1) reverse(v.begin(),v.end());
		for(auto r=v.begin();r!=v.end();r++) add(r->first,r->second);
	}
	
	
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			((calc(Q[M],x)<=calc(Q[M+1],x))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H;
	FOR(i,W) cin>>A[i], SA[i+1]=SA[i]+A[i];
	FOR(i,H) cin>>B[i], SB[i+1]=SB[i]+B[i];
	
	FOR(i,2020) FOR(j,2020) maX[i][j]=maY[i][j]=-1LL<<40;
	FOR(x,W) {
		if(x) FOR(i,2020) maX[x][i]=maX[x-1][i];
		for(i=1;i<=x+1;i++) maX[x][i]=max(maX[x][i],SA[x+1]-SA[x+1-i]);
	}
	FOR(y,H) {
		if(y) FOR(i,2020) maY[y][i]=maY[y-1][i];
		for(i=1;i<=y+1;i++) maY[y][i]=max(maY[y][i],SB[y+1]-SB[y+1-i]);
	}
	
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		
		vector<pair<Rat,Rat>> V;
		ConvexHull<Rat> ch;
		int w,h;
		for(h=1;h<=y;h++) V.push_back(make_pair(Rat(h),Rat(maY[y-1][h])));
		ch.add(V);
		
		ll ma=A[x-1]+B[y-1];
		for(w=1;w<=x;w++) {
			Rat r(maX[x-1][w],w);
			auto rr=ch.query(r)*Rat(w);
			rr.norm();
			assert(rr.n==1);
			ma=max(ma,rr.d);
		}
		
		cout<<ma<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
