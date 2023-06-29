#include  "customer.h"

// CustomerBase class
unsigned int CustomerBase::mIDCounter = 0;
CustomerBase::CustomerBase() { // default constructor
    mID = ++mIDCounter;
}

CustomerBase::~CustomerBase() { // destructor
}

unsigned int CustomerBase::getmID() const {
    return mID;
}

std::string CustomerBase::getmName() const { 
    return mName;
}

std::string CustomerBase::getmAdress() const {
    return mAdress;
}

void CustomerBase::setmID(unsigned int id) {
    mID = id;
}

void CustomerBase::setmName(std::string name) {
    mName = name;
}

void CustomerBase::setmAdress(std::string adress) {
    mAdress = adress;
}

void CustomerBase::displayInfo() const {
    std::cout << "Name: " << mName << std::endl;
    std::cout << "Adress: " << mAdress << std::endl;
}

// Customer class
Customer::Customer(std::string name, std::string adress) {
    mID = ++mIDCounter;
    mName = name;
    mAdress = adress;
}

Customer::~Customer() {
}

void Customer::rentVideo(unsigned int id) {
    mRentedVideos.push(id);
}

void Customer::returnVideos() {
    if (mRentedVideos.empty()) {
        std::cout << "No videos to return" << std::endl;
        return;
    }
    while (!mRentedVideos.empty()) {
        std::cout << "Video ID: " << mRentedVideos.top() << std::endl;
        mRentedVideos.pop();
    }
}

void Customer::displayRentedVideos() const {
    if (mRentedVideos.empty()) {
        std::cout << "No videos rented" << std::endl;
        return;
    }
    std::cout << "List of Videos Rented..." << std::endl;
    std::cout << std::endl;
    std::stack<int> temp = mRentedVideos;
    while (!temp.empty()) {
        std::cout << "Video ID: " << temp.top() << std::endl;
        temp.pop();
    }
}

// QueueCustomers class
QueueCustomers::QueueCustomers() {
}

QueueCustomers::~QueueCustomers() {
}

void QueueCustomers::addCustomer(Customer customer) {
    mCustomers.push(customer);
}

/**
 * Search for a customer in the queue
 * @param id Customer ID
 * @return Customer pointer if found, nullptr otherwise
 */
Customer *QueueCustomers::searchCustomer(unsigned int id) const {
    std::queue<Customer> temp = mCustomers;
    while (!temp.empty()) {
        if (temp.front().getmID() == id) {
            return new Customer(temp.front());
        }
        temp.pop();
    }
    return nullptr;
}
    



