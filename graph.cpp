#include "graph.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"



Graph::Graph()
{

    //init de mon graph
            int  graph[10][10]={
            {0, 350, 200, 150, 0, 0, 0, 0, 0, 0},
            {350, 0, 0, 0, 100, 0, 0, 0, 0, 0},
            {200, 0, 0, 200, 400, 0, 0, 0, 300, 0},
            {150, 0, 200, 0, 0, 0, 0, 0, 300, 0},
            {0, 100, 400, 0, 0, 200, 0, 0, 0, 0},
            {0, 0, 0, 0, 200, 0, 150, 0, 0, 0},
            {0, 0, 0, 0, 0, 150, 0, 200, 0, 0},
            {0, 0, 0, 0, 0, 0, 200, 0, 300, 200},
            {0, 0, 300, 300, 0, 0, 0, 300, 0, 250},
            {0, 0, 0, 0, 0, 0, 0, 200, 250, 0}};
}

void Graph::Dijkstra(int graph[10][10],int src)
{

        int dist[6]; // integer array to calculate minimum distance for each node.
        bool Tset[6];// boolean array to mark visted/unvisted for each node.

        // set the nodes with infinity distance
        // except for the initial node and mark
        // them unvisited.
        for(int i = 0; i<6; i++)
        {
            dist[i] = INT_MAX;
            Tset[i] = false;
        }

        dist[src] = 0;   // Source vertex distance is set to zero.

        for(int i = 0; i<6; i++)
        {
            int m=minimumDist(dist,Tset); // vertex not yet included.
            Tset[m]=true;// m with minimum distance included in Tset.
            for(int i = 0; i<6; i++)
            {
                // Updating the minimum distance for the particular node.
                if(!Tset[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i])
                    dist[i]=dist[m]+graph[m][i];
            }
        }



        for(int i = 0; i<6; i++)
        { //Printing
            char str=65+i; // Ascii values for pritning A,B,C..

           // cout<<str<<"\t\t\t"<<dist[i]<<endl;
            ui->textBrowser->setText(QString::number(dist[i]));
        }
}
int Graph::minimumDist(int dist[], bool Tset[])
{
    int min=INT_MAX,index;

        for(int i=0;i<10;i++)
        {
            if(Tset[i]==false && dist[i]<=min)
            {
                min=dist[i];
                index=i;
            }
        }
        return index;
}

void Graph::on_pushButton_clicked()
{

}

