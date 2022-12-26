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
	vector<V> add;
	vector<V> sum1;
	vector<V> sum2;
	
	SegTree_1(){
		add.resize(NV*2);
		sum1.resize(NV*2);
		sum2.resize(NV*2);
	};
	
	V getval(int x,int y,int l,int r,int k) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return sum2[k];
		if(add[k]) {
			update(l,(l+r)/2,l,(l+r)/2,k*2,add[k]);
			update((l+r)/2,r,(l+r)/2,r,k*2+1,add[k]);
			add[k]=0;
			sum1[k]=sum1[2*k]+sum1[2*k+1];
			sum2[k]=sum2[2*k]+sum2[2*k+1];
		}
		
		return getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
	}
	V getval(int x,int y) { return getval(x,y,0,NV,1);}
	
	void update(int x,int y,int l,int r,int k,int v) {
		if(r<=x || y<=l) return;
		if(v==0) return;
		if(x<=l && r<=y) {
			add[k]+=v;
			sum2[k]+=2LL*v*sum1[k]+1LL*(r-l)*v*v;
			sum1[k]+=1LL*v*(r-l);
			return;
		}
		
		update(l,(l+r),l,(l+r)/2,k*2,add[k]);
		update((l+r)/2,r,(l+r)/2,r,k*2+1,add[k]);
		update(x,y,l,(l+r)/2,k*2,v);
		update(x,y,(l+r)/2,r,k*2+1,v);
		add[k]=0;
		sum1[k]=sum1[2*k]+sum1[2*k+1];
		sum2[k]=sum2[2*k]+sum2[2*k+1];
	}
	void update(int x,int y,int v) { update(x,y,0,NV,1,v);}
};
SegTree_1<ll,1<<20> st;

int N;
int Q;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		st.update(i+1,i+2,x);
	}
	cin>>Q;
	while(Q--) {
		cin>>i>>l>>r;
		if(i==1) {
			cin>>x;
			st.update(l,r+1,x);
		}
		else {
			cout<<st.getval(l,r+1)<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
