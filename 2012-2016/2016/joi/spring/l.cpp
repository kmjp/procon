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

static ll const def=1<<30;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
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
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
};

int N;
pair<int,int> A[202020];
pair<int,int> B[202020];
multiset<int> cand[202020];
SegTree_3<int,1<<20> st;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> Xs;
	FOR(i,N) {
		cin>>A[i].second>>A[i].first;
		Xs.push_back(A[i].first);
	}
	FOR(i,N) {
		cin>>B[i].second>>B[i].first;
		Xs.push_back(B[i].first);
	}
	sort(A,A+N);
	sort(B,B+N);
	sort(ALL(Xs));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	FOR(i,N) {
		A[i].first=lower_bound(ALL(Xs),A[i].first)-Xs.begin();
		st.update(A[i].first,1<<19,1);
	}
	FOR(i,N) {
		B[i].first=lower_bound(ALL(Xs),B[i].first)-Xs.begin();
		st.update(B[i].first,1<<19,-1);
		cand[B[i].second].insert(B[i].first);
	}
	
	
	int ng=N;
	for(i=N-1;i>=0;i--) {
		auto it=cand[A[i].second].lower_bound(A[i].first);
		if(it==cand[A[i].second].end()) continue;
		x=*it;
		st.update(A[i].first,1<<19,-1);
		st.update(x,1<<19,1);
		if(st.getval(0,1<<19)>=0) {
			cand[A[i].second].erase(cand[A[i].second].find(x));
			ng--;
		}
		else {
			st.update(A[i].first,1<<19,1);
			st.update(x,1<<19,-1);
		}
		
	}
	
	
	cout<<ng<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
