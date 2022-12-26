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

int N,Q;
int L[302020],R[302020];

struct range {
	int tp;
	int L,R,T;
	ll C;
};


template<int NV> class SegTree_1 {
public:
	vector<range> val;
	// static V const def=1LL<<60; min
	range comp(range l,range r){
		if(l.tp==-1) return r;
		if(r.tp==-1) return l;
		range ret;
		ret.C=0;
		if(max(l.L,r.L)<=min(l.R,r.R)) {
			ret.L=max(l.L,r.L);
			ret.R=min(l.R,r.R);
		}
		else if(l.R<=r.L) {
			ret.L=ret.R=r.L;
		}
		else {
			ret.L=ret.R=r.R;
		}
		ret.C=l.C+r.C;
		if(l.tp==0) {
			if(r.tp==0) {
				if(max(l.L,r.L)<=min(l.R,r.R)) {
					ret.tp=0;
				}
				else if(l.L>r.R) {
					ret.tp=1;
					ret.T=l.L;
					ret.C=l.L-r.R;
				}
				else {
					ret.tp=1;
					ret.T=l.R;
				}
			}
			else {
				ret.tp=1;
				if(l.R<=r.T) {
					ret.T=l.R;
				}
				else if(l.L<=r.T) {
					ret.T=r.T;
				}
				else {
					ret.T=l.L;
					ret.C+=l.L-r.T;
				}
			}
		}
		else {
			ret.T=l.T;
			ret.tp=1;
			if(r.tp==0) {
				if(l.L>=r.R) ret.C+=l.L-r.R;
			}
			else {
				if(l.R>=r.T) ret.C+=l.R-r.T;
			}
		}
		return ret;
	};
		
	
	SegTree_1(){val=vector<range>(NV*2);FORR(v,val) v.tp=-1;};
	range getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {.tp=-1};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int L,int R) {
		entry += NV;
		val[entry].tp=0;
		val[entry].L=L;
		val[entry].R=R;
		val[entry].C=0;
		
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<1<<20> stR,stL;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>L[i]>>R[i];
		stR.update(i,L[i]-i,R[i]-(i+1));
		stL.update(N-i-2,L[i]-(N-1-(i+1)),R[i]-(N-1-i));
	}
	
	FOR(i,Q) {
		int T;
		cin>>T;
		if(T==1) {
			int P,S,E;
			cin>>P>>S>>E;
			P--;
			L[P]=S;
			R[P]=E;
			stR.update(P,S-P,E-(P+1));
			stL.update(N-2-P,S-(N-1-(P+1)),E-(N-1-P));
		}
		else {
			int A,B,C,D;
			cin>>A>>B>>C>>D;
			A--;
			C--;
			
			if(A==C) {
				cout<<max(0,B-D)<<endl;
			}
			else if(A<C) {
				B-=A;
				D-=C;
				range r=stR.getval(A,C);
				ll ret=r.C;
				if(r.tp==0) {
					if(B>r.R) {
						ret+=B-r.R;
						B=r.R;
					}
					else if(B<r.L) {
						B=r.L;
					}
				}
				else {
					if(B>r.T) ret+=B-r.T;
					B=r.R;
				}
				ret+=max(0,B-D);
				
				cout<<ret<<endl;
			}
			else {
				B-=(N-1-A);
				D-=(N-1-C);
				range r=stL.getval(N-1-A,N-1-C);
				ll ret=r.C;
				if(r.tp==0) {
					if(B>r.R) {
						ret+=B-r.R;
						B=r.R;
					}
					else if(B<r.L) {
						B=r.L;
					}
				}
				else {
					if(B>r.T) ret+=B-r.T;
					B=r.R;
				}
				ret+=max(0,B-D);
				
				cout<<ret<<endl;
			}
			
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
