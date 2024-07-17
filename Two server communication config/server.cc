/*
 * server.cc
 *
 *  Created on: Jun 25, 2024
 *      Author: poorn
 */

#include <omnetpp.h>

using namespace omnetpp;

class server : public cSimpleModule {
    cMessage *msg;
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(server);

void server::initialize() {
    // Create a new message and schedule it to be sent immediately
    msg = new cMessage("CTS");
    scheduleAt(simTime(), msg);
}

void server::handleMessage(cMessage *msg) {
    // Generate two random numbers
    int randomNum1 = intuniform(0, 100);
    int randomNum2 = intuniform(0, 100);

    // Create a new message and add the random numbers as parameters
    cMessage *ctsMsg = new cMessage("CTS");
    ctsMsg->addPar("randomNum1") = randomNum1;
    ctsMsg->addPar("randomNum2") = randomNum2;

    // Find the target module and send the message
    cModule *target = getParentModule()->getSubmodule("Client");
    sendDirect(ctsMsg, target, "radioIn");

    // Clean up the original message
    delete msg;
}
