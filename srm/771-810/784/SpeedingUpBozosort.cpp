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

int pat;
map<vector<int>,int> M;
vector<int> T[720];
int num[720];

double from[720];
double to[720];

double dp[720][720];

const int MAT=720;
int Gauss(int n,double mat_[MAT][MAT],double v_[MAT],double r[MAT]) {
	int i,j,k;
	double mat[MAT][MAT],v[MAT];
	memmove(mat,mat_,sizeof(mat));
	memmove(v,v_,sizeof(v));
	
	FOR(i,n) {
		if(mat[i][i]==0) {
			for(j=i+1;j<n;j++) if(mat[j][i]) break;
			if(j>=n) return i;
			FOR(k,n) swap(mat[i][k],mat[j][k]);
			swap(v[i],v[j]);
		}
		v[i]/=mat[i][i];
		for(k=n-1;k>=i;k--) mat[i][k]/=mat[i][i];
		for(j=i+1;j<n;j++) {
			v[j]-=v[i]*mat[j][i];
			for(k=n-1;k>=i;k--) mat[j][k]-=mat[i][k]*mat[j][i];
		}
	}
	
	for(i=n-1;i>=0;i--) {
		for(j=n-1;j>i;j--) v[i]-=mat[i][j]*v[j],mat[i][j]=0;
		r[i]=v[i];
	}
	return n;
}

double mat[MAT][MAT];
double v[MAT],r[MAT];

class SpeedingUpBozosort {
	public:
	double expectedComparisons(vector <int> A, int numSwaps) {
		int N=A.size();
		int y,x,i,j;
		
		if(N==1) return 0;
		
		vector<int> B=A;
		sort(ALL(B));
		pat=0;
		M.clear();
		do {
			T[pat]=B;
			M[B]=pat;
			v[pat]=0;
			FOR(i,N-1) {
				v[pat]--;
				if(B[i]>B[i+1]) break;
			}
			pat++;
		} while(next_permutation(ALL(B)));
		
		
		vector<int> W;
		vector<vector<int>> X;
		FOR(i,N) W.push_back(i);
		map<vector<int>,int> D;
		do {
			X.push_back(W);
			D[W]=X.size()-1;
		} while(next_permutation(ALL(W)));
		
		ZERO(from);
		from[0]=1;
		
		vector<int> cand[720];
		FOR(j,X.size()) {
			FOR(y,N) FOR(x,N) {
				swap(X[j][x],X[j][y]);
				cand[j].push_back(D[X[j]]);
				swap(X[j][x],X[j][y]);
			}
		}
		FOR(i,numSwaps) {
			ZERO(to);
			FOR(j,X.size()) FORR(c,cand[j]) to[c]+=from[j]/(N*N);
			swap(from,to);
		}
		
		ZERO(mat);
		mat[0][0]+=-1;
		for(i=1;i<pat;i++) {
			FOR(j,X.size()) {
				vector<int> R(N);
				FOR(x,N) R[X[j][x]]=T[i][x];
				mat[i][M[R]]+=from[j];
			}
			mat[i][i]+=-1;
		}
		Gauss(pat,mat,v,r);
		
		return r[M[A]];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 3.0; verify_case(0, Arg2, expectedComparisons(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; double Arg2 = 4.0; verify_case(1, Arg2, expectedComparisons(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 3.0; verify_case(2, Arg2, expectedComparisons(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; double Arg2 = 3.0; verify_case(3, Arg2, expectedComparisons(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {5, 3, 1, 4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 284.4791666666661; verify_case(4, Arg2, expectedComparisons(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {5, 3, 1, 4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 215.35376724261207; verify_case(5, Arg2, expectedComparisons(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {1, 1, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 12.6; verify_case(6, Arg2, expectedComparisons(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SpeedingUpBozosort ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

