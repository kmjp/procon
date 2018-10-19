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

class ForumPostEasy {
	public:
	int conv(string s) {
		int h=(s[0]-'0')*10+(s[1]-'0');
		int m=(s[3]-'0')*10+(s[4]-'0');
		int e=(s[6]-'0')*10+(s[7]-'0');
		return h*3600+m*60+e;
	}
	pair<int,int> range(string s) {
		if(s[0]=='f') return {0,59};
		
		int t=0, i=0;
		while(s[i]!=' ') {
			t=t*10+(s[i]-'0');
			i++;
		}
		
		if(s[i+1]=='m') return {t*60,(t+1)*60-1};
		else return {t*60*60,(t+1)*60*60-1};
	}
	
	string getCurrentTime(vector <string> exactPostTime, vector <string> showPostTime) {
		int N=exactPostTime.size();
		vector<int> V;
		vector<pair<int,int>> V2;
		FORR(s,exactPostTime) V.push_back(conv(s));
		FORR(s,showPostTime) V2.push_back(range(s));
		
		int t,i;
		FOR(t,24*60*60) {
			FOR(i,N) {
				int now=t;
				if(now<V[i]) now+=24*60*60;
				if(now<V[i]+V2[i].first) break;
				if(now>V[i]+V2[i].second) break;
				
			}
			
			if(i==N) {
				char hoge[11];
				sprintf(hoge,"%02d:%02d:%02d",t/3600,t/60%60,t%60);
				return string(hoge);
			}
		}
		return "impossible";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"12:12:12"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"few seconds ago"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "12:12:12"; verify_case(0, Arg2, getCurrentTime(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"23:23:23","23:23:23"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"59 minutes ago","59 minutes ago"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "00:22:23"; verify_case(1, Arg2, getCurrentTime(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"00:10:10","00:10:10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"59 minutes ago","1 hours ago"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "impossible"; verify_case(2, Arg2, getCurrentTime(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"11:59:13","11:13:23","12:25:15"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"few seconds ago","46 minutes ago","23 hours ago"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "11:59:23"; verify_case(3, Arg2, getCurrentTime(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ForumPostEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

