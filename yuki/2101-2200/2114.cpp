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

int N,M,K;
int B[202020],R[202020];
map<int,vector<int>> X,Y;

static ll const def=0;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return 1LL<<60;
		if(x<=l && r<=y) return ma[k];
		ll a=val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		if(a>1LL<<60) a=1LL<<60;
		return a;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
	void reset(int x,int y, int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]=ma[k]=0;
		}
		else if(l < y && x < r) {
			val[k]=ma[k]=0;
			reset(x,y,l,(l+r)/2,k*2);
			reset(x,y,(l+r)/2,r,k*2+1);
		}
	}
};
SegTree_3<ll,1<<20> st;

ll hoge(vector<int> X,vector<int> Y) {
	vector<pair<int,int>> V;
	FORR(x,X) V.push_back({x,0});
	FORR(x,Y) V.push_back({x,1});
	int cur=X.size();
	int N=X.size()+Y.size()+1;
	//èâä˙âª
	int i;
	FOR(i,N+1) st.reset(i,i+1);
	st.update(0,N+1,1LL<<55);
	st.update(cur,cur+1,-(1LL<<55));
	
	sort(ALL(V));
	FORR2(x,c,V) {
		if(c==0) { //ê¬í∏ì_í«â¡
			
			//ê‘Ç™âﬂèËÇ»èÍçá
			st.update(0,cur,x);
			//ê¬Ç™âﬂèËÇ»èÍçá
			st.update(cur,N,-x);
			cur--;
		}
		else { //ê‘í∏ì_í«â¡
			//ñ≥éãÇ∑ÇÈèÍçá
			ll v=st.getval(cur,cur+1);
			//ê‘Ç™âﬂèËÇ»èÍçá
			st.update(0,cur+1,-x);
			//ê¬Ç™âﬂèËÇ»èÍçá
			st.update(cur+1,N+1,x);
			ll nv=st.getval(cur+1,cur+2);
			if(v<nv) st.update(cur+1,cur+2,v-nv);
			cur++;
		}
	}
	return st.getval(cur,cur+1);

}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>B[i];
	FOR(i,M) cin>>R[i];
	sort(B,B+N);
	sort(R,R+M);
	if(N>M) {
		swap(N,M);
		swap(B,R);
	}
	FOR(i,N) X[B[i]%K].push_back(B[i]/K);
	FOR(i,M) Y[R[i]%K].push_back(R[i]/K);
	
	ll ret=0;
	FORR2(a,b,X) {
		if(Y[a].size()<b.size()) {
			cout<<-1<<endl;
			return;
		}
		ret+=hoge(b,Y[a]);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
