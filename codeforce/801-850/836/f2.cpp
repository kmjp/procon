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

int N;
int A[1202020];

static ll const def=1<<25;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<int,1<<21> st;

set<pair<int,int>> S;
pair<int,int> inside(int x) {
	auto it=S.lower_bound({x+1,0});
	if(it==S.begin()) return {-1,-1};
	it--;
	if(x<it->second) return *it;
	return {-1,-1};
}

vector<pair<int,int>> addV,delV;

void add(int L,int R) {
	if(L==R) return;
	S.insert({L,R});
	addV.push_back({L,R});
}
void del(int L,int R) {
	S.erase({L,R});
	delV.push_back({L,R});
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,1<<21) st.update(i+1,1<<20,-1);
	
	cin>>N;
	while(N--) {
		cin>>x;
		addV.clear();
		delV.clear();
		if(A[x]==0) {
			auto p=inside(x);
			A[x]^=1;
			st.update(x,1<<20,2);
			int CL,CR;
			if(p.first==-1) {
				auto q=inside(x+1);
				if(q.first==-1) {
					CL=x;
					CR=x+2;
				}
				else {
					del(q.first,q.second);
					CL=x;
					CR=q.second+1;
				}
				q=inside(x-1);
				if(q.first!=-1) {
					del(q.first,q.second);
					CL=q.first;
				}
			}
			else {
				del(p.first,p.second);
				CL=p.first;
				CR=p.second+1;
				auto q=inside(CR);
				if(q.first!=-1) {
					CR=q.second;
					del(q.first,q.second);
				}
				
				CR++;
			}
			auto q=inside(CR);
			if(q.first!=-1) {
				CR=q.second;
				del(q.first,q.second);
			}
			add(CL,CR);
		}
		else {
			auto p=inside(x);
			int CL=p.first;
			int CR=p.second;
			del(CL,CR);
			int cur=st.getval(CL-1,CL);
			int endr=st.getval(CR-1,CR);
			assert(cur==endr);
			A[x]=0;
			st.update(x,1<<20,-2);
			int TR=CR;
			for(i=19;i>=0;i--) if(TR-(1<<i)>CL) {
				if(st.getval(CL-1,TR-(1<<i))<=cur-2) TR-=1<<i;
			}
			add(CL,TR-2);
			add(TR,CR);
		}
		cout<<delV.size()<<endl;
		FORR2(a,b,delV) cout<<a<<" "<<b-1<<endl;
		cout<<addV.size()<<endl;
		FORR2(a,b,addV) cout<<a<<" "<<b-1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
