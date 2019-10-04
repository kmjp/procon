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
	vector<vector<V>> val,sum;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val.resize(NV*2);sum.resize(NV*2);};
	V getval(int x,int y,int v,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) {
			int i=lower_bound(ALL(val[k]),v+1)-val[k].begin();
			return sum[k].back()-sum[k][i]-v*(val[k].size()-i);
		}
		return getval(x,y,v,l,(l+r)/2,k*2)+getval(x,y,v,(l+r)/2,r,k*2+1);
	}
	void set(int entry,V v) {
		val[entry+NV].clear();
		val[entry+NV].push_back(v);
		sum[entry+NV].clear();
		sum[entry+NV].push_back(0);
		sum[entry+NV].push_back(v);
	}
	void build() {
		for(int i=NV-1;i>=1;i--) {
			val[i].clear();
			int a=0,b=0;
			int x=i*2,y=i*2+1;
			while(a<val[x].size() || b<val[y].size()) {
				if(a==val[x].size()) {
					val[i].push_back(val[y][b++]);
				}
				else if(b==val[y].size()) {
					val[i].push_back(val[x][a++]);
				}
				else if(val[x][a]<val[y][b]) {
					val[i].push_back(val[x][a++]);
				}
				else {
					val[i].push_back(val[y][b++]);
				}
			}
			sum[i].clear();
			sum[i].push_back(0);
			FORR(v,val[i]) sum[i].push_back(sum[i].back()+v);
		}
	}
};
SegTree_1<ll,1<<18> st;

int N,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>x;
		st.set(i+1,x);
	}
	st.build();
	FOR(i,Q) {
		int L,R,X;
		cin>>j>>L>>R>>X;
		cout<<st.getval(L,R+1,X)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
