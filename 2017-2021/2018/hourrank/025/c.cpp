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

int N;
int A[50505];
ll S[50505];

static ll const def=-1LL<<50;
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
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
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

template<class V,int NV> class SegTree_2 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return __gcd(l,r);};
	
	SegTree_2(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_3<ll,1<<17>  stmax;
SegTree_2<int,1<<17> stgcd;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<ll,int>> S;
	S.push_back({1<<20,-1});
	
	ll ret=0;
	int L,R;
	FOR(R,N) {
		cin>>A[R];
		stmax.update(R,R+1,-def);
		stmax.update(0,R,A[R]);
		int prev=R;
		while(S.back().first<=A[R]) {
			x=S[S.size()-2].second+1;
			stmax.update(x,prev,S.back().first-A[R]);
			prev=x;
			S.pop_back();
		}
		S.push_back({A[R],R});
		stgcd.update(R,abs(A[R]));
		
		int now=abs(A[R]);
		prev=R;
		
		L=R;
		while(1) {
			for(i=17;i>=0;i--) {
				if(L-(1<<i)<0) continue;
				if(stgcd.getval(L-(1<<i),R+1)==now) L-=1<<i;
			}
			
			ret=max(ret,1LL*now*stmax.getval(L,prev+1));
			if(L==0 || now==0) break;
			L--;
			prev=L;
			now=stgcd.getval(L,R+1);
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
