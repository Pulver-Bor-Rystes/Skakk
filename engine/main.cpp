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
