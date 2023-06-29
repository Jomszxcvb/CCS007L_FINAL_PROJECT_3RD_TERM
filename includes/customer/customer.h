#pragma once

#include <stack>
#include <queue>
#include <iostream>
#include "../video/video.h"

// CustomerBase class
class CustomerBase {
protected:
    unsigned int mID; // auto increment
    static unsigned int mIDCounter;
    std::string mName;
    std::string mAdress;

public:
    CustomerBase();
    ~CustomerBase();

    unsigned int getmID() const;
    std::string getmName() const;
    std::string getmAdress() const;

    void setmID(unsigned int id);
    void setmName(std::string name);
    void setmAdress(std::string adress);

    void displayInfo() const;
};

// Customer class
class Customer : public CustomerBase {
private:
    std::stack<int> mRentedVideos;

public:
    Customer(std::string name, std::string adress);
    ~Customer();

    void rentVideo(unsigned int id);
    void returnVideos();

    void displayRentedVideos() const;
};

class QueueCustomers {
private:
    std::queue<Customer> mCustomers;

public:
    QueueCustomers();
    ~QueueCustomers();

    void addCustomer(Customer customer);
    Customer *searchCustomer(unsigned int id) const;


};