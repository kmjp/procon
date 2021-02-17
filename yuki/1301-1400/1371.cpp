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

int N;
int A[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;
template<class V,int NV> class SegTree_1 {
public:
	vector<vector<V>> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val.resize(NV*2);};
	V getval(int x,int y,V v,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) {
			return lower_bound(ALL(val[k]),v+1)-val[k].begin();
		}
		return getval(x,y,v,l,(l+r)/2,k*2)+getval(x,y,v,(l+r)/2,r,k*2+1);
	}
	void set(int entry,V v) {
		val[entry+NV].clear();
		val[entry+NV].push_back(v);
	}
	void build() {
		for(int i=2*NV-1;i>=NV;i--) sort(ALL(val[i]));
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
		}
	}
};

int iskado(int cur) {
	if(cur<=0||cur>=N-1) return 1;
	int L=cur-1;
	int R=cur+1;
	if(A[cur]==A[L]) return 0;
	if(A[cur]==A[R]) return 0;
	if(A[L]==A[R]) return 0;
	return (A[L]<A[cur])==(A[R]<A[cur]);
}

vector<int> cand[505050];
vector<int> cand2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	ll ret=0;
	
	
	FOR(x,2) {
		SegTree_1<int,1<<18> st;
		ZERO(bt.bit);
		FOR(i,N+1) cand[i].clear();
		cand2.clear();
		FOR(i,N) {
			int large=0;
			if(i&&A[i]>A[i-1]) large=1;
			if(i+1<N&&A[i]>A[i+1]) large=1;
			if(large) {
				bt.add(A[i],1);
				int ma=0;
				if(i) ma=max(ma,A[i-1]);
				if(i+1<N) ma=max(ma,A[i+1]);
				st.set(A[i],ma+1);
				cand[A[i]].push_back(ma);
			}
			else {
				cand2.push_back(i);
			}
		}
		st.build();
		for(i=N;i>=1;i--) {
			FORR(c,cand[i]) {
				bt.add(i,-1);
				ret+=bt(i)-bt(c);
			}
			cand[i].clear();
		}
		if(x) {
			FORR(i,cand2) {
				int ma=N;
				if(i) ma=min(ma,A[i-1]-1);
				if(i+1<N) ma=min(ma,A[i+1]-1);
				ret+=st.getval(0,ma+1,A[i]);
			}
		}
		
		FOR(i,N) A[i]=N+1-A[i];
	}
	
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
