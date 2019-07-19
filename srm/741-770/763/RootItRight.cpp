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

int N;
vector<int> E[404040];
int C[202020];
ll T[202020];
ll S[202020];
ll V[202020];

class RootItRight {
	public:
	
	void dfs(int cur,int pre) {
		C[cur]=1;
		FORR(e,E[cur]) if(e!=pre) {
			dfs(e,cur);
			C[cur]+=C[e];
			T[cur]+=T[e];
			S[cur]+=S[e];
		}
		S[cur]+=T[cur];
		T[cur]+=C[cur]*V[cur];
		//cout<<cur<<" "<<T[cur]<<" "<<S[cur]<<endl;
	}
	
	void dfs2(int cur,int pre,ll PT,ll PS) {
		PS+=PT;
		S[cur]+=PS;
		//cout<<cur<<" "<<T[cur]<<" "<<S[cur]<<" "<<PT<<" "<<PS<<endl;
		T[cur]-=C[cur]*V[cur];
		
		
		FORR(e,E[cur]) if(e!=pre) {
			
			T[cur]+=(N-C[e])*V[cur];
			dfs2(e,cur,PT+T[cur]-T[e],S[cur]-S[e]-T[e]);
			T[cur]-=(N-C[e])*V[cur];
			
		}
		
	}
	
	long long findMinimumTotalCost(int N_, vector <int> edge, vector <int> V_, int D, int seed, int MX) {
		N=N_;
		vector<ll> A(2*N);
		A[0]=seed;
		int i;
		for(i=1;i<=2*N-1;i++) A[i] = (A[i-1] * 1103515245LL + 12345) % 2147483648;
		for(i=edge.size();i<N;i++) {
			edge.push_back((A[i]%min(i,D))+i-min(i,D));
		}
		
		FOR(i,N) E[i].clear();
		for(i=1;i<=N-1;i++) {
			E[i].push_back(edge[i]);
			E[edge[i]].push_back(i);
		}
		for(i=V_.size();i<=N-1;i++) V_.push_back(A[N+i]%MX);
		FOR(i,N) V[i]=V_[i];
		
		ZERO(C);
		ZERO(T);
		ZERO(S);
		
		dfs(0,-1);
		dfs2(0,-1,0,0);
		
		return *min_element(S,S+N);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {-1,0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,3,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 0; int Arg5 = 5; long long Arg6 = 18LL; verify_case(0, Arg6, findMinimumTotalCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {-1,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,2,3,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 0; int Arg5 = 4; long long Arg6 = 5LL; verify_case(1, Arg6, findMinimumTotalCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {-1,0,0,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,0,3,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 0; int Arg5 = 6; long long Arg6 = 20LL; verify_case(2, Arg6, findMinimumTotalCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 17; int Arr1[] = {-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; int Arg4 = 176; int Arg5 = 15; long long Arg6 = 620LL; verify_case(3, Arg6, findMinimumTotalCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 200000; int Arr1[] = {-1,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 0; int Arg5 = 1000; long long Arg6 = 166346919874650680LL; verify_case(4, Arg6, findMinimumTotalCost(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RootItRight ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

