
#include "RX.h"

Define_Module(RX);



void RX::initialize()
{
    // TODO - Generated method body
    storedMsgs[0] = nullptr;
     storedMsgs[1] = nullptr;
}

void RX::handleMessage(cMessage *msg)
{

    if (msg->arrivedOn("in2")) {
            // Store the latest two messages received on in2
            if (storedMsgs[1] != nullptr) {
                delete storedMsgs[1]; // Avoid memory leak by deleting the oldest stored message
            }
            storedMsgs[1] = storedMsgs[0]; // Shift the current latest message to the second position
            storedMsgs[0] = msg->dup(); // Store a copy of the new message in the first position
            delete msg; // Delete the original message to avoid memory leak
        } else if (msg->arrivedOn("in1")) {
            if (strcmp(msg->getName(), "WUC") == 0) {
                // Create and send a new "WUS" message to nodeB
                cMessage *newMsg = new cMessage("WUS");
                send(newMsg, "out");
            } else if ((storedMsgs[0] != nullptr && strcmp(msg->getName(), storedMsgs[0]->getName()) == 0) ||
                       (storedMsgs[1] != nullptr && strcmp(msg->getName(), storedMsgs[1]->getName()) == 0)) {
                // If the received message matches any of the stored messages
                cMessage *newMsg = new cMessage("WUS");
                send(newMsg, "out");
            }
            delete msg; // Delete the received message to avoid memory leaks
        } else {
            delete msg; // Delete any unexpected messages to avoid memory leaks
        }
}
