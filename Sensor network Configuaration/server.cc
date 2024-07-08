/*
 * server.cc
 *
 *  Created on: Jun 25, 2024
 *      Author: poorn
 */


#include <omnetpp.h>

using namespace omnetpp;

class server: public cSimpleModule{
    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

};

Define_Module(server);

void server::initialize(){

}

void server::handleMessage(cMessage *msg){

    if (strcmp(msg->getName(),getFullName()) == 0) {
        msg = new cMessage(getFullName());

           cModule *target=getParentModule()->getSubmodule("Client");

           sendDirect(msg,target,"radioIn");

    }

}
