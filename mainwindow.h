#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Edge {
    int source, dest, weight;
};

class MainWindow : public QMainWindow // class main de mon ihm
{
    Q_OBJECT

public:


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //methode pour algo de dijkstra
    void Dijkstra(int graph[10][10],int src, int end);
    int minimumDist(int dist[], bool Tset[]);
    //methode pour algo de Prim
    int minKey(int key[], bool mstSet[]);
    void primMST(int graph[10][10], int end, int depart);




private slots:



    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:


    int lille;
    int paris;
    int rennes;
    int strasbourg;
    int nantes;
    int lyon;
    int bordeaux;
    int toulouse;
    int marseille;
    int nice;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
