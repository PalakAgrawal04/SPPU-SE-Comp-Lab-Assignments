//Prims Algorithm - Minimum Spanning Tree Algorithm

//GRAPH using adjacency matrix

#include <iostream>
using namespace std;

class graph
{
    //for dynamic allocation 
    //creating pointers
    int **head;
    string *places;
    int n;
    
    public:
    graph()
    {
        cout<<"---------GRAPH CREATION---------"<<endl;
        int x;
        cout<<"Enter no. of vertices: ";
        cin>>x;
        if(x<=1)
        {
            cout<<"Invalid Input, Graph creation creation unsuccessful"<<endl;
            return;
        }
        
        //create graph matrix and places array
        //and initialise all to 0
        n = x;
        head = new int *[n];
        places =  new string[n];
        
        for (int i=0;i<n;i++)
        {
            //create rows
            head[i] = new int[n];
            for(int j=0; j<n; j++)
            {
                head[i][j] = 0;
            }
        }
        
        //create graph function
        create_graph();
    }
    
    int getIndex(string place)
    {
        for(int i=0;i<n;i++)
        {
            if(places[i]==place)
            {
                return i;
            }
        }
        return -1;
    }
    
    void add_edge(int origin, int dest, int cost)
    {
        //undirected graph 
        //add edge
            head[origin][dest] = cost;
            head[dest][origin] = cost;
        
    }
    
    void create_graph()
    {
        string src, dest;
        int weight;
        int destId, srcId;
         
        //enter all cities(vertices)
        for (int i=0; i<n;i++)
        {
            cout<<"Enter cities (vertices): ";
            cin>>src;
            
            //check if src is present in array of cities
            // int found = getIndex(src);
            // if(found == -1)
            // {
                places[i] = src;
            // }
            // else
            // {
            //     cout<<"vertex already exists, try again"<<endl;
            //     i = i-1;
            //     continue;
            // }
        }
        
        cout<<"All locations entered"<<endl;
         
        //------------add edges---------------
        
        for(int i = 0; i<n;i++)
        {
            int y;
            cout<<"Enter the no. of connected cities for "<<places[i]<<" :";
            cin>>y;
            if (y>((n*(n-1))/2) || y<=0)
            {
                cout<<"Invalid no. of edges, Graph creation unsuccessful"<<endl;
                break;
            }
            
            for (int j=0; j<y;j++)
            {
                //take weight and destinaion city
                cout<<"Enter the connected city(vertex) for "<<places[i]<<" :";
                cin>>dest;
                cout<<"Enter cost of connection: ";
                cin>>weight;
                
                //get indexes
                srcId = getIndex(places[i]);
                destId = getIndex(dest);
                
                // if(srcId == destId)
                // {
                //     cout<<"Destination cannot be same as Origin, try again."<<endl;
                //     j = j-1;
                //     continue;
                // }
                
                // if(srcId == -1 || destId == -1)
                // {
                //     cout<<"Destination doesn't exist, try again."<<endl;
                //     j = j-1;
                //     continue;                    
                // }
                
                add_edge(srcId, destId, weight);
            }
            
        }
        
        display();
    }
    
    void display()
    {
        for(int i=0;i<n;i++)
        {
            cout<<places[i]<<" :    ";
            for(int j=0;j<n;j++)
            {
                cout<<"("<<places[j]<<", "<<head[i][j]<<")"<<"  ";
            }
            cout<<endl;
        }
    }
    
    //Prim's Algorithm
    //requires:
    //1.minKey - to get index of minimum key in the key array
    //key array - stores the min. weights of connections
    //2. printMST - to print the min. cost & MST
    
    int minKey(int key[],int mstSet[]) //to return index of min cost connection
    {
        int min=999, min_index;
        for(int i=0;i<n;i++)
        {
            //search for min cost vertex in the key array and its index
            if(mstSet[i]==0 && key[i]<min)
            {
                min = key[i]; //update min
                min_index = i; //update index of min cost
            }
        }
        
        return min_index;
    }
    
    void printMST(int parent[])
    {
        int cost = 0;
        cout<<"Minimum Spanning Tree is: "<<endl;
        cout<<"Edge\t\tCost "<<endl;
        for(int i=1;i<n;i++)
        {
            cost+=head[i][parent[i]];
            cout<<places[i]<<" - "<<places[parent[i]]<<"\t\t"<<head[i][parent[i]]<<endl;
        }
        cout<<"Total Cost is: "<<cost<<endl;
    }
    
    void primsAlgo()
    {
        //declare arrays for state of MST
        int key[n]; //recording min. weights of connections
        int mstSet[n]; //recording if the vertex is visited or not
        int parent[n]; //recording the column index of vertex with min. weight
        
        //initialise key and mstSet
        for(int i=0;i<n;i++)
        {
            key[i] = 999;
            mstSet[i] = 0;
        }
        
        //start with 1st index
        
        key[0] = 0;
        parent[0] = -1;
        
        for(int count = 0;count<n-1; count++)
        {
            //this returns the index of min key in key array
            int u = minKey(key,mstSet); 
            
            mstSet[u] = 1; //shows that the min. index is visited
            
            for(int i=0;i<n;i++)
            {
                if(mstSet[i]==false && head[u][i]<key[i])
                {
                    //update the key array with min costs
                    //update parent array with column index of min costs
                    key[i] = head[u][i];
                    parent[i] = u;
                }
            }
        }
        
        printMST(parent);
    }
};

int main()
{
    graph g1;
    g1.primsAlgo();
    return 0;
}