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

int T;
int N,C;
int A[201010],L[201010],R[201010],re[201010];
const int g1=0;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<ll,20> bit;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>C;
		int mi=C+1;
		
		int num=0;
		if(g1) {
			vector<int> V;
			FOR(i,N) {
				cin>>A[i];
				V.push_back(i+1+A[i]);
			}
			sort(ALL(V));
			FOR(i,N) if(C>=V[i]) num++, C-=V[i];
		}
		else {
			vector<pair<int,int>> V;
			FOR(i,N) {
				cin>>A[i];
				L[i]=i+1+A[i];
				R[i]=N-i+A[i];
				V.push_back({min(L[i],R[i]),i});
			}
			sort(ALL(V));
			FOR(i,N) re[V[i].second]=i;
			FOR(i,N) {
				bit.add(re[i],min(L[i],R[i]));
			}
			FOR(i,N) {
				if(L[i]>C) continue;
				int lef=C-L[i];
				bit.add(re[i],-min(L[i],R[i]));
				x=bit.lower_bound(lef+1);
				if(x<re[i]) y=x+1;
				else y=x;
				num=max(num,y);
				bit.add(re[i],min(L[i],R[i]));
			}
			num=min(num,N);
			
			FOR(i,N) bit.set(i,0);
			
		}
		cout<<num<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
