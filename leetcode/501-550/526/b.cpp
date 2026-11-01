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
    long long minimumMaxValue(int n, int index, int value) {
		
		int mi=value;
		int i;
		for(i=2;i*i<=value;i++) if(value%i==0) mi=min(mi,i);
		
		if(value==1&&n>=2) return -1;
		
		if(mi==value&&index) return -1;
		
		if(mi==2) {
			if(value<2*(index+1)) return -1;
			return value+2LL*(n-1-index);
		}
		int num=1+(value-mi)/2;
		cout<<mi<<" "<<num<<endl;

		if(index>=num) return -1;
		
		if(n-1==index) return value;
		return value+mi+1LL*(n-1-index-1)*2;
		
		
		
        
    }
};

