#include<bits/stdc++.h>
using namespace std;

class Teams{
    public:
    string teamName;

    Teams(const string& name) : teamName(name){}
    virtual void notifyMatch(string matchWith) = 0;
};

class MI : public Teams{
    public:
        MI(string name) : Teams(name){}

        void notifyMatch(string matchWith) override{
            cout << "Match : " << "MI vs " << matchWith << endl;
        }
};
class RCB : public Teams{
    public:
        RCB(string name) : Teams(name){}

        void notifyMatch(string matchWith) override{
            cout << "Match : " << "RCB vs " << matchWith << endl;
        }
};


class MatchFixer{
    public:
    string teamName;
    virtual void addTeam(Teams* obj) = 0;
    virtual void removeTeam(Teams* obj) = 0;
    virtual void Notify(string teamName , string vs) = 0;
};

class IPL : public MatchFixer{
    vector<Teams*> team;
    public:
    void addTeam(Teams* obj) override {
        team.push_back(obj);
    }

    void removeTeam(Teams* obj) override{
        team.erase(remove(team.begin() , team.end() , obj),team.end());
    }

    void Notify(string n , string vs) override {
        for(auto& it : team){
            if(it->teamName == n){
                it->notifyMatch(vs);
            }
            if(it->teamName == vs){
                it->notifyMatch(n);
            }
        }
    }

};




int main(){

        Teams* mi = new MI("MUMBAI INDIANS");
        Teams* rcb = new RCB("RCB");
        
        MatchFixer* mf = new IPL();
        mf->addTeam(mi);
        mf->addTeam(rcb);

        mf->removeTeam(rcb);

        mf->Notify("MI" , "RCB");




return 0;
}