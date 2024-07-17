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
//
// TODO documentation
//
package newproject;

import ned.IdealChannel;


simple server
{
    @display("i=device/receiverdish,,0");
    gates:
        input radioIn @directIn;
        output out;
}

//
// TODO documentation
//
simple MR
{
    @display("i=device/device,,0");
    gates:
        input in;
}

//
// TODO documentation
//
simple client
{
    @display("i=misc/city,,0");
    gates:
        input radioIn @directIn;
}

//
// TODO documentation
//
network Network
{
    @display("bgb=1049.22,730.8,,,0;i2=status/execute,,0;bgi=background/terrain");
    submodules:
        Server: server {
            @display("p=84,265");
        }
        Client: client {
            @display("p=469,269");
        }
        Server1: server {
            @display("p=358.875,134.41501");
        }
        Server2: server {
            @display("p=567.0675,96.255");
        }
        Server3: server {
            @display("p=833.86127,134.96625");
        }
        Server4: server {
            @display("p=201.92625,459.30374");
        }
        Server5: server {
            @display("p=789.91876,541.9575");
        }
        Server6: server {
            @display("p=536.72626,420.5925");
        }
        Server7: server {
            @display("p=380.835,528.35626");
        }
        mr: MR {
            @display("p=71.775,169.65001");
        }
        mr1: MR {
            @display("p=334.08002,43.065002");
        }
        mr2: MR {
            @display("p=541.575,18.27");
        }
        mr3: MR {
            @display("p=837.81,63.945");
        }
        mr4: MR {
            @display("p=191.835,383.67");
        }
        mr5: MR {
            @display("p=867.825,598.995");
        }
        mr6: MR {
            @display("p=544.185,507.64502");
        }
        mr7: MR {
            @display("p=300.15,598.995");
        }
    connections:
        Server1.out --> IdealChannel --> mr1.in;
        Server2.out --> IdealChannel --> mr2.in;
        Server3.out --> IdealChannel --> mr3.in;
        Server5.out --> IdealChannel --> mr5.in;
        Server6.out --> IdealChannel --> mr6.in;
        Server7.out --> IdealChannel --> mr7.in;
        Server4.out --> IdealChannel --> mr4.in;
        Server.out --> IdealChannel --> mr.in;
}

