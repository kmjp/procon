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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-10000000;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<int,1<<20> st1,st2;
int N,M,ma;
int S[101010],L[101010];
pair<int,int> P[101010];
int V1[101010],V2[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>S[i]>>L[i];
		P[i]={S[i]+L[i],S[i]};
	}
	FOR(i,M+1) st1.update(i,0);
	FOR(i,M+1) st2.update(i,-2000000),V2[i]=-2000000;
	
	sort(P,P+N);
	FOR(i,N) {
		int le=P[i].second;
		int ri=P[i].first;
		
		int hoge1=st1.getval(0,le+1)+ri-le;
		int hoge2=st2.getval(le,ri)+ri+le;
		x = max(hoge1,hoge2);
		ma=max(ma,x);
		
		if(x>V1[ri]) V1[ri]=x, st1.update(ri,V1[ri]);
		if(x-2*ri>V2[ri]) V2[ri]=x-2*ri, st2.update(ri,V2[ri]);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
