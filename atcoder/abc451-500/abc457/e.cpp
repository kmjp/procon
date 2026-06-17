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


vector<int> L[202020];
vector<int> R[202020];

template<class V,int NV> class SegTree_mi {
public:
	vector<V> val;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_mi(){val=vector<V>(NV*2,1<<30);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return 1<<30;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_mi<int,1<<20> st;

int N,M;
int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		L[x].push_back(y+1);
		R[y+1].push_back(x);
		st.update(x,y+1);
	}
	FOR(i,N+2) {
		sort(ALL(L[i]));
		sort(ALL(R[i]));
	}
	cin>>Q;
	while(Q--) {
		int TL,TR;
		cin>>TL>>TR;
		TR++;
		x=lower_bound(ALL(L[TL]),TR+1)-L[TL].begin();
		if(x==0) {
			cout<<"No"<<endl;
			continue;
		}
		if(L[TL][x-1]==TR) {
			if(x>1||st.getval(TL+1,TR)<=TR) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
		}
		else {
			y=lower_bound(ALL(R[TR]),TL)-R[TR].begin();
			if(y<R[TR].size()&&R[TR][y]<=L[TL][x-1]) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
