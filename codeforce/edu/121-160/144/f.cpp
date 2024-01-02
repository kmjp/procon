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

ll A,B,N;
ll p10[11];
int dlen[100001];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	p10[0]=1;
	FOR(i,10) p10[i+1]=p10[i]*10;
	for(i=0;i<=5;i++) for(j=p10[i];j<=100000;j++) dlen[j]++;
	
	int pat=0;
	set<pair<ll,ll>> R;
	for(int nlen=1;nlen<=9;nlen++) {
		ll p9=p10[nlen]-1;
		vector<int> Ks;
		for(int a=1;a*a<=p9;a++) if(p9%a==0) {
			Ks.push_back(a);
			if(a*a!=p9) Ks.push_back(p9/a);
		}
		
		FORR(k2,Ks) {
			int r=p9/k2;
			for(int d=1;d<100000;d++) {
				for(int lenb=dlen[d];lenb<=5;lenb++) {
					int bd=p10[lenb]-1LL*d*r%p10[lenb];
					int lb=(p10[lenb-1]+bd-1)/bd;
					int rb=(p10[lenb]-1)/bd;
					int dd=d/__gcd(d,bd);
					for(int g=(lb+dd-1)/dd*dd;g<=rb;g+=dd) {
						ll b=1LL*g*bd;
						if(b>100000) break;
						int k1=b/d;
						if(__gcd(k1,r)>1) continue;
						int ad=(1LL*d*r+bd)/p10[lenb];
						if(1LL*ad*g>100000) continue;
						ll n=1LL*k1*k2*ad;
						ll a=ad*g;
						if(to_string(n).size()==nlen) R.insert({a*1000000+b,n});
						
					}
				}
			}
		}
		
	}
	
	
	
	cin>>A>>B>>N;
	int num=0;
	FORR2(ab,n,R) {
		ll a=ab/1000000;
		ll b=ab%1000000;
		int nlen=to_string(n).size();
		if(a<A&&b<B&&n<N) {
			ll v=(a*p10[nlen]+n)*b;
			ll w=(n*p10[dlen[b]]+b)*a;
			if(v==w) num++;
		}
	}
	cout<<num<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
