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

#include "NodeB.h"

Define_Module(NodeB);

void NodeB::initialize()
{
    // TODO - Generated method body
    srand(time(nullptr));
}

void NodeB::handleMessage(cMessage *msg)
{


        if (msg->arrivedOn("in1")) {
            // Generate a random number
            int randomNumber = intuniform(1, 100); // Generates a number between 1 and 100

            // Create a message with the random number
            char msgName[30];
            sprintf(msgName, "RandomNum: %d", randomNumber);
            cMessage *newMsg1 = new cMessage(msgName);
            cMessage *newMsg2 = new cMessage(msgName);

            // Send the message to both out1 and out2
            send(newMsg1, "out1");
            send(newMsg2, "out2");
        } else if (msg->arrivedOn("in2") && strcmp(msg->getName(), "ACK") == 0) {

        }

        // Delete the received message to avoid memory leaks
        delete msg;
}
