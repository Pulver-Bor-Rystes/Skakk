#include "shorthands.h"
#include "rng.h"
#include "movegen.h"
#include "perft.h"
#include "uci.h"
#include "utils.h"
#include "board.h"


int main()
{
    movegen::init();

    int debugging = 0;

    if (debugging)
    {
        board::parse_fen(tricky_position);
        print::game();

        static int piece_array[64];
        memset(&piece_array, 0, sizeof(piece_array));
        for (int piece_type = P; piece_type <= k; piece_type++)
        {
            U64 bitboard = state::bitboards[piece_type];

            while (bitboard) {
                int square = movegen::get_ls1b(bitboard);
                pop_bit(bitboard, square);
                piece_array[square] = piece_type;
            }
        }


        moves move_list[1];
        board::generate_moves(move_list);
        print::all_moves(move_list);
        print::game();

        cout << is_capture(move_list->array[0]);
    }

    else
    {
        uci::init();
    }
    
    return 0;
}
