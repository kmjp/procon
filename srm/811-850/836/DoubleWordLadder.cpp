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

int T[33];
int S[33][2];
char C[33];
class DoubleWordLadder {
	public:
	vector <string> transform(string A, string B) {
		int N=A.size();
		string C;
		int i,j;
		ZERO(S);
		ZERO(T);
		int num=0;
		FOR(i,N) {
			if(A[i]==B[i]) {
				T[i]=2;
			}
			else {
				num++;
				C[i]='a';
				while(C[i]==A[i]||C[i]==B[i]) C[i]++;
				S[i][0]=(A[i]<C[i])?1:-1;
				S[i][1]=(C[i]<B[i])?1:-1;
			}
		}
		if(num==1) {
			FOR(i,N) if(num<2&&A[i]==B[i]&&A[i]!='a') {
				num++;
				T[i]=0;
				C[i]='a';
				S[i][0]=(A[i]<C[i])?1:-1;
				S[i][1]=(C[i]<B[i])?1:-1;
			}
			for(i=N-1;i>=0;i--) if(num<2&&A[i]==B[i]&&A[i]=='a') {
				num++;
				T[i]=0;
				C[i]='b';
				S[i][0]=(A[i]<C[i])?1:-1;
				S[i][1]=(C[i]<B[i])?1:-1;
			}
		}
		
		vector<string> R={A};
		int pre=-1;
		while(1) {
			vector<pair<int,int>> V;
			FOR(i,N) if(i!=pre&&T[i]<2) {
				if(S[i][T[i]]==-1) V.push_back({0,i});
				else V.push_back({100-i,i});
			}
			if(V.empty()) break;
			sort(ALL(V));
			FORR(a,V) {
				i=a.second;
				T[i]++;
				int num=0,sum=0;
				FOR(j,N) if(T[j]!=2) num++, sum+=2-T[j];
				if(num==1&&sum==2) {
					T[i]--;
					continue;
				}
				R.push_back(R.back());
				if(T[i]==1) {
					R.back()[i]=C[i];
				}
				else {
					R.back()[i]=B[i];
				}
				pre=i;
				cout<<R.back()<<endl;
				break;
			}
			
		}
		assert(R.back()==B);
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "topcoder"; string Arg1 = "topcoder"; string Arr2[] = {"topcoder" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, transform(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ab"; string Arg1 = "cd"; string Arr2[] = {"ab", "aa", "ba", "bd", "cd" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, transform(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "donation"; string Arg1 = "solution"; string Arr2[] = {"donation", "aonation", "aoaation", "aoabtion", "aolbtion", "aolution", "solution" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, transform(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DoubleWordLadder ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

