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

ll mo[2]={1000000007,1000000009};
ll P[2][(2<<20)+5];



template<class V,int NV,int H> class SegTree_1 {
public:
	vector<pair<V,int>> val;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){
		ll a=(l.first*P[H][r.second]+r.first)%mo[H];
		return {a,l.second+r.second};
	};
	
	SegTree_1(){val=vector<pair<V,int>>(NV*2,{0,0});};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0LL,0};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]={v,1};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<ll,1<<20,0> st1,ts1;
SegTree_1<ll,1<<20,1> st2,ts2;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,2) {
		P[i][0]=1;
		FOR(j,(2<<20)+3) P[i][j+1]=(P[i][j]*1236)%mo[i];
	}
	
	cin>>N>>Q;
	cin>>S;
	FOR(i,N) {
		st1.update(i,S[i]);
		st2.update(i,S[i]);
		ts1.update(N-1-i,S[i]);
		ts2.update(N-1-i,S[i]);
	}
	
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>i>>s;
			i--;
			S[i]=s[0];
			st1.update(i,S[i]);
			st2.update(i,S[i]);
			ts1.update(N-1-i,S[i]);
			ts2.update(N-1-i,S[i]);
		}
		else {
			cin>>x>>y;
			x--;
			y--;
			ll a=st1.getval(x,y+1).first;
			ll b=st2.getval(x,y+1).first;
			x=N-1-x;
			y=N-1-y;
			ll c=ts1.getval(y,x+1).first;
			ll d=ts2.getval(y,x+1).first;
			if(a==c&&b==d) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
		}
	}
	
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
