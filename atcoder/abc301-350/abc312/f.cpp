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

int N,M;
int T[202020],X[202020];

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
BIT<ll,20> sum,num;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<pair<int,int>> V;
	vector<int> C;
	FOR(i,N) {
		cin>>T[i]>>X[i];
		if(T[i]==0) {
			V.push_back({X[i],0});
		}
		else if(T[i]==1) {
			V.push_back({X[i],1});
		}
		else if(T[i]==2) {
			C.push_back(X[i]);
		}
	}
	sort(ALL(V));
	sort(ALL(C));
	reverse(ALL(V));
	reverse(ALL(C));
	
	FOR(i,V.size()) {
		if(V[i].second==0) {
			sum.add(i+1,V[i].first);
			num.add(i+1,1);
		}
	}
	ll ma=0;
	if(num(N)<=M) ma=sum(N);
	else ma=sum(num.lower_bound(M));
	
	int cur=0;
	FOR(i,C.size()) {
		x=C[i];
		M--;
		if(M<0) break;
		while(cur<V.size()&&x) {
			if(V[cur].second==1) {
				x--;
				sum.add(cur+1,V[cur].first);
				num.add(cur+1,1);
			}
			cur++;
		}
		if(num(N)<=M) ma=max(ma,sum(N));
		else ma=max(ma,sum(num.lower_bound(M)));
	}
	
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
