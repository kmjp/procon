#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
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
	static V const def=0;
	SegTree_3(){
		int i;
		val.resize(NV*2); ma.resize(NV*2);
		FOR(i,NV) val[i+NV]=ma[i+NV]=make_pair(0,i);
		FOR(i,NV) val[i]=make_pair(0,0);
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[2*i],ma[2*i+1]);
	};
	
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,0);
		if(x<=l && r<=y) return ma[k];
		auto a=max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
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
			ma[k]=max(ma[k*2],ma[k*2+1]);
			ma[k].first += val[k].first;
		}
	}
};

int N;
int S[101010],T[101010];
int num;

SegTree_3<int,1<<18> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> P;
	P.push_back(0);
	P.push_back(10000000);
	FOR(i,N) {
		cin>>S[i]>>T[i];
		P.push_back(S[i]);
		P.push_back(T[i]);
	}
	sort(ALL(P));
	P.erase(unique(ALL(P)),P.end());
	FOR(i,N) {
		S[i]=lower_bound(ALL(P),S[i])-P.begin();
		T[i]=lower_bound(ALL(P),T[i])-P.begin();
		st.update(S[i],T[i],1);
	}
	
	int mi=1000001;
	FOR(i,N) {
		st.update(S[i],T[i],-1);
		mi=min(mi,st.getval(0,200200).first);
		st.update(S[i],T[i],1);
	}
	if(mi==0) mi=1;
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
