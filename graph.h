#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>
#define INT_MAX		2147483647

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Graph
{
public:
    Graph();
    void Dijkstra(int graph[10][10],int src);
    int minimumDist(int dist[], bool Tset[]);

private slots:
    void on_pushButton_clicked();

private :

 Ui::MainWindow *ui;

};

#endif // GRAPH_H
