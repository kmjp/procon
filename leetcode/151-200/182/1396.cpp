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


map<pair<string,string>,ll> sum,num;
map<int,string> pres;
map<int,int> pret;

class UndergroundSystem {
public:
    UndergroundSystem() {
        sum.clear();
        num.clear();
        pres.clear();
        pret.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        pres[id]=stationName;
        pret[id]=t;
    }
    
    void checkOut(int id, string stationName, int t) {
        
        num[{pres[id],stationName}]++;
        sum[{pres[id],stationName}]+=t-pret[id];
        
    }
    
    double getAverageTime(string startStation, string endStation) {
		double a=sum[{startStation,endStation}];
		double b=num[{startStation,endStation}];
		if(b==0) return 0;
        return a/b;
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
