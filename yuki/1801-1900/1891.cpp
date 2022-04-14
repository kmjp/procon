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


int N,Q;
ll A[1<<18],B[1<<18];
const ll mo=998244353;
template<class V,int NV> class SegTree_1 {
public:
	vector<vector<pair<ll,ll>>> val;
	
	SegTree_1(){val.resize(NV*2);};
	V getval(int x,int y,int mask,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {1LL,0};
		x=max(x,l);
		y=min(y,r);
		if(x<=l && r<=y) {
			return val[k][mask%val[k].size()];
		}
		int op=mask/(val[k].size()/2)%2*(val[k].size()/2);
		if(op==0) {
			auto P=getval(x,y,mask,l,(l+r)/2,k*2);
			auto Q=getval(x,y,mask,(l+r)/2,r,k*2+1);
			return {P.first*Q.first%mo, (Q.first*P.second+Q.second)%mo};
		}
		else {
			y--;
			if((y&op)==0) {
				x^=op;
				y^=op;
				y++;
				return getval(x,y,mask,(l+r)/2,r,k*2+1);
			}
			else if(x&op) {
				x^=op;
				y^=op;
				y++;
				return getval(x,y,mask,l,(l+r)/2,k*2);
			}
			y++;
			auto P=getval(x^op,1<<18,mask,(l+r)/2,r,k*2+1);
			auto Q=getval(0,y^op,mask,l,(l+r)/2,k*2);
			return {P.first*Q.first%mo, (Q.first*P.second+Q.second)%mo};
		}
		
	}
};
SegTree_1<pair<ll,ll>,1<<18> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i]>>B[i];
	N=1<<18;
	FOR(i,N) {
		st.val[N+i].push_back({A[i],B[i]});
	}
	int cur=1<<18;
	FOR(i,18) {
		x=cur/2;
		int mask;
		FOR(j,x) {
			FOR(mask,N/x) {
				int op=mask/(N/(2*x));
				int sub=mask%(N/(2*x));
				auto P=st.val[cur+j*2][sub];
				auto Q=st.val[cur+j*2+1][sub];
				if(op==0) {
					st.val[x+j].push_back({P.first*Q.first%mo, (Q.first*P.second+Q.second)%mo});
				}
				else {
					st.val[x+j].push_back({P.first*Q.first%mo, (P.first*Q.second+P.second)%mo});
				}
			}
		}
		cur=x;
	}
	
	while(Q--) {
		int L,R,P,X;
		cin>>L>>R>>P>>X;
		auto p=st.getval(L,R,P);
		cout<<(p.first*X+p.second)%mo<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
