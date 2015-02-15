#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class TallShoes {
	public:
	int mat[51][51], N;
	ll B;
	
	int ok(int H) {
		int i;
		ll mon[51];
		MINUS(mon);
		
		mon[0]=B;
		priority_queue<pair<ll,int> > Q;
		Q.push(make_pair(B,0));
		while(Q.size()) {
			ll m=Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(mon[cur]!=m) continue;
			FOR(i,N) if(i!=cur && mat[i][cur]>=0) {
				ll c=max(H-mat[i][cur],0);
				c=c*c;
				if(mon[i]<m-c) mon[i]=m-c,Q.push(make_pair(mon[i],i));
			}
			
		}
		
		return mon[N-1]>=0;
	}
	
	int maxHeight(int N, vector <int> X, vector <int> Y, vector <int> height, long long B) {
		int i,x,y;
		MINUS(mat);
		FOR(i,X.size()) mat[X[i]][Y[i]]=mat[Y[i]][X[i]]=height[i];
		
		this->N=N;
		this->B=B;
		int ret=0;
		for(i=30;i>=0;i--) if(ok(ret+(1<<i))) ret += 1<<i;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 4, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 1LL; int Arg5 = 4; verify_case(0, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 4, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 52LL; int Arg5 = 9; verify_case(1, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 8; int Arr1[] = {0, 0, 3, 3, 4, 4, 4, 7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 1, 2, 3, 5, 6, 5, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1000, 1000, 1000, 1000, 1, 1000, 1000, 1000, 1000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 3LL; int Arg5 = 2; verify_case(2, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {0,1,2,3,4,5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0,0,0,0,0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 9876543210123LL; int Arg5 = 1047565; verify_case(3, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 6; int Arr1[] = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {999999,986588,976757,988569,977678,999999,967675,947856,955856,999999,975956,956687,999999,979687,999999}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 0LL; int Arg5 = 999999; verify_case(4, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TallShoes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
