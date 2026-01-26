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
BIT<ll,20> num[3],sum[3];
multiset<ll> V[3];
int X[202020],Y[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		num[Y[i]].add(X[i],1);
		sum[Y[i]].add(X[i],X[i]);
		V[Y[i]].insert(X[i]);
	}
	while(Q--) {
		cin>>i>>x>>y;
		i--;
		num[Y[i]].add(X[i],-1);
		sum[Y[i]].add(X[i],-X[i]);
		V[Y[i]].erase(V[Y[i]].find(X[i]));
		X[i]=x;
		Y[i]=y;
		num[Y[i]].add(X[i],1);
		sum[Y[i]].add(X[i],X[i]);
		V[Y[i]].insert(X[i]);
		
		int n2=V[2].size();
		if(n2==0) {
			cout<<sum[1](1000000)<<endl;
			continue;
		}
		else if(n2==N) {
			ll s=2*sum[2](1000000);
			x=num[2].lower_bound(1);
			s-=x;
			cout<<s<<endl;
		}
		else if(n2==1) {
			ll s=sum[1](1000000)+sum[2](1000000);
			s+=*V[1].rbegin();
			cout<<s<<endl;
		}
		else {
			x=0;
			for(i=19;i>=0;i--) if(N-num[1](x+(1<<i)-1)-num[2](x+(1<<i)-1)>=n2) x+=1<<i;
			ll s=0;
			if(num[2](x-1)==0) {
				s=2*sum[2](1000000)-*V[2].begin()+sum[1](1000000)+*V[1].rbegin();
			}
			else {
				int ov=N-num[1](x-1)-num[2](x-1)-n2;
				s=2*(sum[2](1000000)+sum[1](1000000))-sum[2](x-1)-sum[1](x-1)-(1LL*ov*x);
			}
			cout<<s<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
