#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<int NV> class SegTree_Lazy {
public:
	vector<ll> val,mul;
	SegTree_Lazy(){val.resize(NV*2,0); mul.resize(NV*2,1);};

	ll reverse(int x,int y,int l=0,int r=NV,int k=1) {
		if(x<=l && r<=y) {
			mul[k]*=-1;
		}
		else if(l < y && x < r) {
			val[k]=reverse(x,y,l,(l+r)/2,k*2)+reverse(x,y,(l+r)/2,r,k*2+1);
		}
		return val[k]*mul[k];
	}
};
SegTree_Lazy<1<<20> st;
int N;
int H[101010][4],W[101010][4],R[101010][4],C[101010][4];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		int h,w;
		cin>>h>>w>>y>>x;
		R[i][(y%2)*2+(x%2)]=y/2;
		C[i][(y%2)*2+(x%2)]=x/2;
		H[i][(y%2)*2+(x%2)]=(h+1)/2;
		W[i][(y%2)*2+(x%2)]=(w+1)/2;
		R[i][(((y%2)^1)*2+((x%2)^1))]=(y+1)/2;
		C[i][(((y%2)^1)*2+((x%2)^1))]=(x+1)/2;
		H[i][(((y%2)^1)*2+((x%2)^1))]=h/2;
		W[i][(((y%2)^1)*2+((x%2)^1))]=w/2;
	}
	ll ret=0;
	for(int mask=0;mask<4;mask++) {
		vector<int> cand;
		map<int,vector<int>> ev;
		
		FOR(i,2<<20) st.val[i]=0,st.mul[i]=1;
		cand.push_back(0);
		cand.push_back(1<<30);
		FOR(i,N) if(H[i][mask]&&W[i][mask]) {
			cand.push_back(C[i][mask]);
			cand.push_back(C[i][mask]+W[i][mask]);
			ev[R[i][mask]].push_back(i);
			ev[R[i][mask]+H[i][mask]].push_back(i);
		}
		sort(ALL(cand));
		cand.erase(unique(ALL(cand)),cand.end());
		FOR(i,cand.size()-1) st.val[i+(1<<20)]=cand[i+1]-cand[i];
		for(i=(1<<20)-1;i>=1;i--) st.val[i]=st.val[i*2]+st.val[i*2+1];
	
		ll pre=st.val[1],prey=-1;
		FORR(e,ev) {
			ll black=((1LL<<30)-pre)/2;
			ret+=(e.first-prey)*black;
			prey=e.first;
			FORR(i,e.second) {
				x=lower_bound(ALL(cand),C[i][mask])-cand.begin();
				y=lower_bound(ALL(cand),W[i][mask]+C[i][mask])-cand.begin();
				pre=st.reverse(x,y);
			}
			
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
