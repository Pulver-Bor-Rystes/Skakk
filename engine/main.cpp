#include "shorthands.h"
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
        board::parse_fen(promotion_position);
        print::game();

        moves move_list[1];
        board::generate_moves(move_list);
        print::all_moves(move_list);
        print::bitboard(state::bitboards[5]);
        print::game();
        print::attacked_squares(white);

        uci::parse_json("json movedata");
    }

    else
    {
        uci::init();
    }
    
    return 0;
}
