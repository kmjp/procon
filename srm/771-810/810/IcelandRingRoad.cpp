#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll C[1505050],L[505050],W[505050];
vector<int> ev[1010101];

static ll const def=1<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val;
	vector<pair<V,int>> ma;
	void init(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2);
		FOR(i,NV) {
			val[i+NV]=0;
			ma[i+NV]={0,i};
		}
		for(i=NV-1;i>=1;i--) ma[i]=min(ma[2*i],ma[2*i+1]);
	};
	
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return {def,0};
		if(x<=l && r<=y) return ma[k];
		auto a=min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		a.first+=val[k];
		return a;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=min(ma[k*2],ma[k*2+1]);
			ma[k].first+=val[k];
		}
	}
};
SegTree_3<int,1<<20> st;

int N;
class IcelandRingRoad {
	ll cur;
	void add(int L,int R) {
		st.update(L,R,1);
		while(L<R) {
			auto p=st.getval(L,R);
			assert(p.first>0);
			if(p.first>1) break;
			cur+=C[p.second%N];
			L=p.second+1;
		}
	}
	void del(int L,int R) {
		auto p=st.getval(L,R);
		assert(p.first>0);
		st.update(L,R,-1);
		while(L<R) {
			auto p=st.getval(L,R);
			if(p.first>0) break;
			cur-=C[p.second%N];
			L=p.second+1;
		}
	}
	
	
	public:
	int solve(int N, int P, int M, long long state) {
		int i,j;
		::N=N;
		st.init();
		FOR(i,N) {
			state = (state * 1103515245 + 12345) % (1LL<<31);
			C[i] = 1 + ((state / 10)%M);
			C[i+N] = 1 + ((state / 10)%M);
			ev[i].clear();
			ev[i+N].clear();
		}
		cur=0;
		FOR(j,P) {
			state = (state * 1103515245 + 12345) % (1LL<<31);
		    L[j] = ((state / 10) % N);
			state = (state * 1103515245 + 12345) % (1LL<<31);
		    W[j] = ((state / 10) % N);
		    if(L[j]==W[j]) {
				j--,P--;
				continue;
			}
			if(L[j]>W[j]) swap(L[j],W[j]);
			ev[L[j]].push_back(j);
			add(L[j],W[j]);
		}
		ll mi=cur;
		FOR(i,N) {
			mi=min(mi,cur);
			FORR(e,ev[i]) {
				del(L[e],W[e]);
				L[e]+=N;
				swap(L[e],W[e]);
				add(L[e],W[e]);
				ev[L[e]].push_back(e);
			}
			mi=min(mi,cur);
		}
		
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 1000; long long Arg3 = 474747LL; int Arg4 = 1161; verify_case(0, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 47; int Arg2 = 1000; long long Arg3 = 420042LL; int Arg4 = 991; verify_case(1, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 12; int Arg2 = 1; long long Arg3 = 12345LL; int Arg4 = 83; verify_case(2, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  IcelandRingRoad ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

