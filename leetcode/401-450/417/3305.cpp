#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


class Solution {
public:
    int countOfSubstrings(string word, int k) {
		int i,j;
		int C[5]={0,0,0,0,0};
		FORR(a,word) {
			if(a=='a') a=0;
			else if(a=='i') a=1;
			else if(a=='u') a=2;
			else if(a=='e') a=3;
			else if(a=='o') a=4;
		}
		ll ret=0;
		int N=word.size();
		int A=0,B=0;
		for(int L=0,R=0,R2=0,R3=0;L<N;L++) {
			while(R<N&&(A<k||(C[0]==0||C[1]==0||C[2]==0||C[3]==0||C[4]==0))) {
				if(word[R]>5) A++;
				else C[word[R]]++;
				R++;
			}
			if((A<k||(C[0]==0||C[1]==0||C[2]==0||C[3]==0||C[4]==0))) break;
			while(R2<N&&B<k+1) {
				if(word[R2]>5) B++;
				R2++;
			}
			if(B==k) {
				ret+=N-R+1;
			}
			else {
				if(R<=R2) ret+=R2-R;
			}
			if(word[L]>5) A--,B--;
			else C[word[L]]--;
			
			
		}
		return ret;
        
    }
};