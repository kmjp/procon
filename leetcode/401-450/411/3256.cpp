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
    string largestPalindrome(int n, int k) {
		string R=string(n,'9');
		int i;
		if(n<=6) {
			int ma=1;
			FOR(i,n) ma*=10;
			ma--;
			while(1) {
				if(ma%k==0) {
					string S=to_string(ma);
					string V=S;
					reverse(ALL(V));
					if(S==V) return S;
				}
				ma--;
			}
			return "";
		}
		
		if(k==1||k==3||k==9) {
			;
		}
		else if(k==5) {
			R[0]=R.back()='5';
		}
		else if(k==2) {
			R[0]=R.back()='8';
		}
		else if(k==6) {
			R[0]=R.back()='8';
			int sum=n*9-2;
			while(sum%3) {
				if(n%2) {
					R[n/2]--;
					sum--;
				}
				else {
					R[n/2-1]--;
					R[n/2]--;
					sum-=2;
				}
			}
		}
		else if(k==4) {
			R[0]=R.back()='8';
			R[1]=R[n-2]='8';
		}
		else if(k==8) {
			R[0]=R.back()='8';
			R[1]=R[n-2]='8';
			R[2]=R[n-3]='8';
		}
		else if(k==7) {
			int cur=1;
			FOR(i,n) cur=cur*10%7;
			cur=(cur+6)%7;
			int del=1;
			if(n%2) {
				FOR(i,n/2) del=del*10%7;
			}
			else {
				del=11;
				FOR(i,n/2-1) del=del*10%7;
			}
			while(cur) {
				if(n%2) {
					R[n/2]--;
				}
				else {
					R[n/2-1]--;
					R[n/2]--;
				}
				cur=(cur-del+7)%7;
			}
		}
		
		
		
        return R;
    }
};
