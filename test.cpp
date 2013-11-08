#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<climits>
using namespace std;
const int INF = INT_MAX;

int index(char buf[], int houseNum)
{
    if(buf[0] == 'G')
        return atoi(buf+1) + houseNum - 1;
    else
        return atoi(buf) - 1;
}

//以src为起点的单源最短路径
void Dijkstra(int src, int dist[], int **graph, int n)
{
    bool *used = new bool[n];
    for(int i = 0; i < n; i++)
        {dist[i] = graph[src][i]; used[i] = false;}
    for(int i = 1; i < n; i++)
    {
        int tmin = INF,k;
        for(int j = 0; j < n; j++)
            if(!used[j] && tmin > dist[j])
            {
                tmin = dist[j];
                k = j;
            }
        used[k] = true;
        for(int j = 0; j < n; j++)
            if(dist[k] != INF && graph[k][j] != INF &&
               dist[k] + graph[k][j] < dist[j])
            {
                dist[j] = dist[k] + graph[k][j];
            }
    }
    delete used;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int houseNum, stationNum,roadNum,range;
    scanf("%d%d%d%d", &houseNum, &stationNum, &roadNum, &range);
    const int nodeNum = houseNum + stationNum;
    int **graph = new int*[nodeNum];
    for(int i = 0; i < nodeNum; i++)
    {
        graph[i] = new int[nodeNum];
        for(int j = 0; j < nodeNum; j++)
            graph[i][j] = (i != j ? INF:0);
    }
    for(int i = 0; i < roadNum; i++)
    {
        char buf[10];
        scanf("%s", buf); int a = index(buf, houseNum);
        scanf("%s", buf); int b = index(buf, houseNum);
        scanf("%d", &graph[a][b]);
        graph[b][a] = graph[a][b];
    }

    double minDistance = -1.0, averageDistance = INF;
    int Selectstation = -1;
    int dist[nodeNum];
    for(int i = houseNum; i < nodeNum; i++)
    {
        Dijkstra(i, dist, graph, nodeNum);
        double mindis = INF, averdis = 0.0;
        bool flag = true;
        for(int j = 0; j < houseNum; j++)
        {
            if(dist[j] > range){flag = false; break;}
            averdis += dist[j];
            if(dist[j] < mindis)mindis = dist[j];
        }
        if(flag == false)continue;
        averdis /= houseNum;
        if(mindis > minDistance)
        {
            minDistance = mindis;
            averageDistance = averdis;
            Selectstation = i;
        }
        else if(mindis == minDistance)
        {
            if(averdis < averageDistance)
            {
                averageDistance = averdis;
                Selectstation  = i;
            }
        }
    }
    if(Selectstation != -1)
        printf("G%d\n%.1f %.1f\n", Selectstation+1-houseNum, minDistance,
                averageDistance);
    else printf("No Solution\n");
    return 0;
}