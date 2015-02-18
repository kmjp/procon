#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
ll D[202000],H[202000];
ll DS[201000];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	vector<V> id;
	static V const def=0;
	V comp(V l,V r){ 
		if(l<0) return r;
		if(r<0) return l;
		if(val[l]>=val[r]) return l;
		return r;
	}

	
	SegTree_1(){
		val=vector<V>(NV*2,0);
		id=vector<V>(NV*2,0);
		int i;
		FOR(i,NV) id[i]=2*i;
		FOR(i,NV) id[NV+i]=NV+i;
	};
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return -1;
		if(x<=l && r<=y) return id[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, id[entry]=comp(id[entry*2],id[entry*2+1]);
	}
};

int A[101000],B[101000];
int AD=1<<22;
SegTree_1<ll,1<<22> LT,RT;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>D[i], D[i+N]=D[i];
	FOR(i,N) cin>>H[i], H[i+N]=H[i];
	D[2*N-1]=0;
	FOR(i,200100) DS[i+1]=DS[i]+D[i];
	FOR(i,200100) LT.update(i,DS[200100]-DS[i]+2*H[i]);
	FOR(i,200100) RT.update(i,DS[i]+2*H[i]);
	
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		if(x<=y) A[i]=y+1, B[i]=N+x-1;
		else A[i]=y+1,B[i]=x-1;
		
		ll lc=LT.getval(A[i],B[i]+1);
		ll rc=RT.getval(A[i],B[i]+1);
		
		ll ret;
		if(lc!=rc) {
			ret = LT.val[lc]+RT.val[rc]-DS[200100];
		}
		else {
			lc -= AD;
			ll a1=RT.getval(A[i],lc);
			ll a2=RT.getval(lc+1,B[i]+1);
			ll ret1,ret2;
			if(a1==-1) ret1 = LT.val[lc+AD] + RT.val[a2];
			else if(a2==-1) ret1 = LT.val[lc+AD] + RT.val[a1];
			else ret1 = LT.val[lc+AD] + max(RT.val[a1],RT.val[a2]);
			
			a1=LT.getval(A[i],lc);
			a2=LT.getval(lc+1,B[i]+1);
			if(a1==-1) ret2 = RT.val[lc+AD] + LT.val[a2];
			else if(a2==-1) ret2 = RT.val[lc+AD] + LT.val[a1];
			else ret2 = RT.val[lc+AD] + max(LT.val[a1],LT.val[a2]);
			
			ret=max(ret1,ret2)-DS[200100];
		}
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
