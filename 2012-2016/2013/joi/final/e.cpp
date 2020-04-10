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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return -1<<20;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<int,1<<19> st;

int N;
int A[101010];
vector<int> Xs;
int cat[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int ok=0;
	FOR(i,N) {
		cin>>A[i];
		if(i&&A[i-1]>=A[i]) ok=1;
		Xs.push_back(A[i]);
	}
	
	if(ok==0) return _P("1\n");
	
	sort(ALL(Xs));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	ll ret=0;
	FOR(i,N) {
		A[i]=lower_bound(ALL(Xs),A[i])-Xs.begin();
		ret+=bt(1<<19)-bt(A[i]);
		bt.add(A[i],1);
	}
	
	vector<pair<int,int>> L;
	vector<int> R;
	FOR(i,N) {
		if(L.empty() || A[i]>L.back().first) L.push_back({A[i],i}), cat[i]|=1;
	}
	for(i=N-1;i>=0;i--) {
		if(R.empty() || A[i]<A[R.back()]) R.push_back(i), cat[i]|=2;
	}
	int ma=0;
	int CR=0;
	multiset<pair<int,pair<int,int>>> S1,S2;
	FOR(i,N) {
		
		if(cat[i]&1) {
			CR++;
		}
		else if(cat[i]&2) {
			while(S1.size() && S1.begin()->first<=A[i]) {
				st.update(S1.begin()->second.first,S1.begin()->second.second,-1);
				S1.erase(S1.begin());
			}
			while(S2.size() && S2.begin()->first<A[i]) {
				st.update(S2.begin()->second.first,S2.begin()->second.second,-1);
				S2.erase(S2.begin());
			}
			x=lower_bound(ALL(L),make_pair(A[i]+1,0))-L.begin();
			if(x<CR) {
				ma=max(ma,1+st.getval(x,CR));
			}
		}
		else {
			x=lower_bound(ALL(L),make_pair(A[i],0))-L.begin();
			st.update(x,CR,1);
			S1.insert({A[i],{x,CR}});
			x=lower_bound(ALL(L),make_pair(A[i]+1,0))-L.begin();
			st.update(x,CR,1);
			S2.insert({A[i],{x,CR}});
		}
		
		
	}
	//cout<<ret<<" "<<ma<<endl;
	cout<<ret-ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
