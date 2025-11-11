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

static ll const def=-1<<20;
template<int NV> class SegTree_3 {
public:
	vector<int> add;
	vector<pair<int,int>> val;
	SegTree_3(){
		int i;
		add.resize(NV*2); val.resize(NV*2);
		FOR(i,NV) val[i+NV]={0,1};
		for(i=NV-1;i>=1;i--) val[i]={0,val[2*i].second*2};
	};
	
	pair<int,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return {-1<<20,0};
		if(x<=l && r<=y) return val[k];
		auto a=getval(x,y,l,(l+r)/2,k*2);
		auto b=getval(x,y,(l+r)/2,r,k*2+1);
		if(a.first==b.first) {
			a.first+=add[k];
			a.second+=b.second;
			return a;
		}
		else if(a.first>b.first) {
			a.first+=add[k];
			return a;
		}
		else {
			b.first+=add[k];
			return b;
		}
	}
	
	void update(int x,int y, int v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			add[k]+=v;
			val[k].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			auto a=val[2*k];
			auto b=val[2*k+1];
			if(a.first==b.first) {
				val[k]={add[k]+a.first,a.second+b.second};
			}
			else if(a.first>b.first) {
				val[k]={add[k]+a.first,a.second};
			}
			else if(a.first<b.first) {
				val[k]={add[k]+b.first,b.second};
			}
		}
	}
};
SegTree_3<1<<20> st;


template<class V> struct RangeManager2 {
	V len;
	set<pair<V,V>> S;
private: //“à•”
	void add_callback(V L,V R) {
		st.update(L,R,1);
	}
	void del_callback(V L,V R) {
		st.update(L,R,-1);
	}
public:
	void init() {
		
	}
	void merge(int L,int R) {
		auto it=S.lower_bound({L,0});
		if(it!=S.end()) {
			assert(it->first>=R);
			if(it->first==R) {
				R=it->second;
				S.erase(it);
				it=S.lower_bound({L,0});
			}
		}
		if(it!=S.begin()) {
			it--;
			assert(it->second<=L);
			if(it->second==L) {
				L=it->first;
				S.erase(it);
			}
		}
		S.insert({L,R});
		
	}
	void add(V L,V R){
		while(L<R) {
			auto it=S.lower_bound({L,0});
			if(it!=S.begin()) {
				if(prev(it)->second>L) {
					L=prev(it)->second;
					continue;
				}
			}
			if(it!=S.end()&&it->first==L) {
				L=it->second;
				continue;
			}
			if(it==S.end()||it->first>=R) {
				add_callback(L,R);
				merge(L,R);
				break;
			}
			else {
				add_callback(L,it->first);
				merge(L,it->first);
				L=it->second;
			}
		}
		
	}
	void del(V L,V R){
		auto it=S.lower_bound({L,0});
		if(it!=S.begin()) {
			it--;
			if(it->second>L) {
				auto p=*it;
				S.erase(it);
				if(p.second>R) {
					del_callback(L,R);
					S.insert({R,p.second});
				}
				else {
					del_callback(L,p.second);
				}
				S.insert({p.first,L});
			}
		}
		while(1) {
			auto it=S.lower_bound({L,0});
			if(it==S.end()||it->first>=R) break;
			auto p=*it;
			S.erase(it);
			if(p.second>R) {
				del_callback(p.first,R);
				S.insert({R,p.second});
			}
			else {
				del_callback(p.first,p.second);
			}
		}
		
	}
	
};

RangeManager2<ll> rm[60];
int N,Q;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	while(Q--) {
		int L,R;
		cin>>i>>L>>R;
		L--;
		if(i==1) {
			cin>>x;
			x--;
			rm[x].add(L,R);
		}
		if(i==2) {
			cin>>x;
			x--;
			rm[x].del(L,R);
		}
		if(i==3) {
			auto p=st.getval(L,R);
			cout<<p.first<<" "<<p.second<<endl;
		}
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
