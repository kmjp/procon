typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
		int A=0,B=0,C=0,D=0;
		A+=(event1[0][0]-'0')*60*10;
		A+=(event1[0][1]-'0')*60;
		A+=(event1[0][3]-'0')*10;
		A+=(event1[0][4]-'0')*1;
		B+=(event1[1][0]-'0')*60*10;
		B+=(event1[1][1]-'0')*60;
		B+=(event1[1][3]-'0')*10;
		B+=(event1[1][4]-'0')*1;
		C+=(event2[0][0]-'0')*60*10;
		C+=(event2[0][1]-'0')*60;
		C+=(event2[0][3]-'0')*10;
		C+=(event2[0][4]-'0')*1;
		D+=(event2[1][0]-'0')*60*10;
		D+=(event2[1][1]-'0')*60;
		D+=(event2[1][3]-'0')*10;
		D+=(event2[1][4]-'0')*1;
        return max(A,C)<=min(B,D);
    }
};
