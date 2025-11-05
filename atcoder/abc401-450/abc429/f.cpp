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
string S[3];

array<ll,9> def;
template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	V comp(V l,V r){
		int s,t,e;
		array<ll,9> m;
		FOR(s,3) FOR(t,3) m[s*3+t]=1LL<<30;
		FOR(s,3) FOR(t,3) {
			FOR(e,3) chmin(m[s*3+t],l[s*3+e]+r[e*3+t]);
		}
		return m;
	};
	
	SegTree_ma(){val=vector<V>(NV*2,def);};
	void update(int entry, string S) {
		entry += NV;
		int y,x,z;
		FOR(x,3) FOR(y,3) val[entry][x*3+y]=1<<30;
		FOR(x,3) FOR(y,3) {
			int ok=1;
			for(z=min(x,y);z<=max(x,y);z++) if(S[z]=='#') break;
			if(z==max(x,y)+1) chmin(val[entry][x*3+y],abs(x-y)+1LL);
		}
		
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_ma<array<ll,9>,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	FOR(x,3) FOR(y,3) def[x*3+y]=(x==y)?0:1<<30;
	FOR(i,1<<21) st.val[i]=def;
	
	cin>>N;
	FOR(y,3) cin>>S[y];
	FOR(i,N) {
		s=S[0][i];
		s+=S[1][i];
		s+=S[2][i];
		st.update(i,s);
	}
	cin>>Q;
	while(Q--) {
		cin>>y>>x;
		y--,x--;
		if(S[y][x]=='#') {
			S[y][x]='.';
		}
		else {
			S[y][x]='#';
		}
		s=S[0][x];
		s+=S[1][x];
		s+=S[2][x];
		st.update(x,s);
		if(st.val[1][2]>=1<<20) {
			cout<<-1<<endl;
		}
		else {
			cout<<st.val[1][2]-1<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
