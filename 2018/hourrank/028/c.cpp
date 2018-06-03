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

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(x>=y) return 0;
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return ma[k];
		int num=getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
		if(val[k]) num=(min(y,r)-max(x,l))-num;
		return num;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]^=1;
			ma[k]=(r-l)-ma[k];
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			
			ma[k]=ma[k*2]+ma[k*2+1];
			if(val[k]) ma[k]=(r-l)-ma[k];
		}
	}
};

SegTree_3<int,1<<17> st[18];
int N,M,P;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>P;
	FOR(i,N) {
		cin>>x;
		FOR(j,17) if(x&(1<<j)) st[j].update(max(0,i-P+1),i+1,1);
	}
	
	while(M--) {
		cin>>i>>x>>y;
		if(i==1) {
			FOR(j,17) if(y&(1<<j)) st[j].update(max(0,x-P),x,1);
		}
		else {
			ll ret=0;
			FOR(j,17) ret+=1LL*st[j].getval(x-1,min(N-P+1,y))<<j;
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
