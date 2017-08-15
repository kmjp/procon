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

class OwaskiAndTree {
	public:
	int N;
	vector<int> E[1010];
	int S[1010];
	
	int dfs(int cur,int pre) {
		int tot=S[cur];
		FORR(e,E[cur]) if(e!=pre) tot+=dfs(e,cur);
		return max(0,tot);
	}
	pair<int,int> dfs2(int cur,int pre) {
		int take=S[cur];
		int nottake=0;
		FORR(e,E[cur]) if(e!=pre) {
			pair<int,int> p=dfs2(e,cur);
			take+=max(0,p.first);
			nottake+=max({0,p.first,p.second});
		}
		
		return make_pair(take,nottake);
	}
	
	int maximalScore(vector <int> parent, vector <int> pleasure) {
		N=pleasure.size();
		int i,j,x;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			E[i+1].push_back(parent[i]);
			E[parent[i]].push_back(i+1);
		}
		
		int ma=0;
		FOR(i,N) {
			FOR(j,N) S[j]=pleasure[j];
			
			x=i;
			while(x) x=parent[x-1], S[x]=0;
			
			int tot=max(0,pleasure[i]);
			FORR(e,E[i]) {
				if(e>i) {
					tot+=dfs(e,i);
				}
				if(e<i) {
					auto a=dfs2(e,i);
					tot+=max(a.first,a.second);
				}
			}
			ma=max(ma,tot);
		}
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, -1, -1, -1, -1, 1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, maximalScore(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 4, -1, -1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(1, Arg2, maximalScore(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 1, 1, 2, 2, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, -3, -7, 3, 2, 7, -1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 17; verify_case(2, Arg2, maximalScore(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 1, 1, 1, 0, 3, 1, 3, 4, 4, 3, 6, 8, 0, 12, 12, 11, 7, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-154011, 249645, 387572, 292156, -798388, 560085, -261135, -812756, 191481, -165204, 81513, -448791, 608073, 354614, -455750, 325999, 227225, -696501, 904692, -297238}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3672275; verify_case(3, Arg2, maximalScore(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, maximalScore(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OwaskiAndTree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

