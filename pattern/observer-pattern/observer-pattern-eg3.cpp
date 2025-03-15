/**
 * stock market exchange(subject)
 * st (observer)
 */

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class Investor
{
public:
    virtual void update(float price) = 0;
};

class StockExchange
{
    float stockPrice;
    vector<shared_ptr<Investor>> st;

public:
    void addInvestor(shared_ptr<Investor> inv)
    {
        st.push_back(inv);
    }

    void removeInvestor(shared_ptr<Investor> inv)
    {
        st.erase(remove(st.begin(), st.end(), inv), st.end());

    }

    void notifyInvestors()
    {
        for (auto &investor : st)
        {
            investor->update(stockPrice);
        }
    }

    void setStockPrice(float price)
    {
        stockPrice = price;
        notifyInvestors(); // Notify all subscribed investors
    }
};

class RetailInvestor : public Investor {
    public:
        void update(float price) override {
            cout << "Retail Investor: Stock price updated to $" << price << endl;
        }
    };
    
    class InstitutionalInvestor : public Investor {
    public:
        void update(float price) override {
            cout << "Institutional Investor: Stock price updated to $" << price << endl;
        }
    };

int main()
{

    shared_ptr<StockExchange> st = make_shared<StockExchange>();
    shared_ptr<Investor> retailInvestor = make_shared<RetailInvestor>();
    shared_ptr<Investor> institutionalInvestor = make_shared<InstitutionalInvestor>();

    st->addInvestor(retailInvestor);
    st->addInvestor(institutionalInvestor);

    cout << " Stock price changes to Rs150\n";
    st->setStockPrice(150); 

    cout << " Stock price changes to Rs150\n";
    st -> setStockPrice(175);

    return 0;
}