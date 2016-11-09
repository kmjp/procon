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

template<class V,int NV> class SegTree_3 {
public:
	vector<pair<V,int> > val;
	vector<pair<V,int> > ma;
	static V const def=1LL<<50;
	SegTree_3(){
		int i;
		val.resize(NV*2); ma.resize(NV*2);
		FOR(i,NV) val[i+NV]=ma[i+NV]=make_pair(0,i);
		FOR(i,NV) val[i]=make_pair(0,0);
		for(i=NV-1;i>=1;i--) ma[i]=min(ma[2*i],ma[2*i+1]);
	};
	
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,0);
		if(x<=l && r<=y) return ma[k];
		auto a=min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		a.first += val[k].first;
		return a;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k].first+=v;
			ma[k].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=min(ma[k*2],ma[k*2+1]);
			ma[k].first += val[k].first;
		}
	}
};
int N;
ll A[101010];
ll B[101010];
ll SA[101010];
ll SB[101010];

SegTree_3<ll,1<<19> D,F;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N) {
		cin>>A[i];
		SA[i+1]=SA[i]+A[i];
	}
	ll ret=0;
	FOR(i,N) {
		cin>>B[i];
		SB[i+1]=SB[i]+B[i];
		if(SA[i+1]>SB[i+1]) {
			F.update(i,i+1,SA[i+1]-SB[i+1]);
			D.update(0,i+1,-1);
		}
		else {
			F.update(i,i+1,1LL<<50);
			D.update(0,i+1,1);
		}
		ret += abs(SB[i+1]-SA[i+1]);
	}
	
	ll flow=SA[N]-SB[N];
	while(flow) {
		
		while(1) {
			auto f=F.getval(0,N);
			if(f.first>0) break;
			D.update(0,f.second+1,2);
			F.update(f.second,f.second+1,1LL<<50);
		}
		
		auto p = D.getval(0,N);
		if(p.first>=1LL<<40 || p.first==0) break;
		
		ll d = min(flow,F.getval(p.second,N).first);
		ret += p.first*d;
		flow-=d;
		F.update(p.second,N,-d);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
