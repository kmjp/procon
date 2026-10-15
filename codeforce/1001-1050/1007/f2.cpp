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

static ll const def=-(1LL<<30);
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	V comp(V a,V b) {return max(a,b);};
	SegTree_3(){
		int i;
		val.resize(NV*2); ma.resize(NV*2);
		FOR(i,NV) val[i+NV]=ma[i+NV]={def,-i}; //ƒL[‚Ì~‡¸‡‚Í‚±‚Ì•„†‚ÅŽw’è
		for(i=NV-1;i>=1;i--) ma[i]=comp(ma[2*i],ma[2*i+1]);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return {def,-k};
		if(x<=l && r<=y) return ma[k];
		auto p=comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		p.first+=val[k].first;
		return p;
	}
	
	void reset(int x,int y, int l=0,int r=NV,int k=1) { //ŒJ‚è•Ô‚µŽg‚¤‚Æ‚«‚Íupdate‚æ‚èreset‚ª—Ç‚¢
		if(l>=r||y<=x||y<=l||x>=r) return;
		val[k].first=ma[k].first=0;
		if(r-l!=1) {
			reset(x,y,l,(l+r)/2,k*2);
			reset(x,y,(l+r)/2,r,k*2+1);
			ma[k]=comp(ma[2*k],ma[2*k+1]);
		}
	}
	void update(int x,int y, ll v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k].first+=v;
			ma[k].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=comp(ma[2*k],ma[2*k+1]);
			ma[k].first+=val[k].first;
		}
	}
};
SegTree_3<pair<int,int>,1<<18> st;

int T,N,K,A[202020];
int dp[202020];

int ok(int v) {
	int i,j,lp;
	int num=0;
	FOR(i,N) if(A[i]>=v) num++;
	if(num>=N-K) return 1;
	num=0;
	FOR(i,N) if(A[i]>=v-N) num++;
	if(num<N-K) return 0;
	
	FOR(lp,2) {
		st.reset(0,N);
		int num=0;
		FOR(i,N) {
			ll x=(lp?A[i]:A[N-1-i])-v;
			st.update(i,i+1,x);
			while(1) {
				auto p=st.getval(0,i+1);
				if(p.first<0) break;
				num++;
				int y=-p.second;
				st.update(y,y+1,-1LL<<30);
				st.update(0,y,1);
			}
			if(lp==0) {
				dp[i]=num;
			}
			else {
				if(dp[N-1-i]+num-(x>=0)>=N-K) return 1;
			}
		}
	}
	return 0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) cin>>A[i];
		int ret=0;
		for(i=29;i>=0;i--) if(ok(ret+(1<<i))) ret+=1<<i;
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
