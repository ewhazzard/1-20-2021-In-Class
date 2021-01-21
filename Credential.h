// Class to manage credential data for a phone or watch (simplified)
// Mary Elaine Califf
// 1/20/21
#ifndef CREDENTIAL_H
#define CREDENTIAL_H

#include <string>
#include <ctime>

class Credential
{
private:
    std::string authCode;
    time_t expiration;
    bool valid;

public:
    // constructor
    Credential(const std::string &auth, time_t exp, bool valid = true) : authCode(auth), expiration(exp), valid(valid) {}

    // invalidate the credential
    void invalidate() { valid = false; }

    // getter for authorization code
    std::string getAuthCode() const { return authCode; }

    // check for validity of the credential
    bool isValid() const { return valid && expiration > time(nullptr); }
};

#endif
