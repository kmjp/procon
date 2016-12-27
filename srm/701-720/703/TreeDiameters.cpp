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

class TreeDiameters {
	public:
	int N;
	vector<int> E[1010];
	int ma,md;
	int num[1010];
	int sum[1010];
	int count[1010];
	
	void dfs(int cur,int pre,int d) {
		md=max(md,d);
		count[d]++;
		FORR(r,E[cur]) if(r!=pre) dfs(r,cur,d+1);
	}
	
	int getMax(vector <int> p) {
		int N=p.size()+1;
		int i,j;
		FOR(i,N) E[i].clear();
		FOR(i,p.size()) E[i+1].push_back(p[i]),E[p[i]].push_back(i+1);
		
		ma=0;
		FOR(i,N) {
			ZERO(num);
			ZERO(sum);
			FORR(r,E[i]) {
				md=0;
				dfs(r,i,1);
				for(j=0;j<=md;j++) {
					sum[j] += num[j]*count[j];
					ma=max(ma,sum[j]);
					num[j] += count[j];
					count[j]=0;
				}
			}
		}
		FOR(i,N) FORR(r,E[i]) if(r>i) {
			ZERO(num);
			ZERO(sum);
			md=0;
			dfs(i,r,0);
			for(j=0;j<=md;j++) num[j]=count[j], count[j]=0;
			md=0;
			dfs(r,i,0);
			for(j=0;j<=md;j++) ma=max(ma,num[j]*count[j]),count[j]=0;
		}
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, getMax(Arg0)); }
	void test_case_1() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, getMax(Arg0)); }
	void test_case_2() { int Arr0[] = {0,1,2,3,4,5,6,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getMax(Arg0)); }
	void test_case_3() { int Arr0[] = {0,0,0,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, getMax(Arg0)); }
	void test_case_4() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, getMax(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TreeDiameters ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

