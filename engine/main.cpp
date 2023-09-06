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
        board::parse_fen(start_position);



        board::search_position(8);
    }

    else
    {
        uci::init();
    }
    
    return 0;
}
