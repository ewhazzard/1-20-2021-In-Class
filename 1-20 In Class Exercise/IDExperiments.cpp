// program that does some testing of the IDData class
// Mary Elaine Califf
// 1/20/21

#include "IDData.h"
#include <iostream>
using namespace std;

// method for further copy constructor testing
void changeCopy(IDData argPatron);

int main()
{
    // feel free to add additional test code if desired
    IDData patron1("888888888", 2);
    IDData patron2("555555555", 1);

    patron1.addPhoneCredential("8f342", time_t(1612660679));
    cout << patron1.getPhoneCredentialAuthCode() << endl;
    cout << patron1.getWatchCredentialAuthCode() << endl;
    cout << patron1.hasValidPhoneCredential() << endl;

    changeCopy(patron1); //passed by value, so the copy constructor is called

    cout << "--- Copy --- checking patron1 phone credential -- should still be valid" << endl;
    cout << "patron 1 phone validity: " << patron1.hasValidPhoneCredential() << endl; // but isn't until everything is fixed

    patron1.addWatchCredential("5439d", time_t(1712582052));
    cout << patron1.getPhoneCredentialAuthCode() << endl;
    cout << patron1.getWatchCredentialAuthCode() << endl;
    cout << patron1.hasValidWatchCredential() << endl;

    IDData patron3(patron1); // a different copy constructor test
    cout << patron3.getPhoneCredentialAuthCode() << endl;
    cout << patron3.getWatchCredentialAuthCode() << endl;
    cout << patron3.hasValidWatchCredential() << endl;

    patron1.invalidateCredentials();
    cout << "--- Copy --- Invalidated patron 1, patron 3 should still be valid" << endl;
    cout << "patron 1 watch validity: " << patron1.hasValidWatchCredential() << endl;
    cout << "patron 3 watch validity: " << patron3.hasValidWatchCredential() << endl;

    patron2.addWatchCredential("222ef", time_t(1712582052));

    patron3 = patron2; // testing assignment operator

    patron3.invalidateCredentials();
    cout << "--- Assignment --- Invalidated patron 3, patron 2 should still be valid" << endl;
    cout << "patron 2 watch validity: " << patron2.hasValidWatchCredential() << endl;
    cout << "patron 3 watch validity: " << patron3.hasValidWatchCredential() << endl;

    cout << "\nadding patron2 watch credential" << endl;
    patron2.addWatchCredential("ef444", time_t(1715552301));
    cout << "patron2 auth code: " << patron2.getWatchCredentialAuthCode() << endl;

    cout << "--- Assignment --- patron 2 should still be valid, patron 3 remains invalid" << endl;
    cout << "patron 2 watch validity: " << patron2.hasValidWatchCredential() << endl;
    cout << "patron 3 watch validity: " << patron3.hasValidWatchCredential() << endl;
    cout << "patron3 auth code: " << patron3.getWatchCredentialAuthCode() << endl;

    patron3.addWatchCredential("gg222", time_t(1717552222)); //should not crash after everything is fixed
    cout << "new patron3 auth code: " << patron3.getWatchCredentialAuthCode() << endl;

    patron2 = patron2; // checking self-assignment
    patron2.invalidateCredentials();

    cout << "--- Self Assignment --- Invalidated patron 2" << endl;
    cout << "patron 2 watch validity: " << patron2.hasValidWatchCredential() << endl;
    patron2.addWatchCredential("ab213", 1715552301);

    cout << "--- Self Assignment --- Added new credential to patron 2, should now be valid" << endl;
    cout << "patron 2 watch validity: " << patron2.hasValidWatchCredential() << endl;
    cout << "patron2 auth code: " << patron2.getWatchCredentialAuthCode() << endl;
}

void changeCopy(IDData argPatron)
{
    argPatron.invalidateCredentials();
}