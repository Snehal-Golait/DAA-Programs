#include<iostream>

using namespace std;
#define max 100
#define initial 1
#define visited 2
int n;
 int adj[max][max];
 int state [max];
 
 void df_traversal();
 void dfs (int v);
 void creat_graph();
 int stack[max];
 int top=-1;
 void push(int v);
 int pop();
 int is_emptystack();
 
 int main()
 {
    creat_graph();
    df_traversal();
    return 0;
  }
  
void df_traversal()
{
  int v;
  for (v=0;v<n;v++)
     state[v]=initial;
  cout<<"Enter the starting  node for DFS traversal:";
  cin>>v;
  dfs(v);
}

void dfs(int v)
{
  int i;
   push(v);
   while(!is_emptystack())
   {
      v=pop();
      if (state[v]==initial)
       {
          cout<<v<<" ";
          state[v]=visited;
       }
       for(i=n-1;i>=0;i--)
        {
          if(adj[v][i]==1&&state[i]==initial)
                 push(i);
        }
    }
 }
 void push(int v)
 {
    if(top==(max-1))
     {
       cout<<"stack overflow\n";
          return;
      }
     top=top+1;
     stack[top]=v;
 }
 int pop()
{
  int v;
  if (top==-1)
  {
     cout<<"stack underflown\n";
     exit(1);
   }
   else
   {
      v=stack[top];
      top=top-1;
      return v;
   }
}
int is_emptystack()
{
    if(top==-1)
        return 1;
    else
         return 0;
}
void creat_graph()
{
  int i,max_e,o,d;
  cout<<"Enter the no. of nodes:";
  cin>>n;
  max_e=n*(n-1);
  
  for(i=0;i<max_e;i++)
  {
      cout<<"Enter edge"<<i<<"(-1-1 for quit):";
      cin>>o>>d;
      if((o==-1)&&(d==-1))  
         break;
      if(o>=n||d>=n||o<0||d<0)
       {
          cout<<"Invalid edge";
          i--;
        }
       else
          adj[o][d]=1;
    }
}
 
 /*OUTPUT:
 Enter the no. of nodes:10
Enter edge0(-1-1 for quit):0 1
Enter edge1(-1-1 for quit):0 3
Enter edge2(-1-1 for quit):1 2
Enter edge3(-1-1 for quit):2 3
Enter edge4(-1-1 for quit):1 5
Enter edge5(-1-1 for quit):1 4
Enter edge6(-1-1 for quit):2 5
Enter edge7(-1-1 for quit):3 6
Enter edge8(-1-1 for quit):4 7
Enter edge9(-1-1 for quit):5 6
Enter edge10(-1-1 for quit):5 7
Enter edge11(-1-1 for quit):6 9
Enter edge12(-1-1 for quit):7 8
Enter edge13(-1-1 for quit):8 9
Enter edge14(-1-1 for quit):-1 -1
Enter the starting  node for DFS traversal:0
0 1 2 3 6 9 5 7 8 4
*/
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
           
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
                 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
     
 
