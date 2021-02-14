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
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

typedef unsigned long long ull;
vector <int> L;
vector <int> P;
int N;
ll S[1010];
class MaximumPenalty {
	public:
	ull tim(int i,ull s) {
		if(s>100000) return 1ULL<<63;
		return P[4*i]+P[4*i+1]*s+P[4*i+2]*s*s+P[4*i+3]*s*s*s;
	}
	vector<int> ok(ll v) {
		int i,j;
		vector<pair<int,int>> P;
		FOR(i,N) {
			if(tim(i,L[i])>v) return {};
			S[i]=0;
			for(j=16;j>=0;j--) if(tim(i,S[i]+L[i]+(1<<j))<=v) S[i]+=1<<j;
			P.push_back({S[i]+L[i],i});
		}
		sort(ALL(P));
		ll cur=0;
		vector<int> R;
		FORR(p,P) {
			int i=p.second;
			cur+=L[i];
			if(tim(i,cur)>v) return {};
			R.push_back(i);
		}
		return R;
		
	}
	
	vector <int> schedule(vector <int> L, vector <int> P) {
		::L=L;
		::P=P;
		N=L.size();
		
		ll ret=(1ULL<<63)-1;
		vector<int> V,R;
		for(int i=62;i>=0;i--) {
			V=ok(ret-(1ULL<<i));
			if(V.size()) {
				R=V;
				ret-=1ULL<<i;
			}
		}
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {7, 4, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 1,
 0, 0, 2, 0,
 0, 3, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, schedule(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {7, 4, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {47, 0, 0, 0,
 47, 0, 0, 0,
 47, 0, 0, 0,
 47, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 2, 1, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, schedule(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {7, 4, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 47, 0, 0,
 0, 47, 0, 0,
 0, 47, 0, 0,
 0, 47, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 2, 1, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, schedule(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7, 4, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 7, 8,  15,
 1, 6, 9,  14,
 2, 5, 10, 13,
 3, 4, 11, 12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, schedule(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MaximumPenalty ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

