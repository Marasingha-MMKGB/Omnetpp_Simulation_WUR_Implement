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
    @display("bgb=1044.1575,632.98126,,,0;i=background/streetmap,,0;is=vl;i2=status/execute,,0");
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
}

