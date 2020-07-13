#include <bits/stdc++.h>
#define N 8
#define M 14 
using namespace std;
bool visited[N][M]={false};

bool S_D_func(int mapp[N][M],int xo,int yo,int xd,int yd,vector<int>& pos1,vector<int>& pos2,string& path, bool visited[N][M]);


/*To check that the given point is within bounds and not an obstacle=0*/

bool IsSafe(int x, int y, int s[N][M], bool visited[N][M])
{
    if(x>=0 && x<N && y>=0 && y<M && s[x][y]==1 && visited[x][y]==false)
    {
    
     return true;
    }
    return false;
}

/*Function in which finds the path. Sol will be the final matrix showing the path followed*/

bool S_D(int s[N][M], int x, int y, int xd,int yd, bool visited[N][M])
{
    
    string path; 
    vector<int> pos1; 
    vector<int> pos2;
    if(S_D_func(s,x,y,xd,yd,pos1,pos2,path,visited)==false)
    {
        cout<<"No solution"<<endl;
        return false;
    }
   for (int i = 0; i < path.size(); i++) 
        {
        cout<<"("<<pos1[i]<<",";
        cout<<pos2[i]<<",";
        cout << path[i]<<")"; 
        if(i!=(path.size()-1))
        cout<<"-->";
        }
return true;
}

/*Recursive function for finding the feasible path*/

bool S_D_func(int mapp[N][M],int xo,int yo,int xd,int yd,vector<int>& pos1,vector<int>& pos2, string& path, bool visited[N][M])
{ 
    
    if (xo==xd && yo==yd && mapp[xo][yo]==1)
    {
    path.push_back('F');
    pos1.push_back(xo);
    pos2.push_back(yo);
    visited[xo][yo]=true;
    return true;
    }

    if(IsSafe(xo,yo,mapp, visited)==true)
    {
    visited[xo][yo]=true;
    


     if(IsSafe(xo+1,yo,mapp, visited)==true){
      pos1.push_back(xo);
    pos2.push_back(yo);
     path.push_back('D');
    if(S_D_func(mapp,xo+1,yo,xd,yd,pos1,pos2,path,visited)==true)
    return true;
    pos1.pop_back();
    pos2.pop_back();
    path.pop_back();
    }
   
     if(IsSafe(xo-1,yo,mapp, visited)==true){
      pos1.push_back(xo);
    pos2.push_back(yo);
     path.push_back('U');
    if(S_D_func(mapp,xo-1,yo,xd,yd,pos1,pos2,path,visited)==true)
    return true;
    pos1.pop_back();
    pos2.pop_back();
    path.pop_back();
    }
   
     if(IsSafe(xo,yo+1,mapp, visited)==true){
     pos1.push_back(xo);
    pos2.push_back(yo);
     path.push_back('R');
    if(S_D_func(mapp,xo,yo+1,xd,yd,pos1,pos2,path,visited)==true)
    return true;
    pos1.pop_back();
    pos2.pop_back();
    path.pop_back();
    }
   
     if(IsSafe(xo,yo-1,mapp, visited)==true){
     pos1.push_back(xo);
    pos2.push_back(yo);
     path.push_back('L');
    if(S_D_func(mapp,xo,yo-1,xd,yd,pos1,pos2,path,visited)==true)
    return true;
    pos1.pop_back();
    pos2.pop_back();
    path.pop_back();
    }
    
   
    return false;
    }


   
    return false;
}
    
/*mapp is the given map with 0's as obstacles and 1 as free path*/








int main()
{
    int mapp[N][M]={{1,1,1,1,1,1,1,1,1,1,1,1,1,0},{1,0,1,1,0,1,1,0,1,0,1,1,1,1},{1,1,1,1,1,1,1,1,0,1,1,1,0,1},{1,0,0,1,0,1,1,1,1,0,1,1,1,1},{0,1,1,1,1,1,0,1,1,1,1,1,1,1},{1,1,1,0,1,1,1,1,0,1,1,0,1},{1,1,1,1,0,1,1,0,1,1,1,1,1,1},{1,1,1,0,1,1,1,0,1,1,1,1,1,1}};
    int xo,yo,xd,yd;
    cout<<"Enter starting points x and y:"<<endl;
    cin>>xo>>yo;
    cout<<"Enter destination:"<<endl;
    cin>>xd>>yd;
    cout<<endl<<"Final solution path to destination:"<<endl<<endl;
    S_D(mapp,xo,yo,xd,yd,visited);

    return 0;
}

