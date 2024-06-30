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
	int hoge(int A,int B) {
		int i;
		for(i=1;i<=10101;i++) {
			if(i%2==0) {
				A-=i;
				if(A<0) return i-1;
			}
			else {
				B-=i;
				if(B<0) return i-1;
			}
		}
		return 0;
		
	}
    int maxHeightOfTriangle(int red, int blue) {
		return max(hoge(red,blue),hoge(blue,red));
        
    }
};
