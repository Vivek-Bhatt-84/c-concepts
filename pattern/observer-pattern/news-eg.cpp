#include <bits/stdc++.h>
using namespace std;

enum ChannelType{
    SPORTS,
    BUSINESS,
    TECHNOLOGY  // New Channel Type
};

class BaseAajTak{
  public:
  ChannelType ntype;
  BaseAajTak(ChannelType type) : ntype(type){}
  virtual void onUpdate(string s)=0;
};

class SportsNews:public BaseAajTak{
    public:
    SportsNews() : BaseAajTak(SPORTS){}
    void onUpdate(string s){
        cout<<s<<"Sports"<<endl;
    }
};

class BusinessNews:public BaseAajTak{
    public:
    BusinessNews() : BaseAajTak(BUSINESS){}
    void onUpdate(string s){
        cout<<s<<"Business"<<endl;      
    }
};

class TechnologyNews:public BaseAajTak{  // New class for Technology News
    public:
    TechnologyNews() : BaseAajTak(TECHNOLOGY){}
    void onUpdate(string s){
        cout<<s<<"Technology"<<endl;
    }
};

class AajTakCentral{
    public:
    vector<BaseAajTak*> db;
    void RegisterNews(BaseAajTak* obj){
        db.push_back(obj);
    }
    
    void UnregisterNews(BaseAajTak* obj){
        db.erase(remove(db.begin(),db.end(),obj),db.end());
    }
    
    void update(ChannelType type){
        for(auto it:db){
            if(it->ntype==type){
                it->onUpdate("Today's News is about: ");
            }
        }
    }
};

int main() {
    AajTakCentral* ATC = new AajTakCentral();
    
    BusinessNews* BN = new BusinessNews();
    SportsNews* SN = new SportsNews();
    TechnologyNews* TN = new TechnologyNews();  // Create an instance of TechnologyNews
    
    // Automatically Register and Update Sports News
    ATC->RegisterNews(SN);
    ATC->update(SPORTS);
    
    // Automatically Register and Update Business News
    ATC->RegisterNews(BN);
    ATC->update(BUSINESS);
    
    // Automatically Register and Update Technology News
    ATC->RegisterNews(TN);
    ATC->update(TECHNOLOGY);  // Update for the new technology channel
    
    return 0;
}
