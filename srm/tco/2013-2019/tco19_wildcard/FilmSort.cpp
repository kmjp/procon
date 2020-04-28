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

class FilmSort {
	public:
	vector<int> R,V;
	int N;
	void go(int x,int y) {
		if(x==y) return;
		if(R[x]==0) {
			V.push_back(y);
		}
		else {
			V.push_back(x);
		}
		swap(R[x],R[y]);
		R[x]=-R[x];
		R[y]=-R[y];
	}
	
	
	vector <int> sort(vector <int> reels) {
		R=reels;
		int N=R.size();
		V.empty();
		
		int i,j,x;
		
		for(i=1;i<N;i++) if(abs(R[i])!=i) {
			FOR(j,N) if(abs(R[j])==0) {
				go(i,j);
				break;
			}
			FOR(j,N) if(abs(R[j])==i) {
				go(i,j);
				break;
			}
		}
		FOR(i,N) cout<<R[i]<<" ";
		cout<<endl;
		for(i=1;i<N;i++) if(R[i]<0) {
			for(j=i+1;j<N;j++) if(R[j]<0) {
				go(i,0);
				go(j,i);
				go(j,0);
				go(i,0);
				go(j,i);
				go(j,0);
				break;
			}
			if(j==N) return {-1};
		}
		
		return V;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sort(Arg0)); }
	void test_case_1() { int Arr0[] = {-2, 1, 0, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sort(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 0, 1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 1, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sort(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 1, -2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sort(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FilmSort ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

