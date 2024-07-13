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

template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){
		pair<V,int> a=l;
		a.first.first=min(l.first.first,r.first.first);
		if(l.first.first>r.first.second) {
			a.first.second=r.first.second;
			a.second=r.second;
		}
		return a;
	}
	SegTree_Pair(){
		val.resize(NV*2);
		int i;
		FOR(i,NV) val[i+NV]=make_pair(make_pair(1<<30,1<<30),1<<30);
		for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
	};
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_Pair<pair<int,int>,1<<20> st;
int N;
int A[404040];
int L[202020],R[202020];
int num[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(L);
	cin>>N;
	FOR(i,2*N) {
		cin>>A[i];
		A[i]--;
		if(L[A[i]]<0) {
			L[A[i]]=i;
		}
		else {
			R[A[i]]=i;
		}
	}
	FOR(i,2*N) {
		if(L[A[i]]==i) {
			st.update(i,{R[A[i]],R[A[i]]});
		}
	}
	set<int> cand;
	while(1) {
		while(1) {
			auto p=st.val[1];
			i=p.second;
			if(p.first.second==1<<30) break;
			cand.insert(A[i]);
			st.update(i,{R[A[i]],1<<30});
		}
		if(cand.empty()) break;
		x=*cand.begin();
		cand.erase(x);
		cout<<x+1<<" "<<x+1<<" ";
		st.update(L[x],{1<<30,1<<30});
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
