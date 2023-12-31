#include "hidden_singles.h"
#include <stddef.h>
#include <stdbool.h>

<<<<<<< HEAD
<<<<<<< HEAD
int hidden_singles(SudokuBoard *p_board)
=======

typedef struct 
>>>>>>> bbdb659 (change the hidden singles)
{
    int row;
    int col;
    int value;
} HiddenSingles;


// The function finds hidden single cells in the Sudoku board
void find_a_hidden_single_cell(Cell** p_cells, HiddenSingles* p_hidden_singles, int* p_counter) 
{

    // Iterate through each value (1 to BOARD_SIZE) to find hidden singles
    for (int value = 1; value <= BOARD_SIZE; ++value) 
    {
        // Check if the value is a candidate in only one cell
        int candidate_count = 0;
        Cell* candidate_cell = NULL;

        for (int i = 0; i < BOARD_SIZE; ++i) 
        {
            Cell* cell = p_cells[i];

            // Skip cells that are already solved
            if (cell->num_candidates == 1) {
                continue;
            }

            // Check if the value is a candidate in the cell
            if (cell->candidates[value - 1] != 0) 
            {
                candidate_count++;
                candidate_cell = cell;
            }
        }

        // If only one cell has the value as a candidate, it's a hidden single
        if (candidate_count == 1) 
        {

            HiddenSingles hidden_single;
            hidden_single.row = candidate_cell->row_index;
            hidden_single.col = candidate_cell->col_index;
            hidden_single.value = value;

            // Store the value about the hidden single cell
            bool new_hidden_single_value = true;
            for (int i = 0; i < *p_counter; i ++)
            {

                if (p_hidden_singles[i].row == hidden_single.row)

                {
                    if (p_hidden_singles[i].col == hidden_single.col)

                    {
                        new_hidden_single_value = false;

                    }    

                }

            }
            if (new_hidden_single_value == true){

                p_hidden_singles[*p_counter] = hidden_single;
                (*p_counter)++;
            }
        }
    }
}
<<<<<<< HEAD
=======
>>>>>>> 8b19c97 (added description)
=======

int hidden_singles(SudokuBoard* p_board) 
{
    int total = 0; // of hidden single values
    HiddenSingles hidden_cell[BOARD_SIZE * BOARD_SIZE];


    // Iterate through rows and check hidden single values
    for (int i = 0; i < BOARD_SIZE; ++i) 
    {

        find_a_hidden_single_cell(p_board->p_cols[i], hidden_cell, &total);
    }

    // Iterate through columns and check hidden single values
    for (int j = 0; j < BOARD_SIZE; ++j) 
    {
        
        find_a_hidden_single_cell(p_board->p_rows[j], hidden_cell, &total);

    }

    // Iterate through boxes and check hidden single values
    for (int k = 0; k < BOARD_SIZE; ++k)
    {
        find_a_hidden_single_cell(p_board->p_boxes[k], hidden_cell, &total);
    }

    for(int h = 0; h < total; h++)
    {

        for(int value = 1; value <= 9; value++)
        {

            if(value != hidden_cell[h].value)
            {

                Cell* cell = &p_board->data[hidden_cell[h].row][hidden_cell[h].col];

                if (cell->candidates[value - 1] != 0) 
                {

                    cell->candidates[value -1] = 0;
                    cell->num_candidates--;
                }
            }
        }
    }

    return total;
}
>>>>>>> bbdb659 (change the hidden singles)