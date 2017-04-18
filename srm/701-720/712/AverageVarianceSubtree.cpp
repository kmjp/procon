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
vector<int> E[101];
long double W[101];

long double num[51][51];
long double sum[51][51];
long double sum2[51][51];
long double sum3[51][51];

class AverageVarianceSubtree {
	public:
	
	int dfs(int cur,int pre,int ng) {
		
		num[cur][1]=1;
		sum[cur][1]=W[cur];
		sum2[cur][1]=sum3[cur][1]=W[cur]*W[cur];
		
		int i;
		int C=1;
		
		FORR(r,E[cur]) if(r!=pre && r>ng) {
			int TC=dfs(r,cur,ng);
			long double tnum[52]={};
			long double tsum[52]={};
			long double tsum2[52]={};
			long double tsum3[52]={};
			
			for(int c=1;c<=C+TC;c++) {
				for(int L=1;L<=C;L++) {
					int R=c-L;
					if(R<0 || R>TC) continue;
					tsum2[c]+=sum2[cur][L]*num[r][R]+2*sum[cur][L]*sum[r][R]+sum2[r][R]*num[cur][L];
					tsum[c]+=num[cur][L]*sum[r][R]+num[r][R]*sum[cur][L];
					tsum3[c]+=num[cur][L]*sum3[r][R]+num[r][R]*sum3[cur][L];
					tnum[c]+=num[cur][L]*num[r][R];
				}
			}
			C+=TC;
			FOR(i,C+1) {
				num[cur][i]=tnum[i];
				sum[cur][i]=tsum[i];
				sum2[cur][i]=tsum2[i];
				sum3[cur][i]=tsum3[i];
			}
		}
		num[cur][0]=1;
		
		return C;
	}
	
	
	double average(vector <int> p, vector <int> weight) {
		N=weight.size();
		int i,j;
		long double t=0;
		FOR(i,N) {
			E[i].clear();
			W[i]=weight[i];
			t+=W[i];
		}
		t /= N;
		FOR(i,N) W[i] -= t;
		
		FOR(i,N-1) {
			E[i+1].push_back(p[i]);
			E[p[i]].push_back(i+1);
		}
		
		ZERO(num);
		ZERO(sum);
		ZERO(sum2);
		ZERO(sum3);
		
		long double tnum=0;
		long double tot=0;
		FOR(i,N) {
			dfs(i,i,i);
			
			for(j=1;j<=50;j++) {
				tnum+=num[i][j];
				tot += sum3[i][j]/j - sum2[i][j]/j/j;
			}
		}
		
		return tot/tnum;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 19.444444444444443; verify_case(0, Arg2, average(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,7,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 23.014520202020204; verify_case(1, Arg2, average(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.3333333166666672E16; verify_case(2, Arg2, average(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,1,0,2,3,3,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,11,111,1111,11111,111111,1111111,11111111,111111111}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.432586365551196E14; verify_case(3, Arg2, average(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {712}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(4, Arg2, average(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AverageVarianceSubtree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

