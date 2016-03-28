#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int mat[105][105];
int did[1010];

class EllysTree {
	public:
	
	int N;
	int ok(int st,int L) {
		int did2[101];
		int i,j;
		FOR(i,N) did2[i]=did[i];
		did2[st]=1;
		
		FOR(i,L) {
			int be=-1;
			FOR(j,N) if(did2[j]==0 && (mat[st][j]<=100 || mat[j][st]<=100)) {
				if(be==-1 || mat[0][be]<mat[0][j]) be=j;
			}
			if(be==-1) return 0;
			st=be;
			did2[st]=1;
		}
		return 1;
	}
	
	vector <int> getMoves(vector <int> parent) {
		int i,x,y,z;
		N=parent.size()+1;
		FOR(x,N) FOR(y,N) mat[x][y]=(x!=y)*1010;
		FOR(i,N-1) mat[parent[i]][i+1]=1;
		FOR(z,N) FOR(x,N) FOR(y,N) mat[x][y] = min(mat[x][y],mat[x][z]+mat[z][y]);
		
		vector<int> V;
		ZERO(did);
		did[0]=1;
		x = 0;
		while(1) {
			FOR(i,N) if(did[i]==0 && (mat[x][i]<=100 || mat[i][x]<=100) && ok(i,N-2-V.size())) {
				did[i]=1;
				x=i;
				V.push_back(i);
				break;
			}
			if(i==N) break;
		}
		
		
		if(V.size()!=N-1) V.clear();
		return V;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {9, 13, 7, 9, 8, 14, 14, 0, 6, 9, 2, 2, 5, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 5, 2, 11, 13, 12, 8, 3, 7, 15, 14, 4, 6, 9, 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getMoves(Arg0)); }
	void test_case_1() { int Arr0[] = {3, 4, 5, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getMoves(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getMoves(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 6, 6, 2, 6, 1, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4, 1, 3, 7, 6, 5, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getMoves(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysTree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
