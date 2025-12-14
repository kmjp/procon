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
    string reverseWords(string s) {
        vector<string> V;
        vector<int> C;
        V.push_back("");
        C.push_back(0);
        FORR(c,s) {
			if(c==' ') {
				V.push_back("");
				C.push_back(0);
			}
			else {
				V.back()+=c;
				if(c=='a') C.back()++;
				if(c=='i') C.back()++;
				if(c=='u') C.back()++;
				if(c=='e') C.back()++;
				if(c=='o') C.back()++;
			}
		}
		int i;
		string R=V[0];
		for(i=1;i<V.size();i++) {
			R+=" ";
			if(C[i]==C[0]) reverse(ALL(V[i]));
			R+=V[i];
		}
		return R;
		
    }
};


