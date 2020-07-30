/*
 * Name:Pierce Tarleton
 * Date Submitted: 3/29/2019
 * Lab Section: 002
 * Assignment Name: lab 9 Graph algorithms
 */

#pragma once

#include <string>
#include <map>
#include <iostream>
#include <set>
#include "heap.h"

using namespace std;

typedef std::string node;
struct edge{
    node dest;
    int weight;
    bool operator < (const edge &rhs) {
        return weight > rhs.weight;
    }
};
struct edgeS{
    node curr;
    node dest;
    int weight;
    bool operator < (const edgeS &rhs) {
        return weight > rhs.weight;
    }
};

class graphalgs {
 private:
    std::map <node, std::vector<edge>> graphM;
 public:
    void add_edge(node node1, node node2, int distance);
    void dijkstra(node firstNode);
    void kruskal();
};

// adds two nodes that are directly connected and their distances
// all edges will be added before dijkstra and kruskal are called
void graphalgs::add_edge(node node1, node node2, int distance) {
    edge Temp;
    Temp.dest = node2;
    Temp.weight = distance;
    graphM[node1].push_back(Temp);
    Temp.dest = node1;
    graphM[node2].push_back(Temp);
}

// Calculates the minimum distance from the <sourceNode>
// to all other nodes and prints
void graphalgs::dijkstra(node sourceNode) {
    int first = 0;
    heap <edge>order;
    std::map<node, int> distance;
    edge temp1, temp2;
    temp1.dest = sourceNode;
    temp1.weight = 0;
    order.push(temp1);
    for(auto i:graphM){
        cout<<i.first<<": ";
        for(auto p:i.second){
            cout<<"("<<p.dest<<", "<<p.weight<<"), ";
        }
        cout<<endl;
    }
    // set all of the distances to the vertecis to a large numbrer
    for (auto& i:graphM) {
        distance[i.first] = 100000000;
    }
    // checks if the new distance to the verteci is smaller than the distance that is already there if it is smaller then it changes the distance to the new value.
    while (!order.empty()) {
        temp2 = order.front();
        order.pop();
        for (int o = 0; o<graphM[temp2.dest].size(); o++) {
            if (temp2.weight + graphM[temp2.dest][o].weight < distance[graphM[temp2.dest][o].dest]) {
                distance[graphM[temp2.dest][o].dest] = temp2.weight + graphM[temp2.dest][o].weight;
                edge temp1{graphM[temp2.dest][o].dest, 
                        distance[graphM[temp2.dest][o].dest]};
                        cout<<"temp: "<<temp2.dest<<endl;
                        //cout<<graphM[temp2.dest]<<endl;
                        cout<<"graphM: "<<graphM[temp2.dest][o].dest<<endl;
                order.push(temp1);
            }
        }
    }
    
    // prints the distances out
    for (auto& i:distance) {
        if (first < 1) {
            cout<<"Dijkstra (from "<<sourceNode<<")"<<endl;
        }
        if (i.first != sourceNode) {
            cout<<i.first<<": "<<i.second<<endl;
        }
        first++;
    }
    cout<<endl;
}

//does not always work kruskal need to be worked on

// Generates a minimum spanning tree and prints
// I Understood how to find a cycle but would not figure out how to fix it so I did my best to find the find it other ways in got it to work for some of them.
void graphalgs::kruskal() {
    int total = 0;
    heap <edgeS>edges;
    heap <edge>order;
    vector<edgeS> edgesSort;
    vector<node> visited;
    std::map<node, int> distance;
    std::map<node, int> distanceK;
    std::map<node, std::vector<edge>> graphK;
    edgeS temp1, temp2;
    edge tempE1, tempE2;
    edgeS current, parent, Temp;
    
    // sorts the graph
    for (auto k:graphM) {
        for (auto e:k.second) {
            temp1.curr = k.first;
            temp1.dest = e.dest;
            temp1.weight = e.weight;
            edges.push(temp1);
        }
    }
    
    //puts it in a vector
    while (!edges.empty()) {
        temp2 = edges.front();
        edges.pop();
        edgesSort.push_back(temp2);
    }
    
    //removes edges that are the same
    for (auto i:edgesSort) {
        for (int p = 0; p<edgesSort.size(); p++) {
            temp1 = i;
            temp2 = edgesSort[p+1];
            if (temp1.curr == temp2.dest) {
                if (temp1.dest == temp2.curr) {
                    if (temp1.weight == temp2.weight) {
                        edgesSort.erase(edgesSort.begin()+(p+1));
                    }
                }
            }
        }
    }
    tempE1.dest = edgesSort[0].curr;
    tempE1.weight = 0;
    order.push(tempE1);
    for (auto& i:graphM) {
        distance[i.first] = 100000000;
    }
    
    // Is suposed to get rid of cycles but I was not able to get it to work in time to turn it in.
    while (!order.empty()) {
        tempE2 = order.front();
        order.pop();
        for (int o = 0; o <graphM[tempE2.dest].size(); o++) {
            if (tempE2.weight + graphM[tempE2.dest][o].weight < distance[graphM[tempE2.dest][o].dest]) {
                // chacks if the node is connected already based on if the dijkstra algerithm would have already put in a value for distance. Then it is suposed to remove the larger edge, but it dose not work
                if (distance[graphM[tempE2.dest][o].dest]<100000000) {
                    for (int p = 0; p<edgesSort.size(); p++) {
                        if (distanceK[graphM[tempE2.dest][o].dest] == edgesSort[p].weight) {
                            edgesSort.erase(edgesSort.begin()+p);
                        }
                    }
                }
                distanceK[graphM[tempE2.dest][o].dest] = graphM[tempE2.dest][o].weight;
                distance[graphM[tempE2.dest][o].dest] = tempE2.weight + graphM[tempE2.dest][o].weight;
                tempE1 = {graphM[tempE2.dest][o].dest, distance[graphM[tempE2.dest][o].dest]};
                order.push(tempE1);
            }
        }
    }
    
    if (!edgesSort.empty()) {
        cout<<"kruskal"<<endl;
        for (auto k:edgesSort) {
            total += k.weight;
            std::cout<<k.curr<<", "<<k.dest<<", "<<k.weight<<endl;
        }
        cout<<"total weight = "<<total<<endl;
    }
    cout<<endl;
}
