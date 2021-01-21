// Implementation file for ITData class
// Mary Elaine Califf and Evan Hazzard, Amber Kull, Levi Schaut (enter all group member names)

#include "IDData.h"
using namespace std;

std::string IDData::getPhoneCredentialAuthCode() const
{
    if (phoneCredential)
        return phoneCredential->getAuthCode();
    else
        return "none";
    
}

std::string IDData::getWatchCredentialAuthCode() const
{
    if (watchCredential)
        return watchCredential->getAuthCode();
    else
        return "none";
    
}

bool IDData::addPhoneCredential(string authCode, time_t exp)
{
    if (hasValidPhoneCredential())
    {
        // we already have a valid one -- need to bail
        return false;
    }
    if (phoneCredential)
    {
        //there is an invalid one -- need to clean it up
        delete phoneCredential;
    }
    phoneCredential = new Credential(authCode, exp);
    return true;
}

bool IDData::addWatchCredential(string authCode, time_t exp)
{
    if (hasValidWatchCredential())
    {
        // we already have a valid one -- need to bail
        return false;
    }
    if (watchCredential)
    {
        //there is an invalid one -- need to clean it up
        delete watchCredential;
    }
    watchCredential = new Credential(authCode, exp);
    return true;
}

void IDData::invalidateCredentials()
{
    if (phoneCredential)
        phoneCredential->invalidate();
    if (watchCredential)
        watchCredential->invalidate();
}

bool IDData::hasValidWatchCredential() const
{
    bool watchIsValid = false;
    if (watchCredential)
        watchIsValid = watchCredential->isValid();
    return watchIsValid;
}

bool IDData::hasValidPhoneCredential() const
{
    bool phoneIsValid = false;
    if (phoneCredential)
        phoneIsValid = phoneCredential->isValid();
    return phoneIsValid;
}

//private clear method
void IDData::clear(){
    //delete [] __;
    //__ = nullptr; 
}

//private copy method
void IDData::copy(const IDData& rhs){}

//dectructor
IDData::~IDData(){
    clear();
}

//copy constructor
IDData::IDData(const IDData& rhs)
{
    copy(rhs); 
}


//assignment operator
IDData& IDData::operator=(const IDData& rhs)
{
    //check for self assignment
    if(this != &rhs){
        //call clean-up helper method
        clear(); 
        //call copy helper method               
        copy(rhs);              
    }
    return *this;
}


