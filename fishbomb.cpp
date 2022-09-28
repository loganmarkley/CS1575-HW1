//Programmer: Logan Markley
//Student ID: 12579435
//MST Username: lcmkbc
//Section: 101
//Date: 9/28/22
//File: fishbomb.cpp
//Purpose: dynamically allocated arrays (HW 1 - CS 1575)

#include <iostream>
using namespace std;

struct Coordinate{
    int row, col;
    Coordinate()
    {
        row=0;
        col=0;
    }
};

//Description: given a 2D dynamically allocated array and its size, use getTotalFish() to find the Coordinate which yields the most fish
Coordinate findBestFishSpot(int** grid, const int totalRows, const int totalCols);

//Description: given a 2D dynamically, its size, and a Coordinate in the grid, adds up the total number of fish in the entire row and entire column that spot is located at.
int getTotalFish(int** grid, Coordinate spot, const int totalRows, const int totalCols);

int main()
{
    int numTestCases;
    cin >> numTestCases;
    
    for(int i=0; i<numTestCases; i++)
    {
        int totalRows, totalCols;
        cin >> totalRows >> totalCols;
        
        int** sonarDataGrid = new int*[totalRows];
        for(int i=0; i<totalRows; i++)                //creating the dynamic 2D array sonarDataGrid
        {
            sonarDataGrid[i] = new int[totalCols];
        }
        
        for(int i=0; i<totalRows; i++)               //filling sonarDataGrid with inputs
        {
            for(int j=0; j<totalCols; j++)
            {
                cin >> sonarDataGrid[i][j];
            }
        }
        
        Coordinate bestFishSpot = findBestFishSpot(sonarDataGrid, totalRows, totalCols);
        int biggestFishTotal = getTotalFish(sonarDataGrid, bestFishSpot, totalRows, totalCols);
        cout<<"#"<<i<<": at ("<<bestFishSpot.row<<","<<bestFishSpot.col<<") Bender catches "<<biggestFishTotal<<" fish."<<endl;
        
        for(int i=0; i<totalRows; i++)              //deallocate the 2D array
        {
            delete[] sonarDataGrid[i];
        }
        delete[] sonarDataGrid;
    }
    
    return 0;
}

Coordinate findBestFishSpot(int** grid, const int totalRows, const int totalCols)
{
    Coordinate bestSpot;
    for(int i=0; i<totalRows; i++)
    {
        for(int j=0; j<totalCols; j++)
        {
            Coordinate temp;
            temp.row = i;
            temp.col = j;
            if( getTotalFish(grid, bestSpot, totalRows, totalCols) < getTotalFish(grid, temp, totalRows, totalCols) )
            {
                bestSpot.row = temp.row;
                bestSpot.col = temp.col;
            }
        }
    }
    return bestSpot;
}

int getTotalFish(int** grid, Coordinate spot, const int totalRows, const int totalCols)
{
    int totalFish = 0;
    for(int i=0; i<totalRows; i++)
    {
        totalFish+=grid[i][spot.col];
    }
    for(int i=0; i<totalCols; i++)
    {
        totalFish+=grid[spot.row][i];
    }
    totalFish-=grid[spot.row][spot.col];     //to compensate for the duplicate addition
    return totalFish;
}
