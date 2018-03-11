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


template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
		FOR(i,NV) val[i+NV]=ma[i+NV]=0;
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[2*i],ma[2*i+1]);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
	}
};

int N,Q;
SegTree_3<int,1<<20> st;
int T,L,R,X;
set<pair<int,int>> S[20];

void add(int L,int R,int d) {
	if(L>=R) return;
	auto it=S[d].lower_bound({L+1,0});
	int nex=it->first;
	it--;
	if(it->second==1) {
		it++;
		add(it->first,R,d);
		return;
	}
	
	st.update(L,min(R,nex),1<<d);
	if(L!=it->first || L==1) {
		S[d].insert({L,1});
	}
	else {
		S[d].erase(it);
	}
	if(nex>R) {
		S[d].insert({R,0});
	}
	else {
		it++;
		S[d].erase(it);
		add(nex,R,d);
	}
}

void del(int L,int R,int d) {
	if(L>=R) return;
	auto it=S[d].lower_bound({L+1,0});
	int nex=it->first;
	it--;
	if(it->second==0) {
		it++;
		del(it->first,R,d);
		return;
	}
	
	st.update(L,min(R,nex),-1<<d);
	if(L!=it->first || L==1) {
		S[d].insert({L,0});
	}
	else {
		S[d].erase(it);
	}
	if(nex>R) {
		S[d].insert({R,1});
	}
	else {
		it++;
		S[d].erase(it);
		del(nex,R,d);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	int pre=0;
	FOR(j,20) S[j].insert({-1,0}),S[j].insert({N+1,0});
	for(i=1;i<=N;i++) {
		cin>>x;
		FOR(j,20) if((pre^x)&(1<<j)) {
			S[j].insert({i,((pre^x)>>j)&1});
		}
		pre=x;
	}
	
	while(Q--) {
		cin>>T>>L>>R;
		if(T==1) {
			cin>>X;
			FOR(i,20) if((X&(1<<i))==0) {
				del(L,R+1,i);
			}
		}
		else if(T==2) {
			cin>>X;
			FOR(i,20) if(X&(1<<i)) {
				add(L,R+1,i);
			}
		}
		else {
			cout<<st.getval(L,R+1)<<endl;
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
