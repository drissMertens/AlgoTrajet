#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QDebug>
 #include <time.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //png carte
    ui->label_3->setPixmap(QPixmap("C:\\Users\\driss\\Documents\\ProjetAlgo\\ressource\\image.png"));
    ui->label_3->show();
    ui->label_4->setPixmap(QPixmap("C:\\Users\\driss\\Documents\\ProjetAlgo\\ressource\\bus.png"));
    ui->label_4->show();
     ///////////////////////////////////////////////////////////DIKJSTRA////////////////////////////////////////////
    //data des villes de transport pour le Départ
    ui->comboBoxSrc->addItem("lille",0);
    ui->comboBoxSrc->addItem("rennes",1);
    ui->comboBoxSrc->addItem("paris",2);
    ui->comboBoxSrc->addItem("strasbourg",3);
    ui->comboBoxSrc->addItem("nantes",4);
    ui->comboBoxSrc->addItem("bordeaux",5);
    ui->comboBoxSrc->addItem("toulouse",6);
    ui->comboBoxSrc->addItem("marseille",7);
    ui->comboBoxSrc->addItem("lyon",8);
    ui->comboBoxSrc->addItem("nice",9);

    //data des villes de transport pour l'arrivé
    ui->comboBoxEnd->addItem("lille",0);
    ui->comboBoxEnd->addItem("rennes",1);
    ui->comboBoxEnd->addItem("paris",2);
    ui->comboBoxEnd->addItem("strasbourg",3);
    ui->comboBoxEnd->addItem("nantes",4);
    ui->comboBoxEnd->addItem("bordeaux",5);
    ui->comboBoxEnd->addItem("toulouse",6);
    ui->comboBoxEnd->addItem("marseille",7);
    ui->comboBoxEnd->addItem("lyon",8);
    ui->comboBoxEnd->addItem("nice",9);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


     ///////////////////////////////////////////////////////////Prim////////////////////////////////////////////
    //data des villes de transport pour le Départ
    ui->comboBoxSrc1->addItem("lille",0);
    ui->comboBoxSrc1->addItem("rennes",1);
    ui->comboBoxSrc1->addItem("paris",2);
    ui->comboBoxSrc1->addItem("strasbourg",3);
    ui->comboBoxSrc1->addItem("nantes",4);
    ui->comboBoxSrc1->addItem("bordeaux",5);
    ui->comboBoxSrc1->addItem("toulouse",6);
    ui->comboBoxSrc1->addItem("marseille",7);
    ui->comboBoxSrc1->addItem("lyon",8);
    ui->comboBoxSrc1->addItem("nice",9);

    //data des villes de transport pour l'arrivé
    ui->comboBoxEnd1->addItem("lille",0);
    ui->comboBoxEnd1->addItem("rennes",1);
    ui->comboBoxEnd1->addItem("paris",2);
    ui->comboBoxEnd1->addItem("strasbourg",3);
    ui->comboBoxEnd1->addItem("nantes",4);
    ui->comboBoxEnd1->addItem("bordeaux",5);
    ui->comboBoxEnd1->addItem("toulouse",6);
    ui->comboBoxEnd1->addItem("marseille",7);
    ui->comboBoxEnd1->addItem("lyon",8);
    ui->comboBoxEnd1->addItem("nice",9);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //init des villes
     lille = 0;
     paris = 2;
     rennes = 1;
     strasbourg = 3;
     nantes = 4;
     lyon = 8;
     bordeaux = 5;
     toulouse = 6;
     marseille = 7;
     nice = 9;





}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Dijkstra(int graph[10][10],int src, int end)
{

        int dist[10]; // int tab pour calculer la dist min pour chaque noeud.
        bool Tset[10];// boolean array to mark visted/unvisted for each node.

        // set the nodes with infinity distance
        // except for the initial node and mark
        // them unvisited.
        for(int i = 0; i<10; i++)
        {
            dist[i] = INT_MAX;
            Tset[i] = false;
        }

        dist[src] = 0;   // Source vertex distance is set to zero.

        for(int i = 0; i<10; i++)
        {
            int m=minimumDist(dist,Tset); // vertex not yet included.
            Tset[m]=true;// m with minimum distance included in Tset.
            for(int i = 0; i<10; i++)
            {
                // Update la distance min pour un noeux particulier
                if(!Tset[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i])
                    dist[i]=dist[m]+graph[m][i];
            }
        }


    ui->lcdNumber->display(dist[end]);

}
int MainWindow::minimumDist(int dist[], bool Tset[])
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


int MainWindow::minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < 10; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}



void MainWindow::primMST(int graph[10][10], int end, int depart)
{
    int parent[10];
    int key[10];
    bool mstSet[10];

    for (int i = 0; i < 10; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = 0;

    for (int count = 0; count < 10 - 1; count++)
    {

        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < 10; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }



    parent[depart] = depart;
    ui->lcdNumber1->display(graph[end][parent[depart]]);
    qDebug() <<parent[depart];
    qDebug() <<parent[depart]<<" - "<<end<<" \t"<<graph[end][parent[depart]]<<" \n";


}


void MainWindow::on_pushButton_2_clicked()
{
    int depart;
    int arrive;

    //recuperation de mes value du combobox pour les para de l'algo de dijsktra
    depart = ui->comboBoxSrc1->currentIndex();
    arrive = ui->comboBoxEnd1->currentIndex();



        //init de mon graph
        int graph[10][10]={
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
        qDebug() <<" depart :  "<<depart<<" \n";
        qDebug() <<" arriver :  "<<arrive<<" \n";
        primMST(graph,arrive,depart);
}


void MainWindow::on_pushButton_clicked()
{
    int depart;
    int arrive;
    //temps de calcul algo Dikjstra

    time_t debut, fin;
    float duree;
    debut=time(NULL);
    //recuperation de mes value du combobox pour les para de l'algo de dijsktra
    depart = ui->comboBoxSrc->currentIndex();
    arrive = ui->comboBoxEnd->currentIndex();
    //init de mon graph
    int graph[10][10]={
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

    Dijkstra(graph,depart,arrive);
    fin=time(NULL);
    duree=difftime(fin, debut);
    //ui->label_11->setText()
    qDebug() <<"temp :  "<<duree<<" \n";

}

