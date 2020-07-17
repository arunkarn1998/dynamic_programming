#include<bits/stdc++.h>
using namespace std;
int dp[102][102];

int knapsack(int weight[],int value[],int capacity,int n)
    {



        if(capacity==0||n==0)
            return 0;
        if(weight[n-1]>capacity)
            return knapsack(weight,value,capacity,n-1);
        if(dp[n-1][capacity]!=-1)
            return dp[n-1][capacity];
        if (weight[n-1]<=capacity)
            return dp[n-1][capacity]=max(value[n-1]+knapsack(weight,value,capacity-weight[n-1],n-1),knapsack(weight,value,capacity,n-1));
    }
int main()
    {
        int n,weight[102],value[102],capacity;

        cin>>n>>capacity;
         for(int i=0;i<n;i++)
            for(int j=0;j<capacity+1;j++)
                dp[i][j]=-1;

        for(int i=0;i<n;i++)
        {
            cin>>weight[i];
        }

         for(int i=0;i<n;i++)
        {
            cin>>value[i];
        }

        knapsack(weight,value,capacity,n);
        cout<<dp[n-1][capacity];
        return 0;
    }
