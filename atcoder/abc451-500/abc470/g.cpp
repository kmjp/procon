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

template<class V,int NV> class SegTree_Beats_max { //‹æŠÔmaxXV‚Å‚«‚ésum
public:
	static V const def=(1LL<<60);
	vector<V> mi,mi2,mic,sum;
	SegTree_Beats_max(){
		clear();
	};
	void clear() {
		int i;
		mi.clear(), mi2.clear(), mic.clear(), sum.clear();
		mi.resize(NV*2,-1<<30); mi2.resize(NV*2,def+1);
		mic.resize(NV*2,1); sum.resize(NV*2,-1<<30);
		for(i=NV-1;i>=1;i--) {
			mic[i]=mic[2*i]+mic[2*i+1];
			sum[i]=sum[2*i]+sum[2*i+1];
		}
	}
	
	
	V getmin(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return def;
		if(x<=l && r<=y) return mi[k];
		
		if(mi[2*k]<mi[k]) update_min(2*k,mi[k]);
		if(mi[2*k+1]<mi[k]) update_min(2*k+1,mi[k]);
		return max(getmin(x,y,l,(l+r)/2,k*2),getmin(x,y,(l+r)/2,r,k*2+1));
	}
	V getsum(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return 0;
		if(x<=l && r<=y) return sum[k];
		
		if(mi[2*k]<mi[k]) update_min(2*k,mi[k]);
		if(mi[2*k+1]<mi[k]) update_min(2*k+1,mi[k]);
		return getsum(x,y,l,(l+r)/2,k*2)+getsum(x,y,(l+r)/2,r,k*2+1);
	}
	void update_min(int k,ll v) {
		//1”Ô–Ú‚Ì’l‚ğØ‚èã‚°‚é
		sum[k]+=1LL*(v-mi[k])*mic[k];
		mi[k]=v;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return;
		if(v<=mi[k]) return;
		
		if(x<=l && r<=y&&v<mi2[k]) {
			update_min(k,v);
			return;
		}
		if(mi[2*k]<mi[k]) update_min(2*k,mi[k]);
		if(mi[2*k+1]<mi[k]) update_min(2*k+1,mi[k]);
		update(x,y,v,l,(l+r)/2,k*2);
		update(x,y,v,(l+r)/2,r,k*2+1);
		sum[k]=sum[2*k]+sum[2*k+1];
		if(mi[2*k]<mi[2*k+1]) {
			mi[k]=mi[2*k];
			mic[k]=mic[2*k];
			mi2[k]=min(mi2[2*k],mi[2*k+1]);
		}
		else if(mi[2*k]>mi[2*k+1]) {
			mi[k]=mi[2*k+1];
			mic[k]=mic[2*k+1];
			mi2[k]=min(mi2[2*k+1],mi[2*k]);
		}
		else {
			mi[k]=mi[2*k];
			mic[k]=mic[2*k]+mic[2*k+1];
			mi2[k]=min(mi2[2*k],mi2[2*k+1]);
		}
	}
};
SegTree_Beats_max<ll,1<<19> st;

int N;
int A[303030];
vector<int> P[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		P[A[i]].push_back(i);
		st.update(i,i+1,i+1);
	}
	ll ret=0;
	FOR(i,N+1) {
		P[i].push_back(N);
		int pre=0;
		FOR(j,P[i].size()) {
			st.update(pre,P[i][j]+1,P[i][j]+1);
			pre=P[i][j]+1;
		}
		ret+=1LL*(N+1)*N-st.getsum(0,N);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
