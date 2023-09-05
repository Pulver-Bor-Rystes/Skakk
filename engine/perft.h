#pragma once
#include "board.h"

/*
    The perft namespace is used for performance testing
*/

namespace perft {

    // Amount of reached nodes
    extern long nodes;

    // Recursive function to test how many possible positions exist
    static inline void driver(int depth) {

        if(!depth) {
            nodes++;
            return;
        }

        //generates moves 
        moves move_list[1];
        board::generate_moves(move_list);

        for (int move_count = 0; move_count < move_list->size; move_count++)
        {
            int current_move = move_list->array[move_count];
            int captured_piece = no_piece;
            if(is_capture(current_move)) {
                for (int piece_type = P; piece_type <= k; piece_type++)
                {
                    if(is_occupied(state::bitboards[piece_type], get_target(current_move))) {
                        captured_piece = piece_type;
                        break;
                    }
                }
            }

            // Copies board for later retrieval
            copy_board(current_move, captured_piece);

            // Makes move and skips if illegal
            if(!board::make_move(current_move)) continue;

            // Recursively calls itself with current position
            driver(depth-1);


            // Retrieves the previous position
            revert_board();
        }
    }

    // Essentially an outer layer of the driver function
    // to display test information
    void test(int depth);
}
