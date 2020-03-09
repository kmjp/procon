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
int A[301010];
int L[101010];
int R[101010];

static ll const def=1<<30;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
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
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
};

SegTree_3<int,1<<20> sl,sr;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x;
		x--;
		x-=(i+1);
		if(x<0) x+=N;
		A[x]=A[x+N]=A[x+2*N]=1;
	}
	
	int pre=0;
	FOR(i,3*N) {
		if(i>=N&&i<2*N) R[i-N]=(N-(i-pre))%N;
		if(A[i]) pre=i;
	}
	pre=0;
	for(i=3*N-1;i>=0;i--) {
		if(i>=N&&i<2*N) L[i-N]=(N-(pre-i))%N;
		if(A[i]) pre=i;
	}
	FOR(i,N) {
		sr.update(i,i+1,i+min(L[i],R[i]));
		sl.update(i,i+1,(N-i)%N+min(L[i],R[i]));
	}
	
	FOR(i,N) {
		/*
		cout<<"R ";
		FOR(j,N) cout<<sr.getval(j,j+1);
		cout<<" L ";
		FOR(j,N) cout<<sl.getval(j,j+1);
		cout<<"  ";
		*/
		x=min(sl.getval(0,N),sr.getval(0,N))+min(i,N-i);
		cout<<x<<endl;
		sl.update(0,N,1);
		sl.update((i+1)%N,(i+1)%N+1,-N);
		sr.update(0,N,-1);
		sr.update(i,i+1,N);
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
