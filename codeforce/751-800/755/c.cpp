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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1LL<<60;
	V comp(V l,V r){ return min(l,r);};
	
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
SegTree_1<ll,1<<19> up,down;


int T,N;
int A[303030];
ll S[303030];
map<ll,vector<int>> M;
void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>T;
	while(T--) {
		cin>>N;
		M.clear();
		M[0].push_back(0);
		
		FOR(i,N) {
			cin>>A[i];
			S[i+1]=S[i];
			if(i%2==0) {
				S[i+1]+=A[i];
				up.update(i+1,S[i+1]);
			}
			else {
				S[i+1]-=A[i];
				down.update(i+1,-S[i+1]);
			}
			M[S[i+1]].push_back(i+1);
		}
		ll ret=0;
		FOR(i,N) {
			int R=i,R2=i;
			
			for(j=19;j>=0;j--) {
				if(R+(1<<j)<=N) {
					if(up.getval(i,R+(1<<j)+1)>=S[i]) R+=1<<j;
				}
				if(R2+(1<<j)<=N) {
					if(down.getval(i,R2+(1<<j)+1)>=-S[i]) R2+=1<<j;
				}
			}
			R=min(R,R2);
			vector<int>& V=M[S[i]];
			ret+=lower_bound(ALL(V),R+1)-lower_bound(ALL(V),i+1);
		}
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}