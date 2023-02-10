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

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

template<class V,int NV> class SegTree_2 {
public:
	V nolink;
	vector<V> val;
	SegTree_2(){val.resize(NV*2); clear(); nolink=-100;};
	void clear() { for(int i=0;i<NV*2;i++) val[i]=0; }
	
	V getval(int k) {
		int e=k+NV;
		V ret=nolink;
		while(e>=1) ret=max(ret,val[e]), e/=2;
		return ret;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) val[k]=max(val[k],v);
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
		}
	}
};

int N;
string S;
set<int> alive;
SegTree_2<int,1<<20> st;
vector<int> del[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	auto Z=Zalgo(S);
	for(i=1;i<=N-1;i++) {
		Z[i]=min(i,Z[i]);
		if(Z[i]>1) {
			alive.insert(i);
			del[Z[i]].push_back(i);
		}
	}
	alive.insert(N+1);
	for(i=2;i<N;i++) {
		int cv=st.getval(i)+i-2;
		int nex=*alive.begin()+i;
		while(nex<=N) {
			st.update(nex,N+1,cv);
			cv+=i-1;
			nex=*alive.lower_bound(nex)+i;
		}
		FORR(e,del[i]) alive.erase(e);
	}
	cout<<N-st.getval(N)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
