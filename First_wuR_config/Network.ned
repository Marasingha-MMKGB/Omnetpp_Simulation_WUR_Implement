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

import ned.IdealChannel;


network Network
{
    @display("bgb=652,513");
    submodules:
        nodeA: NodeA {
            @display("p=98,384");
        }
        nodeB: NodeB {
            @display("p=427,384");
        }
        rx: RX {
            @display("p=427,242");
        }
        tx: TX {
            @display("p=98,242");
        }
    connections:
        nodeA.out1 --> IdealChannel --> tx.in;
        tx.out --> IdealChannel --> rx.in1;
        rx.out --> IdealChannel --> nodeB.in1;
        nodeB.out2 --> IdealChannel --> nodeA.in;
        nodeA.out2 --> IdealChannel --> nodeB.in2;
        nodeB.out1 --> IdealChannel --> rx.in2;
}
