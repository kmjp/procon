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
    int generateKey(int num1, int num2, int num3) {
		int A[4]={9,9,9,9};
		A[0]=min(num1/1000,min(num2/1000,num3/1000));
		A[1]=min(num1/100%10,min(num2/100%10,num3/100%10));
		A[2]=min(num1/10%10,min(num2/10%10,num3/10%10));
		A[3]=min(num1/1%10,min(num2/1%10,num3/1%10));
		
		return A[0]*1000+A[1]*100+A[2]*10+A[3];
        
    }
};

