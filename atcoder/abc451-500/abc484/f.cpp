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


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> sum,num;

static int const def=-101010;
template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_ma(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_ma<int,1<<20> st;

int N,Q;
int A[302020];




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]>=0) {
			sum.add(i,A[i]);
			num.add(i,1);
		}
		st.update(i,A[i]);
	}
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y;
			x--;
			if(A[x]!=-1) {
				sum.add(x,-A[x]);
				num.add(x,-1);
			}
			A[x]=y;
			if(A[x]!=-1) {
				sum.add(x,A[x]);
				num.add(x,1);
			}
			st.update(x,A[x]);
		}
		else {
			cin>>x>>y;
			x--;
			k=num(y-1)-num(x-1);
			if(k==0) {
				cout<<"Yes"<<endl;
			}
			else {
				int ma=st.getval(x,y);
				ll s=sum(y-1)-sum(x-1);
				
				if(s==1LL*k*ma) {
					cout<<"Yes"<<endl;
				}
				else {
					cout<<"No"<<endl;
				}
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
