#include <iostream>

using namespace std;

int noOfNeighbours(bool a[3][3]) //function that counts how many live neighbours are in a 3x3 grid
{
    int c = 0;
    for(int h = 0; h < 3; h++)
    {
        for(int k = 0; k < 3; k++)
        {
            if(a[h][k]== true)
            {
                c = c +1;
            }
        }
    }
    if(a[1][1] == true) //if the cell is live we don't count it as a neighbour to its self
    {
        c = c - 1;
    }
    return c;
}

int checkScenario(bool a[3][3]) //function that checks which scenario a live cell is in
{
    int scenario = 0;
    if(a[1][1] == true && noOfNeighbours(a) < 2)
    {
        scenario = 1;
    }
    else if(a[1][1] == true && noOfNeighbours(a) > 3)
    {
        scenario = 2;
    }
    else if(a[1][1] == true && noOfNeighbours(a) == 2)
    {
        scenario = 3;
    }
    else if(a[1][1] == true && noOfNeighbours(a) == 3)
    {
        scenario = 3;
    }
    else if(a[1][1] == false && noOfNeighbours(a) == 3)
    {
        scenario = 4;
    }
    return scenario;
}


int main()
{
    int m;
    int n;
    int t;
    cout << "Please enter the size of the grid:" << endl;
    cout << "Number of rows: " ;
    cin >> m; //number of rows
    cout << "Number of columns: ";
    cin >> n; //number of columns
    cout << "Please enter the number of turns: ";
    cin >> t; //number of turns/iterations
    bool grid[m][n]; //set up grid of size user inputted
    for(int a = 0; a < m; a++)
    {

        for(int b = 0; b < n; b++)
        {
            grid[a][b] = false; //start with everything false
        }
    }
    //starting assumptions:
    grid[1][1] = true;
    grid[1][2] = true;
    grid[1][3] = true;
    int scenario;
    bool copyGrid[m][n]; //set up another grid of size user inputed so we don't change the original grid
    for(int e = 0; e < m; e++)
    {
        for(int f = 0; f < n; f++)
        {
            copyGrid[e][f] = false;//make sure we are changing the right array
        }
    }



    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            //new 3x3 grid to check how many neighbours a cell has
            bool newGrid[3][3] = {
            {grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1]},
            {grid[i][j-1], grid[i][j], grid[i][j+1]},
            {grid[i+1][j-1], grid[i+1][j], grid[i+1][j+1]}};

            if(i == 0 && j == 0)  //top left corner
            {
                newGrid[0][0] = false; newGrid[0][1] = false; newGrid[0][2] = false;
                newGrid[1][0] = false; newGrid[1][1] = grid[0][0]; newGrid[1][2] = grid[0][1];
                newGrid[2][0] = false; newGrid[2][1] = grid[1][0]; newGrid[2][2] = grid[1][1];
            }
            else if(i == m-1 && j == 0) // bottom left corner
            {
                newGrid[0][0] = false; newGrid[0][1] = grid[m-2][0]; newGrid[0][2] = grid[m-2][1];
                newGrid[1][0] = false; newGrid[1][1] = grid[m-1][0]; newGrid[1][2] = grid[m-1][1];
                newGrid[2][0] = false; newGrid[2][1] = false; newGrid[2][2] = false;
            }
            else if(i == 0 && j == n-1) //top right corner
            {
                newGrid[0][0] = false; newGrid[0][1] = false; newGrid[0][2] = false;
                newGrid[1][0] = grid[0][n-2]; newGrid[1][1] = grid[0][n-1]; newGrid[1][2] = false;
                newGrid[2][0] = grid[1][n-2]; newGrid[2][1] = grid[1][n-1]; newGrid[2][2] = false;
            }
            else if(i == m-1 && j == n-1) //bottom right corner
            {
                newGrid[0][0] = grid[m-2][n-2]; newGrid[0][1] = grid[m-2][n-1]; newGrid[0][2] = false;
                newGrid[1][0] = grid[m-1][n-2]; newGrid[1][1] = grid[m-1][n-1]; newGrid[1][2] = false;
                newGrid[2][0] = false; newGrid[2][1] = false; newGrid[2][2] = false;
            }
            else if(i == 0) //top row
            {
                newGrid[0][0] = false;
                newGrid[0][1] = false;
                newGrid[0][2] = false;
                newGrid[1][0] = grid[0][j-1];
                newGrid[1][1] = grid[0][j];
                newGrid[1][2] = grid[0][j+1];
                newGrid[2][0] = grid[1][j-1];
                newGrid[2][1] = grid[1][j];
                newGrid[2][2] = grid[1][j+1];
            }
            else if(j == 0)//left column
            {
                newGrid[0][0] = false;
                newGrid[0][1] = grid[i-1][0];
                newGrid[0][2] = grid[i-1][1];
                newGrid[1][0] = false;
                newGrid[1][1] = grid[i][0];
                newGrid[1][2] = grid[i][1];
                newGrid[2][0] = false;
                newGrid[2][1] = grid[i+1][0];
                newGrid[2][2] = grid[i+1][1];
            }
            else if(i == m-1)//bottom row
            {
                newGrid[0][0] = grid[m-2][j-1];
                newGrid[0][1] = grid[m-2][j];
                newGrid[0][2] = grid[m-2][j+1];
                newGrid[1][0] = grid[m-1][j-1];
                newGrid[1][1] = grid[m-1][j];
                newGrid[1][2] = grid[m-1][j+1];
                newGrid[2][0] = false;
                newGrid[2][1] = false;
                newGrid[2][2] = false;
            }
            else if(j == n-1)//right column
            {
                newGrid[0][0] = grid[i-1][n-2];
                newGrid[0][1] = grid[i-1][n-1];
                newGrid[0][2] = false;
                newGrid[1][0] = grid[i][n-2];
                newGrid[1][1] = grid[i][n-1];
                newGrid[1][2] = false;
                newGrid[2][0] = grid[i+1][n-2];
                newGrid[2][1] = grid[i+1][n-1];
                newGrid[2][2] = false;
            }


            //checks to see which scenario the cell is in
            scenario = checkScenario(newGrid);


            //carries out the outcome of the scenario
            switch(scenario)
            {
            case 0:
                break;
            case 1 : //underpopulation
            case 2: //overcrowding
                copyGrid[i][j] = false;
                break;
            case 3: //survival
            case 4: //creation of life
                copyGrid[i][j] = true;
                break;
            }
        }
    }
    bool useNewGrid[m][n];
    for(int e = 0; e < m; e++)
    {
        for(int f = 0; f < n; f++)
        {
            useNewGrid[e][f] = copyGrid[e][f];
        }
    }




    for(int k = 2; k <= t; k++) //go through each iteration
    {
        for(int g = 0; g < m; g++)
        {
            for(int h = 0; h < n; h++)
            {
                copyGrid[g][h] = false;//make sure we are changing the right array
            }
        }
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    //new 3x3 grid to check how many neighbours a cell has
                    bool newGrid[3][3] = {
                    {useNewGrid[i-1][j-1], useNewGrid[i-1][j], useNewGrid[i-1][j+1]},
                    {useNewGrid[i][j-1], useNewGrid[i][j], useNewGrid[i][j+1]},
                    {useNewGrid[i+1][j-1], useNewGrid[i+1][j], useNewGrid[i+1][j+1]}
                    };
                    if(i == 0 && j == 0)  //top left corner
                    {
                        newGrid[0][0] = false;
                        newGrid[0][1] = false;
                        newGrid[0][2] = false;
                        newGrid[1][0] = false;
                        newGrid[1][1] = useNewGrid[0][0];
                        newGrid[1][2] = useNewGrid[0][1];
                        newGrid[2][0] = false;
                        newGrid[2][1] = useNewGrid[1][0];
                        newGrid[2][2] = useNewGrid[1][1];
                    }
                    else if(i == m-1 && j == 0) // bottom left corner
                    {
                        newGrid[0][0] = false;
                        newGrid[0][1] = useNewGrid[m-2][0];
                        newGrid[0][2] = useNewGrid[m-2][1];
                        newGrid[1][0] = false;
                        newGrid[1][1] = useNewGrid[m-1][0];
                        newGrid[1][2] = useNewGrid[m-1][1];
                        newGrid[2][0] = false;
                        newGrid[2][1] = false;
                        newGrid[2][2] = false;
                    }
                    else if(i == 0 && j == n-1) //top right corner
                    {
                        newGrid[0][0] = false;
                        newGrid[0][1] = false;
                        newGrid[0][2] = false;
                        newGrid[1][0] = useNewGrid[0][n-2];
                        newGrid[1][1] = useNewGrid[0][n-1];
                        newGrid[1][2] = false;
                        newGrid[2][0] = useNewGrid[1][n-2];
                        newGrid[2][1] = useNewGrid[1][n-1];
                        newGrid[2][2] = false;
                    }
                    else if(i == m-1 && j == n-1) //bottom right corner
                    {
                        newGrid[0][0] = useNewGrid[m-2][n-2];
                        newGrid[0][1] = useNewGrid[m-2][n-1];
                        newGrid[0][2] = false;
                        newGrid[1][0] = useNewGrid[m-1][n-2];
                        newGrid[1][1] = useNewGrid[m-1][n-1];
                        newGrid[1][2] = false;
                        newGrid[2][0] = false;
                        newGrid[2][1] = false;
                        newGrid[2][2] = false;
                    }
                    else if(i == 0) //top row
                    {
                        newGrid[0][0] = false;
                        newGrid[0][1] = false;
                        newGrid[0][2] = false;
                        newGrid[1][0] = useNewGrid[0][j-1];
                        newGrid[1][1] = useNewGrid[0][j];
                        newGrid[1][2] = useNewGrid[0][j+1];
                        newGrid[2][0] = useNewGrid[1][j-1];
                        newGrid[2][1] = useNewGrid[1][j];
                        newGrid[2][2] = useNewGrid[1][j+1];
                    }
                    else if(j == 0)//left column
                    {
                        newGrid[0][0] = false;
                        newGrid[0][1] = useNewGrid[i-1][0];
                        newGrid[0][2] = useNewGrid[i-1][1];
                        newGrid[1][0] = false;
                        newGrid[1][1] = useNewGrid[i][0];
                        newGrid[1][2] = useNewGrid[i][1];
                        newGrid[2][0] = false;
                        newGrid[2][1] = useNewGrid[i+1][0];
                        newGrid[2][2] = useNewGrid[i+1][1];
                    }
                    else if(i == m-1)//bottom row
                    {
                        newGrid[0][0] = useNewGrid[m-2][j-1];
                        newGrid[0][1] = useNewGrid[m-2][j];
                        newGrid[0][2] = useNewGrid[m-2][j+1];
                        newGrid[1][0] = useNewGrid[m-1][j-1];
                        newGrid[1][1] = useNewGrid[m-1][j];
                        newGrid[1][2] = useNewGrid[m-1][j+1];
                        newGrid[2][0] = false;
                        newGrid[2][1] = false;
                        newGrid[2][2] = false;
                    }
                    else if(j == n-1)//right column
                    {
                        newGrid[0][0] = useNewGrid[i-1][n-2];
                        newGrid[0][1] = useNewGrid[i-1][n-1];
                        newGrid[0][2] = false;
                        newGrid[1][0] = useNewGrid[i][n-2];
                        newGrid[1][1] = useNewGrid[i][n-1];
                        newGrid[1][2] = false;
                        newGrid[2][0] = useNewGrid[i+1][n-2];
                        newGrid[2][1] = useNewGrid[i+1][n-1];
                        newGrid[2][2] = false;
                    }


                    //checks to see which scenario the cell is in
                    scenario = checkScenario(newGrid);


                    //carries out the outcome of the scenario
                    switch(scenario)
                    {
                    case 0:
                        break;
                    case 1 : //underpopulation
                    case 2: //overcrowding
                        copyGrid[i][j] = false;
                        break;
                    case 3: //survival
                    case 4: //creation of life
                        copyGrid[i][j] = true;
                        break;
                    }
                }
            }
        bool useNewGrid[m][n];
        for(int e = 0; e < m; e++)
        {
            for(int f = 0; f < n; f++)
            {
                useNewGrid[e][f] = copyGrid[e][f];
            }
        }
    }


    int val = 0; //counting how many live cells there are
    for(int c =0; c < m; c++)
    {
        for(int d = 0; d < n; d++)
        {
            if(copyGrid[c][d] == true)
            {
                val = val + 1;
            }
        }
    }

    cout << "Number of cells alive after " << t << " turns is " << val << endl;

    return 0;
}
