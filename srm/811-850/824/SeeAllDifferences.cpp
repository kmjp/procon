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

double dp[1<<16][16];

const int MAT=16;
double ma[MAT][MAT],V[MAT],R[MAT];

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

class SeeAllDifferences {
	public:
	double solve(int D, vector <int> rolled) {
		int i,j,x;
		int D2=(D+1)/2;
		ZERO(dp);
		int mask;
		for(mask=(1<<D)-2;mask>0;mask--) {
			ZERO(ma);
			ZERO(V);
			FOR(i,D) {
				V[i]=1;
				ma[i][i]=1;
				FOR(j,D) {
					x=abs(i-j);
					if((mask&(1<<x))==0) {
						V[i]+=dp[mask|(1<<x)][j]/D;
					}
					else {
						ma[i][j]-=1.0/D;
					}
				}
			}
			Gauss(D,ma,V,R);
			FOR(i,D) {
				dp[mask][i]=R[i];
			}
			
		}
		
		
		FOR(i,D) {
			FOR(j,D) {
				x=abs(i-j);
				dp[0][i]+=dp[1<<x][j]/D;
			}
			dp[0][i]++;
		}
		
		int did=0;
		FOR(i,rolled.size()-1) {
			int x=abs(rolled[i]-rolled[i+1]);
			did|=1<<x;
		}
		int cur=rolled.back()-1;
		return dp[did][cur];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {3, 3, 4, 6, 1, 5, 2, 3, 4, 2, 2, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 11.896969696969695; verify_case(2, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SeeAllDifferences ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

