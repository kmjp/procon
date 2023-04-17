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
    int addMinimum(string word) {
        int num=0;
        if(word[0]=='b') num++;
        if(word[0]=='c') num+=2;
        int i;
        FOR(i,word.size()-1) {
			int x=word[i]-'a';
			int y=word[i+1]-'a';
			x=(x+1)%3;
			while(x!=y) {
				num++;
				x=(x+1)%3;
			}
		}
		if(word.back()=='a') num+=2;
		if(word.back()=='b') num++;
        return num;
        
    }
};
