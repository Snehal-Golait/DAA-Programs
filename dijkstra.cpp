#include<iostream>
using namespace std;
# define max 100
# define temp 0
#define perm 1
# define infinity 9999
#define nil -1
void find_path(int s,int v);
void djkstra(int s);
int min_temp();
void creat_graph();

int n;
int adj[max][max];
int predecessor[max];
int pathlen[max];
int status[max];

int main()
{
  int s,v;
  creat_graph();
  cout<<"Enter source vertex:"<<endl;
  cin>>s;
  djkstra (s);
    
    while(1)
    {
      cout<<"enter destination vertex(-1 to quit):"<<endl;
      cin>> v;
      if(v==-1)
         break;
      if(v<0||v>=n)
       cout<<"vertex does not exists:;";
      else if(v==s)
        cout<<"source and destination vertices are same";
      else if(pathlen[v]==infinity)
        cout<<"there is no path from source to destination";
      else
       find_path(s,v);
     }
   return 0; 
 }
 void djkstra(int s)
 { int i, current;
   /* make all vertices temp*/
   for (i=0;i<n;i++)
    {
       predecessor[i]=nil;
       pathlen[i]=infinity;
       status[i]=temp;
    }
    /*make pathlen of source vertex 0 */
    pathlen[s]=0;
    while(1)
    {
      /*search of temp vertex having mini pathlen and make it current vertex*/
      current=min_temp();
      if (current==nil)
         return;
      status[current]=perm;
      for(i=0;i<n;i++)
       {
         if(adj[current][i]!=0 && status[i]==temp)
          if(pathlen[current]+adj[current][i]<pathlen[i])
            { 
               predecessor[i]=current;
               pathlen[i]=pathlen[current];
             }
       }
   }
 }
  int min_temp()
{
  int i;
  int min=infinity;
  int k=nil;
  for(i=0;i<n;i++)
   {
     if (status[i]==temp&& pathlen[i]<min)
     {
       min=pathlen[i];
       k=i;
      }
   }
  return k;
 }
 void find_path(int s,int v)
 {
    int i,u;
    int path[max];    /*stores the shortest path*/
    int shortdis=0;    /*lenth of shortest path*/
    int count=0;      /* no. of vertices in the shortest path */
    while(v!=s)       
    {
        count++;
        path[count]=v;
        u=predecessor[v];
        shortdis+=adj[u][v];
        v=u;
     }
     count++;
     path[count]=s;
     cout<<"shortest path is:"<<endl;
      for(i=count;i>=1;i--)
           cout<<path[i]<<endl;
      cout<<"shortest distance is :"<<shortdis<<endl;
 }
 void creat_graph()
 {
   int i,max_e,orign,dest,wt;
   cout<<"entr no of vertices:"<<endl;
   cin>>n;
   max_e=n*(n-1);
   for(i=1;i<=max_e;i++)
    {
       cout<<"enter edge"<<i<<"(-1-1 to quit):";
       cin>>orign>>dest;
       if((orign==-1)&&(dest==-1))
         break;
       cout<<"enter the weight of this edge:"<<endl;
       cin>>wt;
       if(orign>n||dest>=n||orign<0||dest<0)
        {
           cout<<"invalid edge!";
           i--;
        }
       else
          adj[orign][dest]=wt;
      }    
 }         
          
  
/*OUTPUT:
/tmp/fWT7BcTXkn.o
entr no of vertices:
8
enter edge1(-1-1 to quit):0 2
enter the weight of this edge:
2
enter edge2(-1-1 to quit):0 3
enter the weight of this edge:
7
enter edge3(-1-1 to quit):0 1
enter the weight of this edge:
8
enter edge4(-1-1 to quit):1 5
enter the weight of this edge:
16
enter edge5(-1-1 to quit):2 0
enter the weight of this edge:
5
enter edge6(-1-1 to quit):2 3
enter the weight of this edge:
4
enter edge7(-1-1 to quit):2 6
enter the weight of this edge:
3
enter edge8(-1-1 to quit):3 4
enter the weight of this edge:
9
enter edge9(-1-1 to quit):4 0
enter the weight of this edge:
4
enter edge10(-1-1 to quit):4 5
enter the weight of this edge:
5
enter edge11(-1-1 to quit):4 7
enter the weight of this edge:
8
enter edge12(-1-1 to quit):6 2
enter the weight of this edge:
6
enter edge13(-1-1 to quit):6 3
enter the weight of this edge:
3
enter edge14(-1-1 to quit):6 4
enter the weight of this edge:
4
enter edge15(-1-1 to quit):7 6
enter the weight of this edge:
5
enter edge16(-1-1 to quit):7 5
enter the weight of this edge:
2
enter edge17(-1-1 to quit):-1 -1
Enter source vertex:
0
enter destination vertex(-1 to quit):
6
shortest path is:
0
2
6
shortest distance is :5
enter destination vertex(-1 to quit):
-1













*/
    
       
           
     
 
