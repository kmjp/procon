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



int N,Q;
int A[202020];
string S;
ll mo=1000000007;

template<int NV> class SegTree_3 {
public:
	vector<vector<ll>> val;
	SegTree_3(){
		int i;
		val.resize(NV*2);
	};
	vector<ll> merge(vector<ll> a,vector<ll> b,int id) {
		char op='+';
		if(id<S.size()) op=S[id];
		
		if(a.empty()) return b;
		if(b.empty()) return a;
		if(op=='*') {
			if(a.size()==1&&b.size()==1) {
				return {a[0]*b[0]%mo};
			}
			else if(a.size()==3&&b.size()==1) {
				return {a[0],a[1],a[2]*b[0]%mo};
			}
			else if(a.size()==1&&b.size()==3) {
				return {a[0]*b[0]%mo,b[1],b[2]};
			}
			else{
				return {a[0],(a[1]+a[2]*b[0]+b[1])%mo,b[2]};
			}
			
		}
		else {
			if(a.size()==1&&b.size()==1) {
				return {a[0],0,b[0]};
			}
			else if(a.size()==3&&b.size()==1) {
				return {a[0],(a[1]+a[2])%mo,b[0]};
			}
			else if(a.size()==1&&b.size()==3) {
				return {a[0],(b[0]+b[1])%mo,b[2]};
			}
			else {
				return {a[0],(a[1]+a[2]+b[0]+b[1])%mo,b[2]};
			}
			
		}
	}
	
	vector<ll> getval(int x,int y,int l=0,int r=NV,int k=1) {
		int m=(l+r)/2;
		if(r<=x || y<=l) return {};
		if(x<=l && r<=y) return val[k];
		
		auto a=getval(x,y,l,(l+r)/2,k*2);
		auto b=getval(x,y,(l+r)/2,r,k*2+1);
		
		return merge(a,b,m-1);
	}
	
	void update(int x,int y, ll v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]={v};
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			val[k]=merge(val[k*2],val[k*2+1],(l+r)/2-1);
			
		}
	}
};
SegTree_3<1<<20> st;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	cin>>S;
	FOR(i,N) st.update(i,i+1,A[i]);
	cin>>Q;
	while(Q--) {
		cin>>i>>x>>y;
		if(i==1) {
			x--;
			A[x]=y;
			st.update(x,x+1,A[x]);
		}
		else if(i==2) {
			x--;
			S[x]=(char)('*'+'+'-S[x]);
			st.update(x+1,x+2,A[x+1]);
		}
		else {
			auto a=st.getval(x-1,y);
			ll ret=0;
			FORR(v,a) ret+=v;
			cout<<ret%mo<<endl;
		}
	}
	
	
}




int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
