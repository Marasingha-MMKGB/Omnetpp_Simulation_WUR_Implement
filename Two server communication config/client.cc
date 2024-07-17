/*
 * client.cc
 *
 *  Created on: Jun 25, 2024
 *      Author: poorn
 */
#include <omnetpp.h>
using namespace omnetpp;

class client : public cSimpleModule {
    cMessage *msg;
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(client);

void client::initialize() {
    EV << "Client initialize" << "\n";
    msg = new cMessage("RTS");
    scheduleAt(simTime() + dblrand(), msg->dup());
    EV << "Client initialize complete" << "\n";
}

void client::handleMessage(cMessage *msg) {
    EV << "Client handle message initialize" << "\n";
    cModule *target;
    cMessage *rtsMsg = new cMessage("RTS");
    target = getParentModule()->getSubmodule("Server");
    // Make sure the submodule name is correct
    sendDirect(rtsMsg, target, "radioIn");

    scheduleAt(simTime() + dblrand(), msg->dup());
}
