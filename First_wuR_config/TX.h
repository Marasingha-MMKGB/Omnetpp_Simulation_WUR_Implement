

#ifndef __SECONDATTEMPT_TX_H_
#define __SECONDATTEMPT_TX_H_

#include <omnetpp.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class TX : public cSimpleModule
{
private:
    cMessage *storedMsg;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
