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

int C;
int N;
pair<int,int> P[101010];
int A[101010],B[101010],S[101010];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-1<<20;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

int ok(int d) {
	int i,ptr;
	
	SegTree_1<int,1<<20> st;
	
	ptr=0;
	FOR(i,N) {
		if(S[i]<d) continue;
		while(A[i]>=A[ptr]+d) {
			if(S[ptr]>=d) st.update(B[ptr],A[ptr]);
			ptr++;
		}
		
		int ma = st.getval(max(0,B[i]+d-C), A[i]-d+1);
		ma=max(ma, st.getval(A[i]+d, B[i]-d+1));
		ma=max(ma, st.getval(B[i]+d, min(C,A[i]-d+C+1)));
		if(ma>=0 && ma+C >= B[i]+d) return 1;
	}
	return 0;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C;
	FOR(i,N) {
		cin>>P[i].first>>P[i].second;
		if(P[i].second<P[i].first) swap(P[i].first,P[i].second);
	}
	
	sort(P,P+N);
	FOR(i,N) {
		A[i]=P[i].first;
		B[i]=P[i].second;
		S[i]=min(B[i]-A[i],C-(B[i]-A[i]));
	}
	
	int ret=0;
	for(i=20;i>=0;i--) if(ok(ret+(1<<i))) ret+=1<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
