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


template<class V,int NV> class SegTree_ModAdd {
public:
	vector<V> mod,add1,add2,sum,even,odd;
	SegTree_ModAdd(){
		sum.resize(NV*2,0);
		add1.resize(NV*2,0);
		add2.resize(NV*2,0);
		mod.resize(NV*2,0);
		even.resize(NV*2,0);
		odd.resize(NV*2,0);
		int i;
		FOR(i,NV) even[i+NV]=1;
		for(i=NV-1;i>=0;i--) even[i]=even[i*2]+even[i*2+1];
	};

	vector<ll> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return {0LL,0LL,0LL};
		vector<ll> R;
		x=max(x,l);
		y=min(y,r);
		if(x<=l && r<=y) {
			R={even[k],odd[k],sum[k]};
		}
		else {
			R=getval(x,y,l,(l+r)/2,k*2);
			vector<ll> b=getval(x,y,(l+r)/2,r,k*2+1);
			R[0]+=b[0];
			R[1]+=b[1];
			R[2]+=b[2];
		}
		
		return adopt(R,add1[k],add2[k],y-x,mod[k]);
	}
	vector<ll> adopt(vector<ll> A,ll a1,ll a2,ll len,int m) {
		if(m) {
			if(a2&1) swap(A[0],A[1]);
			A[2]=A[1];
		}
		A[2]+=len*a1;
		if(a1&1) swap(A[0],A[1]);
		return A;
	}
	void propagate(int k,int s) {
		if(mod[k]) {
			mod[k*2]=mod[k*2+1]=1;
			add2[k*2]+=add2[k]+add1[k*2];
			add2[k*2+1]+=add2[k]+add1[k*2+1];
			add1[k*2]=add1[k*2+1]=0;
			mod[k]=add2[k]=0;
		}
		assert(add2[k]==0);
		add1[k*2]+=add1[k];
		add1[k*2+1]+=add1[k];
		add1[k]=0;
	}
	void update(int k, int len) {
		vector<ll> A={even[2*k],odd[2*k],sum[2*k]};
		vector<ll> B={even[2*k+1],odd[2*k+1],sum[2*k+1]};
		A=adopt(A,add1[2*k],add2[2*k],len,mod[2*k]);
		B=adopt(B,add1[2*k+1],add2[2*k+1],len,mod[2*k+1]);
		odd[k]=A[1]+B[1];
		even[k]=A[0]+B[0];
		sum[k]=A[2]+B[2];
	}

	void doq1(int x,int y,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			mod[k]=1;
			add2[k]+=add1[k];
			add1[k]=0;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			doq1(x,y,l,(l+r)/2,k*2);
			doq1(x,y,(l+r)/2,r,k*2+1);
			update(k,(l+r)/2-l);
		}
	}
	void doadd(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			add1[k]+=v;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			doadd(x,y,v,l,(l+r)/2,k*2);
			doadd(x,y,v,(l+r)/2,r,k*2+1);
			update(k,(l+r)/2-l);
		}
	}
};

SegTree_ModAdd<ll, 1<<18> st;


int N,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>x;
		st.doadd(i+1,i+2,x);
	}
	while(Q--) {
		int T,L,R,X;
		cin>>T>>L>>R;
		if(T==1) {
			st.doq1(L,R+1);
		}
		else if(T==2) {
			cin>>X;
			st.doadd(L,R+1,X);
		}
		else if(T==3) {
			cout<<st.getval(L,R+1)[2]<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
