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

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	static V const def=0;
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	S="*"+S+"*";
	set<int> cand={0,N+1};
	for(i=1;i<=N;i++) if(S[i]!=S[i-1]) {
		cand.insert(i);
	}
	auto it=cand.begin();
	while(next(it)!=cand.end()) {
		st.update(*it,*next(it)-*it);
		it++;
	}
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>s;
			S[x]=s[0];
			cand.insert(x);
			cand.insert(x+1);
			if(S[x]==S[x-1]) {
				cand.erase(x);
				st.update(x,0);
			}
			if(S[x+1]==S[x]) {
				cand.erase(x+1);
				st.update(x+1,0);
			}
			auto it=cand.lower_bound(x);
			FOR(i,3) if(it!=cand.begin()) it--;
			FOR(i,5) {
				if(next(it)!=cand.end()) {
					st.update(*it,*next(it)-*it);
					it++;
				}
			}
		}
		else {
			cin>>x>>y;
			y++;
			auto it=cand.lower_bound(x);
			if(*it>=y) {
				cout<<y-x<<endl;
				continue;
			}
			auto it2=prev(cand.lower_bound(y));
			int a=*it;
			int b=*it2;
			int ret=-1;
			ret=max(ret,a-x);
			ret=max(ret,y-b);
			ret=max(ret,st.getval(a,b));
			cout<<ret<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
