/*
 * MR.cc
 *
 *  Created on: Jun 26, 2024
 *      Author: poorn
 */

#include <omnetpp.h>

using namespace omnetpp;

class MR: public cSimpleModule{
    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

};

Define_Module(MR);

void MR::initialize(){

}

void MR::handleMessage(cMessage *msg){
    if (msg->arrivedOn("in")){
        if (strcmp(msg->getName(),"WUS") == 0) {
            setDisplayString("i=old/greenbox");
        }else if (strcmp(msg->getName(),"ACK") == 0){

            setDisplayString("i=old/ball2");
        }

    }

}


