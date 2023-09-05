#include "utils.h"
#include "board.h"
#include "limits"
#include <bits/stdc++.h>

std::string format::eval(int eval) {
    double divided_score = static_cast<double>(eval) / 100.0;
    std::string formatted_score = std::to_string(divided_score);
    size_t dotPosition = formatted_score.find('.');
    
    // Ensure there are exactly two decimal places
    if (dotPosition != std::string::npos && dotPosition + 3 < formatted_score.length()) {
        formatted_score = formatted_score.substr(0, dotPosition + 3);
    }
    
    return formatted_score;
}

std::string format::move(int move) {
    return index_to_square[get_source(move)] +
           index_to_square[get_target(move)] + 
           char(promoted_pieces[get_promotion_piece_type(move)]);
}

void print::move(int move) {
    cout << format::move(move);
}

void print::all_moves(moves *move_list) {

    if(!move_list->size) {
        cout << "\n     No moves in move list!";
        return;
    }

    cout << "\n     move    piece   capture   double    en passant    castling    score\n\n";

    for (int move_count = 0; move_count < move_list->size; move_count++)
    {
        int move = move_list->array[move_count];
        
        cout << "     " << index_to_square[get_source(move)] <<
        index_to_square[get_target(move)] <<
        char(promoted_pieces[get_promotion_piece_type(move)]) <<
        "   " << ascii_pieces[get_piece(move)] << 
        "       " << (is_capture(move) ? 1 : 0) <<
        "         " << (is_double_pawn_push(move) ? 1 : 0) <<
        "         " << (is_en_passant(move) ? 1 : 0) << 
        "             " << (is_castling(move) ? 1 : 0) << 
        "           " << (board::score_move(move)) << endl;
    }
    
    cout << "\n     Total number of moves: " << move_list->size << "\n\n";
}

void print::attacked_squares(int side) {
    U64 result = 0ULL;
    for (int square = 0; square < 64; square++)
    {
        if(board::is_square_attacked(square, side)) set_bit(result, square);
    }
    
    print::bitboard(result);
}


void print::bitboard(U64 bitboard)
{
    int square;
    cout << "\n";

    for (int rank = 0; rank < 8; rank++)
    {
        for (int file = 0; file < 8; file++)
        {
            square = rank * 8 + file;

            if (!file)
                cout << "  " << 8 - rank << " ";

            cout << " " << get_bit(bitboard, square);
        }

        cout << "\n";
    }

    cout << "\n     a b c d e f g h\n\n";

    cout << "     bitboard: " << bitboard << "\n";
}

void print::game() {
    int square;
    cout << "\n";

    for (int rank = 0; rank < 8; rank++)
    {
        for (int file = 0; file < 8; file++)
        {
            square = rank * 8 + file;

            if (!file)
                cout << "  " << 8 - rank << " ";

            int piece = -1;
            for(int i = 0; i < 12; i++) {
                if(is_occupied(state::bitboards[i], square)) {
                    piece = i;
                    break;
                }
            }

            cout << " " << (piece == -1 ? "." : ascii_pieces[piece]);

        }

        cout << "\n";
    }

    cout << "\n     a b c d e f g h\n\n";
    cout << "     Side:        " << (state::side == white ? "white" : "black") << endl;
    cout << "     en_passant:  " << ((state::en_passant != no_sq) ? index_to_square[state::en_passant] : "no") << endl;
    cout << "     Castling:    " << ((state::castle & wk) ? 'K' : '-') <<
                                    ((state::castle & wq) ? 'Q' : '-') <<
                                    ((state::castle & bk) ? 'k' : '-') <<
                                    ((state::castle & bq) ? 'q' : '-') <<
                                    endl;
}

unsigned int rng::random_state = 1804289383;

// Generates a random 32-bit number from the current state
unsigned int rng::generate_32_bit()
{
    unsigned int number = rng::random_state;

    number ^= number << 13;
    number ^= number >> 17;
    number ^= number << 5;

    // Updates state so new numbers can be found
    random_state = number;

    return number;
}

unsigned int rng::generate_64_bit()
{

    // Generates four different 32-bit numbers where the first 16 bits are 0
    U64 n1 = (U64)(rng::generate_32_bit()) & 0xFFFF;
    U64 n2 = (U64)(rng::generate_32_bit()) & 0xFFFF;
    U64 n3 = (U64)(rng::generate_32_bit()) & 0xFFFF;
    U64 n4 = (U64)(rng::generate_32_bit()) & 0xFFFF;

    // Slices them all together
    return n1 | (n2 << 16) | (n3 << 32) | (n4 << 48);
}

U64 rng::generate_magic_number_contender()
{
    return rng::generate_64_bit() & rng::generate_64_bit() & rng::generate_64_bit();
}

Timer::Timer() {
    start_time = std::chrono::high_resolution_clock::now();
}

void Timer::reset() {
    start_time = std::chrono::high_resolution_clock::now();
}

double Timer::get_time_passed_millis() {
    auto current_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();
}

Timer timer;

bool stop_calculating = false;
bool found_checkmate = false;
bool use_time = false;
double stop_time = std::numeric_limits<double>::infinity();

