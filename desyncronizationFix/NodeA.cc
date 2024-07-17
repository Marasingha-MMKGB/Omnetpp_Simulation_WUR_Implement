
#include "NodeA.h"

Define_Module(NodeA);

void NodeA::initialize()
{
    // TODO - Generated method body
    previousMsg = nullptr;
    msgCounter = 0;
}

void NodeA::handleMessage(cMessage *msg)
{
    // Increment the message counter
        msgCounter++;

        // Check if this is the fourth message
        if (msgCounter % 4 == 0) {
            // Send the previous message to out1
            if (previousMsg != nullptr) {
                cMessage *forwardedMsg = previousMsg->dup(); // Create a duplicate of the previous message
                send(forwardedMsg, "out1");
            }
        } else {
            // Store the current message as the previous message for future use
            if (previousMsg != nullptr) {
                delete previousMsg; // Avoid memory leak by deleting the old previous message
            }
            previousMsg = msg->dup();

            // Check if the received message is "RandomNum: 10"
            if (strcmp(msg->getName(), "RandomNum: 10") == 0) {
                // Create and send a "RandomNum: 9" message to out1
                cMessage *newMsg = new cMessage("RandomNum: 68");
                send(newMsg, "out1");
            } else {
                // Create an ACK message
                cMessage *ackMsg = new cMessage("ACK");

                // Send the ACK message to NodeB via port "out2"
                send(ackMsg, "out2");

                // Forward the received message to port "out1"
                cMessage *forwardedMsg = msg->dup(); // Create a duplicate of the received message
                send(forwardedMsg, "out1");
            }
        }

        // Delete the original received message to avoid memory leaks
        delete msg;
}
