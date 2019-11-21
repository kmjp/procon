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
int P[202020];
int H[202020];
int HS[202020];
string S;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-(1<<30);
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v; //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<int,1<<20> st[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	S.resize(N,'0');
	int ma=0;
	FOR(i,N) {
		cin>>P[i];
		if(P[i]>ma) {
			H[i]=1;
			ma=P[i];
		}
		HS[i+1]=HS[i]+H[i];
	}
	FORR(v,st[0].val) v=0;
	FORR(v,st[1].val) v=-1<<30;
	
	for(i=N-1;i>=0;i--) {
		int e=st[0].getval(P[i]+1,N+2);
		int o=st[1].getval(P[i]+1,N+2);
		
		if(e>=0) st[H[i]^1].update(P[i],e+H[i]+1);
		if(o>=0) st[H[i]].update(P[i],o+H[i]+1);
	}
	
	
	
	int Hx=0,Hy=0,Cx=0,Cy=0;
	FOR(i,N) {
		int Q=HS[N]-HS[i+1];

		st[0].update(P[i],0);
		st[1].update(P[i],-1<<30);
		
		S[i]='1';
		// a=Q-k, b=k+m, T=Cx-Cy+Q;
		{
			int T=(Cx+(P[i]>Hx))-Cy+Q;
			int num=st[T&1].getval(Hy+1,N+2);
			if(num>=T && T>=0) S[i]='0';
		}
		// a=k+m, b=Q-k, T=Cy-Cx+Q;
		{
			int T=Cy-(Cx+(P[i]>Hx))+Q;
			int num=st[T&1].getval(max(Hx,P[i])+1,N+2);
			if(num>=T && T>=0) S[i]='0';
		}
		if(S[i]=='0') {
			if(Hx<P[i]) Cx++, Hx=P[i];
		}
		else {
			if(Hy<P[i]) Cy++, Hy=P[i];
		}
		
	}
	
	
	if(Cx!=Cy) cout<<-1<<endl;
	else cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
