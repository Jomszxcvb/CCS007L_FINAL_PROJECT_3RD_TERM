#pragma once

#include <iostream>

/**
 * @brief this class is used to store information about a video
 */
class Video {
private:
    unsigned int mID;
    static unsigned int mIDCounter;
    std::string mTitle;
    std::string mGenre;
    std::string mProduction;
    unsigned int mNumberOfCopies;
    std::string mImageFilename;
    Video *mNext;

public:
    Video();
    ~Video();

    unsigned int getmID() const;
    std::string getmTitle() const;
    std::string getmGenre() const;
    std::string getmProduction() const;
    unsigned int getmNumberOfCopies() const;
    std::string getmImageFilename() const;
    Video *getmNext() const;

    void setmID(unsigned int id);
    void setmTitle(std::string title);
    void setmGenre(std::string genre);
    void setmProduction(std::string production);
    void setmNumberOfCopies(unsigned int numberOfCopies);
    void setmImageFilename(std::string imageFilename);
    Video *setmNext(Video *next);

    void display() const;

    void decreaseNumberOfCopies();
    void increaseNumberOfCopies();
    bool isAvailable() const;
};

// class VideoLibrary
class VideoLibrary {
private:
    Video *mHead;

public:
    VideoLibrary();

    Video *getmHead() const;

    void setmHead(Video* head);

    void insertVideo(Video video);
    Video *searchVideo(unsigned int id) const;

    void checkOutVideo(unsigned int id);
    void checkInVideo(unsigned int id);
    void displayAllVideos() const;
};


