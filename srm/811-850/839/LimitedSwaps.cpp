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

ll W[252525];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,19> bit;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	// static V const def=1LL<<60; min
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v; //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<18> st;

class LimitedSwaps {
	public:
	long long minInversions(int N, int L, int M, vector <int> Wprefix, int seed) {
		ll state = seed;
		int i;
		vector<ll> Ws;
		FOR(i,Wprefix.size()) W[i]=Wprefix[i];
		for(i=Wprefix.size();i<N;i++) {
			state = (state * 1103515245 + 12345)%(1LL<<31);
			W[i]=1+state%M;
		}
		ZERO(bit.bit);
		
		vector<pair<int,int>> V;
		FOR(i,N) {
			V.push_back({W[i],i});
			bit.add(i,1);
			st.update(i,W[i]);
		}
		sort(ALL(V));
		ll ret=0;
		int j;
		FORR(v,V) {
			i=v.second;
			int t=i;
			for(j=20;j>=0;j--) if(t-(1<<j)>=0) {
				int w=st.getval(t-(1<<j),i);
				if(w+W[i]<=L) t-=1<<j;
			}
			ret+=bit(t-1);
			bit.add(i,-1);
			
		}
		
		
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 200; int Arg2 = 1000; int Arr3[] = {40, 20, 10, 70, 30, 50, 60}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 42; long long Arg5 = 0LL; verify_case(0, Arg5, minInversions(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 29; int Arg2 = 1000; int Arr3[] = {40, 20, 10, 70, 30, 50, 60}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 47; long long Arg5 = 7LL; verify_case(1, Arg5, minInversions(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 30; int Arg2 = 1000; int Arr3[] = {40, 20, 10, 70, 30, 50, 60}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 47; long long Arg5 = 6LL; verify_case(2, Arg5, minInversions(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 30; int Arg2 = 1000; int Arr3[] = {20, 40, 10, 70, 30, 50, 60}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 47; long long Arg5 = 6LL; verify_case(3, Arg5, minInversions(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 1234; int Arg2 = 1000; int Arr3[] = {500, 470, 923}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 47; long long Arg5 = 7LL; verify_case(4, Arg5, minInversions(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 7; int Arg1 = 100; int Arg2 = 100; int Arr3[] = {5, 5, 5, 7, 6, 6, 6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 47; long long Arg5 = 0LL; verify_case(5, Arg5, minInversions(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LimitedSwaps ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

