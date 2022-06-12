/*
https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1/?page=1&company[]=Google&sortBy=submissions#
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.
*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int currPetrol = 0, dist = 0;
       int index = 0;
       int deff = 0;
       for(int i=0;i<n;i++)
       {
           currPetrol+=p[i].petrol - p[i].distance;
           if(currPetrol<0)
           {
               deff+=currPetrol;
               currPetrol = 0;
               index = i+1;
           }
       }
       return (currPetrol + deff < 0 ) ? -1 : index;
    }
};
