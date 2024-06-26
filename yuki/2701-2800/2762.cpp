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

vector<ll> def={1,0,0,0,1,0,0,0,1};
vector<ll> A0={1,1,0,0,1,0,0,0,1};
vector<ll> A1={1,0,0,1,1,1,0,0,1};

const ll mo=998244353;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		vector<ll> A(9);
		int a,b,c;
		FOR(a,3) FOR(b,3) FOR(c,3) {
			(A[a*3+b]+=r[a*3+c]*l[c*3+b])%=mo;
		}
		
		return A;
	};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
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
SegTree_1<vector<ll>,1<<20> st;

int N,Q;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	set<int> alive;
	FOR(i,N) {
		alive.insert(i);
		if(S[i]=='0') st.update(i,A0);
		else st.update(i,A1);
	}
	alive.insert(N);
	while(Q--) {
		int L,R;
		cin>>i>>L>>R;
		L--;
		if(i==1) {
			auto it=alive.lower_bound(L);
			while(*it<R) {
				st.update(*it,def);
				it=alive.erase(it);
			}
		}
		else {
			auto p=st.getval(L,R);
			cout<<(p[2]+p[5])%mo<<endl;
		}
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
