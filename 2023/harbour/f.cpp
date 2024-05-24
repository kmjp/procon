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

int N,Q;
int A[1010101];
vector<int> add[1010101],Qs[1010101];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-1;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v; //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> st;
int L[1010101],R[1010101],ret[1010101];
int NV[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	FOR(i,N) {
		scanf("%d",&x);
		add[x].push_back(i);
	}
	FOR(i,Q) {
		scanf("%d%d",&L[i],&R[i]);
		Qs[R[i]].push_back(i);
	}
	int tnum=0;
	for(i=1;i<=N;i++) {
		for(j=1;j<add[i].size();j++) {
			x=add[i][j-1];
			y=add[i][j];
			k=st.getval(x,y);
			bt.add(k+1,-1);
		}
		NV[i]=NV[i-1];
		if(add[i].size()) NV[i]++;
		tnum+=add[i].size();
		FORR(v,add[i]) {
			st.update(v,i);
		}
		FORR(q,Qs[i]) {
			ret[q]=tnum-NV[L[q]-1]+bt(L[q]);
		}
	}
	FOR(i,Q) _P("%d\n",ret[i]);
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
