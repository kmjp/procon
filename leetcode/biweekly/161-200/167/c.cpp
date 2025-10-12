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


class ExamTracker {
public:
	vector<int> tim;
	vector<ll> sum;
    ExamTracker() {
		tim={0};
		sum={0};
    }
    
    void record(int time, int score) {
		if(tim.back()==time) sum.back()+=score;
		else {
			tim.push_back(time);
			sum.push_back(sum.back()+score);
		}
        
    }
    
    long long totalScore(int startTime, int endTime) {
		int x=lower_bound(ALL(tim),startTime)-tim.begin();
		int y=lower_bound(ALL(tim),endTime+1)-tim.begin();
        return sum[y-1]-sum[x-1];
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
 