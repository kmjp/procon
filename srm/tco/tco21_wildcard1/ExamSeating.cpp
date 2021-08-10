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

class ExamSeating {
	public:
	vector <string> distribute(string students) {
		pair<int,int> P[27]={};
		int i,y,x,z;
		FOR(i,27) P[i].second=i;
		FORR(c,students) P[c-'a'].first++;
		sort(P,P+26);
		reverse(P,P+26);
		int mix=51,miy=51;
		for(x=1;x<=50;x++) for(y=1;y<=50;y++) {
			if(x*y<students.size()) continue;
			if((x*y+1)/2<P[0].first) continue;
			if(x*y<mix*miy) {
				mix=x,miy=y;
			}
		}
		if(mix==51) return {};
		cout<<mix<<" "<<miy<<endl;
		P[26]={mix*miy-students.size(),26};
		swap(P[1],P[26]);
		
		vector<string> S;
		FOR(i,miy) S.push_back(string(mix,'-'));
		FOR(i,2) {
			FOR(y,miy) {
				for(x=(i+y)%2;x<mix;x+=2) {
					FOR(z,27) if(P[z].first) {
						P[z].first--;
						if(P[z].second!=26) S[y][x]='a'+P[z].second;
						break;
					}
				}
			}
		}
		return S;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "aabcda"; string Arr1[] = {"a", "c", "a", "d", "a", "b" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, distribute(Arg0)); }
	void test_case_1() { string Arg0 = "aabb"; string Arr1[] = {"ab", "ba" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, distribute(Arg0)); }
	void test_case_2() { string Arg0 = "zzz"; string Arr1[] = {"z", "-", "z", "-", "z" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, distribute(Arg0)); }
	void test_case_3() { string Arg0 = "qwertyuiopasdfghjklz"; string Arr1[] = {"qwert", "yuiop", "asdfg", "hjzkl" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, distribute(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ExamSeating ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

