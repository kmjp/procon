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

int T,N;
ll A[505050];

int LP[502020],LPS[502020],RP[502020],RPS[502020];

static ll const def=0;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
		FOR(i,NV) val[i+NV]=ma[i+NV]=def;
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[2*i],ma[2*i+1]);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
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
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
	}
};

SegTree_3<int,1<<20> st;
vector<pair<int,int>> add[502020],del[502020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<ll> As;
		FOR(i,N) {
			cin>>A[i];
			A[i]=(A[i]<<20)-i;
			As.push_back(A[i]);
		}
		FOR(i,N+1) add[i].clear(),del[i].clear();
		
		sort(ALL(As));
		vector<int> Ls,Rs;
		FOR(i,N) {
			A[i]=lower_bound(ALL(As),A[i])-As.begin();
			if(Ls.empty()||Ls.back()>A[i]) {
				Ls.push_back(A[i]);
				LP[i]=LPS[i]=-Ls.size();
			}
			else {
				LP[i]=1;
				LPS[i]=LPS[i-1];
			}
		}
		reverse(ALL(Ls));
		for(i=N-1;i>=0;i--) {
			if(Rs.empty()||Rs.back()<A[i]) {
				Rs.push_back(A[i]);
				RP[i]=RPS[i]=Rs.size()-1;
				
			}
			else {
				RP[i]=-1;
				RPS[i]=RPS[i+1];
			}
		}
		
		int ret=0;
		FOR(i,N) {
			if(LP[i]==1) LP[i]=-1;
			else LP[i]=Ls.size()+LP[i];
			LPS[i]=Ls.size()+LPS[i];
			
			int sx,tx,sy,ty;
			if(LP[i]!=-1) {
				sx=tx=LP[i];
			}
			else {
				sx=lower_bound(ALL(Ls),(int)A[i]+1)-Ls.begin();
				sx--;
				tx=LPS[i];
			}
			if(RP[i]==-1) {
				ty=RPS[i];
				sy=lower_bound(ALL(Rs),(int)A[i])-Rs.begin();
			}
			else {
				sy=ty=RP[i];
			}
			sx=Ls.size()-1-sx;
			tx=Ls.size()-1-tx;
			//cout<<i<<" "<<sx<<" "<<tx<<" "<<sy<<" "<<ty<<endl;
			add[sx].push_back({sy,ty+1});
			del[tx].push_back({sy,ty+1});
		}
		FOR(i,Ls.size()) {
			FORR2(a,b,add[i]) st.update(a,b,1);
			ret=max(ret,st.getval(0,N));
			FORR2(a,b,del[i]) st.update(a,b,-1);
		}
		cout<<ret<<endl;
		
			
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
