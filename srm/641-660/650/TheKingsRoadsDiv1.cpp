#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

vector<int> E[1030];
int vis[1030];
int num[1040]={},N[15]={};

class TheKingsRoadsDiv1 {
	public:
	int H;
	
	bool ok(int cur,int pre,int num) {
		int i;
		bool ret=true;
		if(num==0) return false;
		num--;
		
		if(E[cur].size()==1) return num==0;
		if(num%2) return false;
		if(pre!=-1 && E[cur].size()!=3) return false;
		
		FOR(i,E[cur].size()) if(E[cur][i]!=pre) ret &= ok(E[cur][i],cur,num/2);
		return ret;
		
	}
	int conn(int cur,int pre) {
		int num=1,i;
		vis[cur]=1;
		FOR(i,E[cur].size()) if(E[cur][i]!=pre) {
			if(vis[E[cur][i]]) return 1025;
			num+=conn(E[cur][i],cur);
		}
		return num;
	}
	
	string getAnswer(int h, vector <int> a, vector <int> b) {
		int i,x,j,L,X,Y,Z,H;
		
		H=(1<<h)-1;
		ZERO(num);
		ZERO(N);
		
		L=a.size();
		FOR(i,L) num[--a[i]]++, num[--b[i]]++;
		FOR(i,H) {
			if(num[i]>=10) return "Incorrect";
			N[num[i]]++;
		}
		
		FOR(X,L) {
			N[num[a[X]]]--;N[--num[a[X]]]++;
			N[num[b[X]]]--;N[--num[b[X]]]++;
			
			FOR(Y,X) {
				N[num[a[Y]]]--;N[--num[a[Y]]]++;
				N[num[b[Y]]]--;N[--num[b[Y]]]++;
				if(N[2]>3) goto out;
				if(N[1]>(1<<(h-1))+2 || N[1]<(1<<(h-1))-3) goto out;
				if(N[3]>(1<<(h-1)) || N[3]<(1<<(h-1))-4) goto out;
				FOR(Z,Y) {
					int st=-1;
					N[num[a[Z]]]--;N[--num[a[Z]]]++;
					N[num[b[Z]]]--;N[--num[b[Z]]]++;
					
					if(N[2]!=1) goto out2;
					if(N[1]!=(1<<(h-1))) goto out2;
					if(N[3]!=(1<<(h-1))-2) goto out2;
					
					FOR(x,1<<h) E[x].clear();
					FOR(j,L) if(j!=X && j!=Y && j!=Z) E[a[j]].push_back(b[j]),E[b[j]].push_back(a[j]);
					ZERO(vis);
					if(conn(0,-1)!=(1<<h)-1) goto out2;
					
					
					FOR(j,(1<<h)-1) if(E[j].size()==2) st=j;
					if(st!=-1 && ok(st,-1,(1<<h)-1)) return "Correct";
					
					out2:
					N[num[a[Z]]]--;N[++num[a[Z]]]++;
					N[num[b[Z]]]--;N[++num[b[Z]]]++;
				}
				
				
				out:
				N[num[a[Y]]]--;N[++num[a[Y]]]++;
				N[num[b[Y]]]--;N[++num[b[Y]]]++;
			}
			N[num[a[X]]]--;N[++num[a[X]]]++;
			N[num[b[X]]]--;N[++num[b[X]]]++;
		}
		
		return "Incorrect";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 3, 2, 2, 3, 7, 1, 5, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6, 5, 4, 7, 4, 3, 3, 1, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Correct"; verify_case(0, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {1, 2, 1, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1, 2, 3, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Incorrect"; verify_case(1, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {1, 3, 2, 2, 6, 6, 4, 4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1, 4, 5, 4, 4, 7, 7, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Incorrect"; verify_case(2, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {1, 2, 2, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Incorrect"; verify_case(3, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {6, 15, 29, 28, 7, 13, 13, 23, 28, 13, 30, 27, 14, 4, 14, 19, 27, 20, 20, 19, 10, 15, 7, 7, 19, 29, 4, 24, 10, 23, 30, 6, 24}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9, 22, 30, 20, 26, 25, 8, 7, 24, 21, 27, 31, 4, 28, 29, 6, 16, 1, 17, 10, 3, 12, 30, 18, 14, 23, 19, 21, 5, 13, 15, 2, 11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Correct"; verify_case(4, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 2; int Arr1[] = {1,1,1,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,1,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Correct"; verify_case(5, Arg3, getAnswer(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheKingsRoadsDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
