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

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

const ll mo=1000000007;
ll p2[101010];

class TheSocialNetwork {
	public:
	int minimumCut(int n, int m, vector <int> u, vector <int> v, vector <int> l) {
		
		int i;
		p2[0]=1;
		FOR(i,100100) p2[i+1]=p2[i]*2%mo;
		ll ret=0;
		vector<pair<int,int>> V;
		FOR(i,l.size()) V.push_back({l[i],i});
		sort(ALL(V));
		reverse(ALL(V));
		UF<303> uf;
		
		
		FORR(x,V) {
			int a=u[x.second];
			int b=v[x.second];
			if(uf[a]==uf[b]) continue;
			if(uf.count(a)+uf.count(b)<n) {
				uf(a,b);
			}
			else {
				ret+=p2[x.first];
			}
		}
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0_() { int Arg0 = 6; int Arg1 = 6; int Arr2[] = {1, 2, 3, 4, 5, 6}	; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 3, 4, 5, 6, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 7, 3, 4, 6, 12}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 10; verify_case(0, Arg5, minimumCut(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_0() { int Arg0 = 2; int Arg1 = 145; int Arr2[] = {0,84,87,78,16,94,36,87,93,50,22,63,28,91,60,64,27,41,27,73,37,12,69,68,30,83,31,63,24,68,36,30,3,23,59,70,68,94,57,12,43,30,74,22,20,85,38,99,25,16,71,14,27,92,81,57,74,63,71,97,82,6,26,85,28,37,6,47,30,14,58,25,96,83,46,15,68,35,65,44,51,88,9,77,79,89,85,4,52,55,100,33,61,77,69,40,13,27,87,95,40,96,71,35,79,68,2,98,3,18,93,53,57,2,81,87,42,66,90,45,20,41,30,32,18,98,72,82,76,10,28,68,57,98,54,87,66,7,84,20,25,29,72,33,30,4,20,71,69,9,16,41,50,97,24,19,46,47,52,22,56,80,89,65,29,42,51,94,1,35,65,25,15,88,57,44,92,28,66,60,37,33,52,38,29,76,8,75,22,59,96,30,38,36,94,19,29,44,12,29,30,77,5,44,64,14,39,7,41,5,19,29,89,70,18,18,97,25,44,71,84,91,100,73,26,45,91,6,40,55,87,70,83,43,65,98,8,56,5,49,12,23,29,100,44,47,69,41,23,12,11,6,2,62,31,79,6,21,37,45,27,23,66,9,17,83,59,25,38,63,25,1,37,53,100,80,51,69,72,74,32,82,31,34,95,61,64,100,5,0}	; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,84,87,78,16,94,36,87,93,50,22,63,28,91,60,64,27,41,27,73,37,12,69,68,30,83,31,63,24,68,36,30,3,23,59,70,68,94,57,12,43,30,74,22,20,85,38,99,25,16,71,14,27,92,81,57,74,63,71,97,82,6,26,85,28,37,6,47,30,14,58,25,96,83,46,15,68,35,65,44,51,88,9,77,79,89,85,4,52,55,100,33,61,77,69,40,13,27,87,95,40,96,71,35,79,68,2,98,3,18,93,53,57,2,81,87,42,66,90,45,20,41,30,32,18,98,72,82,76,10,28,68,57,98,54,87,66,7,84,20,25,29,72,33,30,4,20,71,69,9,16,41,50,97,24,19,46,47,52,22,56,80,89,65,29,42,51,94,1,35,65,25,15,88,57,44,92,28,66,60,37,33,52,38,29,76,8,75,22,59,96,30,38,36,94,19,29,44,12,29,30,77,5,44,64,14,39,7,41,5,19,29,89,70,18,18,97,25,44,71,84,91,100,73,26,45,91,6,40,55,87,70,83,43,65,98,8,56,5,49,12,23,29,100,44,47,69,41,23,12,11,6,2,62,31,79,6,21,37,45,27,23,66,9,17,83,59,25,38,63,25,1,37,53,100,80,51,69,72,74,32,82,31,34,95,61,64,100,5,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0,84,87,78,16,94,36,87,93,50,22,63,28,91,60,64,27,41,27,73,37,12,69,68,30,83,31,63,24,68,36,30,3,23,59,70,68,94,57,12,43,30,74,22,20,85,38,99,25,16,71,14,27,92,81,57,74,63,71,97,82,6,26,85,28,37,6,47,30,14,58,25,96,83,46,15,68,35,65,44,51,88,9,77,79,89,85,4,52,55,100,33,61,77,69,40,13,27,87,95,40,96,71,35,79,68,2,98,3,18,93,53,57,2,81,87,42,66,90,45,20,41,30,32,18,98,72,82,76,10,28,68,57,98,54,87,66,7,84,20,25,29,72,33,30,4,20,71,69,9,16,41,50,97,24,19,46,47,52,22,56,80,89,65,29,42,51,94,1,35,65,25,15,88,57,44,92,28,66,60,37,33,52,38,29,76,8,75,22,59,96,30,38,36,94,19,29,44,12,29,30,77,5,44,64,14,39,7,41,5,19,29,89,70,18,18,97,25,44,71,84,91,100,73,26,45,91,6,40,55,87,70,83,43,65,98,8,56,5,49,12,23,29,100,44,47,69,41,23,12,11,6,2,62,31,79,6,21,37,45,27,23,66,9,17,83,59,25,38,63,25,1,37,53,100,80,51,69,72,74,32,82,31,34,95,61,64,100,5,0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 10; verify_case(0, Arg5, minimumCut(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 7; int Arr2[] = {1, 1, 1, 2, 2, 3, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5, 3, 2, 5, 3, 5, 4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 8, 2, 3, 4, 6, 9}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 28; verify_case(1, Arg5, minimumCut(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 6; int Arr2[] = {1, 1, 2, 2, 3, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 3, 4, 5, 6, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {7, 11, 6, 9, 20, 15}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 64; verify_case(2, Arg5, minimumCut(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 11; int Arr2[] = {1, 1, 2, 2, 3, 3, 3, 4, 5, 5, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 8, 3, 5, 4, 6, 7, 5, 6, 8, 8}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 3, 1, 6, 11, 8, 9, 10, 7, 4, 5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 12; verify_case(3, Arg5, minimumCut(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 13; int Arg1 = 56; int Arr2[] = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 11, 11, 12}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 4, 5, 7, 9, 12, 13, 3, 5, 8, 9, 10, 12, 13, 5, 6, 8, 9, 10, 11, 12, 5, 6, 7, 9, 11, 13, 7, 8, 9, 11, 12, 7, 8, 9, 10, 13, 8, 9, 10, 11, 12, 13, 9, 11, 12, 10, 11, 12, 13, 11, 12, 13, 12, 13, 13}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {82, 240, 395, 1041, 1165, 1274, 1540, 1650, 1904, 2306, 2508, 3162, 3380, 3637, 3778, 3913, 3971, 4101, 4148, 4218, 4394, 4434, 5107, 6147, 6280, 6337, 6461, 6490, 7056, 8024, 8373, 8924, 8961, 9058, 9304, 9359, 10899, 11049, 11090, 11174, 11269, 11356, 11547, 11808, 12566, 12591, 13322, 13447, 13667, 13672, 15013, 15319, 16153, 16447, 16454, 16470}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 504663883; verify_case(4, Arg5, minimumCut(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TheSocialNetwork ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

