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


template<int NV> class SegTree_Lazy {
public:
	vector<ll> val,mul;
	SegTree_Lazy(){val.resize(NV*2,0); mul.resize(NV*2,1);};

	void update(int x,int y,int v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]*=v;
			mul[k]*=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			val[k]=(val[2*k]+val[2*k+1])*mul[k];
		}
	}
};

int Q;
int A[101010],B[101010],C[101010],D[101010];
vector<int> Ys;
SegTree_Lazy<1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	vector<pair<int,int>> ev;
	
	Ys.push_back(-1<<30);
	Ys.push_back(1<<30);
	FOR(i,Q) {
		cin>>A[i]>>B[i]>>C[i]>>D[i];
		ev.push_back({A[i],B[i]});
		ev.push_back({A[i],D[i]});
		ev.push_back({C[i],B[i]});
		ev.push_back({C[i],D[i]});
		Ys.push_back(B[i]);
		Ys.push_back(D[i]);
	}
	sort(ALL(Ys));
	Ys.erase(unique(ALL(Ys)),Ys.end());
	
	FOR(i,Ys.size()-1) {
		st.val[(1<<20)+i]=Ys[i+1]-Ys[i];
	}
	for(i=(1<<20)-1;i>=1;i--) st.val[i]=st.val[2*i]+st.val[2*i+1];
	
	int pre=-1<<30;
	ll ret=0;
	sort(ALL(ev));
	FORR2(x,y,ev) {
		y=lower_bound(ALL(Ys),y)-Ys.begin();
		
		ll now=((2LL<<30)-st.val[1])/2;
		ret+=(x-pre)*now;
		pre=x;
		st.update(0,y,-1);
	}
	
	cout<<ret<<endl;
	
	
	
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
