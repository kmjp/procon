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

int N,Q,D;

int rot(int v) {
	string S=to_string(v);
	S=S.substr(1)+S[0];
	return atoi(S.c_str());
}

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val[10];
	vector<V> nr;
	SegTree_3(){
		int i;
		FOR(i,10) {
			val[i].resize(NV*2,0);
		}
		nr.resize(NV*2);
	};
	
	vector<int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		vector<int> R(10);
		int i;
		if(r<=x || y<=l || y<=x) return R;
		if(x<=l && r<=y) {
			FOR(i,D) R[i]=val[i][k];
			return R;
		}
		auto a=getval(x,y,l,(l+r)/2,k*2);
		auto b=getval(x,y,(l+r)/2,r,k*2+1);
		FOR(i,D) R[i]=a[(i+nr[k])%D]^b[(i+nr[k])%D];
		return R;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		int i;
		if(x<=l && r<=y) {
			vector<int> W(10);
			FOR(i,D) W[i]=val[i][k];
			FOR(i,D) val[i][k]=W[(i+v)%D];
			nr[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			FOR(i,D) val[i][k]=val[(i+nr[k])%D][2*k]^val[(i+nr[k])%D][2*k+1];
		}
	}
	void update(int entry, V v) {
		entry += NV;
		int i;
		FOR(i,D) {
			val[i][entry]=v;
			v=rot(v);
		}
		while(entry>1) {
			entry>>=1;
			FOR(i,D) val[i][entry]=val[i][entry*2]^val[i][entry*2+1];
		}
	}
};
SegTree_3<int,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	ll cur=0;
	FOR(i,N) {
		cin>>x;
		st.update(i,x);
	}

	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x;
			cur+=x;
			cur%=N;
		}
		else if(i==2) {
			int L,R;
			cin>>L>>R>>y;
			L=L-1+cur;
			R=R-1+cur;
			if(L/N==R/N) {
				st.update(L%N,R%N+1,y);
			}
			else {
				st.update(L%N,N,y);
				st.update(0,R%N+1,y);
			}
		}
		else if(i==3) {
			int L,R;
			cin>>L>>R;
			L=L-1+cur;
			R=R-1+cur;
			x=0;
			if(L/N==R/N) {
				x=st.getval(L%N,R%N+1)[0];
			}
			else {
				x=st.getval(L%N,N)[0]^st.getval(0,R%N+1)[0];
			}
			cout<<x<<endl;
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
