#include <iostream>
#include <crafter.h>

/* Collapse namespaces */
using namespace std;
using namespace Crafter;

int main() {
        /* Set the interface */
        string iface = "ZTEUSBModem";

        /* Get the IP address associated to the interface */
        string MyIP = "250.84.21.163";//GetMyIP(iface);
        cout << "[@] My IP address is  : " << MyIP  << endl;

        /* Create an IP header */
        IP ip_header;
        /* Set the Source and Destination IP address */
        ip_header.SetSourceIP(MyIP);
        ip_header.SetDestinationIP("www.google.com");

        /* Create an TCP - SYN header */
        TCP tcp_header;
        tcp_header.SetSrcPort(11);
        tcp_header.SetDstPort(80);
        tcp_header.SetSeqNumber(RNG32());
        tcp_header.SetFlags(TCP::SYN);

        /* A raw layer, this could be any array of bytes or chars */
        RawLayer payload("ArbitraryPayload");

        /* Create a packets */
        Packet tcp_packet = ip_header / tcp_header / payload;

        cout << endl << "[@] Print before sending: " << endl;
        tcp_packet.Print();

        /* Write the packet on the wire */
        tcp_packet.Send();

        cout << endl << "[@] Print after sending: " << endl;
        tcp_packet.Print();

        return 0;
}
