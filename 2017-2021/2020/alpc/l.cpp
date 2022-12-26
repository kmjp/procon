#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<int NV> class SegTree_Lazy {
public:
	vector<int> num[2],op;
	vector<ll> inv[2];
	SegTree_Lazy(){
		num[0].resize(NV*2,1);
		num[1].resize(NV*2);
		op.resize(NV*2);
		inv[0].resize(NV*2);
		inv[1].resize(NV*2);
		for(int i=NV-1;i>0;i--) num[0][i]=num[0][2*i]+num[0][2*i+1];
	};

	pair<pair<int,int>,pair<ll,ll>> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return {{0,0},{0LL,0LL}};
		if(x<=l && r<=y) return {{num[0][k],num[1][k]},{inv[0][k],inv[1][k]}};
		auto a=getval(x,y,l,(l+r)/2,k*2);
		auto b=getval(x,y,(l+r)/2,r,k*2+1);
		pair<int,int> p={a.first.first+b.first.first,a.first.second+b.first.second};
		pair<ll,ll> q;
		q.first=a.second.first+b.second.first+1LL*a.first.second*b.first.first;
		q.second=a.second.second+b.second.second+1LL*a.first.first*b.first.second;
		
		if(op[k]) {
			swap(p.first,p.second);
			swap(q.first,q.second);
		}
		
		return {p,q};
	}

	void update(int x,int y,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			op[k]^=1;
			swap(num[0][k],num[1][k]);
			swap(inv[0][k],inv[1][k]);
		}
		else if(l < y && x < r) {
			update(x,y,l,(l+r)/2,k*2);
			update(x,y,(l+r)/2,r,k*2+1);
			num[0][k]=num[0][2*k]+num[0][2*k+1];
			num[1][k]=num[1][2*k]+num[1][2*k+1];
			inv[0][k]=inv[0][2*k]+inv[0][2*k+1]+1LL*num[1][2*k]*num[0][2*k+1];
			inv[1][k]=inv[1][2*k]+inv[1][2*k+1]+1LL*num[0][2*k]*num[1][2*k+1];
			if(op[k]) {
				swap(num[0][k],num[1][k]);
				swap(inv[0][k],inv[1][k]);
			}
			
		}
	}
};
SegTree_Lazy<1<<20> st;
int N,Q;
int T,L,R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>x;
		if(x) st.update(i,i+1);
	}
	while(Q--) {
		cin>>T>>L>>R;
		L--;
		if(T==1) {
			st.update(L,R);
		}
		else {
			auto a=st.getval(L,R);
			cout<<a.second.first<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
