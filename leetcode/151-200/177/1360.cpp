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
    int daysBetweenDates(string date1, string date2) {
		int Y1=(date1[0]-'0')*1000+(date1[1]-'0')*100+(date1[2]-'0')*10+(date1[3]-'0')*1;
		int M1=(date1[5]-'0')*10+(date1[6]-'0');
		int D1=(date1[8]-'0')*10+(date1[9]-'0');
		int Y2=(date2[0]-'0')*1000+(date2[1]-'0')*100+(date2[2]-'0')*10+(date2[3]-'0')*1;
		int M2=(date2[5]-'0')*10+(date2[6]-'0');
		int D2=(date2[8]-'0')*10+(date2[9]-'0');
		M1--;
		D1--;
		M2--;
		D2--;
		if(Y1>Y2) swap(Y1,Y2),swap(M1,M2),swap(D1,D2);
		if(Y1==Y2 && M1>M2) swap(Y1,Y2),swap(M1,M2),swap(D1,D2);
		if(Y1==Y2 && M1==M2 && D1>D2) swap(Y1,Y2),swap(M1,M2),swap(D1,D2);
		
		int ret=0;
		while(Y1!=Y2||D1!=D2||M1!=M2) {
			ret++;
			int D[12]={31,28,31,30,31,30,31,31,30,31,30,31};
			if(Y1%400==0 || (Y1%4==0&&Y1%100!=0)) D[1]++;
			D1++;
			if(D[M1]==D1) M1++,D1=0;
			if(M1==12) Y1++,M1=0;
		}
		return ret;
        
    }
};


