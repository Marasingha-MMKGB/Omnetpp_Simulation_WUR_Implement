
#include "TX.h"

Define_Module(TX);

void TX::initialize()
{
    storedMsg = nullptr; // Initialize the storedMsg to nullptr
        // Send the initial "WUC" message
        cMessage *msg = new cMessage("WUC");
        send(msg, "out");

}

void TX::handleMessage(cMessage *msg)
{
    if (msg->arrivedOn("in")) {
            // Store the received message

        storedMsg = nullptr;  // Avoid memory leak by deleting the previous message

            storedMsg = msg; // Store the received message

            send(storedMsg, "out");}


}
