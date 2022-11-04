#include<bits/stdc++.h>
using namespace std;
struct business{
    string name;
    long long earning;
    long long developementTime;
};
void recommendBusiness(pair<long long ,long long> &requirement){
    business businesses[3];
    businesses[0].name="T";
    businesses[0].earning=1500;
    businesses[0].developementTime=5;

    businesses[1].name="P";
    businesses[1].earning=1000;
    businesses[1].developementTime=4;

    businesses[2].name="C";
    businesses[2].earning=3000;
    businesses[2].developementTime=10;

    for(int i=0;i<3;i++){
        business B=businesses[i];
        if(requirement.first<B.developementTime){
            continue;
        }
        else{
            long long noOfBusiness=(long long)(requirement.first/B.developementTime);
            long long totalBusinessRunningTime=0;
            long long totalTimeSpentInDevelopment=0;
            for(int j=1;j<=noOfBusiness;j++){
                long long businessRunningTime=(requirement.first-totalTimeSpentInDevelopment)-B.developementTime;
                totalBusinessRunningTime+=businessRunningTime;
                totalTimeSpentInDevelopment+=B.developementTime;
            }   
            long long totalEarningFromBusiness = totalBusinessRunningTime*B.earning;
            if(totalEarningFromBusiness==requirement.second){
                unordered_map<string,long long> solution;
                solution["T"]=0;
                solution["P"]=0;
                solution["C"]=0;
                solution[B.name]=noOfBusiness;
                    cout<<"{";
                    for(auto it:solution){
                        cout<<it.first<<":"<<it.second<<" , ";
                    }
                    cout<<"}";
                    cout<<"\t";                
            }
        }
    }
    cout<<"\n";

}
int main()
{
    pair<long long,long long> testcase1={7,3000};
    pair<long long,long long> testcase2={8,4500};
    pair<long long,long long> testcase3={13,16500};
    vector<long long> timetoBuild={5,4,10};
    vector<long long> earningPerUnit={1500,1000,3000};
    recommendBusiness(testcase1);
    recommendBusiness(testcase2);
    recommendBusiness(testcase3);
    return 0;
}