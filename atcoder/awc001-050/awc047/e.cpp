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

int N,Q;
string S;

template<typename ST=string>
struct SuffixArray {
	int N; vector<int> rank,lcp,sa,rsa; ST S;

	
	SuffixArray(ST S) : S(S){
		int i,h=0; vector<int> tmp;
		N=S.size(); rank.resize(N+1); sa.resize(N+1); tmp.resize(N+1);
		FOR(i,N+1) sa[i]=i, rank[i]=i==N?-1:S[i];
		
		for(int k=1; k<=N; k<<=1) {
			auto pred2 = [k,this](int& a,int &b)->bool{ return (((a+k<=N)?rank[a+k]:-1)<((b+k<=N)?rank[b+k]:-1));};
			auto pred = [pred2,k,this](int& a,int &b)->bool{ return (rank[a]!=rank[b])?(rank[a]<rank[b]):pred2(a,b);};
			int x=0;
			if(k!=1) for(i=1;i<N+1;i++) if(rank[sa[i]]!=rank[sa[x]]) sort(sa.begin()+x,sa.begin()+i,pred2), x=i;
			sort(sa.begin()+x,sa.end(),pred);
			FOR(i,N+1) tmp[sa[i]]=(i==0)?0:tmp[sa[i-1]]+pred(sa[i-1],sa[i]);
			swap(rank,tmp);
		}
		lcp.resize(N+1); rsa.resize(N+1);
		FOR(i,N+1) rsa[sa[i]]=i;
		FOR(i,N) {
			int j=sa[rsa[i]-1];
			for(h=max(h-1,0);i+h<N && j+h<N; h++) if(S[j+h]!=S[i+h]) break;
			lcp[rsa[i]-1]=h;
		}
	}
};

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<20;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,0);};
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
SegTree_1<int,1<<20> st;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	S=S+S+"$";
	SuffixArray sa(S);
	
	ll ma=0;
	set<int> V;
	FOR(i,2*N+1) {
		st.update(i,sa.lcp[i]);
		if(sa.sa[i]>=N) V.insert(i);
	}
	
	while(Q--) {
		ll L,R;
		cin>>L>>R;
		L--;
		if(R-L>N) {
			cout<<"No"<<endl;
			continue;
		}
		int len=R-L;
		L%=N;
		R%=N;
		if(L<R) {
			cout<<"Yes"<<endl;
			continue;
		}
		
		int ok=0;
		x=sa.rsa[L];
		auto it=V.lower_bound(x);
		if(it!=V.begin()) {
			y=*prev(it);
			if(st.getval(y,x)>=len) ok=1;
		}
		if(it!=V.end()) {
			y=*it;
			if(st.getval(x,y)>=len) ok=1;
		}
		if(ok) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
