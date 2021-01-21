// Manages data for an ID
// Mary Elaine Califf and Evan Hazzard, Amber Kull, Levi Schaut(enter all group member names)

#ifndef IDDATA_H
#define IDDATA_H

#include "Credential.h"

class IDData
{
private:
    std::string patronID;
    int patronType;
    bool active;
    Credential *phoneCredential;
    Credential *watchCredential;
    void clear();
    void copy(const IDData& rhs);

public:
    // constructor
    IDData(std::string id, int patType, bool active = true) : patronID(id), patronType(patType), active(active),
                                                              phoneCredential(nullptr), watchCredential(nullptr) {}

    // getters for the credential authorization codes
    std::string getPhoneCredentialAuthCode() const;
    std::string getWatchCredentialAuthCode() const;

    // add a phone credential -- only if no existing valid phone credential
    // returns true if the new credential was added
    bool addPhoneCredential(std::string authCode, time_t exp);

    // add a watch credential -- only if no existing valid watch credential
    // returns true if the new credential was added
    bool addWatchCredential(std::string authCode, time_t exp);

    // invalidate any existing credentials
    void invalidateCredentials();

    // check for a valid watch credential
    bool hasValidWatchCredential() const;

    // check for a valid phone credential
    bool hasValidPhoneCredential() const;

    //Destructor
    ~IDData();

    //Copy Constructor
    IDData(const IDData& rhs);

    //Assignment Operator
    IDData& operator=(const IDData& rhs);

};

#endif