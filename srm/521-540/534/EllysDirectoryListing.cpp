#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(x) x.begin(),x.end()
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

class EllysDirectoryListing {
	public:
	vector <string> getFiles(vector <string> files) {
		int N=files.size();
		int i;
		
		if((files[N-1]=="." || files[N-1]=="..") &&
		(files[N-2]=="." || files[N-2]=="..")) return files;
		
		FOR(i,N-1) if(files[i]=="." || files[i]=="..") {
			swap(files[i],files[N-1]);
			break;
		}
		if((files[N-1]=="." || files[N-1]=="..") &&
		(files[N-2]=="." || files[N-2]=="..")) return files;
		FOR(i,N-2) if(files[i]=="." || files[i]=="..") {
			swap(files[i],files[N-2]);
			break;
		}
		return files;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ContestApplet.jnlp", ".", "Image.jpg", "..", "Book.pdf", "Movie.avi"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ContestApplet.jnlp", "Movie.avi", "Image.jpg", "Book.pdf", "..", "." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getFiles(Arg0)); }
	void test_case_1() { string Arr0[] = {"Image.jpg", "..", "."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Image.jpg", "..", "." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getFiles(Arg0)); }
	void test_case_2() { string Arr0[] = {"..", ".", "Image.jpg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Image.jpg", ".", ".." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getFiles(Arg0)); }
	void test_case_3() { string Arr0[] = {"No", "..", "Zaphod", ".", "Just", "very", "very...", "Improbable"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"No", "Improbable", "Zaphod", "very...", "Just", "very", ".", ".." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getFiles(Arg0)); }
	void test_case_4() { string Arr0[] = {"www.topcoder.com", "Ever.tried", ".", "Ever.failed", "..", "No", "Matter.", "Try", "Again.", "Fail", "Again..", "Fail.Better"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"www.topcoder.com", "Ever.tried", "Fail.Better", "Ever.failed", "Again..", "No", "Matter.", "Try", "Again.", "Fail", "..", "." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getFiles(Arg0)); }
	void test_case_5() { string Arr0[] = {"This", ".", "is", "tricky", "test", ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"This", "test", "is", "tricky", "..", "." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getFiles(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysDirectoryListing ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

