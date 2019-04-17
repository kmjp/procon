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

int vis[505050];

class OneHandSort2 {
	public:
	int minMoves(int N, vector <int> P, int a, int b) {
		set<int> S;
		int i;
		FOR(i,N) S.insert(i);
		FORR(p,P) S.erase(p);
		for(i=P.size();i<N;i++) {
			ll tmp=(1LL*P.back()*a+b)%N;
			auto it=S.lower_bound(tmp);
			if(it==S.end()) it=S.begin();
			P.push_back(*it);
			S.erase(it);
		}
		ZERO(vis);
		int ret=0;
		FOR(i,N) {
			if(vis[i]) continue;
			if(P[i]==i) continue;
			int cur=i;
			int len=0;
			while(P[cur]!=i) {
				len++;
				cur=P[cur];
				vis[cur]=1;
			}
			vis[i]=1;
			ret+=len+2;
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {1, 2, 3, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 0; int Arg4 = 5; verify_case(0, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {2, 3, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 0; int Arg4 = 6; verify_case(1, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {3, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1664525; int Arg3 = 1013904223; int Arg4 = 11; verify_case(2, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {5, 9, 8, 7, 6, 0, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 1; int Arg4 = 13; verify_case(3, Arg4, minMoves(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OneHandSort2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

