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


template<class V,int NV> class SegTree_Beats_max { //ãÊä‘maxçXêVÇ≈Ç´ÇÈsum
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
		//1î‘ñ⁄ÇÃílÇêÿÇËè„Ç∞ÇÈ
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
SegTree_Beats_max<ll,1<<16> st;

int N,Q;
int K;
int A[50101];
int UL[50101],UR[50101],UX[50101];
int QL[50101],QR[50101];
ll QX[50101];
int ret[50101];
int RL[50505],RR[50505];
vector<int> ev[50505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>Q;
	FOR(i,N) {
		cin>>A[i];
		st.update(i,i+1,A[i]);
	}
	
	FOR(i,K) {
		cin>>UL[i]>>UR[i]>>UX[i];
		UL[i]--;
	}
	FOR(i,Q) {
		cin>>QL[i]>>QR[i]>>QX[i];
		QL[i]--;
		ret[i]=-2;
		if(st.getsum(QL[i],QR[i])>=QX[i]) {
			ret[i]=0;
		}
	}
	FOR(i,K) {
		st.update(UL[i],UR[i],UX[i]);
	}
	FOR(i,Q) {
		if(st.getsum(QL[i],QR[i])<QX[i]) ret[i]=-1;
		if(ret[i]==-2) {
			RL[i]=0;
			RR[i]=K;
			if(K==1) ret[i]=1;
		}
	}
	FOR(k,20) {
		st.clear();
		FOR(i,K+1) {
			ev[i].clear();
		}
		FOR(i,N) {
			st.update(i,i+1,A[i]);
		}
		FOR(i,Q) if(ret[i]==-2) {
			ev[(RL[i]+RR[i])/2].push_back(i);
		}
		FOR(i,K) {
			st.update(UL[i],UR[i],UX[i]);
			FORR(e,ev[i+1]) {
				if(st.getsum(QL[e],QR[e])>=QX[e]) {
					RR[e]=i+1;
				}
				else {
					RL[e]=i+1;
				}
				if(RL[e]+1==RR[e]) ret[e]=RR[e];
			}
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
