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

typedef pair<int,pair<int,int>> entry;
typedef pair<entry,entry> node;


node comp(vector<entry> v,node def) {
	sort(ALL(v));
	reverse(ALL(v));
	for(int i=v.size()-1;i>=1;i--) if(v[i].second.first==v[i-1].second.first) v.erase(v.begin()+i);
	while(v.size()<2) v.push_back(def.first);
	return {v[0],v[1]};
}
node comp(node n1,node n2,node def) {
	vector<entry> v;
	if(n1.first.first>0) v.push_back(n1.first);
	if(n1.second.first>0) v.push_back(n1.second);
	if(n2.first.first>0) v.push_back(n2.first);
	if(n2.second.first>0) v.push_back(n2.second);
	return comp(v,def);
}

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V def;
	
	void init(V def_){def=def_;val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || x>=y) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1),def);
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(val[entry],v,def);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1],def);
	}
};

SegTree_1<node,1<<18> st_inc,st_dec;

int N;
int A[101010],rev[101010];
map<int,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) cin>>A[i],M[A[i]]=0;
	x=0;
	FORR(r,M) r.second=++x,rev[x]=r.first;
	
	int ma=0;
	st_inc.init({{0,{0,x+1}},{0,{0,x+1}}});
	st_dec.init({{0,{0,0}},{0,{0,0}}});
	FOR(i,N) {
		A[i]=M[A[i]];
		
		{
			// dec
			node hoge=st_dec.def, hoge2=st_dec.def;
			auto r=st_inc.getval(A[i]+1,N+2);
			int m=r.first.second.second;
			vector<entry> e,e2;
			e.push_back(r.first);
			e.push_back(r.second);
			e.push_back(st_inc.val[m+(1<<18)].second);
			r=comp(st_inc.getval(A[i]+1,m),st_inc.getval(m+1,N+2),st_inc.def);
			m=r.first.second.second;
			e.push_back(r.first);
			e.push_back(r.second);
			e.push_back(st_inc.val[m+(1<<18)].second);
			sort(ALL(e));
			e.erase(unique(ALL(e)),e.end());
			FORR(rr,e) if(A[i]!=rr.second.first) e2.push_back({rr.first+1,{rr.second.second,A[i]}}), ma=max(ma,rr.first+1);
			st_dec.update(A[i],comp(e2,st_dec.def));
		}
		{
			// inc
			node hoge=st_inc.def, hoge2=st_inc.def;
			auto r=st_dec.getval(0,A[i]);
			int m=r.first.second.second;
			vector<entry> e,e2;
			e.push_back(r.first);
			e.push_back(r.second);
			e.push_back(st_dec.val[m+(1<<18)].second);
			r=comp(st_dec.getval(0,m),st_dec.getval(m+1,A[i]),st_dec.def);
			e.push_back(r.first);
			e.push_back(r.second);
			m=r.first.second.second;
			e.push_back(st_dec.val[m+(1<<18)].second);
			e.erase(unique(ALL(e)),e.end());
			FORR(rr,e) if(A[i]!=rr.second.first) e2.push_back({rr.first+1,{rr.second.second,A[i]}}), ma=max(ma,rr.first+1);
			st_inc.update(A[i],comp(e2,st_inc.def));
		}
	}
	if(ma<3) ma=0;
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
