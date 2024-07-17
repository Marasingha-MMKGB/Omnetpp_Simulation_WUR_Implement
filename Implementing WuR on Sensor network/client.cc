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
    cMessage *Code[8];
    cMessage *ACK;
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

//-----------------------------------------------------------------------------

Define_Module(client);

void client::initialize() {
    ACK = nullptr;
    EV << "Client initialize" << "\n";
    msg = new cMessage("RTS");
    scheduleAt(simTime() + dblrand(), msg->dup());
    EV << "Client initialize complete" << "\n";
}
//--------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------

void client::handleMessage(cMessage *msg) {





    ACK = nullptr;
    EV << "Client handle message initialize" << "\n";

//------------------------STRINGS HANDLING --------------------------------------------------
    int randomIndex = intuniform(1, 8); // Random number between 1 and 10
        char serverName[20];
        sprintf(serverName, "Server%d", randomIndex);
  //-------------------------------------CYPETRTEXT HANDLING-----------------------------------

           if (msg->arrivedOn("radioIn")){

                           ACK = new cMessage("ACK");
                           const char* messageName = msg->getName();


                              cModule *target=getParentModule()->getSubmodule(messageName);

                              sendDirect(ACK,target,"radioIn");





                       }




//-----------------------MSG INITIALIZING (SENDING WUC)---------------------------------------------

     {
            cModule *target;
            cMessage *rtsMsg = new cMessage(serverName);
            target = getParentModule()->getSubmodule("Server");
            // Make sure the submodule name is correct
            sendDirect(rtsMsg, target, "radioIn");

            scheduleAt(simTime() + dblrand(), msg->dup());
     }

  {
    cModule *target;
    cMessage *rtsMsg = new cMessage(serverName);
    target = getParentModule()->getSubmodule("Server1");
    // Make sure the submodule name is correct
    sendDirect(rtsMsg, target, "radioIn");

    scheduleAt(simTime() + dblrand(), msg->dup());
    }
    {
        EV << "Client handle message initialize" << "\n";

            cModule *target;
            cMessage *rtsMsg = new cMessage(serverName);
            target = getParentModule()->getSubmodule("Server2");
            // Make sure the submodule name is correct
            sendDirect(rtsMsg, target, "radioIn");

            scheduleAt(simTime() + dblrand(), msg->dup());

    }

    {
        cModule *target;
        cMessage *rtsMsg = new cMessage(serverName);
        target = getParentModule()->getSubmodule("Server3");
        // Make sure the submodule name is correct
        sendDirect(rtsMsg, target, "radioIn");

        scheduleAt(simTime() + dblrand(), msg->dup());
        }
    {
           cModule *target;
           cMessage *rtsMsg = new cMessage(serverName);
           target = getParentModule()->getSubmodule("Server4");
           // Make sure the submodule name is correct
           sendDirect(rtsMsg, target, "radioIn");

           scheduleAt(simTime() + dblrand(), msg->dup());
           }
    {
           cModule *target;
           cMessage *rtsMsg = new cMessage(serverName);
           target = getParentModule()->getSubmodule("Server5");
           // Make sure the submodule name is correct
           sendDirect(rtsMsg, target, "radioIn");

           scheduleAt(simTime() + dblrand(), msg->dup());
           }
    {
           cModule *target;
           cMessage *rtsMsg = new cMessage(serverName);
           target = getParentModule()->getSubmodule("Server6");
           // Make sure the submodule name is correct
           sendDirect(rtsMsg, target, "radioIn");

           scheduleAt(simTime() + dblrand(), msg->dup());
           }
    {
           cModule *target;
           cMessage *rtsMsg = new cMessage(serverName);
           target = getParentModule()->getSubmodule("Server7");
           // Make sure the submodule name is correct
           sendDirect(rtsMsg, target, "radioIn");

           scheduleAt(simTime() + dblrand(), msg->dup());
           }






}
