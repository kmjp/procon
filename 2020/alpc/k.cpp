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

const ll mo=998244353;

int rev2=(mo+1)/2;
template<class V,int NV> class SegTree_MulAdd {
public:
	vector<V> sum,mul,add; // sum stores val after muladd
	SegTree_MulAdd(){sum.resize(NV*2,0); mul.resize(NV*2,1); add.resize(NV*2,0);};

	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return sum[k];
		x=max(x,l);
		y=min(y,r);
		V ret=getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
		return (ret*mul[k]+add[k]*(y-x))%mo;
	}
	void propagate(int k,int s) {
		(mul[k*2]*=mul[k])%=mo;
		add[k*2]*=mul[k];
		sum[k*2]*=mul[k];
		(add[k*2]+=add[k])%=mo;
		(sum[k*2]+=add[k]*s%mo*rev2)%=mo;
		(mul[k*2+1]*=mul[k])%=mo;
		add[k*2+1]*=mul[k];
		sum[k*2+1]*=mul[k];
		(add[k*2+1]+=add[k])%=mo;
		(sum[k*2+1]+=add[k]*s%mo*rev2)%=mo;
		
		mul[k]=1;
		add[k]=0;
	}

	void domul(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(mul[k]*=v)%=mo;
			(add[k]*=v)%=mo;
			(sum[k]*=v)%=mo;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			domul(x,y,v,l,(l+r)/2,k*2);
			domul(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=(sum[k*2]+sum[k*2+1])%mo;
		}
	}
	void doadd(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(add[k]+=v)%=mo;
			(sum[k]+=(r-l)*v)%=mo;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			doadd(x,y,v/mul[k],l,(l+r)/2,k*2);
			doadd(x,y,v/mul[k],(l+r)/2,r,k*2+1);
			(sum[k]=sum[k*2]+sum[k*2+1])%=mo;
		}
	}
};

int N,Q;
SegTree_MulAdd<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>x;
		st.doadd(i,i+1,x);
	}
	while(Q--) {
		int L,R,B,C;
		cin>>i>>L>>R;
		if(i==0) {
			cin>>B>>C;
			st.domul(L,R,B);
			st.doadd(L,R,C);
		}
		else {
			cout<<st.getval(L,R)<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
