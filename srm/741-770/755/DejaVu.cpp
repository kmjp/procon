#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll A[202020];
ll M[202020];
map<int,vector<int>> memo;
int pre[201010];
int nex[201010];

static ll const def=-1<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	void init(){
		val.resize(NV*2,0); ma.resize(NV*2,0);
	}
	
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
SegTree_3<int,1<<20> st;

class DejaVu {
	public:
	int mostDejaVus(int N, int seed, int R) {
		A[0]=seed;
		int i;
		for(i=1;i<N;i++) A[i]=(A[i-1]*1664525+1013904223)%4294967296;
		memo.clear();
		FOR(i,N) {
			M[i]=A[i]%R;
			memo[M[i]].push_back(i);
			pre[i]=-1;
			nex[i]=N;
		}
		nex[N]=N;
		st.init();
		FORR(m,memo) {
			vector<int> V=m.second;
			if(V.size()>=2) {
				for(i=0;i<V.size();i++) {
					if(i) pre[V[i]]=V[i-1];
					if(i+1<V.size()) nex[V[i]]=V[i+1];
				}
				int f=V[0];
				st.update(nex[f],nex[nex[f]],1);
			}
		}
		int ma=0;
		FOR(i,N) {
			ma=max(ma,st.getval(0,N));
			st.update(nex[i],nex[nex[i]],-1);
			st.update(nex[nex[i]],nex[nex[nex[i]]],1);
		}
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 47; int Arg2 = 5; int Arg3 = 2; verify_case(0, Arg3, mostDejaVus(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 14; int Arg1 = 474747; int Arg2 = 7; int Arg3 = 3; verify_case(1, Arg3, mostDejaVus(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DejaVu ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

