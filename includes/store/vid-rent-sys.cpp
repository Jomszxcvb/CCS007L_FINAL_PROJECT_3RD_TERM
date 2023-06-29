#include "vid-rent-sys.h"

void CustomerSystem::addNewCustomerMenu() {
    //TODO : PROGRAMMER 1
}

void CustomerSystem::showCustomerDetailsMenu() {
    //TODO : PROGRAMMER 2
}

/**
 * Enter customer ID: 1
 * 
 * Name: John
 * Adress: 123 Main St
 * 
 * List of Videos Rented...
 * 
 * Video ID: 1
 * Video ID: 2...
 **/
void CustomerSystem::showCustomerRentedVideosMenu() {
    unsigned int id;
    std::cout << "Enter customer ID: ";
    std::cin >> id;
    Customer *customer = mQueueCustomers.searchCustomer(id);
    if (customer == nullptr) {
        std::cout << "Customer not found" << std::endl;
        return;
    }

    std::cout << std::endl;
    customer->displayRentedVideos();
    std::cout << std::endl;
}

void VidRentSystem::rentVideoMenu() {
    unsigned int id;
    std::cout << "Enter customer ID: ";
    std::cin >> id;

    Customer *customer = mQueueCustomers.searchCustomer(id);
    if (customer == nullptr) {
        std::cout << "Customer not found" << std::endl;
        return;
    }

    
    while (true) {
        std::cout << "Enter Video ID: " << std::endl;
        std::cin >> id;

        Video *video = mVideoLibrary.searchVideo(id);
        if (video == nullptr) {
            std::cout << "Video not found" << std::endl;
            continue;
        }

        if (!video->isAvailable()) {
            std::cout << "Video not available" << std::endl;
            continue;
        }

        customer->rentVideo(id);
        mVideoLibrary.checkOutVideo(id);

        std::cout << "Movie Title: " << video->getmTitle() << std::endl;
        std::cout << "Number of Copies:" << video->getmNumberOfCopies() << std::endl;

        std::cout << std::endl;
        std::cout << "Rent another video? (Y/N): ";
        
    }

}



