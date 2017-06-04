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

class InPrePost {
	public:
	vector<int> S;
	
	int ok(string a1, string a2, string a3) {
		string v1=a1,v2=a2,v3=a3;
		sort(ALL(v1));
		sort(ALL(v2));
		sort(ALL(v3));
		if(v1!=v2 || v1!=v3) return 0;
		if(v1.size()<=1) return 1;
		int label = a1[0];
		int a,b,i;
		FOR(i,a2.size()) if(a2[i]==label) {
			a=i;
			b=a2.size()-(i+1);
		}
		string L[3],R[3];
		L[S[0]]=a1.substr(1,a);
		R[S[1]]=a1.substr(1+a);
		L[S[2]]=a2.substr(0,a);
		R[S[3]]=a2.substr(1+a);
		L[S[4]]=a3.substr(0,a);
		R[S[5]]=a3.substr(a,b);
		return ok(L[0],L[1],L[2]) && ok(R[0],R[1],R[2]);
	}
	
	string isPossible(vector <string> s, vector <int> a1, vector <int> a2, vector <int> a3) {
		S.clear();
		string s1,s2,s3;
		FORR(c,s) {
			if(c=="pre") S.push_back(0);
			if(c=="in") S.push_back(1);
			if(c=="post") S.push_back(2);
		}
		FORR(a,a1) s1.push_back(a);
		FORR(a,a2) s2.push_back(a);
		FORR(a,a3) s3.push_back(a);
		
		if(ok(s1,s2,s3)) return "Possible";
		return "Impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"post", "in", "pre", "post", "in", "pre"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,1,3,5,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,4,3,5,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Possible"; verify_case(0, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"pre", "pre", "in", "in", "post", "post"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,4,3,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,3,2,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Possible"; verify_case(1, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"post", "in", "pre", "post", "in", "pre"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,1,3,5,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,4,3,5,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Impossible"; verify_case(2, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"post", "pre", "in", "post", "pre", "in"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Possible"; verify_case(3, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"pre", "pre", "in", "in", "post", "post"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,5,1,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,5,4,3,2,10,9,8,7,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Impossible"; verify_case(4, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arr0[] = {"post","post","in","pre","pre","in"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,4,8,3,7,5,6,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,8,7,4,6,5,9,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,7,3,8,4,5,1,2,9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "Possible"; verify_case(5, Arg4, isPossible(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  InPrePost ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

