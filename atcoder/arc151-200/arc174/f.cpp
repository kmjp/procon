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

int N;
ll L[303030],R[303030];
int Q;
ll C[303030];

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val;
	vector<pair<V,int>> ma;
	SegTree_3(){
		int i;
		val.resize(NV*2); ma.resize(NV*2);
		FOR(i,NV) val[i+NV]=0, ma[i+NV]={0,i};
		for(i=NV-1;i>=1;i--) ma[i]=min(ma[2*i],ma[2*i+1]);
	};
	
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return {1LL<<60,0};
		if(x<=l && r<=y) return ma[k];
		auto a=min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		a.first+=val[k];
		return a;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=min(ma[k*2],ma[k*2+1]);
			ma[k].first+=val[k];
		}
	}
};
SegTree_3<ll,1<<20> st[2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i]>>R[i];
	set<int> alive[2];
	for(i=N;i<=3*N;i++) {
		x=i/2;
		y=i%2;
		st[y].update(x,x+1,1LL<<60);
	}
	for(i=N-1;i>=0;i--) {
		x=i/2;
		y=i%2;
		st[y].update(x,x+1,L[i]);
		int nx=x;
		if(y==1) nx++;
		st[y^1].update(nx,N+1,R[i]-L[i]);
		alive[y].insert(i);
		st[y].update(x+1,N+1,-(R[i]-L[i]));
		while(1) {
			auto p=st[y].getval(x+1,N+1);
			if(p.first>0) break;
			ll dif=p.first;
			j=p.second*2+y;
			alive[y].erase(j);
			st[y].update(p.second,p.second+1,1LL<<60);
			auto it=alive[y^1].lower_bound(j);
			if(it!=alive[y^1].end()&&it!=alive[y^1].begin()) {
				int a=*it;
				int b=*prev(it);
				alive[y^1].erase(b);
				ll v=st[y^1].getval(b/2,b/2+1).first;
				st[y^1].update(a/2,a/2+1,v+dif);
				st[y^1].update(b/2,b/2+1,1LL<<60);
			}
		}
	}
	ll sum=-1;
	vector<ll> V;
	FOR(i,N) {
		if(alive[i%2].count(i)) {
			sum+=st[i%2].getval(i/2,i/2+1).first;
			V.push_back(sum);
		}
	}
	
	
	
	cin>>Q;
	while(Q--) {
		ll C;
		cin>>C;
		x=lower_bound(ALL(V),C)-V.begin();
		if(x==V.size()) {
			cout<<"Draw"<<endl;
		}
		else if(x%2==0) {
			cout<<"Bob"<<endl;
		}
		else {
			cout<<"Alice"<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
