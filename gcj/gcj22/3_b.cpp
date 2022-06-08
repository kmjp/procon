#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
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

int N,C;
int A[101010],B[101010];
int P[301010];
vector<int> Cs[101010];
int L[2][101010],R[2][101010];
static ll const def=0;
template<class V,int NV> class SegTree_3 {
public:
	vector<pair<int,int>> val;
	vector<int> add;
	SegTree_3(){
		reinit();
	};
	void reinit() {
		int i;
		val.clear();
		add.clear();
		val.resize(NV*2,{0,1});
		add.resize(NV*2,0);
		for(i=NV-1;i>=1;i--) val[i].second=val[2*i].second+val[2*i+1].second;
	}
	pair<int,int> merge(pair<int,int> a,pair<int,int> b) {
		if(a.first<b.first) return b;
		if(a.first>b.first) return a;
		return {a.first,a.second+b.second};
	}
	
	pair<int,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return {-1,0};
		if(x<=l && r<=y) return val[k];
		auto v=merge(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		v.first+=add[k];
		return v;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k].first+=v;
			add[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			val[k]=merge(val[k*2],val[k*2+1]);
			val[k].first+=add[k];
		}
	}
};
SegTree_3<int,1<<20> st;

void update(int c,int n) {
	int f=lower_bound(ALL(Cs[c]),n)-Cs[c].begin()-1;
	R[0][c]=3*N;
	L[1][c]=R[1][c]=3*N;
	if(f+1<Cs[c].size()) {
		R[0][c]=Cs[c][f+1];
		if(A[c]) {
			if(f+A[c]<Cs[c].size()) {
				L[1][c]=Cs[c][f+A[c]];
			}
			if(f+B[c]+1<Cs[c].size()) {
				R[1][c]=Cs[c][f+B[c]+1];
			}
		}
	}
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	st.reinit();
	
	cin>>N>>C;
	FOR(i,C) {
		cin>>A[i]>>B[i];
		Cs[i].clear();
		if(B[i]>=1&&A[i]==0) A[i]++;
	}
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
		Cs[P[i]].push_back(i);
		Cs[P[i]].push_back(N+i);
		Cs[P[i]].push_back(2*N+i);
	}
	FOR(i,C) {
		sort(ALL(Cs[i]));
		if(B[i]>=1&&A[i]==0) A[i]++;
		update(i,0);
		st.update(L[0][i],R[0][i],1);
		st.update(L[1][i],R[1][i],1);
	}
	ll ret=0;
	FOR(i,N) {
		auto p=st.getval(i+1,i+N-1);
		if(p.first==C) ret+=p.second;
		x=P[i];
		st.update(L[0][x],R[0][x],-1);
		st.update(L[1][x],R[1][x],-1);
		update(x,i+1);
		st.update(L[0][x],R[0][x],1);
		st.update(L[1][x],R[1][x],1);
		
	}
	
	cout<<"Case #"<<_loop<<": "<<ret<<endl;
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


