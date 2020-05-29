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

int W;
int A[101010];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<30;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<int,1<<20> LS,RS;
int ma[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W;
	FOR(i,W) {
		cin>>A[i];
		if(A[i]<0) {
			LS.update(i,-A[i]+i);
			RS.update(i,-A[i]-i);
		}
	}
	int pre=-1;
	FOR(i,W) {
		if(A[i]==0) pre=i;
		if(A[i]>0 && pre>=0) {
			x=LS.getval(pre+1,i)-i;
			ma[i]=max(ma[i],min(x,A[i]));
		}
	}
	pre=W;
	for(i=W-1;i>=0;i--) {
		if(A[i]==0) pre=i;
		if(A[i]>0 && pre<W) {
			x=RS.getval(i+1,pre)+i;
			ma[i]=max(ma[i],min(x,A[i]));
		}
	}
	int ret=0;
	FOR(i,W) ret+=ma[i];
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
