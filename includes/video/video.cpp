#include "video.h"

// Video class
unsigned int Video::mIDCounter = 0;
Video::Video() { // default constructor
    mID = ++mIDCounter;
}

Video::~Video() { // destructor
}

unsigned int Video::getmID() const {
    return mID;
}

std::string Video::getmTitle() const {
    return mTitle;
}

std::string Video::getmGenre() const {
    return mGenre;
}

std::string Video::getmProduction() const {
    return mProduction;
}

unsigned int Video::getmNumberOfCopies() const {
    return mNumberOfCopies;
}

std::string Video::getmImageFilename() const {
    return mImageFilename;
}

Video *Video::getmNext() const {
    return mNext;
}

void Video::setmID(unsigned int id) {
    mID = id;
}

void Video::setmTitle(std::string title) {
    mTitle = title;
}

void Video::setmGenre(std::string genre) {
    mGenre = genre;
}

void Video::setmProduction(std::string production) {
    mProduction = production;
}

void Video::setmNumberOfCopies(unsigned int numberOfCopies) {
    mNumberOfCopies = numberOfCopies;
}

void Video::setmImageFilename(std::string imageFilename) {
    mImageFilename = imageFilename;
}

Video *Video::setmNext(Video *next) {
    mNext = next;
}

/**
 * This function is used to display information about a video.
 */
void Video::display() const {
    std::cout << "Video ID: " << mID << std::endl;
    std::cout << "Movie Title: " << mTitle << std::endl;
    std::cout << "Genre: " << mGenre << std::endl;
    std::cout << "Production: " << mProduction << std::endl;
    std::cout << "Number of copies: " << mNumberOfCopies << std::endl;
    std::cout << "Image filename: " << mImageFilename << std::endl;
    std::cout << "Availability: " << (isAvailable() ? "Available" : "Not available") << std::endl;
}

/**
 * This function is used to decrease the number of copies of a video by 1.
 */
void Video::decreaseNumberOfCopies() {
    mNumberOfCopies--;
}

/**
 * This function is used to increase the number of copies of a video by 1.
 */
void Video::increaseNumberOfCopies() {
    mNumberOfCopies++;
}

/**
 * This function is used to check if a video is available.
 * @return true if the video is available, false otherwise
 */
bool Video::isAvailable() const {
    return mNumberOfCopies > 0;
}

// class VideoLibrary
VideoLibrary::VideoLibrary() {
    mHead = NULL;
}

Video *VideoLibrary::getmHead() const {
    return mHead;
}

void VideoLibrary::setmHead(Video* head) {
    mHead = head;
}

/**
 * This function is used to insert a video to the video library.
 * The video is inserted at the end of the list.
 * @param video the video to be inserted
 */
void VideoLibrary::insertVideo(Video video) {
    Video *newVideo = new Video();
    *newVideo = video;
    newVideo->setmNext(NULL);
    if (mHead == NULL) {
        mHead = newVideo;
    } else {
        Video *temp = mHead;
        while (temp->getmNext() != NULL) {
            temp = temp->getmNext();
        }
        temp->setmNext(newVideo);
    }
}

/**
 * This function is used to search for a video in the video library.
 * @param id the id of the video to be searched for.
 * @return the video if found, nullptr otherwise.
 */
Video *VideoLibrary::searchVideo(unsigned int id) const {
    Video *temp = mHead;
    
    while (temp != NULL) {
        if (temp->getmID() == id) {
            return temp;
        }
        temp = temp->getmNext();
    }
    return nullptr;
}

/**
 * This function is used to check out a video.
 * The number of copies of the video is decreased by 1.
 * @param id the id of the video to be checked out
 */
void VideoLibrary::checkOutVideo(unsigned int id) {
    Video *temp = mHead;

    if (temp->getmID() == id) {
        temp->decreaseNumberOfCopies();
        return;
    }
    temp = temp->getmNext();
}

/**
 * This function is used to check in a video.
 * The number of copies of the video is increased by 1.
 * @param id the id of the video to be checked in
 */
void VideoLibrary::checkInVideo(unsigned int id) {
    Video *temp = mHead;

    if (temp->getmID() == id) {
        temp->increaseNumberOfCopies();
        return;
    }
    temp = temp->getmNext();
}

/**
 * This function is used to display all videos in the video library.
 */
void VideoLibrary::displayAllVideos() const {
    Video *temp = mHead;
    while (temp != NULL) {
        temp->display();
        std::cout << std::endl;
        temp = temp->getmNext();
    }
}
         
    










