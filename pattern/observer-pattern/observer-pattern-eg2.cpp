/**
 * Weather station (subject) and Display screens Object)
 */

 #include <iostream>
 #include <vector>
 #include <memory>
 #include <algorithm>
 using namespace std;

 class Observer{
public:
    virtual void update(float temp) = 0;

 };

class Subject{
public :
    virtual void addObserver(shared_ptr<Observer> obs) = 0;
    virtual void removeObserver(shared_ptr<Observer> obs) = 0;
    virtual void notifyObservers() = 0;
 };

 class WeatherStation : public Subject{
    float temp;
    vector<shared_ptr<Observer>> observers;
public :

    void addObserver(shared_ptr<Observer> obs) override{
        observers.push_back(obs);
    }

    void removeObserver(shared_ptr<Observer> obs) override{
        observers.erase(remove(observers.begin() , observers.end() , obs),observers.end());
    }

    void notifyObservers() override{
        for(auto& it : observers){
            it -> update(temp);
        }
    }

    void setTemp(float tmp){
        temp = tmp;
        notifyObservers();
    }

 };

 class PhoneDisplay : public Observer{
    private:
    shared_ptr<WeatherStation> weatherStation;

public:
    PhoneDisplay(shared_ptr<WeatherStation> ws) : weatherStation(ws) {}

    void update(float temperature) override {
        cout << "Phone Display: Temperature updated to " << temperature << "°C\n";
    }
 };

 class TVDisplay : public Observer {
    private:
        shared_ptr<WeatherStation> weatherStation;
    
    public:
        TVDisplay(shared_ptr<WeatherStation> ws) : weatherStation(ws) {}
    
        void update(float temperature) override {
            cout << "TV Display: Temperature updated to " << temperature << "°C\n";
        }
    };
 
 
    int main() {
        shared_ptr<WeatherStation> weatherStation = make_shared<WeatherStation>();
    
        shared_ptr<Observer> phoneDisplay = make_shared<PhoneDisplay>(weatherStation);
        shared_ptr<Observer> tvDisplay = make_shared<TVDisplay>(weatherStation);
    
        weatherStation->addObserver(phoneDisplay);
        weatherStation->addObserver(tvDisplay);
    
        cout << "Setting temperature to 30°C\n";
        weatherStation->setTemp(30);
    
        cout << "\nSetting temperature to 25°C\n";
        weatherStation->setTemp(25);
    
        return 0;
    }
    
 
