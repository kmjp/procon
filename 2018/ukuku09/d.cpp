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

pair<vector<int>,pair<int,int> > manacher(string S) {
	int L=S.size(),i,j,k;
	vector<int> rad(2*L-1,0);
	for(i=j=0;i<2*L-1;i+=k,j=max(j-k,0)) {
		while(i-j>=0 && i+j+1<=2*L-1 && S[(i-j)/2]==S[(i+j+1)/2]) j++;
		rad[i]=j;
		for(k=1;i-k>=0 && rad[i]-k>=0 && rad[i-k]!=rad[i]-k; k++) rad[i+k]=min(rad[i-k],rad[i]-k);
	}
	i=max_element(rad.begin(),rad.end())-rad.begin();
	return make_pair(rad,make_pair((i-(rad[i]-1))/2,(i+(rad[i]-1))/2));
}

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
		val[entry]=comp(v,val[entry]); //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> st;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	auto p=manacher(S);
	FOR(i,N) {
		st.update(i,(p.first[i*2]+1)/2);
	}
	
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--;
		int ret=1;
		for(i=20;i>=0;i--) {
			int tmp=ret+(1<<i);
			if(tmp*2-1>R-L) continue;
			if(st.getval(L+tmp-1,R-tmp+1)>=tmp) ret=tmp;
		}
		cout<<ret*2-1<<endl;
		
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
