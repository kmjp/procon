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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> sum,ma,Lma,Rma;
	
	SegTree_1(){
		Lma=Rma=ma=sum=vector<V>(NV*2,-1LL<<50);
	};
	vector<V> getmax(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0,-(1LL<<60),-(1LL<<60),-(1LL<<60)};
		if(x<=l && r<=y) return {sum[k],Lma[k],Rma[k],ma[k]};
		
		auto a=getmax(x,y,l,(l+r)/2,k*2);
		auto b=getmax(x,y,(l+r)/2,r,k*2+1);
		if(a[1]<=-(1LL<<50)) return b;
		if(b[1]<=-(1LL<<50)) return a;
		vector<V> c(4);
		c[0]=a[0]+b[0];
		c[1]=max({a[1],a[0],a[0]+b[1]});
		c[2]=max({b[2],b[0],a[2]+b[0]});
		c[3]=max({a[3],b[3],a[1],a[2],b[1],b[2],a[2]+b[1]});
		
		return c;
	}
	
	void update(int entry, V v) {
		entry += NV;
		sum[entry]=ma[entry]=Lma[entry]=Rma[entry]=v;
		
		while(entry>1) {
			entry>>=1;
			sum[entry]=sum[entry*2]+sum[entry*2+1];
			Lma[entry]=max({Lma[entry*2],sum[entry*2]+Lma[entry*2+1],sum[entry*2]});
			Rma[entry]=max({Rma[entry*2]+sum[entry*2+1],sum[entry*2+1],Rma[entry*2+1]});
			ma[entry]=max({ma[entry*2],ma[entry*2+1],Rma[entry*2]+Lma[entry*2+1],Lma[entry*2],Rma[entry*2],Lma[entry*2+1],Rma[entry*2+1]});
			
		}
	}
};

int N,Q;
ll A[101010];
SegTree_1<ll,1<<18> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i+1];
		st.update(i+1,A[i+1]);
	}
	
	while(Q--) {
		cin>>s;
		if(s=="set") {
			cin>>i>>x;
			A[i]=x;
			st.update(i,x);
		}
		else {
			int L1,L2,R1,R2;
			cin>>L1>>L2>>R1>>R2;
			R1=max(L1,R1);
			L2=min(L2,R2);
			
			ll ret=-1LL<<60;
			if(L2<=R1) {
				auto b=st.getmax(L1,L2+1);
				auto c=st.getmax(L2,R1+1);
				auto d=st.getmax(R1,R2+1);
				ret=max(ret,b[2]+c[0]+d[1]-A[L2]-A[R1]);
			}
			else {
				{
					auto b=st.getmax(L1,R1+1);
					auto c=st.getmax(R1,R2+1);
					ret=max(ret,b[2]+c[1]-A[R1]);
				}
				{
					auto b=st.getmax(L1,L2+1);
					auto c=st.getmax(L2,R2+1);
					ret=max(ret,b[2]+c[1]-A[L2]);
				}
				{
					auto b=st.getmax(R1,L2+1);
					ret=max(ret,b[3]);
				}
			}
			
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
