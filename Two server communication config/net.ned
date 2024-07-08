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

import inet.visualizer.common.IntegratedVisualizer;


simple server
{
    @display("i=device/server,,0");
    gates:
        input radioIn @directIn;
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
    @display("bgb=837,364,,,0;i=background/streetmap,,0;is=vl;i2=status/execute,,0");
    submodules:
        Server: server {
            @display("p=84,265");
        }
        Client: client {
            @display("p=469,269");
        }
        Server1: server {
            @display("p=350.49374,103.57875");
        }
        integratedVisualizer: IntegratedVisualizer {
            @display("p=727.14374,58.59");
        }
}

