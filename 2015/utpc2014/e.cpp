#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val,ma;
	SegTree_3(){val.resize(NV*2,0); ma.resize(NV*2,0);};
	
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

int N;
ll A[101000],B[101000],W[101000];
map<ll,int> M;
ll ma;
SegTree_3<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s,t;
	
	cin>>N;
	M[-1]=M[10000000000LL]=0;
	FOR(i,N) {
		cin>>s>>W[i];
		reverse(s.begin(),s.end());
		t=s+"99999999999";
		s=s+"00000000000";
		s=s.substr(0,10);
		t=t.substr(0,10);
		A[i]=atoll(s.c_str());
		B[i]=atoll(t.c_str())+1;
		M[A[i]]=M[B[i]]=0;
	}
	x=0;
	ITR(it,M) it->second=x++;
	FOR(i,N) {
		A[i]=M[A[i]];
		B[i]=M[B[i]];
		st.update(A[i],B[i],W[i]);
		cout<<st.ma[1]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
