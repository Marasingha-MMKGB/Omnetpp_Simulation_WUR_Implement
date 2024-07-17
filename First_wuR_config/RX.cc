//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "RX.h"

Define_Module(RX);



void RX::initialize()
{
    // TODO - Generated method body
    storedMsg = nullptr; // Initialize the storedMsg to nullptr
}

void RX::handleMessage(cMessage *msg)
{

    if (msg->arrivedOn("in2")) {
            // Store the message received on in2
            if (storedMsg != nullptr) {
                delete storedMsg; // Avoid memory leak by deleting the previous stored message
            }
            storedMsg = msg->dup(); // Store a copy of the received message
            delete msg; // Delete the original message to avoid memory leak
        } else if (msg->arrivedOn("in1")) {
            if (strcmp(msg->getName(), "WUC") == 0) {
                // Create and send a new "WUS" message to nodeB
                cMessage *newMsg = new cMessage("WUS");
                send(newMsg, "out");
            } else if (storedMsg != nullptr && strcmp(msg->getName(), storedMsg->getName()) == 0) {
                // If the received message matches the stored message
                cMessage *newMsg = new cMessage("WUS");
                send(newMsg, "out");
            }
            delete msg; // Delete the received message to avoid memory leaks
        } else {
            delete msg; // Delete any unexpected messages to avoid memory leaks
        }
}
