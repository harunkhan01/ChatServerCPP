## Central node discovery

This program implements a way to determine what devices are connected to your network. This requires that each device be running an instance of this code. The purpose is to know whether
a device is on/off and/or consuming power. 

A custom application layer protocol is built over TCP connections that utilizes multi-threading to handle client load while employing thread-safety features. This library will eventually 
implement a cryptographic layer to enable DHKE aand symmetric key based communication.