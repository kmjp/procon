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

int dp[152][152][152];

class TaroCutting {
	public:
	pair<int,int> T[151];
	int getNumber(vector <int> height, vector <int> add, vector <int> device, int time) {
		int N=height.size();
		int D=device.size();
		int i,j,x,y;
		FOR(i,N) T[i]=make_pair(add[i],height[i]);
		sort(T,T+N);
		reverse(T,T+N);
		sort(device.begin(),device.end());
		
		FOR(i,N+1) FOR(x,D+1) FOR(y,time+1) dp[i][x][y]=1<<29;
		dp[0][0][0]=0;
		FOR(y,time+1) FOR(i,N+1) FOR(x,D+1) {
			int cur=dp[i][x][y];
			
			dp[i][x+1][y]=min(dp[i][x+1][y],cur);
			dp[i][0][y+1]=min(dp[i][0][y+1],cur);
			
			if(i<N) dp[i+1][x][y]=min(dp[i+1][x][y], cur+T[i].second+T[i].first*time);
			if(y<time&&i<N&&x<D) dp[i+1][x+1][y]=min(dp[i+1][x+1][y],cur+device[x]+y*T[i].first);
		}
		
		int mi=1<<29;
		FOR(x,D+1) FOR(y,time+1) mi=min(mi,dp[N][x][y]);
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 15; verify_case(0, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {3, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7, 7, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 12; verify_case(1, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {100, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {75, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {200, 100, 50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 130; verify_case(2, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {7, 10, 1, 7, 5, 4, 11, 5, 7, 9, 10, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 4, 10, 2, 1, 6, 4, 8, 7, 5, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7, 1, 5, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 96; verify_case(3, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {35, 45, 32, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 25, 31, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {29, 28, 3, 11, 28, 37}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; int Arg4 = 29; verify_case(4, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {614, 649, 977, 808, 821, 356, 801, 493, 669, 650, 652, 627, 129, 261, 883, 513, 62, 698, 83, 772, 
779, 719, 83, 105, 774, 867, 412, 892, 142, 851, 743, 66, 221, 494, 125, 905, 638, 342, 723, 680, 
407, 197, 111, 368, 676, 694, 765, 482, 712, 188, 325, 535, 6, 49, 655, 595, 958, 805, 659, 893, 
370, 904, 276, 156, 29, 458, 757, 632, 731, 289, 582, 207, 843, 365, 387, 521, 69, 269, 459, 428, 
423, 885, 744, 199, 998, 968, 296, 473, 50, 752, 492, 919, 473, 981, 380, 896, 769, 991, 269, 93, 
108, 184, 762, 312, 511, 256, 374, 600, 643, 445, 908, 250, 384, 518, 119, 464, 499, 124, 82, 999, 
881, 767, 177, 796, 2, 620, 759, 380, 901, 221, 407, 622, 260, 622, 729, 264, 768, 79, 236, 524, 
437, 215, 108, 518, 820, 725, 490, 796, 986, 318}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {391, 938, 772, 630, 54, 775, 379, 613, 647, 8, 946, 885, 604, 822, 663, 559, 452, 565, 637, 695, 24, 
515, 92, 956, 194, 551, 813, 362, 190, 268, 440, 781, 450, 789, 566, 372, 402, 860, 531, 608, 434, 
761, 754, 26, 504, 873, 132, 756, 206, 93, 284, 807, 642, 637, 936, 954, 205, 303, 582, 822, 134, 
269, 967, 147, 589, 549, 24, 670, 403, 105, 40, 531, 486, 695, 898, 287, 443, 542, 599, 151, 45, 
567, 548, 945, 912, 764, 451, 404, 700, 522, 227, 954, 84, 347, 625, 278, 377, 730, 635, 604, 959, 
845, 41, 193, 459, 532, 429, 216, 473, 415, 85, 933, 90, 643, 94, 927, 692, 99, 771, 594, 318, 627, 
89, 340, 110, 488, 909, 253, 20, 114, 179, 177, 116, 42, 676, 91, 787, 437, 551, 51, 880, 336, 759, 
795, 243, 727, 279, 620, 488, 607}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {942, 79, 387, 184, 104, 981, 766, 678, 715, 998, 161, 125, 439, 532, 550, 415, 4, 467, 211, 852, 781, 
577, 728, 592, 40, 971, 852, 592, 338, 555, 662, 636, 823, 122, 728, 69, 701, 476, 346, 190, 36, 
535, 826, 739, 517, 551, 257, 36, 906, 171, 629, 292, 49, 29, 109, 151, 299, 180, 193, 731, 655, 
877, 174, 688, 866, 957, 57, 89, 513, 765, 68, 245, 454, 968, 224, 417, 657, 383, 769, 809, 13, 51, 
813, 970, 632, 357, 787, 717, 254, 645, 352, 636, 370, 950, 917, 959, 364, 453, 890, 43, 98, 438, 
748, 277, 115, 298, 431, 709, 312, 49, 553, 395, 798, 58, 419, 355, 770, 818, 460, 89, 880, 515, 
952, 219, 608, 284, 532, 254, 361, 524, 199, 265, 407, 782, 737, 928, 977, 729, 510, 175, 609, 81, 
155, 24, 425, 186, 999, 839, 896, 721}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 150; int Arg4 = 43325; verify_case(5, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TaroCutting ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
