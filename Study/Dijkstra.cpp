#define INF 1000000000
#define N 10

int g[N][N];
int dist[N];
int marc[N];
int prev[N];
 
void dijkstra(int a) {
    // Coloca a distância de todos os vértices até o vértice "a" em dist.
    // prev é o vetor de predecessores
    for (int i = 0; i < N; i++) dist[i] = INF;
    dist[a] = 0;
   
    int curr = a;
    while (curr != -1) {
        marc[curr]=1;
       
        for (int i = 0; i < N; i++) {
            if (g[curr][i] && dist[curr]+g[curr][i] < dist[i]) {
                dist[i] = dist[curr]+g[curr][i];
                prev[i] = curr;
            }
        }
       
        curr=-1;
        int min_dist = INF;
        for (int i = 0; i < N; i++) {
            if (!marc[i] && dist[i] < min_dist) {
                curr = i;
                min_dist = dist[i];
            }
        }        
    }
}