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
    int secondsBetweenTimes(string startTime, string endTime) {
		int S=(startTime[0]-'0')*36000;
		S+=(startTime[1]-'0')*3600;
		S+=(startTime[3]-'0')*600;
		S+=(startTime[4]-'0')*60;
		S+=(startTime[6]-'0')*10;
		S+=(startTime[7]-'0')*1;
        int E=(endTime[0]-'0')*36000;
		E+=(endTime[1]-'0')*3600;
		E+=(endTime[3]-'0')*600;
		E+=(endTime[4]-'0')*60;
		E+=(endTime[6]-'0')*10;
		E+=(endTime[7]-'0')*1;
		return E-S;
    }
};

