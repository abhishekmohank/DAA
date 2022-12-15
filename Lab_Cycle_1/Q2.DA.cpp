#include<iostream>
using namespace std;
int visited[10];
void bfs(int n,int a[10][10],int source)
{
    int i,q[10],u,front=1,rear=1;
    visited[source]=1;
    q[rear]=source;
    while(front<=rear)
    {
        u=q[front];
        front++;
        for(i=1;i<=n;i++)
            if(a[u][i]==1 && visited[i]==0)
            {
                rear++;
                q[rear]=i;
                visited[i]=1;
            }

    }
}
int main()
{
    int n,a[10][10],i,j,source;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    cout<<"Enter the adjacency matrix :\n";
    for(i=1;i<=n;i++)   
        for(j=1;j<=n;j++)
            cin>>a[i][j];
    cout<<"Enter the source : ";
    cin>>source;
    for(i=1;i<=n;i++)
        visited[i]=0;
    bfs(n,a,source);
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
            cout<<"The node "<<i<<" is NOT reachable.\n";
        else
            cout<<"The node "<<i<<" is reachable.\n";

    }
    return 0;
}