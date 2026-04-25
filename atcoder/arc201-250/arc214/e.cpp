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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

int T,N,K;
int A[303030],B[303030],P[303030];
vector<int> C[303030],D[303030];

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
	void build(int MV=NV) {
		int i;
		FOR(i,NV) {
			if(i<MV) {
				sort(ALL(val[NV+i]));
			}
			else {
				//ŒÃ‚¢‚à‚Ì‚ÍŽc‚Á‚Ä‚¢‚éê‡Á‚·
				if(val[NV+i].empty()) break;
				val[NV+i].clear();
			}
		}
		int L=NV,R=NV+i;
		while(L>1) {
			L=L/2;
			R=(R+1)/2;
			for(int i=L;i<R;i++) {
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
	}
};
SegTree_1<int,1<<19> st;



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			C[i].clear();
			D[i].clear();
			bt.add(i,-bt(i));
		}
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
			C[A[i]].push_back(i);
		}
		FOR(i,N) {
			cin>>B[i];
			B[i]--;
			D[B[i]].push_back(i);
		}
		FOR(i,N) {
			FOR(j,C[i].size()) P[C[i][j]]=D[i][j];
		}
		ll ret=1LL<<60;
		
		ll sum=0;
		FOR(i,N) {
			sum+=bt(N-1)-bt(P[i]);
			bt.add(P[i],1);
			st.set(i,P[i]);
		}
		st.build(N);
		ll mi=(sum+K-1)/K;
		if(mi*K%2==sum%2) ret=min(ret,mi);
		if((mi+1)*K%2==sum%2) ret=min(ret,mi+1);
		
		FOR(i,N) if(C[i].size()>1) {
			FOR(j,C[i].size()-1) {
				x=C[i][j];
				y=C[i][j+1];
				int num=st.getval(x,y,P[y])-st.getval(x,y,P[x]);
				ll tsum=sum+2*num+1;
				ll mi=(tsum+K-1)/K;
				if(mi*K%2==tsum%2) ret=min(ret,mi);
				if((mi+1)*K%2==tsum%2) ret=min(ret,mi+1);
				
				
			}
		}
		
			
		if(ret==1LL<<60) {
			cout<<-1<<endl;
		}
		else {
			cout<<ret<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
