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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
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
SegTree_1<int,1<<16> st[202];

int N,Q;
int A[101010];
int L[101010],R[101010],K[101010];

unsigned long long BM[700];
const int D=201;
vector<pair<int,int>> E[205];

int num[40505];
int ret[40505];

int bset(int v) {
	BM[v>>6] |= 1ULL<<(v&63);
}
int bclear(int v) {
	BM[v>>6] &= (~0ULL)^(1ULL<<(v&63));
}
int hoge(int k) {
	int ma=0,x=0;;
	for(int i=0;i*64<=40000;i++) {
		if(x+63<k) {
			if(BM[i]) ma=max(ma,x+63-__builtin_clzll(BM[i]));
			x+=64;
			if(x==k) x=0;
		}
		else {
			int left=k-x;
			ll b=(BM[i]<<(64-left))>>(64-left);
			if(b) ma=max(ma,x+63-__builtin_clzll(b));
			
			x=0;
			b=BM[i]>>left;
			if(b) ma=max(ma,x+63-__builtin_clzll(b));
			x=64-left;
		}
		
	}
	return ma;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		for(j=1;j<=64;j++) {
			st[j].update(i,A[i]%j);
		}
	}
	FOR(i,Q) {
		cin>>L[i]>>R[i]>>K[i];
		L[i]--;
		if(K[i]<=64) {
			ret[i]=st[K[i]].getval(L[i],R[i]);
		}
		else {
			E[L[i]/D].push_back({R[i],i});
		}
	}
	
	FOR(i,202) if(E[i].size()) {
		ZERO(num);
		ZERO(BM);
		int LL=0,RR=0;
		LL=RR=i*D;
		sort(ALL(E[i]));
		FORR(e,E[i]) {
			x=e.second;
			while(RR<R[x]) {
				if(++num[A[RR]]==1) bset(A[RR]);
				RR++;
			}
			while(L[x]<LL) {
				LL--;
				if(++num[A[LL]]==1) bset(A[LL]);
			}
			while(L[x]>LL) {
				if(--num[A[LL]]==0) bclear(A[LL]);
				LL++;
			}
			ret[x]=hoge(K[x]);
		}
		
	}
	
	FOR(i,Q) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
