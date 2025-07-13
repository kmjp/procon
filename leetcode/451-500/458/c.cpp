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
    char processStr(string s, long long k) {
		ll len=0;
		vector<ll> L={0};
		FORR(c,s) {
			if(c=='*') {
				if(len) len--;
			}
			else if(c=='#') {
				len*=2;
			}
			else if(c=='%'){
				;
			}
			else {
				len++;
			}
			L.push_back(len);
		}
		if(len-1<k) return '.';
		reverse(ALL(s));
		FORR(c,s) {
			len=L.back();
			if(c=='*') {
				;
			}
			else if(c=='#') {
				len/=2;
				if(k>=len) k-=len;
			}
			else if(c=='%'){
				k=len-1-k;
			}
			else {
				len--;
				if(k==len) return c;
			}
			L.pop_back();
		}
		return '0';
			
        
    }
};

