#pragma once

#include <iostream>

#include "../video/video.h"
#include "../customer/customer.h"

class CustomerSystem {
private:
    QueueCustomers mQueueCustomers;

public:
    void addNewCustomerMenu();
    void showCustomerDetailsMenu();
    void showCustomerRentedVideosMenu();
};

class VidRentSystem {
private:
    VideoLibrary mVideoLibrary;
    QueueCustomers mQueueCustomers;

public:
    void newVideoMenu();
    void rentVideoMenu();
    void returnVideoMenu();
    void showVideoDetailsMenu();
    void displayAllVideosMenu();
    void checkVideoAvailabilityMenu();
    void exitMenu();
};