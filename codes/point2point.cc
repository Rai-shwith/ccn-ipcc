#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
//#include "ns3/netanim-module.h"  //Uncomment for simulation

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("FirstScriptExample");

int main (int argc, char *argv[])
{
  
 LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
 LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);

  NodeContainer nodes;
  nodes.Create (2);

  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("5Mbps")); // change the values and observe output
  pointToPoint.SetChannelAttribute ("Delay", StringValue ("15ms"));  // change the values and observe output

  NetDeviceContainer devices;
  devices = pointToPoint.Install (nodes);

  InternetStackHelper stack;
  stack.Install (nodes);

  Ipv4AddressHelper address;
  address.SetBase ("10.1.1.0", "255.255.255.0");

  Ipv4InterfaceContainer interfaces = address.Assign (devices);

  UdpEchoServerHelper echoServer (9);
  ApplicationContainer serverApps = echoServer.Install (nodes.Get (1));
  serverApps.Start (Seconds (1.0));
  serverApps.Stop (Seconds (10.0));

  UdpEchoClientHelper echoClient (interfaces.GetAddress (1), 9);
  echoClient.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient.SetAttribute ("PacketSize", UintegerValue (1024));


  ApplicationContainer clientApps = echoClient.Install (nodes.Get (0));
  clientApps.Start (Seconds (2.0));
  clientApps.Stop (Seconds (10.0));

//Uncomment below for simulation
  // AnimationInterface anim("first.xml");
  // anim.SetConstantPosition(nodes.Get(0),10.0.10.0);
  // anim.SetConstantPosition(nodes.Get(1),20.0.30.0);

  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}


/*
INSTRUCTIONS:
1. Open VMware workstation
2. Open Ubuntu os
3. Open terminal
4. cd ns-allinone-3.26
5. cd ns-3.26
6. Open files (file manager) and navigate to /home/ec/ns-allinone-3.26/ns-3.26/scratch
7. create a file eg: program.cc and then paste the code inside
8. now go back to the terminal (make sure u r in /home/ec/ns-allinone-3.26/ns-3.26 to confirm just run pwd in terminal)
9. ./waf --run program
10. OUTPUT:
          Waf: Entering directory `/home/ec/ns-allinone-3.26/ns-3.26/build'
          [ 929/2634] Compiling scratch/p2p.cc
          [2619/2634] Linking build/scratch/p2p
          Waf: Leaving directory `/home/ec/ns-allinone-3.26/ns-3.26/build'
          Build commands will be stored in build/compile_commands.json
          'build' finished successfully (14.578s)
          At time 2s client sent 1024 bytes to 10.1.1.2 port 9
          At time 2.00369s server received 1024 bytes from 10.1.1.1 port 49153
          At time 2.00369s server sent 1024 bytes to 10.1.1.1 port 49153
          At time 2.00737s client received 1024 bytes from 10.1.1.2 port 9
11. Now change the DataRate , Delay in code and bserve the output

12. Animation:
  from the terminal 
  cd ..
14. cd netanim-3.107
15. ./NetAnim 
15. A window will open , select the first.xml file from file icon frop top left. (the file will be here /home/ec/ns-allinone-3.26/ns-3.26/first )
16. see the result

*/