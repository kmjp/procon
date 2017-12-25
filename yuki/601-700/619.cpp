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

int N,M;
int A[101010];
ll V[101010];
string S[101010];
ll mo=1000000007;

template<class V,int NV> class SegTree_mul {
public:
	vector<V> val;
	static V const def=1;
	V comp(V l,V r){ return l*r%mo;};
	
	SegTree_mul(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return 1;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_mul<ll,1<<18> st;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	set<int> C;
	C.insert(0);
	C.insert((N+1)/2);
	FOR(i,N) {
		if(i%2==0) {
			cin>>A[i/2];
			st.update(i/2,A[i/2]);
		}
		else {
			cin>>S[i/2];
			if(S[i/2]=="+") C.insert((i+1)/2);
		}
	}
	int pre=-1;
	FORR(r,C) {
		if(pre!=-1) {
			V[pre]=st.getval(pre,r);
			bt.add(pre,V[pre]);
		}
		pre=r;
	}
	
	cin>>M;
	while(M--) {
		
		cin>>s>>x>>y;
		if(s=="!") {
			x--,y--;
			if(x%2==0) {
				x/=2;
				y/=2;
				auto itx=C.lower_bound(x+1);
				int nx=*itx;
				i=*(--itx);
				auto ity=C.lower_bound(y+1);
				int ny=*ity;
				j=*(--ity);
				
				if(i==j) {
					swap(A[x],A[y]);
					st.update(x,A[x]);
					st.update(y,A[y]);
				}
				else {
					bt.add(i,-V[i]);
					bt.add(j,-V[j]);
					swap(A[x],A[y]);
					st.update(x,A[x]);
					st.update(y,A[y]);
					V[i]=st.getval(i,nx);
					V[j]=st.getval(j,ny);
					bt.add(i,V[i]);
					bt.add(j,V[j]);
				}
			}
			else {
				x/=2;
				y/=2;
				if(S[x]==S[y]) continue;
				set<int> cand;
				
				if(S[x]=="+") swap(x,y);
				auto it=C.lower_bound(x+1);
				cand.insert(*(--it));
				it=C.lower_bound(y+1);
				cand.insert(*(--it));
				
				C.insert(x+1);
				C.erase(y+1);
				cand.insert(x+1);
				cand.insert(y+1);
				swap(S[x],S[y]);
				FORR(c,cand) {
					bt.add(c,-V[c]);
					V[c]=0;
					if(c>0 && S[c-1]=="*") continue;
					it=C.lower_bound(c+1);
					V[c]=st.getval(c,*it);
					bt.add(c,V[c]);
				}
				
			}
		}
		else {
			x/=2;
			y/=2;
			auto itx=C.lower_bound(x);
			auto ity=C.lower_bound(y+1);
			if(itx==ity) {
				cout<<st.getval(x,y+1)<<endl;
			}
			else {
				ll ret=0;
				if(x<*itx) ret+=st.getval(x,*itx);
				ity--;
				ret+=st.getval(*ity,y+1);
				ret+=bt(*ity-1)-bt(*itx-1);
				cout<<(ret%mo+mo)%mo<<endl;
				
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
