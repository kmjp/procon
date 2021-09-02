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

class MarsHabitats {
	public:
	vector <int> design(vector <int> distances) {
		int N=distances.size();
		if(N%2) return {};
		vector<pair<int,int>> V;
		int i;
		FOR(i,N) V.push_back({distances[i],i});
		sort(ALL(V));
		vector<pair<int,int>> R[200];
		FOR(i,N-1) {
			int x=V[i].second;
			int y=V[i+1].second;
			
			if(i%2==0) {
				R[x].push_back({y,distances[y]-distances[x]});
				R[x].push_back({y,distances[y]-distances[x]});
				R[y].push_back({x,distances[y]-distances[x]});
				R[y].push_back({x,distances[y]-distances[x]});
			}
			else {
				R[x].push_back({y,distances[y]-distances[x]});
				R[y].push_back({x,distances[y]-distances[x]});
			}
		}
		int x=V[0].second;
		int y=V.back().second;
		R[x].push_back({y,distances[y]-distances[x]});
		R[y].push_back({x,distances[y]-distances[x]});
		vector<int> ret;
		FOR(i,N) {
			assert(R[i].size()==3);
			FORR(a,R[i]) ret.push_back(a.first),ret.push_back(a.second);
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, design(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 10, 1, 42, 1, 47, 0, 10, 0, 47, 0, 42 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, design(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 10, 0, 10, 1, 47, 1, 10, 0, 47, 1, 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, design(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 47, 42, 25, 10, 22}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 47, 2, 42, 4, 10, 0, 47, 3, 33, 3, 34, 0, 42, 2, 1234, 2, 1234, 1, 34, 1, 33, 4, 15, 0, 10, 3, 15, 5, 12, 5, 0, 4, 12, 5, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, design(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MarsHabitats ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

