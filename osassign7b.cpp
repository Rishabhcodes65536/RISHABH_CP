#include<bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// #define endl              '\n'
#define ff                first
#define ss                second
#define pb                emplace_back
#define ppb               pop_back
#define int               long long
#define float             long double
#define lb                lower_bound
#define ub                upper_bound
#define sz(x)             (int)(x).size()
#define ppc               __builtin_popcountll
#define all(x)            (x).begin(), (x).end()
#define rall(x)           (x).rbegin(), (x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define per(i,a,b)        for(int i=(a);i>=(b);i--)
#define invec(a,n)        vector<int>a(n); rep(i,0,n) cin>>a[i]
#define inarr(a,n)        int a[n]; rep(i,0,n) cin>>a[i]
#define in(k,a) for(auto k : a)
#define disp(a) in(k,a){ cout<<k<<' ';} cout<<endl


void simulateNetworkDelay() {
    
    int delay = rand() % 3 + 1;
    sleep(delay);
}

bool simulatePacketLoss() {
    int randomNum = rand() % 2;
    return (randomNum == 0); 
}

void senderSide() {
    std::cout << "Sender side: " << std::endl;
    std::string message = "Hello, Receiver!";
    std::cout << "Sending message: " << message << std::endl;
    bool ackReceived = false;
    int sequenceNumber = 0;
    
    while (!ackReceived) {
        simulateNetworkDelay();
        
        if (simulatePacketLoss()) {
            std::cout << "Packet lost. Resending packet with sequence number: " << sequenceNumber << std::endl;
            continue;
        }
        
        std::cout << "Packet sent with sequence number: " << sequenceNumber << std::endl;
        
        simulateNetworkDelay();
        std::cout << "Waiting for acknowledgment..." << std::endl;
        
        if (simulatePacketLoss()) {
            std::cout << "Acknowledgment lost. Resending packet with sequence number: " << sequenceNumber << std::endl;
            continue;
        }
        
        std::cout << "Acknowledgment received for sequence number: " << sequenceNumber << std::endl;
        ackReceived = true;
        sequenceNumber++;
    }
    
    std::cout << "Message sent successfully!" << std::endl;
}

void receiverSide() {
    std::cout << "Receiver side: " << std::endl;
    bool ackSent = false;
    int expectedSequenceNumber = 0;
    
    while (!ackSent) {
        simulateNetworkDelay();
        
        if (simulatePacketLoss()) {
            std::cout << "Packet lost. Ignoring packet." << std::endl;
            continue;
        }
        
        std::cout << "Packet received with sequence number: " << expectedSequenceNumber << std::endl;
        
        simulateNetworkDelay();
        std::cout << "Sending acknowledgment for sequence number: " << expectedSequenceNumber << std::endl;
        
        if (simulatePacketLoss()) {
            std::cout << "Acknowledgment lost. Resending acknowledgment for sequence number: " << expectedSequenceNumber << std::endl;
            continue;
        }
        
        std::cout << "Acknowledgment sent for sequence number: " << expectedSequenceNumber << std::endl;
        ackSent = true;
        expectedSequenceNumber++;
    }
    
    std::cout << "Message received successfully!" << std::endl;
}

signed main() {
    srand(time(0));
    senderSide();
    receiverSide();
    return 0;
}
