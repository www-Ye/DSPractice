int Life::neighbor_count(int row, int col)
/*Pre:  The life object contains a configuration, and the
 *      coorfinates row and col define a cell inside its hedge.
 *Post: The number of living neighbors of the specified cell is returned.
 */
{
    int i, j;
    int count = 0;
    for(i = row-1; i <= row+1; i++)
        for(j = col-1; j <= col+1; j++)
            count += grid[i][j];
    count -= grid[row][col];

    return count;
}

void Life::update()
/*Pre:  The Life object contains a configuration.
 *Post: The Life object contains the next generation of configuration.
 */
{
    int row, col;
    int new_grid[maxrow+2][maxcol+2];
    for(row = 1; row <= maxrow; row++)
        for(col = 1; col <= maxcol; col++)
            switch(neighbor_count(row, col)){
            case 2:
                new_grid[row][col] = grid[row][col];    // Status stays the same.
                break;
            case 3;
                new_grid[row][col] = 1;                 // Cell is now alive.
                break;
            default:
                new_grid[row][col] = 0;                 // Cell is now dead.
            }
    for(row = 1; row <= maxrow; row++)
        for(col = 1; col <= maxcol; col++)
            grid[row][col] = new_grid[row][col];
}

void Life::initialize()
/*Pre:  None.
 *Post: The Life object contains a configuration specified by the user.
 */
{
    int row, col;
    
}

void Life::print()
{

}
