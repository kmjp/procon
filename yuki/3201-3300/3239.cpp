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

template<class V, int ME> class BIT_map {
public:
	map<int,V> bit;
	V op(V a,V b){ return a+b; };
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s=op(s,bit[e-1]),e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]=op(bit[e-1],v),e+=e&-e;}
};

BIT_map<int,18> num[26*26*26];
BIT_map<ll,18> sum[26*26*26];

int N,Q;
int V[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>s;
	FOR(i,N) V[i]=s[i]-'a';
	FOR(i,N) {
		x=V[i]+V[i+1]*26+V[i+2]*26*26;
		num[x].add(i,1);
		sum[x].add(i,i);
	}
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>s;
			x--;
			for(i=max(0,x-2);i<=x;i++) {
				y=V[i]+V[i+1]*26+V[i+2]*26*26;
				num[y].add(i,-1);
				sum[y].add(i,-i);
			}
			V[x]=s[0]-'a';
			for(i=max(0,x-2);i<=x;i++) {
				y=V[i]+V[i+1]*26+V[i+2]*26*26;
				num[y].add(i,1);
				sum[y].add(i,i);
			}
		}
		else {
			int L,R;
			cin>>L>>R>>s;
			L--;
			y=(s[0]-'a')*1LL+(s[1]-'a')*26LL+(s[2]-'a')*26LL*26;
			ll ret=0;
			if(R-L>=3) {
				ll ns=num[y](R-3)-num[y](L-1);
				ll ss=sum[y](R-3)-sum[y](L-1);
				ret=ss-ns*(L-1);
			}
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
