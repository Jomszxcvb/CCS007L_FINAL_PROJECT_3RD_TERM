#include <stdio.h>
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

    customer->displayInfo();
    
    std::cout << std::endl;
    std::cout << "List of Videos Rented..." << std::endl;
    std::cout << std::endl;
    // TO CONTINUE... : LEAD PROGRAMMER
}

void CustomerSystem::customerMaintenanceMenu() {
    //TODO :

}

/**
 * Enter Customer ID: 1
 * Name: John
 * Address: 123 Main St
 * 
 * Videos to Rent...
 * 
 * Enter Video ID: 1
 * Movie Title: The Matrix
 * Number of Copies: 5
 * 
 * Rent nother video? (Y/N): Y...
*/
void VidRentSystem::rentVideoMenu() {
    unsigned int id;
    std::cout << "Enter customer ID: ";
    std::cin >> id;

    Customer *customer = mQueueCustomers.searchCustomer(id);
    if (customer == nullptr) {
        std::cout << "Customer not found" << std::endl;
        return;
    } else {
        customer->displayInfo();
    }

    std::cout << std::endl;
    std::cout << "Videos to Rent..." << std::endl;
    std::cout << std::endl;

    while (true) {

        std::cout << "Enter Video ID: " << std::endl;
        std::cin >> id;

        Video *video = mVideoLibrary.searchVideo(id);
        if (video == nullptr) {
            std::cout << "Video not found" << std::endl;
            continue;
        } else {
        customer->displayInfo();
    }

        if (!video->isAvailable()) {
            std::cout << "Video not available" << std::endl;
            continue;
        }

        customer->rentVideo(id);
        mVideoLibrary.checkOutVideo(id);

        std::cout << "Movie Title: " << video->getmTitle() << std::endl;
        std::cout << "Number of Copies:" << video->getmNumberOfCopies() << std::endl;

        LoopQuestion:
        std::cout << std::endl;
        std::cout << "Rent another video? (Y/N): ";
        char choice;
        std::cin >> choice;
        if (choice == 'N' || choice == 'n') {
            break;
        } else if (choice == 'Y' || choice == 'y') {
            continue;
        } else {
            std::cout << "Invalid choice." << std::endl;
            goto LoopQuestion;
        }
    }
}

void VidRentSystem::returnVideosMenu() {
    unsigned int id;
    std::cout << "Enter customer ID: ";
    std::cin >> id;

    Customer *customer = mQueueCustomers.searchCustomer(id);
    if (customer == nullptr) {
        std::cout << "Customer not found" << std::endl;
        return;
    } else {
        customer->displayInfo();
    }

    std::cout << std::endl;
    std::cout << "Videos Rented..." << std::endl;
    std::cout << std::endl;
    customer->displayVideos();
    customer->returnVideos();

    std::cout << std::endl;
    std::cout << "Videos successfully returned" << std::endl;
}

void VidRentSystem::showVideoDetailsMenu() {
    //TODO : PROGRAMMER 2

}

void VidRentSystem::displayAllVideosMenu() {
    //TODO : PROGRAMMER 1

}

void VidRentSystem::checkVideoAvailabilityMenu() {
    //TODO : PROGRAMMER 2

}



