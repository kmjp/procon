#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int T,N,V;
int A[202020],B[202020];

template<class V,int NV> class RMQ {
private:
	V table[NV+1][1<<NV];
	int LG[1<<NV];
public:
	int NV2;
	static V const def=-(1<<30);
	V comp(V l,V r){ return max(l,r);};
	RMQ() {
		int i,x;
		NV2=1<<NV;
		LG[1]=0;
		for(i=2;i<NV2;i++) LG[i]=LG[i/2]+1;
		FOR(i,NV) FOR(x,NV2) table[i][x]=def;
	}
	void set(int x,V v){ table[0][x]=v;}
	void build() {
		int i,j,x,y;
		FOR(i,NV) FOR(x,NV2) table[i+1][x]=comp(table[i][x],(x+(1<<i)<NV2)?table[i][x+(1<<i)]:def);
	}
	V query(int L,int R) { //[L,R),
		L=max(0,L), R=min(R,NV2);
		if(R<=L) return def;
		int WL=LG[R-L];
		return comp(table[WL][L],table[WL][R-(1<<WL)]);
	}
	
};
RMQ<int,18> rmq;

struct info {
	int L[30],R[30];
	int PL,PR;
	int ret;
};

info tmp;

template<class C,int NV> class SegTree_1 {
public:
	vector<C> val;
	C comp(C l,C r){
		if(l.PL==-1) return r;
		if(r.PL==-1) return l;
		C v;
		v.ret=min(l.ret,r.ret);
		v.PL=l.PL;
		v.PR=r.PR;
		int i;
		FOR(i,30) {
			v.L[i]=(l.L[i]==-1)?r.L[i]:l.L[i];
			v.R[i]=(r.R[i]==-1)?l.R[i]:r.R[i];
		}
		
		int CPL=l.PR;
		int CPR=r.PL;
		for(i=29;i>=0;i--) {
			int LV=(l.R[i]==-1)?1<<30:rmq.query(min(l.R[i],CPL),CPR+1);
			int RV=(r.L[i]==-1)?1<<30:rmq.query(CPL,max(r.L[i],CPR)+1);
			if(LV<RV) {
				if(V&(1<<i)) {
					if(LV<v.ret) {
						CPL=min(CPL,l.R[i]);
					}
					else {
						break;
					}
				}
				else {
					v.ret=min(v.ret,LV);
				}
			}
			else {
				if(V&(1<<i)) {
					if(RV<v.ret) {
						CPR=max(CPR,r.L[i]);
					}
					else {
						break;
					}
				}
				else {
					v.ret=min(v.ret,RV);
				}
			}
		}
		
		return v;
	};
	
	SegTree_1(){
		MINUS(tmp.L);
		MINUS(tmp.R);
		tmp.ret=1<<30;
		tmp.PL=tmp.PR=-1;
		val=vector<C>(NV*2,tmp);
	};
	C getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return tmp;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int v) {
		
		entry += NV;
		int i;
		val[entry]=tmp;
		val[entry].PL=val[entry].PR=entry-NV;
		if(v>V) {
			val[entry].ret=A[entry-NV];
		}
		else {
			val[entry].ret=1<<30;
			FOR(i,30) if(v&(1<<i)) val[entry].L[i]=val[entry].R[i]=entry-NV;
		}
		
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<info,1<<18> st;
int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	tmp.ret=1<<30;
	FOR(i,30) tmp.L[i]=tmp.R[i]=-1;
	
	cin>>T;
	while(T--) {
		cin>>N>>V;
		FOR(i,N) {
			cin>>A[i];
			rmq.set(i,A[i]);
		}
		V--;
		x=1;
		while(x<N) x*=2;
		rmq.NV2=x;
		rmq.build();
		FOR(i,N) {
			cin>>B[i];
			st.update(i,B[i]);
		}
		cin>>Q;
		while(Q--) {
			int L,R;
			cin>>i>>L>>R;
			L--;
			if(i==1) {
				B[L]=R;
				st.update(L,B[L]);
			}
			else {
				auto r=st.getval(L,R);
				if(r.ret==1<<30) {
					cout<<-1<<" ";
				}
				else {
					cout<<r.ret<<" ";
				}
			}
		}
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
