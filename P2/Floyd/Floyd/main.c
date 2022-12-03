//
//  main.c
//  Floyd
//
//  Created by Leonardo Alejandro González López on 17/10/21.
//  Copyright © 2021 UASLP. All rights reserved.
//

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
// Number of vertices in the graph
#define V 10

/* Define Infinite as a large enough
value. This value will be used
for vertices not connected to each other */
#define INF 99999

// A function to print the solution matrix
void printSolution(int dist[][V]);
void floyd (int graph[][V]);
void fillGraph(int graph[][V]);
void printGraf(int graph[][V]);

int main(){
//    int graph[V][V] = { {0, 5, INF, 10},
//                        {INF, 0, 3, INF},
//                        {5, INF, 0, 1},
//                        {INF, INF, INF, 0}
//                    };
    clock_t t_ini, t_end;
    double t_elapsed;
    t_ini = clock();
    int graph[V][V];
    fillGraph(graph);
    //WARNING ONLY FOR SMALL V VALUES
    printGraf(graph);
    printf("\n\n");
    // Print the solution
    floyd(graph);
    t_end = clock() - t_ini;
    t_elapsed = ((double)t_end)/CLOCKS_PER_SEC;
    printf("\nTotal time: %f segs\n", t_elapsed);
    return 0;
}

/* A utility function to print solution */
void printSolution(int dist[][V]){
    printf ("The following matrix shows the shortest distances between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%5s", "INF");
            else
                printf ("%5d", dist[i][j]);
        }
        printf("\n");
    }
}

void floyd (int graph[][V]){
    
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            
            for (j = 0; j < V; j++)
            {
               
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    // WARNING ONLY FOR SMALL V VALUES
    printSolution(dist);
}
void fillGraph(int graph[][V]){
    
    srand((unsigned)time(NULL));
    int i, j, aux;
    
    for (i=0; i<V; i++) {
        for (j=0; j<V; j++) {
            if (i==j) {
                graph[i][j]=0;
            }else{
                aux = 1+rand()%30;
                if (aux%5 == 0) {
                    graph[i][j]=INF;
                }else{
                    graph[i][j] = aux;
                }
            }
        }
    }
}

void printGraf(int graph[][V]){
    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            if (graph[i][j] == INF)
                printf("%5s", "INF");
            else
                printf ("%5d", graph[i][j]);
        }
        printf("\n");
    }
}
